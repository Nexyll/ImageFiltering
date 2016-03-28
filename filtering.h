#ifndef FILTERING_H
#define FILTERING_H
#include <QImage>
#include <QPixmap>

class Filtering
{
public:
    static QImage filter(QImage const& img, double fil[5]);
    static QImage gauss(QImage const& img);
    static QImage canny(QImage const& img);
private:

};

#endif // FILTERING_H
