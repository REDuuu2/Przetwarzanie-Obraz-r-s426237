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

    // Tworzymy nowy obraz w trybie monochromatycznym
    PNM* newImage = new PNM(width, height, QImage::Format_Mono);

    // Iterujemy po każdym pikselu
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Pobieramy wartość jasności piksela
            int pixelValue = qGray(image->pixel(x, y));

            // Porównujemy z progiem
            if (pixelValue < threshold) {
                newImage->setPixel(x, y, 0); // czarny
            } else {
                newImage->setPixel(x, y, 1); // biały
            }
        }
    }

    return newImage;
}




