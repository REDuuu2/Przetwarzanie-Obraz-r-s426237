#include "convolution.h"

/** Overloaded constructor */
Convolution::Convolution(PNM* img) :
    Transformation(img)
{
}

Convolution::Convolution(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

/** Returns a convoluted form of the image */
PNM* Convolution::transform()
{
    return convolute(getMask(3, Normalize), RepeatEdge);
}

/** Returns a sizeXsize matrix with the center point equal 1.0 */
math::matrix<float> Convolution::getMask(int size, Mode mode = Normalize)
{
    math::matrix<float> mask(size, size, 0.0f);
    int center = size / 2;
    mask(center, center) = 1.0f;
    return mask;
}

/** Does the convolution process for all pixels using the given mask. */
template <typename T>
T clamp(T value, T min, T max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

PNM* Convolution::convolute(math::matrix<float> mask, Mode mode = RepeatEdge)
{
    int width  = image->width();
    int height = image->height();
    int size   = mask.rowno();
    float weight = sum(mask);
    if (weight == 0) weight = 1.0f;

    PNM* newImage = new PNM(width, height, image->format());

    mask = reflection(mask);

    if (image->format() == QImage::Format_Indexed8)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                math::matrix<float> window = getWindow(x, y, size, LChannel, mode);
                math::matrix<float> acc = join(window, mask);
                float value = sum(acc) / weight;
                value = clamp(value, 0.0f, 255.0f);

                newImage->setPixel(x, y, static_cast<int>(value));
            }
        }
    }
    else
    {
        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                float r, g, b;

                math::matrix<float> wR = getWindow(x, y, size, RChannel, mode);
                math::matrix<float> wG = getWindow(x, y, size, GChannel, mode);
                math::matrix<float> wB = getWindow(x, y, size, BChannel, mode);

                r = sum(join(wR, mask)) / weight;
                g = sum(join(wG, mask)) / weight;
                b = sum(join(wB, mask)) / weight;

                r = clamp(r, 0.0f, 255.0f);
                g = clamp(g, 0.0f, 255.0f);
                b = clamp(b, 0.0f, 255.0f);

                newImage->setPixel(x, y, qRgb(static_cast<int>(r), static_cast<int>(g), static_cast<int>(b)));
            }
        }
    }

    return newImage;
}

/** Joins to matrices by multiplying the A[i,j] with B[i,j].
  * Warning! Both Matrices must be squares with the same size!
  */
const math::matrix<float> Convolution::join(math::matrix<float> A, math::matrix<float> B)
{
    int size = A.rowno();
    math::matrix<float> C(size, size);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            C(i, j) = A(i, j) * B(i, j);

    return C;
}

/** Sums all of the matrixes elements */
 float Convolution::sum(const math::matrix<float> A)
{
    float result = 0.0f;

    for (int i = 0; i < A.rowno(); ++i)
        for (int j = 0; j < A.colno(); ++j)
            result += A(i, j);

    return result;
}


/** Returns reflected version of a matrix */
    const math::matrix<float> Convolution::reflection(const math::matrix<float> A)
{
    int size = A.rowno();
    math::matrix<float> C(size, size);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            C(i, j) = A(size - 1 - i, size - 1 - j);

    return C;
}
