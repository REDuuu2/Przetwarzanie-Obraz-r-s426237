/********************************************************************************
** Form generated from reading UI file 'slider_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDER_DIALOG_H
#define UI_SLIDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SliderDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *slider;
    QLabel *sliderLabel;
    QLabel *previewLabel;
    QCheckBox *previevBox;

    void setupUi(QDialog *SliderDialog)
    {
        if (SliderDialog->objectName().isEmpty())
            SliderDialog->setObjectName(QString::fromUtf8("SliderDialog"));
        SliderDialog->resize(470, 355);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/witch.png"), QSize(), QIcon::Normal, QIcon::Off);
        SliderDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(SliderDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(380, 10, 81, 331));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        slider = new QSlider(SliderDialog);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(40, 10, 321, 20));
        slider->setMinimum(1);
        slider->setMaximum(1000);
        slider->setOrientation(Qt::Horizontal);
        sliderLabel = new QLabel(SliderDialog);
        sliderLabel->setObjectName(QString::fromUtf8("sliderLabel"));
        sliderLabel->setGeometry(QRect(20, 10, 20, 20));
        previewLabel = new QLabel(SliderDialog);
        previewLabel->setObjectName(QString::fromUtf8("previewLabel"));
        previewLabel->setGeometry(QRect(20, 60, 351, 281));
        previewLabel->setFrameShape(QFrame::Box);
        previewLabel->setLineWidth(0);
        previevBox = new QCheckBox(SliderDialog);
        previevBox->setObjectName(QString::fromUtf8("previevBox"));
        previevBox->setGeometry(QRect(20, 40, 70, 17));
        previevBox->setChecked(true);

        retranslateUi(SliderDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SliderDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SliderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SliderDialog);
    } // setupUi

    void retranslateUi(QDialog *SliderDialog)
    {
        SliderDialog->setWindowTitle(QCoreApplication::translate("SliderDialog", "Dialog", nullptr));
        sliderLabel->setText(QCoreApplication::translate("SliderDialog", "0", nullptr));
        previewLabel->setText(QCoreApplication::translate("SliderDialog", "Image", nullptr));
        previevBox->setText(QCoreApplication::translate("SliderDialog", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SliderDialog: public Ui_SliderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDER_DIALOG_H
