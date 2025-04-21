/********************************************************************************
** Form generated from reading UI file 'mask_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASK_DIALOG_H
#define UI_MASK_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MaskDialog
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *okButton;

    void setupUi(QDialog *MaskDialog)
    {
        if (MaskDialog->objectName().isEmpty())
            MaskDialog->setObjectName(QString::fromUtf8("MaskDialog"));
        MaskDialog->setEnabled(true);
        MaskDialog->resize(227, 89);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/personal_finance.png"), QSize(), QIcon::Normal, QIcon::Off);
        MaskDialog->setWindowIcon(icon);
        comboBox = new QComboBox(MaskDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 10, 71, 22));
        label = new QLabel(MaskDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        okButton = new QPushButton(MaskDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(140, 60, 75, 23));
        okButton->setFlat(false);

        retranslateUi(MaskDialog);
        QObject::connect(okButton, SIGNAL(clicked()), MaskDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(MaskDialog);
    } // setupUi

    void retranslateUi(QDialog *MaskDialog)
    {
        MaskDialog->setWindowTitle(QCoreApplication::translate("MaskDialog", "Parameters", nullptr));
        label->setText(QCoreApplication::translate("MaskDialog", "Mask size", nullptr));
        okButton->setText(QCoreApplication::translate("MaskDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskDialog: public Ui_MaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_DIALOG_H
