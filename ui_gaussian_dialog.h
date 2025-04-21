/********************************************************************************
** Form generated from reading UI file 'gaussian_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSIAN_DIALOG_H
#define UI_GAUSSIAN_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GaussianDialog
{
public:
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *okButton;

    void setupUi(QDialog *GaussianDialog)
    {
        if (GaussianDialog->objectName().isEmpty())
            GaussianDialog->setObjectName(QString::fromUtf8("GaussianDialog"));
        GaussianDialog->resize(227, 89);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/draw_convolve.png"), QSize(), QIcon::Normal, QIcon::Off);
        GaussianDialog->setWindowIcon(icon);
        comboBox = new QComboBox(GaussianDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 10, 71, 22));
        doubleSpinBox = new QDoubleSpinBox(GaussianDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 40, 62, 22));
        doubleSpinBox->setMinimum(0.000000000000000);
        doubleSpinBox->setSingleStep(0.250000000000000);
        doubleSpinBox->setValue(1.000000000000000);
        label = new QLabel(GaussianDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        label_2 = new QLabel(GaussianDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 46, 13));
        okButton = new QPushButton(GaussianDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(140, 60, 75, 23));
        okButton->setFlat(false);

        retranslateUi(GaussianDialog);
        QObject::connect(okButton, SIGNAL(clicked()), GaussianDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(GaussianDialog);
    } // setupUi

    void retranslateUi(QDialog *GaussianDialog)
    {
        GaussianDialog->setWindowTitle(QCoreApplication::translate("GaussianDialog", "Gausian Blur ", nullptr));
        label->setText(QCoreApplication::translate("GaussianDialog", "Mask size", nullptr));
        label_2->setText(QCoreApplication::translate("GaussianDialog", "Sigma", nullptr));
        okButton->setText(QCoreApplication::translate("GaussianDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaussianDialog: public Ui_GaussianDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSIAN_DIALOG_H
