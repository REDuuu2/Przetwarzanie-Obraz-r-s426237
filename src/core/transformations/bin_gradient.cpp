#include "bin_gradient.h"

BinarizationGradient::BinarizationGradient(PNM* img) :
    Transformation(img)
{
}

BinarizationGradient::BinarizationGradient(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* BinarizationGradient::transform()
{
    int width = image->width();
    int height = image->height();


    PNM* newImage = new PNM(width, height, QImage::Format_Mono);


    auto getGraySafe = [&](int x, int y) -> int {
        x = qBound(0, x, width - 1);
        y = qBound(0, y, height - 1);
        return qGray(image->pixel(x, y));
    };

    double numerator = 0.0;
    double denominator = 0.0;


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int Ix = getGraySafe(x + 1, y) - getGraySafe(x - 1, y);
            int Iy = getGraySafe(x, y + 1) - getGraySafe(x, y - 1);

            int M = std::max(abs(Ix), abs(Iy));
            int I = getGraySafe(x, y);

            numerator += M * I;
            denominator += M;
        }
    }

    double T = denominator > 0 ? numerator / denominator : 0;


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int I = getGraySafe(x, y);
            if (I < T)
                newImage->setPixel(x, y, 0);
            else
                newImage->setPixel(x, y, 1);
        }
    }

    return newImage;
}


