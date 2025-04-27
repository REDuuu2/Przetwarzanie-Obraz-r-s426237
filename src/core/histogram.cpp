#include "histogram.h"

#include <QDebug>
#include <QPainter>

#include <cmath>

Histogram::Histogram(QImage* image)
{
    R = new QHash<int, int>;
    G = new QHash<int, int>;
    B = new QHash<int, int>;
    L = new QHash<int, int>;
    generate(image);
}

Histogram::~Histogram()
{
    delete R;
    delete G;
    delete B;
    delete L;
}

void Histogram::generate(QImage* image)
{
    int width = image->width();
    int height = image->height();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            QColor color = image->pixelColor(x, y);

            int r = color.red();
            int g = color.green();
            int b = color.blue();
            int l = qRound(0.299 * r + 0.587 * g + 0.114 * b);

            R->insert(r, R->value(r, 0) + 1);
            G->insert(g, G->value(g, 0) + 1);
            B->insert(b, B->value(b, 0) + 1);
            L->insert(l, L->value(l, 0) + 1);
        }
    }
}

/** Returns the maximal value of the histogram in the given channel */
int Histogram::maximumValue(Channel selectedChannel = RGB)
{
    if (selectedChannel == RGB) {
        int rMax = maximumValue(RChannel);
        int gMax = maximumValue(GChannel);
        int bMax = maximumValue(BChannel);
        return std::max({rMax, gMax, bMax});
    }

    QHash<int, int>* channel = get(selectedChannel);
    int maxValue = 0;

    QHash<int, int>::const_iterator it = channel->constBegin();
    while (it != channel->constEnd()) {
        if (it.value() > maxValue) {
            maxValue = it.value();
        }
        ++it;
    }

    return maxValue;
}


/** Returns a pointer to the given channel QHash<int, int> */
QHash<int, int>* Histogram::get(Channel channel = LChannel)
{
    if (channel==LChannel) return L;
    if (channel==RChannel) return R;
    if (channel==GChannel) return G;
    if (channel==BChannel) return B;

    return 0;
}

/**
 *  Returns a 255 by 100 QImage containing a Histogram for the given channel.
 *  The background is transparent (Alpha 0, RGB=255) */
QImage Histogram::getImage(Channel channel = LChannel, QBrush pen = Qt::gray)
{
    // Create blank QImage and fill it with transparent background:
    QImage histImage(255, 100, QImage::Format_ARGB32);
    histImage.fill(0);
    QPainter painter(&histImage);
    painter.setBrush(Qt::transparent);
    painter.setPen(Qt::transparent);
    painter.drawRect(0,0,255,100);

    // Calculate the aspect ratio using the maximal value of the color histograms
    int maximum = (channel == LChannel ? maximumValue(LChannel) :  maximumValue(RGB));
    float ratio = 100.0/float(maximum);

    // Preparing the painter:
    painter.setBrush(pen);
    painter.setPen(pen.color());

    int h;
    // Draw histogram
    QHash<int, int>* hist = get(channel);
    QHash<int, int>::const_iterator cit = hist->begin();

    while (cit != hist->end())
    {
        h = 100 - floor(ratio*cit.value());
        painter.drawLine(cit.key(), h, cit.key(), 100);
        ++cit;
    }

    return histImage;
}
