/********************************************************************************
** Form generated from reading UI file 'PruebaJuego.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRUEBAJUEGO_H
#define UI_PRUEBAJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PruebaJuegoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PruebaJuegoClass)
    {
        if (PruebaJuegoClass->objectName().isEmpty())
            PruebaJuegoClass->setObjectName("PruebaJuegoClass");
        PruebaJuegoClass->resize(600, 400);
        menuBar = new QMenuBar(PruebaJuegoClass);
        menuBar->setObjectName("menuBar");
        PruebaJuegoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PruebaJuegoClass);
        mainToolBar->setObjectName("mainToolBar");
        PruebaJuegoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PruebaJuegoClass);
        centralWidget->setObjectName("centralWidget");
        PruebaJuegoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PruebaJuegoClass);
        statusBar->setObjectName("statusBar");
        PruebaJuegoClass->setStatusBar(statusBar);

        retranslateUi(PruebaJuegoClass);

        QMetaObject::connectSlotsByName(PruebaJuegoClass);
    } // setupUi

    void retranslateUi(QMainWindow *PruebaJuegoClass)
    {
        PruebaJuegoClass->setWindowTitle(QCoreApplication::translate("PruebaJuegoClass", "PruebaJuego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PruebaJuegoClass: public Ui_PruebaJuegoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEBAJUEGO_H
