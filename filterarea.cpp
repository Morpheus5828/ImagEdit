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
    //connect(ui->OmbresChaudesFilterButton, SIGNAL(clicked()), this, SLOT(appliquerOmbresChaudesFilter()));
    //connect(ui->LumFroidesFilterButton, SIGNAL(clicked()), this, SLOT(appliquerLumFroidesFilter()));


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


void FilterArea::on_OmbresChaudesFilterButton_clicked()
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

                newColor = newColor.darker(115);
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

