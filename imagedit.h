#ifndef IMAGEDIT_H
#define IMAGEDIT_H

#include <QMainWindow>
#include <QPalette>

#include "libraryarea.h"
#include "settingarea.h"
#include "toolboxarea.h"
#include "rognerarea.h"
#include "filterarea.h"
#include <iostream>
#include <QStringList>
#include <QKeySequence>
#include <QShortcut>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class ImagEdit;
}
QT_END_NAMESPACE

class ImagEdit : public QMainWindow
{
    Q_OBJECT

public:
    ImagEdit(QWidget *parent = nullptr);
    ~ImagEdit();
    LibraryArea *libraryarea;
    SettingArea *settingarea;
    ToolboxArea *toolboxarea;



public slots:
    void on_open_clicked();
    void displayOnEdition(int index);
    void on_filter_clicked();
    void on_rogner_clicked();
    void on_save_clicked();
    void on_save_under_clicked();



private:
    Ui::ImagEdit *ui;
    QString *path;
    QPixmap *pix;
    QStringList selectedImagePaths;
    QMap<QPushButton*, QString> buttonToOriginalPath;
    QShortcut *raccourciEnregistrer;
    QShortcut *raccourciOuvrir;
    int currentIndex;
};
#endif // IMAGEDIT_H
