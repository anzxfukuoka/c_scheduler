/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadbtn;
    QPushButton *savebtn;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exportbtn;
    QLabel *charcount;
    QFrame *line;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadbtn = new QPushButton(centralwidget);
        loadbtn->setObjectName(QString::fromUtf8("loadbtn"));
        loadbtn->setGeometry(QRect(360, 20, 93, 28));
        savebtn = new QPushButton(centralwidget);
        savebtn->setObjectName(QString::fromUtf8("savebtn"));
        savebtn->setGeometry(QRect(360, 60, 93, 28));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 160, 431, 271));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 100, 331, 22));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 50, 194, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 140, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 91, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 55, 16));
        exportbtn = new QPushButton(centralwidget);
        exportbtn->setObjectName(QString::fromUtf8("exportbtn"));
        exportbtn->setGeometry(QRect(360, 100, 93, 28));
        charcount = new QLabel(centralwidget);
        charcount->setObjectName(QString::fromUtf8("charcount"));
        charcount->setGeometry(QRect(390, 440, 55, 16));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 450, 431, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(460, 20, 311, 501));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadbtn->setText(QCoreApplication::translate("MainWindow", "LOAD", nullptr));
        savebtn->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\321\201\320\276\320\261\321\213\321\202\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\321\202\320\260", nullptr));
        exportbtn->setText(QCoreApplication::translate("MainWindow", "EXPORT", nullptr));
        charcount->setText(QCoreApplication::translate("MainWindow", "0/240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
