/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayoutMain;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSlider *verticalSlider;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QTabWidget *tabAll;
    QWidget *tabSong;
    QWidget *tabPlaylist;
    QWidget *tabRadio;
    QWidget *tabPref;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1169, 698);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 10, 1151, 641));
        gridLayoutMain = new QGridLayout(gridLayoutWidget_4);
        gridLayoutMain->setSpacing(6);
        gridLayoutMain->setContentsMargins(11, 11, 11, 11);
        gridLayoutMain->setObjectName(QStringLiteral("gridLayoutMain"));
        gridLayoutMain->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(gridLayoutWidget_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 150));
        groupBox->setStyleSheet(QLatin1String("border-style : solid  ;\n"
"border-width : 1px; "));
        gridLayoutWidget_3 = new QWidget(groupBox);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 20, 1161, 91));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 0, 10, 0);
        verticalSlider = new QSlider(gridLayoutWidget_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(verticalSlider, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 1, 4, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 1, 7, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 1, 2, 1, 1);

        checkBox_2 = new QCheckBox(gridLayoutWidget_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 1, 6, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout_3->addWidget(checkBox, 1, 5, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 3, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("border-width : 0px ;\n"
""));

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        horizontalSlider = new QSlider(gridLayoutWidget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider, 0, 2, 1, 5);

        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("border-width : 0px ;\n"
""));

        gridLayout_3->addWidget(label_2, 0, 7, 1, 1);

        gridLayoutWidget_3->raise();

        gridLayoutMain->addWidget(groupBox, 2, 0, 1, 1);

        tabAll = new QTabWidget(gridLayoutWidget_4);
        tabAll->setObjectName(QStringLiteral("tabAll"));
        tabAll->setMaximumSize(QSize(10000, 500));
        tabAll->setStyleSheet(QLatin1String("border-style : solid  ;\n"
"border-width : 1px; "));
        tabSong = new QWidget();
        tabSong->setObjectName(QStringLiteral("tabSong"));
        tabAll->addTab(tabSong, QString());
        tabPlaylist = new QWidget();
        tabPlaylist->setObjectName(QStringLiteral("tabPlaylist"));
        tabAll->addTab(tabPlaylist, QString());
        tabRadio = new QWidget();
        tabRadio->setObjectName(QStringLiteral("tabRadio"));
        tabAll->addTab(tabRadio, QString());
        tabPref = new QWidget();
        tabPref->setObjectName(QStringLiteral("tabPref"));
        tabAll->addTab(tabPref, QString());

        gridLayoutMain->addWidget(tabAll, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1169, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabAll->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        checkBox->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        tabAll->setTabText(tabAll->indexOf(tabSong), QApplication::translate("MainWindow", "Morceaux", Q_NULLPTR));
        tabAll->setTabText(tabAll->indexOf(tabPlaylist), QApplication::translate("MainWindow", "Liste de lecture", Q_NULLPTR));
        tabAll->setTabText(tabAll->indexOf(tabRadio), QApplication::translate("MainWindow", "Radio", Q_NULLPTR));
        tabAll->setTabText(tabAll->indexOf(tabPref), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
