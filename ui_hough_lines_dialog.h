/********************************************************************************
** Form generated from reading UI file 'hough_lines_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOUGH_LINES_DIALOG_H
#define UI_HOUGH_LINES_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_HoughLinesDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QSpinBox *sB_theshold;
    QLabel *label;
    QComboBox *cb_draw_whole_lines;

    void setupUi(QDialog *HoughLinesDialog)
    {
        if (HoughLinesDialog->objectName().isEmpty())
            HoughLinesDialog->setObjectName(QString::fromUtf8("HoughLinesDialog"));
        HoughLinesDialog->resize(272, 76);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/videodisplay.png"), QSize(), QIcon::Normal, QIcon::Off);
        HoughLinesDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(HoughLinesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(180, 10, 81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label_3 = new QLabel(HoughLinesDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 71, 21));
        sB_theshold = new QSpinBox(HoughLinesDialog);
        sB_theshold->setObjectName(QString::fromUtf8("sB_theshold"));
        sB_theshold->setGeometry(QRect(100, 10, 71, 22));
        sB_theshold->setMinimum(0);
        sB_theshold->setMaximum(255);
        sB_theshold->setValue(150);
        label = new QLabel(HoughLinesDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 81, 21));
        cb_draw_whole_lines = new QComboBox(HoughLinesDialog);
        cb_draw_whole_lines->setObjectName(QString::fromUtf8("cb_draw_whole_lines"));
        cb_draw_whole_lines->setGeometry(QRect(100, 40, 69, 22));

        retranslateUi(HoughLinesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HoughLinesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HoughLinesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HoughLinesDialog);
    } // setupUi

    void retranslateUi(QDialog *HoughLinesDialog)
    {
        HoughLinesDialog->setWindowTitle(QCoreApplication::translate("HoughLinesDialog", "Hough Lines Detection", nullptr));
        label_3->setText(QCoreApplication::translate("HoughLinesDialog", "threshold", nullptr));
        label->setText(QCoreApplication::translate("HoughLinesDialog", "draw whole lines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HoughLinesDialog: public Ui_HoughLinesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOUGH_LINES_DIALOG_H
