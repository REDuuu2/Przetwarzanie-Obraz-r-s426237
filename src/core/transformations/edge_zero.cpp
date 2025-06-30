#include "edge_zero.h"
#include "edge_laplacian_of_gauss.h"
#include <QtDebug>
#include <QtGui/qcolor.h>

EdgeZeroCrossing::EdgeZeroCrossing(PNM* img) :
    Convolution(img)
{
}

EdgeZeroCrossing::EdgeZeroCrossing(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

PNM* EdgeZeroCrossing::transform()
{
    int width = image->width();
    int height = image->height();

    int size = getParameter("size").toInt();
    double sigma = getParameter("sigma").toDouble();
    int t = getParameter("threshold").toInt();

    EdgeLaplaceOfGauss laplace(image);
    laplace.setParameter("size", size);
    laplace.setParameter("sigma", sigma);
    PNM* laplaceImg = laplace.transform();

    int minVal = 255;
    int maxVal = 0;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int val = qGray(laplaceImg->pixel(x, y));
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
        }
    }

    double center = (maxVal + minVal) / 2.0;

    PNM* newImage = new PNM(width, height, QImage::Format_Grayscale8);

    int halfWindow = size / 2;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int localMin = 255;
            int localMax = 0;

            for (int wy = -halfWindow; wy <= halfWindow; ++wy)
            {
                int yy = y + wy;
                if (yy < 0) yy = 0;
                if (yy >= height) yy = height - 1;

                for (int wx = -halfWindow; wx <= halfWindow; ++wx)
                {
                    int xx = x + wx;
                    if (xx < 0) xx = 0;
                    if (xx >= width) xx = width - 1;

                    int val = qGray(laplaceImg->pixel(xx, yy));
                    if (val < localMin) localMin = val;
                    if (val > localMax) localMax = val;
                }
            }

            if (localMin < (center - t) && localMax > (center + t))
            {
                int v = qGray(laplaceImg->pixel(x, y));
                if (v < 0) v = 0;
                if (v > 255) v = 255;
                newImage->setPixel(x, y, qRgb(v, v, v));
            }
            else
            {
                newImage->setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }

    delete laplaceImg;

    return newImage;
}
