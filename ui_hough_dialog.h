/********************************************************************************
** Form generated from reading UI file 'hough_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOUGH_DIALOG_H
#define UI_HOUGH_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_HoughDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QSpinBox *sB_theta_density;

    void setupUi(QDialog *HoughDialog)
    {
        if (HoughDialog->objectName().isEmpty())
            HoughDialog->setObjectName(QString::fromUtf8("HoughDialog"));
        HoughDialog->resize(227, 72);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/videodisplay.png"), QSize(), QIcon::Normal, QIcon::Off);
        HoughDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(HoughDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(140, 10, 81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label_3 = new QLabel(HoughDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 71, 21));
        sB_theta_density = new QSpinBox(HoughDialog);
        sB_theta_density->setObjectName(QString::fromUtf8("sB_theta_density"));
        sB_theta_density->setGeometry(QRect(90, 10, 41, 22));
        sB_theta_density->setMinimum(1);
        sB_theta_density->setMaximum(10);
        sB_theta_density->setValue(3);

        retranslateUi(HoughDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HoughDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HoughDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HoughDialog);
    } // setupUi

    void retranslateUi(QDialog *HoughDialog)
    {
        HoughDialog->setWindowTitle(QCoreApplication::translate("HoughDialog", "Hough Transform", nullptr));
        label_3->setText(QCoreApplication::translate("HoughDialog", "theta density", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HoughDialog: public Ui_HoughDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOUGH_DIALOG_H
