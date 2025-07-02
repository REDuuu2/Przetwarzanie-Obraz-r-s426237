#include "edge_sobel.h"

EdgeSobel::EdgeSobel(PNM* img, ImageViewer* iv) :
    EdgeGradient(img, iv)
{
    prepareMatrices();
}

EdgeSobel::EdgeSobel(PNM* img) :
    EdgeGradient(img)
{
    prepareMatrices();
}

void EdgeSobel::prepareMatrices()
{
    g_x = math::matrix<float>(3, 3);
    g_x(0,0) = -1; g_x(0,1) = 0; g_x(0,2) = 1;
    g_x(1,0) = -2; g_x(1,1) = 0; g_x(1,2) = 2;
    g_x(2,0) = -1; g_x(2,1) = 0; g_x(2,2) = 1;

    g_y = math::matrix<float>(3, 3);
    g_y(0,0) =  -1; g_y(0,1) =  -2; g_y(0,2) =  -1;
    g_y(1,0) =  0; g_y(1,1) =  0; g_y(1,2) =  0;
    g_y(2,0) = 1; g_y(2,1) = 2; g_y(2,2) = 1;
}

math::matrix<float>* EdgeSobel::rawHorizontalDetection()
{
    int w = image->width();
    int h = image->height();
    math::matrix<float>* gradX = new math::matrix<float>(w, h);


    const int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    for (int y = 1; y < h - 1; ++y)
    {
        for (int x = 1; x < w -1; ++x)
        {
            float sum = 0;
            for (int ky = -1; ky <= 1; ++ky)
                for (int kx = -1; kx <= 1; ++kx)
                {
                    int px = x + kx;
                    int py = y + ky;
                    int pixelVal = image->pixel(px, py) & 0xFF;
                    sum += sobelX[ky + 1][kx + 1] * pixelVal;
                }
            (*gradX)(x,y) = sum;
        }
    }
    return gradX;
}

math::matrix<float>* EdgeSobel::rawVerticalDetection()
{
    int w = image->width();
    int h = image->height();
    math::matrix<float>* gradY = new math::matrix<float>(w, h);


    const int sobelY[3][3] = {
        { 1,  2,  1},
        { 0,  0,  0},
        {-1, -2, -1}
    };

    for (int y = 1; y < h - 1; ++y)
    {
        for (int x = 1; x < w -1; ++x)
        {
            float sum = 0;
            for (int ky = -1; ky <= 1; ++ky)
                for (int kx = -1; kx <= 1; ++kx)
                {
                    int px = x + kx;
                    int py = y + ky;
                    int pixelVal = image->pixel(px, py) & 0xFF;
                    sum += sobelY[ky + 1][kx + 1] * pixelVal;
                }
            (*gradY)(x,y) = sum;
        }
    }
    return gradY;
}
