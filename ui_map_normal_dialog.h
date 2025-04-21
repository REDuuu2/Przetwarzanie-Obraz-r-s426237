/********************************************************************************
** Form generated from reading UI file 'map_normal_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_NORMAL_DIALOG_H
#define UI_MAP_NORMAL_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MapNormalDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QDoubleSpinBox *dSB_strength;

    void setupUi(QDialog *MapNormalDialog)
    {
        if (MapNormalDialog->objectName().isEmpty())
            MapNormalDialog->setObjectName(QString::fromUtf8("MapNormalDialog"));
        MapNormalDialog->resize(221, 71);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/flag_airfield_vehicle_safety.png"), QSize(), QIcon::Normal, QIcon::Off);
        MapNormalDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(MapNormalDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(130, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(MapNormalDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 51, 21));
        dSB_strength = new QDoubleSpinBox(MapNormalDialog);
        dSB_strength->setObjectName(QString::fromUtf8("dSB_strength"));
        dSB_strength->setGeometry(QRect(60, 10, 62, 22));
        dSB_strength->setMinimum(0.250000000000000);
        dSB_strength->setMaximum(10.000000000000000);
        dSB_strength->setSingleStep(0.250000000000000);
        dSB_strength->setValue(2.000000000000000);

        retranslateUi(MapNormalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapNormalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapNormalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MapNormalDialog);
    } // setupUi

    void retranslateUi(QDialog *MapNormalDialog)
    {
        MapNormalDialog->setWindowTitle(QCoreApplication::translate("MapNormalDialog", "Map Normal", nullptr));
        label_2->setText(QCoreApplication::translate("MapNormalDialog", "strength", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapNormalDialog: public Ui_MapNormalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_NORMAL_DIALOG_H
