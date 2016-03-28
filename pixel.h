#ifndef PIXEL_H
#define PIXEL_H

struct pixel{
    quint8 R;
    quint8 G;
    quint8 B;
    quint8 A;

    pixel(){
        this->A = 0;
        this->R = 0;
        this->G = 0;
        this->B = 0;
    }

    pixel(quint8 A, quint8 R, quint8 G, quint8 B){
        this->A = A;
        this->R = R;
        this->G = G;
        this->B = B;
    }
    pixel(quint8 R, quint8 G, quint8 B){
        this->A = 255;
        this->R = R;
        this->G = G;
        this->B = B;
    }
    pixel(quint8 gray){
        this->A = 255;
        this->R = gray;
        this->G = gray;
        this->B = gray;
    }
    pixel(int pix){
        this->A = (pix & 0xFF000000) >> 24;
        this->R = (pix & 0x00FF0000) >> 16;
        this->G = (pix & 0x0000FF00) >> 8;
        this->B = (pix & 0x000000FF);
    }
    int toInt(){
        return (A<<24)|(R<<16)|(G<<8)|(B);
    }
    void toGray(){
        quint8 l = (R*11 + G*16 + B*5)/32;
        this->R = l;
        this->G = l;
        this->B = l;
    }
    int getR(){
        return this->R;
    }
};

#endif // PIXEL_H
