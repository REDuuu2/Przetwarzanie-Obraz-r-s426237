/********************************************************************************
** Form generated from reading UI file 'edge_zero_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGE_ZERO_DIALOG_H
#define UI_EDGE_ZERO_DIALOG_H

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

class Ui_EdgeZeroDialog
{
public:
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QSpinBox *spinBox;

    void setupUi(QDialog *EdgeZeroDialog)
    {
        if (EdgeZeroDialog->objectName().isEmpty())
            EdgeZeroDialog->setObjectName(QString::fromUtf8("EdgeZeroDialog"));
        EdgeZeroDialog->resize(227, 101);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/edge_detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        EdgeZeroDialog->setWindowIcon(icon);
        comboBox = new QComboBox(EdgeZeroDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 10, 61, 22));
        doubleSpinBox = new QDoubleSpinBox(EdgeZeroDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(71, 40, 61, 22));
        doubleSpinBox->setMinimum(0.000000000000000);
        doubleSpinBox->setSingleStep(0.200000000000000);
        doubleSpinBox->setValue(1.600000000000000);
        label = new QLabel(EdgeZeroDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 16));
        label_2 = new QLabel(EdgeZeroDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 46, 16));
        buttonBox = new QDialogButtonBox(EdgeZeroDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(140, 10, 81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label_3 = new QLabel(EdgeZeroDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 46, 21));
        spinBox = new QSpinBox(EdgeZeroDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(70, 70, 61, 22));
        spinBox->setMaximum(127);
        spinBox->setValue(5);

        retranslateUi(EdgeZeroDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EdgeZeroDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EdgeZeroDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EdgeZeroDialog);
    } // setupUi

    void retranslateUi(QDialog *EdgeZeroDialog)
    {
        EdgeZeroDialog->setWindowTitle(QCoreApplication::translate("EdgeZeroDialog", "Edge Zero Crossing", nullptr));
        label->setText(QCoreApplication::translate("EdgeZeroDialog", "Mask size", nullptr));
        label_2->setText(QCoreApplication::translate("EdgeZeroDialog", "Sigma", nullptr));
        label_3->setText(QCoreApplication::translate("EdgeZeroDialog", "Threshold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdgeZeroDialog: public Ui_EdgeZeroDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGE_ZERO_DIALOG_H
