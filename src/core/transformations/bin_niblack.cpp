#include "bin_niblack.h"

BinarizationNiblack::BinarizationNiblack(PNM* img) :
    Transformation(img)
{
}

BinarizationNiblack::BinarizationNiblack(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* BinarizationNiblack::transform()
{
    int width = image->width();
    int height = image->height();

    int r = getParameter("r").toInt();
    double a = getParameter("a").toDouble();

    PNM* newImage = new PNM(width, height, QImage::Format_Mono);

    // Funkcja zabezpieczająca odczyt poza krawędziami
    auto getGraySafe = [&](int x, int y) -> int {
        x = qBound(0, x, width - 1);
        y = qBound(0, y, height - 1);
        return qGray(image->pixel(x, y));
    };

    // Dla każdego piksela obliczamy próg i binarizujemy
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Granice okna
            int x_min = qMax(0, x - r);
            int x_max = qMin(width - 1, x + r);
            int y_min = qMax(0, y - r);
            int y_max = qMin(height - 1, y + r);

            int count = 0;
            double sum = 0;
            double sum_sq = 0;

            // Obliczamy średnią i odchylenie standardowe w oknie
            for (int wy = y_min; wy <= y_max; ++wy) {
                for (int wx = x_min; wx <= x_max; ++wx) {
                    int val = getGraySafe(wx, wy);
                    sum += val;
                    sum_sq += val * val;
                    count++;
                }
            }

            double mean = sum / count;
            double variance = (sum_sq / count) - (mean * mean);
            double stddev = (variance > 0) ? sqrt(variance) : 0;

            // Próg według wzoru Niblack
            double T = mean + a * stddev;

            int pixel_val = getGraySafe(x, y);
            newImage->setPixel(x, y, pixel_val < T ? 0 : 1);
        }
    }

    return newImage;
}
