#include "filterarea.h"
#include "ui_filterarea.h"
#include <iostream>
using namespace std;

FilterArea::FilterArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilterArea)
{
    ui->setupUi(this);
    connect(ui->NbFilterButton, SIGNAL(clicked()), this, SLOT(appliquerFiltreNoirEtBlanc()));

    connect(ui->OmbresChaudesFilterButton, SIGNAL(clicked()), this, SLOT(appliquerOmbresChaudesFilter()));
    connect(ui->LumFroidesFilterButton, SIGNAL(clicked()), this, SLOT(appliquerLumFroidesFilter()));
<<<<<<< HEAD
    connect(ui->luminositeSlider, SIGNAL(valueChanged(int)), this, SLOT(luminosityChanged()));
=======


>>>>>>> aab4435daf9413a39cfcb7051f84fc9eabda9bda
}


FilterArea::~FilterArea()
{
    delete ui;
}


void FilterArea::on_NbFilterButton_clicked()
{
    qDebug() << "NbFilterButton clicked";
    emit applyNbFilter();

}


void FilterArea::setLabel(QLabel *label) {

    labelSelected = label;
}

void FilterArea::appliquerFiltreNoirEtBlanc()
{

    if (!labelSelected->pixmap().isNull()) {

        QImage imageNoirEtBlanc(labelSelected->pixmap().toImage().size(), QImage::Format_Grayscale8);

        for (int y = 0; y < labelSelected->pixmap().toImage().height(); ++y) {
            for (int x = 0; x < labelSelected->pixmap().toImage().width(); ++x) {
                QRgb pixel = labelSelected->pixmap().toImage().pixel(x, y);
                int grayValue = qGray(pixel);
                imageNoirEtBlanc.setPixel(x, y, qRgb(grayValue, grayValue, grayValue));
            }
        }

        QPixmap pixmap = QPixmap::fromImage(imageNoirEtBlanc);


        labelSelected->setPixmap(pixmap);


    }
    else {
        qDebug() << "Erreur : Aucune image actuelle à traiter.";
    }
}


void FilterArea::on_LumFroidesFilterButton_clicked()
{

    if (!labelSelected->pixmap().isNull()) {

        QImage imageOmbresChaudes(labelSelected->pixmap().toImage().size(), QImage::Format_ARGB32);
        QColor ombresFroidesColor(0, 0, 50);
        qreal colorIntensity = 0.6;

        for (int y = 0; y < labelSelected->pixmap().toImage().height(); ++y) {
            for (int x = 0; x < labelSelected->pixmap().toImage().width(); ++x) {
                QRgb pixel = labelSelected->pixmap().toImage().pixel(x, y);
                QColor originalColor(pixel);
                QColor newColor = originalColor.toRgb();
                newColor = QColor::fromRgb(
                    qMin(255, int((newColor.red() * colorIntensity) + ombresFroidesColor.red() * (1.0 - colorIntensity))),
                    qMin(255, int(newColor.green() * colorIntensity + ombresFroidesColor.green() * (1.0 - colorIntensity))),
                    qMin(255, int(newColor.blue() * colorIntensity + ombresFroidesColor.blue() * (1.0 - colorIntensity)))
                    );
                newColor = newColor.lighter(150);

                imageOmbresChaudes.setPixel(x, y, newColor.rgb());
            }
        }
        QPixmap pixmap = QPixmap::fromImage(imageOmbresChaudes);
        labelSelected->setPixmap(pixmap);
    }
    else {
        qDebug() << "Erreur : Aucune image actuelle à traiter.";
    }

}


void FilterArea::appliquerOmbresChaudesFilter()

{
    qDebug() << "Appliquer filtre Ombres Chaudes";

    if (!labelSelected->pixmap().isNull()) {

        QImage imageOmbresChaudes(labelSelected->pixmap().toImage().size(), QImage::Format_ARGB32);
        QColor ombresChaudesColor(255, 170, 0);
        qreal colorIntensity = 0.8;

        for (int y = 0; y < labelSelected->pixmap().toImage().height(); ++y) {
            for (int x = 0; x < labelSelected->pixmap().toImage().width(); ++x) {
                QRgb pixel = labelSelected->pixmap().toImage().pixel(x, y);
                QColor originalColor(pixel);
                QColor newColor = originalColor.toRgb();
                newColor = QColor::fromRgb(
                    qMin(255, int((newColor.red() * colorIntensity) + ombresChaudesColor.red() * (1.0 - colorIntensity))),
                    qMin(255, int(newColor.green() * colorIntensity + ombresChaudesColor.green() * (1.0 - colorIntensity))),
                    qMin(255, int(newColor.blue() * colorIntensity + ombresChaudesColor.blue() * (1.0 - colorIntensity)))
                    );
<<<<<<< HEAD
                newColor = newColor.lighter(150);
                //newColor = newColor.darker(115);
=======


                newColor = newColor.darker(115);
                //newColor = newColor.saturation();

>>>>>>> aab4435daf9413a39cfcb7051f84fc9eabda9bda
                imageOmbresChaudes.setPixel(x, y, newColor.rgb());
            }
        }
        QPixmap pixmap = QPixmap::fromImage(imageOmbresChaudes);
        labelSelected->setPixmap(pixmap);
    }
    else {
        qDebug() << "Erreur : Aucune image actuelle à traiter.";
    }


}


<<<<<<< HEAD
void FilterArea::luminosityChanged()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    if (!labelSelected->pixmap().isNull()) {
        QImage imageLuminosityChanged(labelSelected->pixmap().toImage().size(), QImage::Format_ARGB32);


        int sliderValue = ui->luminositeSlider->value();
        for (int y = 0; y < labelSelected->pixmap().toImage().height(); ++y) {
            for (int x = 0; x < labelSelected->pixmap().toImage().width(); ++x) {
                QRgb pixel = labelSelected->pixmap().toImage().pixel(x, y);
                QColor originalColor(pixel);
                QColor newColor = originalColor.toRgb();
                newColor = newColor.lighter(100 + sliderValue/15);
                imageLuminosityChanged.setPixel(x, y, newColor.rgb());
            }
        }

        QPixmap pixmap = QPixmap::fromImage(imageLuminosityChanged);
        labelSelected->setPixmap(pixmap);
    } else {
        qDebug() << "Erreur : Aucune image actuelle à traiter.";
    }
}
=======



void FilterArea::on_OmbresChaudesFilterButton_clicked()
{

}

>>>>>>> aab4435daf9413a39cfcb7051f84fc9eabda9bda
