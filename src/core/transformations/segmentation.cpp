#include "segmentation.h"

#include "conversion_grayscale.h"
#include "blur_gaussian.h"

#include <queue>

Segmentation::Segmentation(PNM* img) :
    Transformation(img)
{
}

Segmentation::Segmentation(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

#define INIT -1
#define MASK -2
#define WSHED 0

QPoint* Segmentation::neighbourhood(QPoint p)
{
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    QPoint* neighbors = new QPoint[8];
    int index = 0;

    for (int i = 0; i < 8; ++i)
    {
        int nx = p.x() + dx[i];
        int ny = p.y() + dy[i];
        if (nx >= 0 && ny >= 0 && nx < image->width() && ny < image->height())
        {
            neighbors[index++] = QPoint(nx, ny);
        }
    }

    return neighbors;
}

PNM* Segmentation::transform()
{
    int width = image->width();
    int height = image->height();

    // 1. Konwersja do odcieni szarości
    PNM* grayImage = ConversionGrayscale(image).transform();

    // 2. (Opcjonalnie) rozmycie
    if (getParameter("apply_blur").toBool())
    {
        grayImage = BlurGaussian(grayImage).transform();
    }

    // 3. Przygotowanie struktur
    std::vector<std::vector<int>> heightmap(height, std::vector<int>(width));
    std::vector<std::vector<int>> labels(height, std::vector<int>(width, INIT));
    std::vector<std::vector<int>> dist(height, std::vector<int>(width, 0));
    std::queue<QPoint> fifo;

    // 4. Wypełnij mapę wysokości (jasność pikseli)
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            heightmap[y][x] = qGray(grayImage->pixel(x, y));

    int current_label = 0;
    const int IN_QUEUE = -3;

    // 5. Iteracja po poziomach szarości [0–255]
    for (int h = 0; h <= 255; ++h)
    {
        // 5.1 Znajdź piksele na poziomie h i oznacz jako MASK
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (heightmap[y][x] == h && labels[y][x] == INIT)
                {
                    labels[y][x] = MASK;
                    QPoint p(x, y);

                    QPoint* neighbors = neighbourhood(p);
                    for (int i = 0; i < 8; ++i)
                    {
                        QPoint n = neighbors[i];
                        if (!n.isNull() && labels[n.y()][n.x()] >= 0)
                        {
                            dist[y][x] = 1;
                            fifo.push(p);
                            labels[y][x] = IN_QUEUE;
                            break;
                        }
                    }
                    delete[] neighbors;
                }
            }
        }

        // 5.2 Propagacja znanych etykiet
        while (!fifo.empty())
        {
            QPoint p = fifo.front();
            fifo.pop();

            int px = p.x(), py = p.y();

            QPoint* neighbors = neighbourhood(p);
            for (int i = 0; i < 8; ++i)
            {
                QPoint n = neighbors[i];
                if (n.isNull()) continue;

                int nx = n.x(), ny = n.y();

                if (labels[ny][nx] > 0)
                {
                    if (labels[py][px] == IN_QUEUE || labels[py][px] == WSHED)
                        labels[py][px] = labels[ny][nx];
                    else if (labels[py][px] != labels[ny][nx])
                        labels[py][px] = WSHED;
                }
                else if (labels[ny][nx] == MASK)
                {
                    dist[ny][nx] = dist[py][px] + 1;
                    fifo.push(QPoint(nx, ny));
                    labels[ny][nx] = IN_QUEUE;
                }
            }
            delete[] neighbors;
        }

        // 5.3 Tworzenie nowych regionów
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (heightmap[y][x] == h && labels[y][x] == MASK)
                {
                    current_label++;
                    std::queue<QPoint> q;
                    q.push(QPoint(x, y));
                    labels[y][x] = current_label;

                    while (!q.empty())
                    {
                        QPoint p = q.front(); q.pop();
                        QPoint* neighbors = neighbourhood(p);

                        for (int i = 0; i < 8; ++i)
                        {
                            QPoint n = neighbors[i];
                            if (!n.isNull() && labels[n.y()][n.x()] == MASK)
                            {
                                labels[n.y()][n.x()] = current_label;
                                q.push(n);
                            }
                        }
                        delete[] neighbors;
                    }
                }
            }
        }
    }

    // 6. Tworzenie obrazu wyjściowego z etykiet
    PNM* result = new PNM(width, height, QImage::Format_Grayscale8);
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
        {
            int value = (labels[y][x] == WSHED) ? 0 : (labels[y][x] * 255 / current_label);
            result->setPixel(x, y, qRgb(value, value, value));
        }

    return result;
}

