/********************************************************************************
** Form generated from reading UI file 'correction_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORRECTION_DIALOG_H
#define UI_CORRECTION_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_CorrectionDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *okButton;
    QLabel *correctionLabel;
    QLabel *contrastLabel;
    QLabel *contrastLabelText;
    QSlider *contrast;
    QSlider *correction;
    QLabel *correctionTextLabel;
    QLabel *preview;
    QCheckBox *previewBox;
    QSlider *gamma;
    QLabel *gammaTextLabel;
    QLabel *gammaLabel;

    void setupUi(QDialog *CorrectionDialog)
    {
        if (CorrectionDialog->objectName().isEmpty())
            CorrectionDialog->setObjectName(QString::fromUtf8("CorrectionDialog"));
        CorrectionDialog->resize(478, 341);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/lightbulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        CorrectionDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(CorrectionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        okButton = new QPushButton(CorrectionDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout->addWidget(okButton, 5, 3, 1, 1);

        correctionLabel = new QLabel(CorrectionDialog);
        correctionLabel->setObjectName(QString::fromUtf8("correctionLabel"));

        gridLayout->addWidget(correctionLabel, 0, 3, 1, 1);

        contrastLabel = new QLabel(CorrectionDialog);
        contrastLabel->setObjectName(QString::fromUtf8("contrastLabel"));

        gridLayout->addWidget(contrastLabel, 1, 3, 1, 1);

        contrastLabelText = new QLabel(CorrectionDialog);
        contrastLabelText->setObjectName(QString::fromUtf8("contrastLabelText"));
        contrastLabelText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(contrastLabelText, 1, 1, 1, 1);

        contrast = new QSlider(CorrectionDialog);
        contrast->setObjectName(QString::fromUtf8("contrast"));
        contrast->setMaximum(1000);
        contrast->setSingleStep(10);
        contrast->setValue(500);
        contrast->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(contrast, 1, 2, 1, 1);

        correction = new QSlider(CorrectionDialog);
        correction->setObjectName(QString::fromUtf8("correction"));
        correction->setMaximum(510);
        correction->setValue(255);
        correction->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(correction, 0, 2, 1, 1);

        correctionTextLabel = new QLabel(CorrectionDialog);
        correctionTextLabel->setObjectName(QString::fromUtf8("correctionTextLabel"));
        correctionTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(correctionTextLabel, 0, 1, 1, 1);

        preview = new QLabel(CorrectionDialog);
        preview->setObjectName(QString::fromUtf8("preview"));

        gridLayout->addWidget(preview, 3, 2, 1, 1);

        previewBox = new QCheckBox(CorrectionDialog);
        previewBox->setObjectName(QString::fromUtf8("previewBox"));
        previewBox->setChecked(true);

        gridLayout->addWidget(previewBox, 5, 1, 1, 1);

        gamma = new QSlider(CorrectionDialog);
        gamma->setObjectName(QString::fromUtf8("gamma"));
        gamma->setMaximum(1000);
        gamma->setSingleStep(10);
        gamma->setValue(500);
        gamma->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(gamma, 2, 2, 1, 1);

        gammaTextLabel = new QLabel(CorrectionDialog);
        gammaTextLabel->setObjectName(QString::fromUtf8("gammaTextLabel"));
        gammaTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(gammaTextLabel, 2, 1, 1, 1);

        gammaLabel = new QLabel(CorrectionDialog);
        gammaLabel->setObjectName(QString::fromUtf8("gammaLabel"));

        gridLayout->addWidget(gammaLabel, 2, 3, 1, 1);


        retranslateUi(CorrectionDialog);

        QMetaObject::connectSlotsByName(CorrectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CorrectionDialog)
    {
        CorrectionDialog->setWindowTitle(QCoreApplication::translate("CorrectionDialog", "Correction", nullptr));
        okButton->setText(QCoreApplication::translate("CorrectionDialog", "OK", nullptr));
        correctionLabel->setText(QCoreApplication::translate("CorrectionDialog", "TextLabel", nullptr));
        contrastLabel->setText(QCoreApplication::translate("CorrectionDialog", "TextLabel", nullptr));
        contrastLabelText->setText(QCoreApplication::translate("CorrectionDialog", "Contrast", nullptr));
        correctionTextLabel->setText(QCoreApplication::translate("CorrectionDialog", "Brightness", nullptr));
        preview->setText(QCoreApplication::translate("CorrectionDialog", "PREVIEW", nullptr));
        previewBox->setText(QCoreApplication::translate("CorrectionDialog", "Preview", nullptr));
        gammaTextLabel->setText(QCoreApplication::translate("CorrectionDialog", "Gamma", nullptr));
        gammaLabel->setText(QCoreApplication::translate("CorrectionDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CorrectionDialog: public Ui_CorrectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORRECTION_DIALOG_H
