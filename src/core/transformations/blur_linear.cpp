#include "blur_linear.h"

BlurLinear::BlurLinear(PNM* img) :
    Convolution(img)
{
}

BlurLinear::BlurLinear(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

PNM* BlurLinear::transform()
{
    int maskSize = getParameter("size").toInt();
    QList<QVariant> tmpMask = getParameter("mask").toList();
    bool normalize = getParameter("normalize").toBool();

    math::matrix<float> mask(maskSize, maskSize);

    for (int i = 0; i < maskSize; ++i)
    {
        for (int j = 0; j < maskSize; ++j)
        {
            int index = i * maskSize + j;
            if (index < tmpMask.size())
                mask(i, j) = tmpMask.at(index).toDouble();
            else
                mask(i, j) = 0.0f;
        }
    }

    if (normalize)
    {
        float s = sum(mask);
        if (s != 0.0f)
        {
            for (int i = 0; i < maskSize; ++i)
                for (int j = 0; j < maskSize; ++j)
                    mask(i, j) /= s;
        }
    }

    return convolute(mask, RepeatEdge);
}
