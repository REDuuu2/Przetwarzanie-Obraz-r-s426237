#include "bin_manual.h"

BinarizationManual::BinarizationManual(PNM* img) :
    Transformation(img)
{
}

BinarizationManual::BinarizationManual(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* BinarizationManual::transform()
{
    int threshold = getParameter("threshold").toInt();

    int width  = image->width();
    int height = image->height();


    PNM* newImage = new PNM(width, height, QImage::Format_Mono);


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            int pixelValue = qGray(image->pixel(x, y));


            if (pixelValue < threshold) {
                newImage->setPixel(x, y, 0);
            } else {
                newImage->setPixel(x, y, 1);
            }
        }
    }

    return newImage;
}




