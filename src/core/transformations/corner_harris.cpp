#include "corner_harris.h"

#include "blur_gaussian.h"
#include "conversion_grayscale.h"
#include "edge_sobel.h"

#include <algorithm> // dla std::max_element

CornerHarris::CornerHarris(PNM* img) :
    Convolution(img)
{
}

CornerHarris::CornerHarris(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

PNM* CornerHarris::transform()
{
    int threshold    = getParameter("threshold").toInt();
    double sigma        = getParameter("sigma").toDouble();
    double sigma_weight = getParameter("sigma_weight").toDouble();
    double k_param      = getParameter("k").toDouble();

    int width  = image->width();
    int height = image->height();

    // Nowy obraz binarny (czarno-biały) do wyników
    PNM* newImage = new PNM(width, height, QImage::Format_Mono);

    // 1. Konwersja do szarości
    ConversionGrayscale gray(image);
    PNM* grayImg = gray.transform();

    // 2. Rozmycie Gaussa 3x3 z podanym sigma
    BlurGaussian blur(grayImg);
    blur.setParameter("size", 3);
    blur.setParameter("sigma", sigma);
    PNM* blurred = blur.transform();
    delete grayImg; // już nie potrzebne

    // 3. Gradienty Sobela
    EdgeSobel sobel(blurred);
    math::matrix<float>* Gx = sobel.rawHorizontalDetection();
    math::matrix<float>* Gy = sobel.rawVerticalDetection();
    delete blurred;

    // 4. Inicjalizacja macierzy Ixx, Iyy, Ixy oraz corner-candidates i corner-nonmax-suppress
    math::matrix<float> Ixx(width, height);
    math::matrix<float> Iyy(width, height);
    math::matrix<float> Ixy(width, height);
    math::matrix<float> corner_candidates(width, height);
    math::matrix<float> corner_nonmax_suppress(width, height);

    // Zerowanie macierzy
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
        {
            Ixx(x,y) = 0;
            Iyy(x,y) = 0;
            Ixy(x,y) = 0;
            corner_candidates(x,y) = 0;
            corner_nonmax_suppress(x,y) = 0;
        }

    // 5. Obliczanie Ixx, Iyy, Ixy
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
        {
            float gx = (*Gx)(x,y);
            float gy = (*Gy)(x,y);
            Ixx(x,y) = gx * gx;
            Iyy(x,y) = gy * gy;
            Ixy(x,y) = gx * gy;
        }

    delete Gx;
    delete Gy;

    // 6. Liczenie wartości r dla każdego piksela (pomijamy krawędzie)
    for (int x = 1; x < width - 1; ++x)
    {
        for (int y = 1; y < height -1; ++y)
        {
            double Sxx = 0, Syy = 0, Sxy = 0;

            // sumowanie z maską Gaussa 3x3
            for (int kx = -1; kx <= 1; ++kx)
                for (int ky = -1; ky <= 1; ++ky)
                {
                    double w = BlurGaussian::getGauss(kx, ky, sigma) * sigma_weight;
                    Sxx += Ixx(x + kx, y + ky) * w;
                    Syy += Iyy(x + kx, y + ky) * w;
                    Sxy += Ixy(x + kx, y + ky) * w;
                }

            // macierz H
            // | Sxx  Sxy |
            // | Sxy  Syy |
            double det = Sxx * Syy - Sxy * Sxy;
            double trace = Sxx + Syy;
            double r = det - k_param * trace * trace;

            if (r > threshold)
                corner_candidates(x,y) = r;
            else
                corner_candidates(x,y) = 0;
        }
    }

    // 7. Non-max suppression iteracyjny
    bool search = true;
    while (search)
    {
        search = false;
        for (int x = 1; x < width - 1; ++x)
        {
            for (int y = 1; y < height - 1; ++y)
            {
                float val = corner_candidates(x,y);
                if (val == 0)
                {
                    corner_nonmax_suppress(x,y) = 0;
                    continue;
                }

                // Sprawdź 8 sąsiadów
                bool isMax = true;
                for (int nx = -1; nx <= 1; ++nx)
                    for (int ny = -1; ny <= 1; ++ny)
                    {
                        if (nx == 0 && ny == 0) continue;
                        if (corner_candidates(x + nx, y + ny) > val)
                        {
                            isMax = false;
                            break;
                        }
                    }

                if (isMax)
                    corner_nonmax_suppress(x,y) = val;
                else
                {
                    corner_nonmax_suppress(x,y) = 0;
                    search = true;
                }
            }
        }

        // Zamiana macierzy
        for (int x = 0; x < width; ++x)
            for (int y = 0; y < height; ++y)
                corner_candidates(x,y) = corner_nonmax_suppress(x,y);
    }

    // 8. Finalne przypisanie do obrazu wynikowego (binarne: 0 lub 1)
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
        {
            if (corner_candidates(x,y) == 0)
                newImage->setPixel(x, y, 0);
            else
                newImage->setPixel(x, y, 1);
        }

    return newImage;
}
