/********************************************************************************
** Form generated from reading UI file 'map_horizon_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_HORIZON_DIALOG_H
#define UI_MAP_HORIZON_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MapHorizonDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *sB_alpha;
    QDoubleSpinBox *dSB_scale;
    QLabel *label_3;
    QComboBox *cB_direction;

    void setupUi(QDialog *MapHorizonDialog)
    {
        if (MapHorizonDialog->objectName().isEmpty())
            MapHorizonDialog->setObjectName(QString::fromUtf8("MapHorizonDialog"));
        MapHorizonDialog->resize(257, 103);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/flag_airfield_vehicle_safety.png"), QSize(), QIcon::Normal, QIcon::Off);
        MapHorizonDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(MapHorizonDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(170, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(MapHorizonDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 31, 21));
        label_2 = new QLabel(MapHorizonDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 41, 21));
        sB_alpha = new QSpinBox(MapHorizonDialog);
        sB_alpha->setObjectName(QString::fromUtf8("sB_alpha"));
        sB_alpha->setGeometry(QRect(60, 10, 61, 22));
        sB_alpha->setMinimum(0);
        sB_alpha->setMaximum(90);
        sB_alpha->setValue(45);
        dSB_scale = new QDoubleSpinBox(MapHorizonDialog);
        dSB_scale->setObjectName(QString::fromUtf8("dSB_scale"));
        dSB_scale->setGeometry(QRect(60, 40, 61, 22));
        dSB_scale->setDecimals(1);
        dSB_scale->setMinimum(0.500000000000000);
        dSB_scale->setMaximum(10.000000000000000);
        dSB_scale->setSingleStep(1.000000000000000);
        dSB_scale->setValue(1.000000000000000);
        label_3 = new QLabel(MapHorizonDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 41, 16));
        cB_direction = new QComboBox(MapHorizonDialog);
        cB_direction->setObjectName(QString::fromUtf8("cB_direction"));
        cB_direction->setGeometry(QRect(60, 70, 101, 22));

        retranslateUi(MapHorizonDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapHorizonDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapHorizonDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MapHorizonDialog);
    } // setupUi

    void retranslateUi(QDialog *MapHorizonDialog)
    {
        MapHorizonDialog->setWindowTitle(QCoreApplication::translate("MapHorizonDialog", "Map Horizon", nullptr));
        label->setText(QCoreApplication::translate("MapHorizonDialog", "alpha", nullptr));
        label_2->setText(QCoreApplication::translate("MapHorizonDialog", "scale", nullptr));
        label_3->setText(QCoreApplication::translate("MapHorizonDialog", "direction", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapHorizonDialog: public Ui_MapHorizonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_HORIZON_DIALOG_H
