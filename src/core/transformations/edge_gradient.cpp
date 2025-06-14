#include "edge_gradient.h"

EdgeGradient::EdgeGradient(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

EdgeGradient::EdgeGradient(PNM* img) :
    Convolution(img)
{
}

PNM* EdgeGradient::verticalDetection()
{
    return convolute(g_y, RepeatEdge);
}

PNM* EdgeGradient::horizontalDetection()
{
    return convolute(g_x, RepeatEdge);
}

PNM* EdgeGradient::transform()
{
    PNM* gxImage = horizontalDetection();
    PNM* gyImage = verticalDetection();

    int width  = image->width();
    int height = image->height();
    QImage::Format format = image->format();

    PNM* result = new PNM(width, height, format);

    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            if (format == QImage::Format_Indexed8)
            {
                int gx = qGray(gxImage->pixel(x, y));
                int gy = qGray(gyImage->pixel(x, y));

                int g = static_cast<int>(std::sqrt(gx * gx + gy * gy));


                if (g < 0)   g = 0;
                if (g > 255) g = 255;

                result->setPixel(x, y, g);
            }
            else
            {
                QColor colorX(gxImage->pixel(x, y));
                QColor colorY(gyImage->pixel(x, y));

                int r = static_cast<int>(std::sqrt(colorX.red()   * colorX.red()   + colorY.red()   * colorY.red()));
                int g = static_cast<int>(std::sqrt(colorX.green() * colorX.green() + colorY.green() * colorY.green()));
                int b = static_cast<int>(std::sqrt(colorX.blue()  * colorX.blue()  + colorY.blue()  * colorY.blue()));


                if (r < 0) r = 0;
                if (r > 255) r = 255;

                if (g < 0) g = 0;
                if (g > 255) g = 255;

                if (b < 0) b = 0;
                if (b > 255) b = 255;

                result->setPixel(x, y, qRgb(r, g, b));
            }
        }
    }

    delete gxImage;
    delete gyImage;

    return result;
}
