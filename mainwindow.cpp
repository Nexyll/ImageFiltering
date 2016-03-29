#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filtering.h"
#include <qstandardpaths.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rawImage = QImage(ui->imageLabel->pixmap()->toImage());
    QSize maxSize = ui->imageLabel->size();
    scaledImage = rawImage.scaled(maxSize, Qt::KeepAspectRatio);
    createAction();
}

void MainWindow::createAction(){
    //UI action
    QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    //UI push button
    QObject::connect(ui->actProcess, SIGNAL(clicked()), this, SLOT(process()));
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                    tr("Open File"), QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).last());
    if (!fileName.isEmpty()) {
        rawImage = QImage(fileName);
        if (rawImage.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        QSize maxSize = ui->imageLabel->size();
        scaledImage = rawImage.scaled(maxSize, Qt::KeepAspectRatio);
        ui->imageLabel->setPixmap(QPixmap::fromImage(scaledImage));
        ui->rawImageLabel->setPixmap(*ui->imageLabel->pixmap());
    }
}

void MainWindow::process(){
    //Raw image
    if (ui->comboBox->currentIndex() == 0) {
        processedImage = Filtering::canny(rawImage);
        QSize maxSize = ui->imageLabel->size();
        QPixmap pix = QPixmap::fromImage(processedImage);
        pix = pix.scaled(maxSize, Qt::KeepAspectRatio);
        ui->imageLabel->setPixmap(pix);
    }
    //Scaled image
    else if (ui->comboBox->currentIndex() == 1) {
        processedImage = Filtering::canny(scaledImage);
        ui->imageLabel->setPixmap(QPixmap::fromImage(processedImage));
    }
    //Processed image
    else {
        processedImage = Filtering::canny(processedImage);
        ui->imageLabel->setPixmap(QPixmap::fromImage(processedImage));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
