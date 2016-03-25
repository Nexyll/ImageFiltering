#include "pmatrix.h"

PMatrix::PMatrix(QImage const& img): format(img.format()), height(img.height()), width(img.width())  {
    format = img.format();
    pArray = new pixel*[height];
    for(int i = 0; i < height; i++)
        pArray[i] = new pixel[width];

    for(int i = 0; i < img.height(); i++){
        int *ptr = (int*) img.scanLine(i);

        for(int j = 0; j < img.width(); j++){
            pixel p = pixel(*ptr);
            pArray[i][j] = p;
            ptr++;
        }
    }
}
PMatrix::PMatrix(int height, int width, QImage::Format f): format(f), height(height), width(width){
    pArray = new pixel*[height];
    for(int i = 0; i < height; i++)
        pArray[i] = new pixel[width];
}

PMatrix::PMatrix(PMatrix const& matrix): format(matrix.format), height(matrix.height), width(matrix.width){
    pArray = new pixel*[height];
    for(int i = 0; i < height; i++)
        pArray[i] = new pixel[width];

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            pArray[i][j] = matrix.pArray[i][j];
        }
    }
}

pixel PMatrix::getPixel(int i, int j){
    return pArray[i][j];
}

void PMatrix::setPixel(int i, int j, pixel p){
    pArray[i][j] = p;
}

QImage PMatrix::toImage(){
    QImage img = QImage(width, height, format);
    for(int i = 0; i < img.height(); i++){
        int *ptr = (int*) img.scanLine(i);

        for(int j = 0; j < img.width(); j++){
            *ptr = pArray[i][j].toInt();
            ptr++;
        }
    }
    return img;
}

PMatrix::~PMatrix(){
    for(int i = 0; i < height; ++i) {
        delete [] pArray[i];
    }
    delete [] pArray;
}
