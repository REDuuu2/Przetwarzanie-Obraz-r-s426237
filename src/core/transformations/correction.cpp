#include "correction.h"
#include <QtMath>
#include <QColor>
#include <QDebug>
Correction::Correction(PNM* img) :
    Transformation(img)
{
}

Correction::Correction(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* Correction::transform()
{
    float shift  = getParameter("shift").toFloat();   // Jasność
    float factor = getParameter("factor").toFloat();  // Kontrast
    float gamma  = getParameter("gamma").toFloat();   // Gamma
    float LUT[256];
    float value;

    int width  = image->width();
    int height = image->height();

    PNM* newImage = new PNM(width, height, image->format());

    for (int i = 0; i < 256; ++i)
    {
        value = pow(i + shift * factor, gamma);
        value = qBound(0.0f, value, 255.0f);
        LUT[i]=value;
    }

    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            QRgb pixel = image->pixel(x, y);

            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);

            int newR = LUT[r];
            int newG = LUT[g];
            int newB = LUT[b];

            newImage->setPixel(x, y, qRgb(newR, newG, newB));
        }
    }

    return newImage;
}
