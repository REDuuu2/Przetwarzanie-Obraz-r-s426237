/********************************************************************************
** Form generated from reading UI file 'bin_niblack_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIN_NIBLACK_DIALOG_H
#define UI_BIN_NIBLACK_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BinNiblackDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *sB_r;
    QDoubleSpinBox *dSB_a;

    void setupUi(QDialog *BinNiblackDialog)
    {
        if (BinNiblackDialog->objectName().isEmpty())
            BinNiblackDialog->setObjectName(QString::fromUtf8("BinNiblackDialog"));
        BinNiblackDialog->resize(205, 72);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/universal_binary.png"), QSize(), QIcon::Normal, QIcon::Off);
        BinNiblackDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(BinNiblackDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(BinNiblackDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 16, 21));
        label_2 = new QLabel(BinNiblackDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 16, 21));
        sB_r = new QSpinBox(BinNiblackDialog);
        sB_r->setObjectName(QString::fromUtf8("sB_r"));
        sB_r->setGeometry(QRect(30, 10, 61, 22));
        sB_r->setMinimum(1);
        sB_r->setMaximum(100);
        sB_r->setValue(15);
        dSB_a = new QDoubleSpinBox(BinNiblackDialog);
        dSB_a->setObjectName(QString::fromUtf8("dSB_a"));
        dSB_a->setGeometry(QRect(30, 40, 62, 22));
        dSB_a->setMinimum(-0.990000000000000);
        dSB_a->setMaximum(-0.010000000000000);
        dSB_a->setSingleStep(0.010000000000000);
        dSB_a->setValue(-0.200000000000000);

        retranslateUi(BinNiblackDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BinNiblackDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BinNiblackDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BinNiblackDialog);
    } // setupUi

    void retranslateUi(QDialog *BinNiblackDialog)
    {
        BinNiblackDialog->setWindowTitle(QCoreApplication::translate("BinNiblackDialog", "Niblack Binarization", nullptr));
        label->setText(QCoreApplication::translate("BinNiblackDialog", "r", nullptr));
        label_2->setText(QCoreApplication::translate("BinNiblackDialog", "a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BinNiblackDialog: public Ui_BinNiblackDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIN_NIBLACK_DIALOG_H
