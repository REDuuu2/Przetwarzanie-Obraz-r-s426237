/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionBinary_format;
    QAction *actionText_format;
    QAction *actionClose;
    QAction *actionClose_all;
    QAction *actionUndo_Ctrl_Z;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(789, 474);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/witch.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDocumentMode(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/door_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionBinary_format = new QAction(MainWindow);
        actionBinary_format->setObjectName(QString::fromUtf8("actionBinary_format"));
        actionBinary_format->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/picture_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBinary_format->setIcon(icon3);
        actionText_format = new QAction(MainWindow);
        actionText_format->setObjectName(QString::fromUtf8("actionText_format"));
        actionText_format->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/layer_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionText_format->setIcon(icon4);
        actionText_format->setIconVisibleInMenu(true);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/picture_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon5);
        actionClose_all = new QAction(MainWindow);
        actionClose_all->setObjectName(QString::fromUtf8("actionClose_all"));
        actionUndo_Ctrl_Z = new QAction(MainWindow);
        actionUndo_Ctrl_Z->setObjectName(QString::fromUtf8("actionUndo_Ctrl_Z"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionText_format);
        menuFile->addAction(actionBinary_format);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo_Ctrl_Z);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionBinary_format->setText(QCoreApplication::translate("MainWindow", "Save Binary", nullptr));
        actionText_format->setText(QCoreApplication::translate("MainWindow", "Save ASCII", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionClose_all->setText(QCoreApplication::translate("MainWindow", "Close all", nullptr));
        actionUndo_Ctrl_Z->setText(QCoreApplication::translate("MainWindow", "Undo (Ctrl+Z)", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo_Ctrl_Z->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
