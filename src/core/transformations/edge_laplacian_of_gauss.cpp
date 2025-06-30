#include "edge_laplacian_of_gauss.h"

#include "blur_gaussian.h"

EdgeLaplaceOfGauss::EdgeLaplaceOfGauss(PNM* img) :
    Convolution(img)
{
}

EdgeLaplaceOfGauss::EdgeLaplaceOfGauss(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

math::matrix<float> EdgeLaplaceOfGauss::getMask(int, Mode)
{
    size = getParameter("size").toInt();
    double sigma = getParameter("sigma").toDouble();

    math::matrix<float> mask(size, size);
    int center = size / 2;

    for (int i = 0; i < size; ++i)
    {
        int x = i - center;
        for (int j = 0; j < size; ++j)
        {
            int y = j - center;
            mask(i, j) = getLoG(x, y, sigma);
        }
    }

    return mask;
}

float EdgeLaplaceOfGauss::getLoG(int x, int y, float sigma)
{
    float sigma2 = sigma * sigma;
    float r2 = float(x * x + y * y);

    float numerator = r2 - 2.0f * sigma2;
    float denominator = sigma2 * sigma2;

    return (numerator / denominator) * BlurGaussian::getGauss(x, y, sigma);
}

int EdgeLaplaceOfGauss::getSize()
{
    return size;
}

