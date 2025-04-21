/********************************************************************************
** Form generated from reading UI file 'noise_median_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISE_MEDIAN_DIALOG_H
#define UI_NOISE_MEDIAN_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NoiseMedianDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *sB_radius;

    void setupUi(QDialog *NoiseMedianDialog)
    {
        if (NoiseMedianDialog->objectName().isEmpty())
            NoiseMedianDialog->setObjectName(QString::fromUtf8("NoiseMedianDialog"));
        NoiseMedianDialog->resize(211, 75);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/checkerboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        NoiseMedianDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(NoiseMedianDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NoiseMedianDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 31, 21));
        sB_radius = new QSpinBox(NoiseMedianDialog);
        sB_radius->setObjectName(QString::fromUtf8("sB_radius"));
        sB_radius->setGeometry(QRect(50, 10, 61, 22));
        sB_radius->setMinimum(1);
        sB_radius->setMaximum(25);
        sB_radius->setValue(1);

        retranslateUi(NoiseMedianDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NoiseMedianDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NoiseMedianDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NoiseMedianDialog);
    } // setupUi

    void retranslateUi(QDialog *NoiseMedianDialog)
    {
        NoiseMedianDialog->setWindowTitle(QCoreApplication::translate("NoiseMedianDialog", "Noise Median", nullptr));
        label->setText(QCoreApplication::translate("NoiseMedianDialog", "radius", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoiseMedianDialog: public Ui_NoiseMedianDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISE_MEDIAN_DIALOG_H
