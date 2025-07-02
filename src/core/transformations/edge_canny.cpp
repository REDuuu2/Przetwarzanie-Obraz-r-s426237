#include "edge_canny.h"

#include "blur_gaussian.h"
#include "conversion_grayscale.h"
#include "edge_sobel.h"

#include <cmath>
#include <queue>

EdgeCanny::EdgeCanny(PNM* img) :
    Convolution(img)
{
}

EdgeCanny::EdgeCanny(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

PNM* EdgeCanny::transform()
{
    int width = image->width();
    int height = image->height();

    int upper_thresh = getParameter("upper_threshold").toInt();
    int lower_thresh = getParameter("lower_threshold").toInt();

    qDebug() << "Thresholds: upper =" << upper_thresh << ", lower =" << lower_thresh;


    ConversionGrayscale grayscale(image);
    PNM* grayImage = grayscale.transform();

    qDebug() << "Gray image created";




    BlurGaussian blur(grayImage);
    blur.setParameter("size", 3);
    blur.setParameter("sigma", 1.6);
    PNM* blurredImage = blur.transform();

    qDebug() << "Blurred image created";


    EdgeSobel sobel(blurredImage);
    math::matrix<float>* gradX = sobel.rawHorizontalDetection();
    math::matrix<float>* gradY = sobel.rawVerticalDetection();


    float minGradX = std::numeric_limits<float>::max();
    float maxGradX = std::numeric_limits<float>::lowest();
    float minGradY = std::numeric_limits<float>::max();
    float maxGradY = std::numeric_limits<float>::lowest();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)

        {
            float valX = (*gradX)(x, y);
            float valY = (*gradY)(x, y);
            if (valX < minGradX) minGradX = valX;
            if (valX > maxGradX) maxGradX = valX;
            if (valY < minGradY) minGradY = valY;
            if (valY > maxGradY) maxGradY = valY;
        }
    }
    qDebug() << "GradX min:" << minGradX << "max:" << maxGradX;
    qDebug() << "GradY min:" << minGradY << "max:" << maxGradY;


    math::matrix<float> magnitude(width, height);
    math::matrix<float> direction(width, height);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float gx = (*gradX)(x, y);
            float gy = (*gradY)(x, y);

            magnitude(x, y) = std::sqrt(gx * gx + gy * gy);
            float angle = std::atan2(gy, gx) * 180.0f / M_PI;
            if (angle < 0) angle += 180.0f;

            direction(x, y) = angle;
        }
    }


    float minMag = std::numeric_limits<float>::max();
    float maxMag = std::numeric_limits<float>::lowest();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float mag = magnitude(x, y);
            if (mag < minMag) minMag = mag;
            if (mag > maxMag) maxMag = mag;
        }
    }
    qDebug() << "Magnitude min:" << minMag << "max:" << maxMag;


    math::matrix<float> suppressed(width, height, 0.0f);

    for (int y = 1; y < height - 1; ++y)
    {
        for (int x = 1; x < width - 1; ++x)
        {
            float angle = direction(x, y);
            float mag = magnitude(x, y);

            float mag1 = 0, mag2 = 0;

            if ((angle >= 0 && angle < 22.5) || (angle >= 157.5 && angle < 180))
            {
                mag1 = magnitude(x - 1, y);
                mag2 = magnitude(x + 1, y);
            }
            else if (angle >= 22.5 && angle < 67.5)
            {
                mag1 = magnitude(x - 1, y - 1);
                mag2 = magnitude(x + 1, y + 1);
            }
            else if (angle >= 67.5 && angle < 112.5)
            {
                mag1 = magnitude(x, y - 1);
                mag2 = magnitude(x, y + 1);
            }
            else if (angle >= 112.5 && angle < 157.5)
            {
                mag1 = magnitude(x - 1, y + 1);
                mag2 = magnitude(x + 1, y - 1);
            }

            if (mag >= mag1 && mag >= mag2 && mag >= lower_thresh/10)
                suppressed(x, y) = mag;
            else
                suppressed(x, y) = 0;
        }
    }


    float minSupp = std::numeric_limits<float>::max();
    float maxSupp = std::numeric_limits<float>::lowest();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float val = suppressed(x, y);
            if (val < minSupp) minSupp = val;
            if (val > maxSupp) maxSupp = val;
        }
    }
    qDebug() << "Suppressed min:" << minSupp << "max:" << maxSupp;


    PNM* result = new PNM(width, height, QImage::Format_Grayscale8);

    math::matrix<bool> visited(width, height, false);
    std::queue<std::pair<int, int>> edgePixels;

    for (int y = 1; y < height - 1; ++y)
    {
        for (int x = 1; x < width - 1; ++x)
        {
            if (suppressed(x, y) >= upper_thresh/10)
            {
                edgePixels.push(std::make_pair(x, y));
                visited(x, y) = true;
                result->setPixel(x, y, qRgb(255, 255, 255));
            }
            else
            {
                result->setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }


    qDebug() << "Initial edge pixels count:" << edgePixels.size();


    int countEdges = 0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            QRgb px = result->pixel(x, y);
            if (qRed(px) > 0) countEdges++;
        }
    }
    qDebug() << "Total edge pixels after hysteresis:" << countEdges;

    delete gradX;
    delete gradY;
    delete grayImage;
    delete blurredImage;

    return result;
}
