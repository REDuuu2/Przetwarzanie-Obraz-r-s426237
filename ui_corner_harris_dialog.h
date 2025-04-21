/********************************************************************************
** Form generated from reading UI file 'corner_harris_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORNER_HARRIS_DIALOG_H
#define UI_CORNER_HARRIS_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CornerHarrisDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QDoubleSpinBox *dSB_sigma;
    QDoubleSpinBox *dSB_sigma_weight;
    QDoubleSpinBox *dSB_k;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sB_threshold;

    void setupUi(QDialog *CornerHarrisDialog)
    {
        if (CornerHarrisDialog->objectName().isEmpty())
            CornerHarrisDialog->setObjectName(QString::fromUtf8("CornerHarrisDialog"));
        CornerHarrisDialog->resize(252, 138);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/things_digital.png"), QSize(), QIcon::Normal, QIcon::Off);
        CornerHarrisDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(CornerHarrisDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(160, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CornerHarrisDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 21));
        dSB_sigma = new QDoubleSpinBox(CornerHarrisDialog);
        dSB_sigma->setObjectName(QString::fromUtf8("dSB_sigma"));
        dSB_sigma->setGeometry(QRect(80, 10, 62, 22));
        dSB_sigma->setMinimum(0.000000000000000);
        dSB_sigma->setMaximum(10.000000000000000);
        dSB_sigma->setSingleStep(0.100000000000000);
        dSB_sigma->setValue(1.000000000000000);
        dSB_sigma_weight = new QDoubleSpinBox(CornerHarrisDialog);
        dSB_sigma_weight->setObjectName(QString::fromUtf8("dSB_sigma_weight"));
        dSB_sigma_weight->setGeometry(QRect(80, 40, 62, 22));
        dSB_sigma_weight->setMinimum(0.000000000000000);
        dSB_sigma_weight->setMaximum(5.000000000000000);
        dSB_sigma_weight->setSingleStep(0.100000000000000);
        dSB_sigma_weight->setValue(0.780000000000000);
        dSB_k = new QDoubleSpinBox(CornerHarrisDialog);
        dSB_k->setObjectName(QString::fromUtf8("dSB_k"));
        dSB_k->setGeometry(QRect(80, 70, 62, 22));
        dSB_k->setDecimals(4);
        dSB_k->setMinimum(0.000000000000000);
        dSB_k->setMaximum(1.000000000000000);
        dSB_k->setSingleStep(0.050000000000000);
        dSB_k->setValue(0.050000000000000);
        label_2 = new QLabel(CornerHarrisDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 21));
        label_3 = new QLabel(CornerHarrisDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 61, 21));
        label_4 = new QLabel(CornerHarrisDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 61, 21));
        sB_threshold = new QSpinBox(CornerHarrisDialog);
        sB_threshold->setObjectName(QString::fromUtf8("sB_threshold"));
        sB_threshold->setGeometry(QRect(80, 100, 81, 22));
        sB_threshold->setMaximum(100000000);
        sB_threshold->setSingleStep(1000);
        sB_threshold->setValue(30000000);

        retranslateUi(CornerHarrisDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CornerHarrisDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CornerHarrisDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CornerHarrisDialog);
    } // setupUi

    void retranslateUi(QDialog *CornerHarrisDialog)
    {
        CornerHarrisDialog->setWindowTitle(QCoreApplication::translate("CornerHarrisDialog", "Corner Harris", nullptr));
        label->setText(QCoreApplication::translate("CornerHarrisDialog", "sigma", nullptr));
        label_2->setText(QCoreApplication::translate("CornerHarrisDialog", "sigma weight", nullptr));
        label_3->setText(QCoreApplication::translate("CornerHarrisDialog", "k", nullptr));
        label_4->setText(QCoreApplication::translate("CornerHarrisDialog", "threshold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CornerHarrisDialog: public Ui_CornerHarrisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORNER_HARRIS_DIALOG_H
