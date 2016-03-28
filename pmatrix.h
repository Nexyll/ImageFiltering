#ifndef PMATRIX_H
#define PMATRIX_H
#include <QImage>
#include "pixel.h"
/**
 * @brief The PMatrix class
 *
 * Should add a gray boolean and functionality to gain in memory space and ?speed?
 */
class PMatrix
{
public:
    PMatrix(QImage const& img);
    PMatrix(int height, int width, QImage::Format f);
    PMatrix(PMatrix const& matrix);
    ~PMatrix();
    pixel getPixel(int i, int j);
    void setPixel(int i, int j, pixel p);
    QImage toImage();

private:
    pixel** pArray;
    const int height;
    const int width;
    QImage::Format format;
};

#endif // PMATRIX_H
