#include "histogram_equalization.h"
#include <algorithm>
#include "../histogram.h"

HistogramEqualization::HistogramEqualization(PNM* img) :
    Transformation(img)
{
}

HistogramEqualization::HistogramEqualization(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* HistogramEqualization::transform()
{

    int width = image->width();
    int height = image->height();
    int size = width * height;
    int levels = 256;

    PNM* newImage = new PNM(width, height, image->format());

    if (image->format() == QImage::Format_Indexed8) // Obraz w skali szarości
    {
        QHash<int, int>* hist = image->getHistogram()->get(Histogram::LChannel);

        QVector<double> prob(levels, 0.0);
        for (int i = 0; i < levels; ++i)
        {
            prob[i] = static_cast<double>((*hist)[i]) / size;
        }

        QVector<double> cdf(levels, 0.0);
        cdf[0] = prob[0];
        for (int i = 1; i < levels; ++i)
        {
            cdf[i] = cdf[i - 1] + prob[i];
        }

        QVector<int> lut(levels, 0);
        for (int i = 0; i < levels; ++i)
        {
            lut[i] = std::min(255, std::max(0, static_cast<int>(cdf[i] * 255)));
        }

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                int val = image->pixelIndex(x, y);
                newImage->setPixel(x, y, lut[val]);
            }
        }
    }
    else
    {
        QVector<int> lutR(levels, 0), lutG(levels, 0), lutB(levels, 0);

        QHash<int, int>* histR = image->getHistogram()->get(Histogram::RChannel);
        QHash<int, int>* histG = image->getHistogram()->get(Histogram::GChannel);
        QHash<int, int>* histB = image->getHistogram()->get(Histogram::BChannel);

        auto computeLUT = [&](QHash<int, int>* hist) -> QVector<int>
        {
            QVector<double> prob(levels, 0.0);
            for (int i = 0; i < levels; ++i)
                prob[i] = static_cast<double>((*hist)[i]) / size;

            QVector<double> cdf(levels, 0.0);
            cdf[0] = prob[0];
            for (int i = 1; i < levels; ++i)
                cdf[i] = cdf[i - 1] + prob[i];

            QVector<int> lut(levels, 0);
            for (int i = 0; i < levels; ++i)
                lut[i] = std::min(255, std::max(0, static_cast<int>(cdf[i] * 255)));

            return lut;
        };

        lutR = computeLUT(histR);
        lutG = computeLUT(histG);
        lutB = computeLUT(histB);

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                QRgb pixel = image->pixel(x, y);

                int r = qRed(pixel);
                int g = qGreen(pixel);
                int b = qBlue(pixel);

                int newR = lutR[r];
                int newG = lutG[g];
                int newB = lutB[b];

                newImage->setPixel(x, y, qRgb(newR, newG, newB));
            }
        }
    }

    return newImage;
}

