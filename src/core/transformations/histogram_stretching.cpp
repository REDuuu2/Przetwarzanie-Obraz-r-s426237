#include "histogram_stretching.h"
#include <algorithm>
#include "../histogram.h"

HistogramStretching::HistogramStretching(PNM* img) :
    Transformation(img)
{
}

HistogramStretching::HistogramStretching(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* HistogramStretching::transform()
{
    int width  = image->width();
    int height = image->height();
    PNM* newImage = new PNM(width, height, image->format());

    int levels = 256;

    if (image->format() == QImage::Format_Indexed8)
    {
        QHash<int, int>* hist = image->getHistogram()->get(Histogram::LChannel);

        int l = 0, r = 255;

        for (int i = 0; i < levels; ++i)
        {
            if ((*hist)[i] > 0)
            {
                l = i;
                break;
            }
        }

        for (int i = levels - 1; i >= 0; --i)
        {
            if ((*hist)[i] > 0)
            {
                r = i;
                break;
            }
        }

        if (r == l)
            return newImage;

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                int val = image->pixelIndex(x, y);
                int newVal = (val - l) * 255 / (r - l);
                newVal = std::min(255, std::max(0, newVal));
                newImage->setPixel(x, y, newVal);
            }
        }
    }
    else
    {
        QHash<int, int>* histR = image->getHistogram()->get(Histogram::RChannel);
        QHash<int, int>* histG = image->getHistogram()->get(Histogram::GChannel);
        QHash<int, int>* histB = image->getHistogram()->get(Histogram::BChannel);

        int lR = 0, rR = 255;
        int lG = 0, rG = 255;
        int lB = 0, rB = 255;

        for (int i = 0; i < levels; ++i)
        {
            if ((*histR)[i] > 0) { lR = i; break; }
        }
        for (int i = levels - 1; i >= 0; --i)
        {
            if ((*histR)[i] > 0) { rR = i; break; }
        }

        for (int i = 0; i < levels; ++i)
        {
            if ((*histG)[i] > 0) { lG = i; break; }
        }
        for (int i = levels - 1; i >= 0; --i)
        {
            if ((*histG)[i] > 0) { rG = i; break; }
        }

        for (int i = 0; i < levels; ++i)
        {
            if ((*histB)[i] > 0) { lB = i; break; }
        }
        for (int i = levels - 1; i >= 0; --i)
        {
            if ((*histB)[i] > 0) { rB = i; break; }
        }

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                QRgb pixel = image->pixel(x, y);

                int r = qRed(pixel);
                int g = qGreen(pixel);
                int b = qBlue(pixel);

                int newR = (r - lR) * 255 / (rR - lR);
                int newG = (g - lG) * 255 / (rG - lG);
                int newB = (b - lB) * 255 / (rB - lB);

                newR = std::min(255, std::max(0, newR));
                newG = std::min(255, std::max(0, newG));
                newB = std::min(255, std::max(0, newB));

                newImage->setPixel(x, y, qRgb(newR, newG, newB));
            }
        }
    }

    return newImage;
}
