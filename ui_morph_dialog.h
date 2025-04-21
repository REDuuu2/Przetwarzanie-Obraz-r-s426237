/********************************************************************************
** Form generated from reading UI file 'morph_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPH_DIALOG_H
#define UI_MORPH_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MorphDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *seSize;
    QLabel *label_2;
    QComboBox *seShape;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MorphDialog)
    {
        if (MorphDialog->objectName().isEmpty())
            MorphDialog->setObjectName(QString::fromUtf8("MorphDialog"));
        MorphDialog->resize(328, 93);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MorphDialog->sizePolicy().hasHeightForWidth());
        MorphDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/personal_finance.png"), QSize(), QIcon::Normal, QIcon::Off);
        MorphDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(MorphDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MorphDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        seSize = new QComboBox(MorphDialog);
        seSize->setObjectName(QString::fromUtf8("seSize"));

        gridLayout->addWidget(seSize, 0, 1, 1, 1);

        label_2 = new QLabel(MorphDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        seShape = new QComboBox(MorphDialog);
        seShape->setObjectName(QString::fromUtf8("seShape"));

        gridLayout->addWidget(seShape, 1, 1, 1, 1);

        okButton = new QPushButton(MorphDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout->addWidget(okButton, 2, 1, 1, 1);

        cancelButton = new QPushButton(MorphDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 2, 2, 1, 1);


        retranslateUi(MorphDialog);

        QMetaObject::connectSlotsByName(MorphDialog);
    } // setupUi

    void retranslateUi(QDialog *MorphDialog)
    {
        MorphDialog->setWindowTitle(QCoreApplication::translate("MorphDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MorphDialog", "SE size:", nullptr));
        label_2->setText(QCoreApplication::translate("MorphDialog", "SE Shape:", nullptr));
        okButton->setText(QCoreApplication::translate("MorphDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("MorphDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MorphDialog: public Ui_MorphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPH_DIALOG_H
