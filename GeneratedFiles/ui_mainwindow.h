/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCanny;
    QAction *actionAppliquer;
    QAction *actionOptions;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *actFile;
    QPushButton *pushButton_2;
    QPushButton *actProcess;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuFiltres;
    QMenu *menuGaussien;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAcceptDrops(false);
        MainWindow->setIconSize(QSize(24, 24));
        actionCanny = new QAction(MainWindow);
        actionCanny->setObjectName(QStringLiteral("actionCanny"));
        actionAppliquer = new QAction(MainWindow);
        actionAppliquer->setObjectName(QStringLiteral("actionAppliquer"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8("../../../Pictures/Camera Roll/WIN_20160324_184651.JPG")));
        imageLabel->setScaledContents(false);

        verticalLayout->addWidget(imageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        actFile = new QPushButton(centralwidget);
        actFile->setObjectName(QStringLiteral("actFile"));

        horizontalLayout->addWidget(actFile);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        actProcess = new QPushButton(centralwidget);
        actProcess->setObjectName(QStringLiteral("actProcess"));

        horizontalLayout->addWidget(actProcess);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuFiltres = new QMenu(menubar);
        menuFiltres->setObjectName(QStringLiteral("menuFiltres"));
        menuGaussien = new QMenu(menuFiltres);
        menuGaussien->setObjectName(QStringLiteral("menuGaussien"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuFiltres->menuAction());
        menuFiltres->addAction(menuGaussien->menuAction());
        menuFiltres->addAction(actionCanny);
        menuGaussien->addAction(actionAppliquer);
        menuGaussien->addSeparator();
        menuGaussien->addAction(actionOptions);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pornhub", 0));
        actionCanny->setText(QApplication::translate("MainWindow", "Canny", 0));
        actionAppliquer->setText(QApplication::translate("MainWindow", "Appliquer", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        imageLabel->setText(QString());
        actFile->setText(QApplication::translate("MainWindow", "Select File", 0));
        actFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Ne pas appuyer ici", 0));
        actProcess->setText(QApplication::translate("MainWindow", "Process", 0));
        actProcess->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuFiltres->setTitle(QApplication::translate("MainWindow", "Filtres", 0));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "Gaussien", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
