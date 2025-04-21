/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QLabel *imageLabel;
    QProgressBar *dial;

    void setupUi(QWidget *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->setWindowModality(Qt::WindowModal);
        ImageViewer->resize(613, 256);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageViewer->sizePolicy().hasHeightForWidth());
        ImageViewer->setSizePolicy(sizePolicy);
        ImageViewer->setMinimumSize(QSize(50, 50));
        ImageViewer->setBaseSize(QSize(100, 100));
        ImageViewer->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImageViewer->setWindowIcon(icon);
        ImageViewer->setLayoutDirection(Qt::LeftToRight);
        ImageViewer->setAutoFillBackground(true);
        imageLabel = new QLabel(ImageViewer);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 321, 48));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        imageLabel->setFont(font);
        imageLabel->setAlignment(Qt::AlignCenter);
        dial = new QProgressBar(ImageViewer);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(0, 220, 301, 31));
        dial->setValue(24);
        dial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dial->setTextVisible(true);
        dial->setOrientation(Qt::Horizontal);
        dial->setTextDirection(QProgressBar::TopToBottom);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QWidget *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("ImageViewer", "Form", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
