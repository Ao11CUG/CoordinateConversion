/********************************************************************************
** Form generated from reading UI file 'CoordinateConversion.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDINATECONVERSION_H
#define UI_COORDINATECONVERSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoordinateConversionClass
{
public:
    QAction *openFile;
    QAction *saveFile;
    QAction *BLHtoXYZ;
    QAction *XYZtoBLH;
    QAction *spotsPicture;
    QAction *report;
    QAction *enlarge;
    QAction *reduce;
    QAction *helpAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QHBoxLayout *horizontalLayout;
    QWidget *widget1;
    QWidget *tab2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *tab3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *help;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CoordinateConversionClass)
    {
        if (CoordinateConversionClass->objectName().isEmpty())
            CoordinateConversionClass->setObjectName("CoordinateConversionClass");
        CoordinateConversionClass->resize(600, 400);
        CoordinateConversionClass->setMinimumSize(QSize(600, 400));
        openFile = new QAction(CoordinateConversionClass);
        openFile->setObjectName("openFile");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CoordinateConversion/res/openFile.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openFile->setIcon(icon);
        saveFile = new QAction(CoordinateConversionClass);
        saveFile->setObjectName("saveFile");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/CoordinateConversion/res/saveFile.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        saveFile->setIcon(icon1);
        BLHtoXYZ = new QAction(CoordinateConversionClass);
        BLHtoXYZ->setObjectName("BLHtoXYZ");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/CoordinateConversion/res/BLHXYZ.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BLHtoXYZ->setIcon(icon2);
        XYZtoBLH = new QAction(CoordinateConversionClass);
        XYZtoBLH->setObjectName("XYZtoBLH");
        XYZtoBLH->setIcon(icon2);
        spotsPicture = new QAction(CoordinateConversionClass);
        spotsPicture->setObjectName("spotsPicture");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/CoordinateConversion/res/spotsPicture.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        spotsPicture->setIcon(icon3);
        report = new QAction(CoordinateConversionClass);
        report->setObjectName("report");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/CoordinateConversion/res/report.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        report->setIcon(icon4);
        enlarge = new QAction(CoordinateConversionClass);
        enlarge->setObjectName("enlarge");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/CoordinateConversion/res/enlagre.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        enlarge->setIcon(icon5);
        reduce = new QAction(CoordinateConversionClass);
        reduce->setObjectName("reduce");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/CoordinateConversion/res/reduce.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reduce->setIcon(icon6);
        helpAction = new QAction(CoordinateConversionClass);
        helpAction->setObjectName("helpAction");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/CoordinateConversion/res/help.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        helpAction->setIcon(icon7);
        centralWidget = new QWidget(CoordinateConversionClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::South);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabBarAutoHide(false);
        tab1 = new QWidget();
        tab1->setObjectName("tab1");
        horizontalLayout = new QHBoxLayout(tab1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        widget1 = new QWidget(tab1);
        widget1->setObjectName("widget1");

        horizontalLayout->addWidget(widget1);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/CoordinateConversion/res/data.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tabWidget->addTab(tab1, icon8, QString());
        tab2 = new QWidget();
        tab2->setObjectName("tab2");
        horizontalLayout_2 = new QHBoxLayout(tab2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/CoordinateConversion/res/picture.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tabWidget->addTab(tab2, icon9, QString());
        tab3 = new QWidget();
        tab3->setObjectName("tab3");
        horizontalLayout_3 = new QHBoxLayout(tab3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget3 = new QWidget(tab3);
        widget3->setObjectName("widget3");

        horizontalLayout_3->addWidget(widget3);

        tabWidget->addTab(tab3, icon4, QString());

        verticalLayout->addWidget(tabWidget);

        CoordinateConversionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CoordinateConversionClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 33));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        help = new QMenu(menuBar);
        help->setObjectName("help");
        CoordinateConversionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CoordinateConversionClass);
        mainToolBar->setObjectName("mainToolBar");
        CoordinateConversionClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(CoordinateConversionClass);
        toolBar->setObjectName("toolBar");
        CoordinateConversionClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(help->menuAction());
        menu->addAction(openFile);
        menu->addAction(saveFile);
        menu_2->addAction(BLHtoXYZ);
        menu_2->addAction(XYZtoBLH);
        menu_3->addAction(spotsPicture);
        menu_3->addAction(enlarge);
        menu_3->addAction(reduce);
        help->addAction(helpAction);
        mainToolBar->addAction(openFile);
        mainToolBar->addAction(saveFile);
        mainToolBar->addAction(BLHtoXYZ);
        mainToolBar->addAction(XYZtoBLH);
        mainToolBar->addAction(spotsPicture);
        mainToolBar->addAction(enlarge);
        mainToolBar->addAction(reduce);
        mainToolBar->addAction(helpAction);

        retranslateUi(CoordinateConversionClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CoordinateConversionClass);
    } // setupUi

    void retranslateUi(QMainWindow *CoordinateConversionClass)
    {
        CoordinateConversionClass->setWindowTitle(QCoreApplication::translate("CoordinateConversionClass", "CoordinateConversion", nullptr));
        openFile->setText(QCoreApplication::translate("CoordinateConversionClass", "\346\211\223\345\274\200", nullptr));
        saveFile->setText(QCoreApplication::translate("CoordinateConversionClass", "\344\277\235\345\255\230", nullptr));
        BLHtoXYZ->setText(QCoreApplication::translate("CoordinateConversionClass", "BLH\342\206\222XYZ", nullptr));
        XYZtoBLH->setText(QCoreApplication::translate("CoordinateConversionClass", "XYZ\342\206\222BLH", nullptr));
        spotsPicture->setText(QCoreApplication::translate("CoordinateConversionClass", "\347\202\271\344\275\215\345\233\276", nullptr));
        report->setText(QCoreApplication::translate("CoordinateConversionClass", "\346\212\245\345\221\212", nullptr));
        enlarge->setText(QCoreApplication::translate("CoordinateConversionClass", "\346\224\276\345\244\247", nullptr));
        reduce->setText(QCoreApplication::translate("CoordinateConversionClass", "\347\274\251\345\260\217", nullptr));
        helpAction->setText(QCoreApplication::translate("CoordinateConversionClass", "\346\237\245\347\234\213\350\257\264\346\230\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("CoordinateConversionClass", "\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("CoordinateConversionClass", "\345\233\276\345\275\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("CoordinateConversionClass", "\346\212\245\345\221\212", nullptr));
        menu->setTitle(QCoreApplication::translate("CoordinateConversionClass", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("CoordinateConversionClass", "\350\256\241\347\256\227", nullptr));
        menu_3->setTitle(QCoreApplication::translate("CoordinateConversionClass", "\346\237\245\347\234\213", nullptr));
        help->setTitle(QCoreApplication::translate("CoordinateConversionClass", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("CoordinateConversionClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoordinateConversionClass: public Ui_CoordinateConversionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDINATECONVERSION_H
