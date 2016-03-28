#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filtering.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    filter {-2, -1, 0, 1, 2}
{
    ui->setupUi(this);
    createAction();
}

void MainWindow::createAction(){
    //UI Push buttons
    QObject::connect(ui->actFile, SIGNAL(clicked()), this, SLOT(open()));
    QObject::connect(ui->actProcess, SIGNAL(clicked()), this, SLOT(process()));
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        QPixmap rd = QPixmap::fromImage(image);
        QSize maxSize = ui->imageLabel->size();
        rd = rd.scaled(maxSize);
        ui->imageLabel->setPixmap(rd);
    }
}

void MainWindow::process(){
    QImage img = QImage();
    img = Filtering::canny(ui->imageLabel->pixmap()->toImage());
    ui->imageLabel->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
