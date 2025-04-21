/********************************************************************************
** Form generated from reading UI file 'toolsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSMENU_H
#define UI_TOOLSMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QToolButton *rotate270Button;
    QToolButton *zoominButton;
    QToolButton *zoomoutButton;
    QToolButton *zoomResetButton;
    QToolButton *rotate90Button;
    QToolButton *rotate180Button;
    QToolButton *negativeButton;
    QToolButton *grayscaleButton;
    QToolButton *lightButton;
    QToolButton *histogramButton;
    QToolButton *blurButton;
    QToolButton *binarizationButton;
    QToolButton *noiseButton;
    QToolButton *morphButton;
    QToolButton *edgeButton;
    QToolButton *textureButton;
    QToolButton *transformationsButton;
    QToolButton *cornerButton;

    void setupUi(QWidget *ToolsMenu)
    {
        if (ToolsMenu->objectName().isEmpty())
            ToolsMenu->setObjectName(QString::fromUtf8("ToolsMenu"));
        ToolsMenu->resize(150, 640);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolsMenu->sizePolicy().hasHeightForWidth());
        ToolsMenu->setSizePolicy(sizePolicy);
        ToolsMenu->setMinimumSize(QSize(150, 0));
        ToolsMenu->setMaximumSize(QSize(150, 16777215));
        ToolsMenu->setBaseSize(QSize(150, 0));
        ToolsMenu->setContextMenuPolicy(Qt::NoContextMenu);
        ToolsMenu->setLayoutDirection(Qt::LeftToRight);
        ToolsMenu->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(ToolsMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 196, 587));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(1);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setSizeConstraint(QLayout::SetMaximumSize);
        layout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(verticalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        rotate270Button = new QToolButton(frame);
        rotate270Button->setObjectName(QString::fromUtf8("rotate270Button"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rotate270Button->sizePolicy().hasHeightForWidth());
        rotate270Button->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/transform_rotate_270.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotate270Button->setIcon(icon);
        rotate270Button->setIconSize(QSize(32, 32));
        rotate270Button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        rotate270Button->setAutoRaise(true);

        gridLayout->addWidget(rotate270Button, 1, 2, 1, 1);

        zoominButton = new QToolButton(frame);
        zoominButton->setObjectName(QString::fromUtf8("zoominButton"));
        sizePolicy2.setHeightForWidth(zoominButton->sizePolicy().hasHeightForWidth());
        zoominButton->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoominButton->setIcon(icon1);
        zoominButton->setIconSize(QSize(32, 32));
        zoominButton->setPopupMode(QToolButton::InstantPopup);
        zoominButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        zoominButton->setAutoRaise(true);

        gridLayout->addWidget(zoominButton, 0, 0, 1, 1);

        zoomoutButton = new QToolButton(frame);
        zoomoutButton->setObjectName(QString::fromUtf8("zoomoutButton"));
        sizePolicy2.setHeightForWidth(zoomoutButton->sizePolicy().hasHeightForWidth());
        zoomoutButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomoutButton->setIcon(icon2);
        zoomoutButton->setIconSize(QSize(32, 32));
        zoomoutButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        zoomoutButton->setAutoRaise(true);

        gridLayout->addWidget(zoomoutButton, 0, 1, 1, 1);

        zoomResetButton = new QToolButton(frame);
        zoomResetButton->setObjectName(QString::fromUtf8("zoomResetButton"));
        sizePolicy2.setHeightForWidth(zoomResetButton->sizePolicy().hasHeightForWidth());
        zoomResetButton->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/zoom_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomResetButton->setIcon(icon3);
        zoomResetButton->setIconSize(QSize(32, 32));
        zoomResetButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        zoomResetButton->setAutoRaise(true);

        gridLayout->addWidget(zoomResetButton, 0, 2, 1, 1);

        rotate90Button = new QToolButton(frame);
        rotate90Button->setObjectName(QString::fromUtf8("rotate90Button"));
        sizePolicy2.setHeightForWidth(rotate90Button->sizePolicy().hasHeightForWidth());
        rotate90Button->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/transform_rotate_90.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotate90Button->setIcon(icon4);
        rotate90Button->setIconSize(QSize(32, 32));
        rotate90Button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        rotate90Button->setAutoRaise(true);

        gridLayout->addWidget(rotate90Button, 1, 0, 1, 1);

        rotate180Button = new QToolButton(frame);
        rotate180Button->setObjectName(QString::fromUtf8("rotate180Button"));
        sizePolicy2.setHeightForWidth(rotate180Button->sizePolicy().hasHeightForWidth());
        rotate180Button->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/transform_rotate_180.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotate180Button->setIcon(icon5);
        rotate180Button->setIconSize(QSize(32, 32));
        rotate180Button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        rotate180Button->setAutoRaise(true);

        gridLayout->addWidget(rotate180Button, 1, 1, 1, 1);


        layout->addWidget(frame);

        negativeButton = new QToolButton(verticalLayoutWidget);
        negativeButton->setObjectName(QString::fromUtf8("negativeButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(negativeButton->sizePolicy().hasHeightForWidth());
        negativeButton->setSizePolicy(sizePolicy3);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/eye_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        negativeButton->setIcon(icon6);
        negativeButton->setIconSize(QSize(32, 32));
        negativeButton->setPopupMode(QToolButton::DelayedPopup);
        negativeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        negativeButton->setAutoRaise(true);

        layout->addWidget(negativeButton);

        grayscaleButton = new QToolButton(verticalLayoutWidget);
        grayscaleButton->setObjectName(QString::fromUtf8("grayscaleButton"));
        sizePolicy3.setHeightForWidth(grayscaleButton->sizePolicy().hasHeightForWidth());
        grayscaleButton->setSizePolicy(sizePolicy3);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/convert_color_to_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        grayscaleButton->setIcon(icon7);
        grayscaleButton->setIconSize(QSize(32, 32));
        grayscaleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        grayscaleButton->setAutoRaise(true);

        layout->addWidget(grayscaleButton);

        lightButton = new QToolButton(verticalLayoutWidget);
        lightButton->setObjectName(QString::fromUtf8("lightButton"));
        sizePolicy3.setHeightForWidth(lightButton->sizePolicy().hasHeightForWidth());
        lightButton->setSizePolicy(sizePolicy3);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/lightbulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        lightButton->setIcon(icon8);
        lightButton->setIconSize(QSize(32, 32));
        lightButton->setPopupMode(QToolButton::DelayedPopup);
        lightButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lightButton->setAutoRaise(true);

        layout->addWidget(lightButton);

        histogramButton = new QToolButton(verticalLayoutWidget);
        histogramButton->setObjectName(QString::fromUtf8("histogramButton"));
        sizePolicy3.setHeightForWidth(histogramButton->sizePolicy().hasHeightForWidth());
        histogramButton->setSizePolicy(sizePolicy3);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/chart_curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        histogramButton->setIcon(icon9);
        histogramButton->setIconSize(QSize(32, 32));
        histogramButton->setAutoRepeat(false);
        histogramButton->setPopupMode(QToolButton::MenuButtonPopup);
        histogramButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        histogramButton->setAutoRaise(true);
        histogramButton->setArrowType(Qt::NoArrow);

        layout->addWidget(histogramButton);

        blurButton = new QToolButton(verticalLayoutWidget);
        blurButton->setObjectName(QString::fromUtf8("blurButton"));
        sizePolicy3.setHeightForWidth(blurButton->sizePolicy().hasHeightForWidth());
        blurButton->setSizePolicy(sizePolicy3);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        blurButton->setIcon(icon10);
        blurButton->setIconSize(QSize(32, 32));
        blurButton->setPopupMode(QToolButton::MenuButtonPopup);
        blurButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        blurButton->setAutoRaise(true);

        layout->addWidget(blurButton);

        binarizationButton = new QToolButton(verticalLayoutWidget);
        binarizationButton->setObjectName(QString::fromUtf8("binarizationButton"));
        sizePolicy3.setHeightForWidth(binarizationButton->sizePolicy().hasHeightForWidth());
        binarizationButton->setSizePolicy(sizePolicy3);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/universal_binary.png"), QSize(), QIcon::Normal, QIcon::Off);
        binarizationButton->setIcon(icon11);
        binarizationButton->setIconSize(QSize(32, 32));
        binarizationButton->setPopupMode(QToolButton::MenuButtonPopup);
        binarizationButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        binarizationButton->setAutoRaise(true);

        layout->addWidget(binarizationButton);

        noiseButton = new QToolButton(verticalLayoutWidget);
        noiseButton->setObjectName(QString::fromUtf8("noiseButton"));
        sizePolicy3.setHeightForWidth(noiseButton->sizePolicy().hasHeightForWidth());
        noiseButton->setSizePolicy(sizePolicy3);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/icons/checkerboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        noiseButton->setIcon(icon12);
        noiseButton->setIconSize(QSize(32, 32));
        noiseButton->setPopupMode(QToolButton::MenuButtonPopup);
        noiseButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        noiseButton->setAutoRaise(true);

        layout->addWidget(noiseButton);

        morphButton = new QToolButton(verticalLayoutWidget);
        morphButton->setObjectName(QString::fromUtf8("morphButton"));
        sizePolicy3.setHeightForWidth(morphButton->sizePolicy().hasHeightForWidth());
        morphButton->setSizePolicy(sizePolicy3);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/icons/document_shapes.png"), QSize(), QIcon::Normal, QIcon::Off);
        morphButton->setIcon(icon13);
        morphButton->setIconSize(QSize(32, 32));
        morphButton->setPopupMode(QToolButton::MenuButtonPopup);
        morphButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        morphButton->setAutoRaise(true);

        layout->addWidget(morphButton);

        edgeButton = new QToolButton(verticalLayoutWidget);
        edgeButton->setObjectName(QString::fromUtf8("edgeButton"));
        sizePolicy3.setHeightForWidth(edgeButton->sizePolicy().hasHeightForWidth());
        edgeButton->setSizePolicy(sizePolicy3);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/icons/edge_detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        edgeButton->setIcon(icon14);
        edgeButton->setIconSize(QSize(32, 32));
        edgeButton->setPopupMode(QToolButton::MenuButtonPopup);
        edgeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        edgeButton->setAutoRaise(true);

        layout->addWidget(edgeButton);

        textureButton = new QToolButton(verticalLayoutWidget);
        textureButton->setObjectName(QString::fromUtf8("textureButton"));
        sizePolicy3.setHeightForWidth(textureButton->sizePolicy().hasHeightForWidth());
        textureButton->setSizePolicy(sizePolicy3);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/icons/flag_airfield_vehicle_safety.png"), QSize(), QIcon::Normal, QIcon::Off);
        textureButton->setIcon(icon15);
        textureButton->setIconSize(QSize(32, 32));
        textureButton->setPopupMode(QToolButton::MenuButtonPopup);
        textureButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        textureButton->setAutoRaise(true);

        layout->addWidget(textureButton);

        transformationsButton = new QToolButton(verticalLayoutWidget);
        transformationsButton->setObjectName(QString::fromUtf8("transformationsButton"));
        sizePolicy3.setHeightForWidth(transformationsButton->sizePolicy().hasHeightForWidth());
        transformationsButton->setSizePolicy(sizePolicy3);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/icons/videodisplay.png"), QSize(), QIcon::Normal, QIcon::Off);
        transformationsButton->setIcon(icon16);
        transformationsButton->setIconSize(QSize(32, 32));
        transformationsButton->setPopupMode(QToolButton::MenuButtonPopup);
        transformationsButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        transformationsButton->setAutoRaise(true);

        layout->addWidget(transformationsButton);

        cornerButton = new QToolButton(verticalLayoutWidget);
        cornerButton->setObjectName(QString::fromUtf8("cornerButton"));
        sizePolicy3.setHeightForWidth(cornerButton->sizePolicy().hasHeightForWidth());
        cornerButton->setSizePolicy(sizePolicy3);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/icons/things_digital.png"), QSize(), QIcon::Normal, QIcon::Off);
        cornerButton->setIcon(icon17);
        cornerButton->setIconSize(QSize(32, 32));
        cornerButton->setPopupMode(QToolButton::MenuButtonPopup);
        cornerButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        cornerButton->setAutoRaise(true);

        layout->addWidget(cornerButton);


        retranslateUi(ToolsMenu);

        QMetaObject::connectSlotsByName(ToolsMenu);
    } // setupUi

    void retranslateUi(QWidget *ToolsMenu)
    {
        ToolsMenu->setWindowTitle(QCoreApplication::translate("ToolsMenu", "Tools", nullptr));
#if QT_CONFIG(tooltip)
        rotate270Button->setToolTip(QCoreApplication::translate("ToolsMenu", "Rotate 270", nullptr));
#endif // QT_CONFIG(tooltip)
        rotate270Button->setText(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        zoominButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Zoom in", nullptr));
#endif // QT_CONFIG(tooltip)
        zoominButton->setText(QCoreApplication::translate("ToolsMenu", "Zoom in", nullptr));
#if QT_CONFIG(tooltip)
        zoomoutButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#endif // QT_CONFIG(tooltip)
        zoomoutButton->setText(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        zoomResetButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Reset zoom", nullptr));
#endif // QT_CONFIG(tooltip)
        zoomResetButton->setText(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        rotate90Button->setToolTip(QCoreApplication::translate("ToolsMenu", "Rotate 90", nullptr));
#endif // QT_CONFIG(tooltip)
        rotate90Button->setText(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        rotate180Button->setToolTip(QCoreApplication::translate("ToolsMenu", "Rotate 180", nullptr));
#endif // QT_CONFIG(tooltip)
        rotate180Button->setText(QCoreApplication::translate("ToolsMenu", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        negativeButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Brightnes, contrast and gamma correction", nullptr));
#endif // QT_CONFIG(tooltip)
        negativeButton->setText(QCoreApplication::translate("ToolsMenu", "Negative", nullptr));
#if QT_CONFIG(tooltip)
        grayscaleButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Conversion to grayscale", nullptr));
#endif // QT_CONFIG(tooltip)
        grayscaleButton->setText(QCoreApplication::translate("ToolsMenu", "Grayscale", nullptr));
#if QT_CONFIG(tooltip)
        lightButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Brightnes, contrast and gamma correction", nullptr));
#endif // QT_CONFIG(tooltip)
        lightButton->setText(QCoreApplication::translate("ToolsMenu", "Correction", nullptr));
#if QT_CONFIG(tooltip)
        histogramButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Show histogram", nullptr));
#endif // QT_CONFIG(tooltip)
        histogramButton->setText(QCoreApplication::translate("ToolsMenu", "Histogram", nullptr));
#if QT_CONFIG(tooltip)
        blurButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        blurButton->setText(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#if QT_CONFIG(tooltip)
        binarizationButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        binarizationButton->setText(QCoreApplication::translate("ToolsMenu", "Black and white", nullptr));
#if QT_CONFIG(tooltip)
        noiseButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        noiseButton->setText(QCoreApplication::translate("ToolsMenu", "Noise reduction", nullptr));
#if QT_CONFIG(tooltip)
        morphButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        morphButton->setText(QCoreApplication::translate("ToolsMenu", "Morphological ", nullptr));
#if QT_CONFIG(tooltip)
        edgeButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        edgeButton->setText(QCoreApplication::translate("ToolsMenu", "Edge detection", nullptr));
#if QT_CONFIG(tooltip)
        textureButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        textureButton->setText(QCoreApplication::translate("ToolsMenu", "Textures", nullptr));
#if QT_CONFIG(tooltip)
        transformationsButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        transformationsButton->setText(QCoreApplication::translate("ToolsMenu", "Transformations", nullptr));
#if QT_CONFIG(tooltip)
        cornerButton->setToolTip(QCoreApplication::translate("ToolsMenu", "Filters", nullptr));
#endif // QT_CONFIG(tooltip)
        cornerButton->setText(QCoreApplication::translate("ToolsMenu", "Corner detection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolsMenu: public Ui_ToolsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSMENU_H
