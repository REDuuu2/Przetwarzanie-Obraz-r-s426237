#include "edge_laplacian.h"

EdgeLaplacian::EdgeLaplacian(PNM* img) :
    Convolution(img)
{
}

EdgeLaplacian::EdgeLaplacian(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

math::matrix<float> EdgeLaplacian::getMask(int size, Mode)
{
    math::matrix<float> mask(size, size);


    float centerValue = static_cast<float>(size * size - 1);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {

            if (i == size / 2 && j == size / 2)
                mask(i, j) = centerValue;
            else
                mask(i, j) = -1.0f;
        }
    }

    return mask;
}

