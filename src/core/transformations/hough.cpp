#include "hough.h"

#include "conversion_grayscale.h"
#include "edge_laplacian.h"

#include <cmath>
#include <algorithm>

Hough::Hough(PNM* img) :
    Transformation(img)
{
}

Hough::Hough(PNM* img, ImageViewer* super) :
    Transformation(img, super)
{
}

PNM* Hough::transform()
{
    // Parametr dokładności kąta
    int thetaDensity = getParameter("theta_density").toInt();
    bool skipEdgeDetection = getParameter("skip_edge_detection").toBool();

    // Konwersja do odcieni szarości
    PNM* grayImage = ConversionGrayscale(image).transform();

    // Wykrywanie krawędzi (jeśli nie pominięto)
    if (!skipEdgeDetection) {
        grayImage = EdgeLaplacian(grayImage).transform();
    }

    int width = grayImage->width();
    int height = grayImage->height();

    // Maksymalne możliwe rho (długość przekątnej)
    int rhoMax = std::ceil(std::sqrt(width * width + height * height));

    // Rozmiar przestrzeni Hougha dla kąta
    int thetaSize = 180 * thetaDensity;

    // Utworzenie macierzy Hougha
    QImage houghImage(thetaSize, rhoMax * 2 + 1, QImage::Format_Grayscale8);
    houghImage.fill(0);

    std::vector<std::vector<int>> hough(thetaSize, std::vector<int>(2 * rhoMax + 1, 0));

    // Przeliczenia
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixelValue = qGray(grayImage->pixel(x, y));
            if (pixelValue > 0) {
                for (int k = 0; k < thetaSize; k++) {
                    double theta = (k * M_PI) / (thetaDensity * 180.0);
                    double rho = x * std::cos(theta) + y * std::sin(theta);
                    int rhoIndex = static_cast<int>(std::round(rho)) + rhoMax;
                    if (rhoIndex >= 0 && rhoIndex < 2 * rhoMax + 1) {
                        hough[k][rhoIndex]++;
                    }
                }
            }
        }
    }

    // Znalezienie maksimum
    int maxValue = 0;
    for (int k = 0; k < thetaSize; k++) {
        for (int r = 0; r < 2 * rhoMax + 1; r++) {
            if (hough[k][r] > maxValue) {
                maxValue = hough[k][r];
            }
        }
    }

    // Normalizacja do zakresu [0,255] i zapis do obrazu
    for (int k = 0; k < thetaSize; k++) {
        for (int r = 0; r < 2 * rhoMax + 1; r++) {
            int value = (maxValue > 0) ? (hough[k][r] * 255) / maxValue : 0;
            houghImage.setPixel(k, r, qRgb(value, value, value));
        }
    }

    return new PNM(houghImage);
}
