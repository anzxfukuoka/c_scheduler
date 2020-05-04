/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *deletebtn;
    QPushButton *savebtn;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exportbtn;
    QLabel *charcount;
    QFrame *line;
    QListView *listView;
    QCheckBox *checkBox;
    QPushButton *importbtn;
    QCalendarWidget *calendarWidget;
    QTimeEdit *timeEdit;
    QLabel *label_4;
    QFrame *line_2;
    QPushButton *weekbtn;
    QPushButton *alltimebtn;
    QPushButton *newbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 641);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        deletebtn = new QPushButton(centralwidget);
        deletebtn->setObjectName(QString::fromUtf8("deletebtn"));
        deletebtn->setGeometry(QRect(210, 550, 93, 28));
        savebtn = new QPushButton(centralwidget);
        savebtn->setObjectName(QString::fromUtf8("savebtn"));
        savebtn->setGeometry(QRect(310, 550, 93, 28));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 400, 401, 111));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 350, 271, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 380, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 330, 91, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 55, 16));
        exportbtn = new QPushButton(centralwidget);
        exportbtn->setObjectName(QString::fromUtf8("exportbtn"));
        exportbtn->setGeometry(QRect(110, 550, 93, 28));
        charcount = new QLabel(centralwidget);
        charcount->setObjectName(QString::fromUtf8("charcount"));
        charcount->setGeometry(QRect(350, 510, 55, 16));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 530, 401, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(420, 20, 311, 521));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 350, 101, 20));
        importbtn = new QPushButton(centralwidget);
        importbtn->setObjectName(QString::fromUtf8("importbtn"));
        importbtn->setGeometry(QRect(10, 550, 93, 28));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(15, 50, 391, 218));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(10, 300, 118, 22));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 55, 16));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 20, 391, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        weekbtn = new QPushButton(centralwidget);
        weekbtn->setObjectName(QString::fromUtf8("weekbtn"));
        weekbtn->setGeometry(QRect(510, 550, 111, 28));
        alltimebtn = new QPushButton(centralwidget);
        alltimebtn->setObjectName(QString::fromUtf8("alltimebtn"));
        alltimebtn->setGeometry(QRect(632, 550, 101, 28));
        newbtn = new QPushButton(centralwidget);
        newbtn->setObjectName(QString::fromUtf8("newbtn"));
        newbtn->setGeometry(QRect(310, 290, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 743, 26));
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
        deletebtn->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        savebtn->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\321\201\320\276\320\261\321\213\321\202\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\321\202\320\260", nullptr));
        exportbtn->setText(QCoreApplication::translate("MainWindow", "EXPORT", nullptr));
        charcount->setText(QCoreApplication::translate("MainWindow", "0/240", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276", nullptr));
        importbtn->setText(QCoreApplication::translate("MainWindow", "IMPORT", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\262\321\200\320\265\320\274\321\217", nullptr));
        weekbtn->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260 \321\215\321\202\320\276\320\271 \320\275\320\265\320\264\320\265\320\273\320\265", nullptr));
        alltimebtn->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260 \320\262\321\201\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        newbtn->setText(QCoreApplication::translate("MainWindow", "NEW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
