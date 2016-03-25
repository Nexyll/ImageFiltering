#include "filtering.h"
#include <QDebug>
#include <pmatrix.h>
#include <cmath>

/**
 * @brief Filtering::filter
 * @param img passage en référence constante de l'image sur laquelle appliquée le filtre pour retourner l'image traitée
 * @param fil
 * @return
 *
 *
 *
 */
QImage Filtering::filter(QImage const& img, double fil[5])
{
    PMatrix image = PMatrix(img);
    PMatrix nImg = PMatrix(img.height(), img.width(), img.format());
    for(int i = 1; i < img.height()-1; i++){
        for(int j = 1; j < img.width()-1; j++){
            pixel p = image.getPixel(i, j);
            p.toGray();
            image.setPixel(i, j, p);
        }
    }
    for(int i = 1; i < img.height()-1; i++){
        for(int j = 1; j < img.width()-1; j++){


            pixel p0 = image.getPixel(i-1,j);
            pixel p1 = image.getPixel(i+1, j);
            quint8 l = (p0.R-p1.R)/2;
            pixel p = pixel(l, l, l);
            nImg.setPixel(i, j, p);
        }
    }
    return nImg.toImage();
}

/**
 * @brief Filtering::gauss
 * @param img
 * @return
 *
 * J'ai fais de la merde sans le constructeur, mais ça ne fonctionne pas encore...
 *
 */
QImage Filtering::gauss(QImage const& img)
{
    //int gauss[5][5] = {{1,4,7,4,1},{4,16,26,16,4},{7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1}}; avec SOMME = 273
    int gauss[5][5] = {{2,4,5,4,2},{4,9,12,9,4},{5,12,15,12,5},{4,9,12,9,4},{2,4,5,4,2}};
    PMatrix image = PMatrix(img);
    PMatrix nImg = PMatrix(img.height(), img.width(), img.format());
    for(int i = 1; i < img.height()-1; i++){
        for(int j = 1; j < img.width()-1; j++){
            pixel p = image.getPixel(i, j);
            p.toGray();
            image.setPixel(i, j, p);
        }
    }
    for(int i = 2; i < img.height()-2; i++){
        for(int j = 2; j < img.width()-2; j++){

            quint32 sumGauss = 0;

            for(int k = i-2 ; k <= i+2 ; k++){
                for(int l = j-2 ; l <= j+2 ; l++){
                    pixel p = image.getPixel(k,l);
                    sumGauss += (p.getR()*gauss[(k-i+2)][(l-j+2)]);
                    //qDebug()<< gauss[k-i+2][l-j+2];
                }
            }
            sumGauss /= 159;
            //qDebug() << sumGauss;
            pixel p = pixel((quint8)sumGauss);
            nImg.setPixel(i, j, p);
        }
    }
    return QImage(nImg.toImage());
}


/**
 * @brief Filtering::canny
 * @param img EN NOIR ET BLANC
 * @return
 *
 */
QImage Filtering::canny(QImage const& img)
{
    int threeshold = 30;
    int cannyX[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int cannyY[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    PMatrix image = PMatrix(gauss(img));
    PMatrix nImg = PMatrix(img.height(), img.width(), img.format());

    int g = 0;
    int gX = 0;
    int gY = 0;

    for(int i = 2; i < img.height()-2; i++){
        for(int j = 2; j < img.width()-2; j++){

        gX = 0;
        gY = 0;

            for(int k = i-1 ; k <= i+1 ; k++){
                for(int l = j-1 ; l <= j+1 ; l++){
                    pixel p = image.getPixel(k,l);
                    gX += p.getR()*cannyX[k-i+1][l-j+1];
                    gY += p.getR()*cannyY[k-i+1][l-j+1];

                }
            }
            g = sqrt(pow(gX,2)+pow(gY,2));
            if(g<threeshold){
                g = 0;
            }
            pixel p = pixel(g, g, g);
            nImg.setPixel(i, j, p);
        }
    }
    return QImage(nImg.toImage());
}






