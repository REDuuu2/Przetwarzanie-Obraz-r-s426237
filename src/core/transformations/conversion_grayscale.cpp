#include "conversion_grayscale.h"
#include <QtGlobal>
ConversionGrayscale::ConversionGrayscale(PNM* img) :
    Transformation(img)
{
}

ConversionGrayscale::ConversionGrayscale(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* ConversionGrayscale::transform()
{
    int width = image->width();
    int height = image->height();

    PNM* newImage = new PNM(width, height, QImage::Format_Grayscale8);

    if (image->format() == QImage::Format_Mono)
    {
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
            {
                QColor color = QColor::fromRgb(image->pixel(x,y));
                newImage->setPixel(x,y, color == Qt::white ? PIXEL_VAL_MAX : PIXEL_VAL_MIN);
            }
    }
    else
    {
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
            {
                QRgb pixel = image->pixel(x,y);

                int r = qRed(pixel);
                int g = qGreen(pixel);
                int b = qBlue(pixel);
                int q = 0.299*r + 0.587*g+0 + 0.114*b;
                q = qBound(0, q, 255);

                QColor newPixel = QColor(q);
                newImage->setPixel(x,y, newPixel.rgb());
            }
        }
    return newImage;
}
