#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QDialog>
#include <QLabel>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QStringListModel>
#include <QString>

#include <stdlib.h>
#include <iostream>

#include "storage.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try {
        QVector<ts::Task> tasks = ts::read();

        QStringListModel *model = new  QStringListModel(this);
        QStringList list;

        for(int i = 0; i < tasks.length(); i++){
            list << tasks[i].name; // QString::fromStdString(ts::to_string(tasks[i]));
        }

        model->setStringList(list);
        ui->listView->setModel(model);

    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void showDialog(QWidget *p, QString msg){
    QDialog dialog(p);
    dialog.setWindowTitle("ошибка");
    dialog.setMinimumSize(340, 80);

    QLabel *l = new QLabel(&dialog);
    l->setText(msg);

    QFormLayout *layout = new QFormLayout();
    layout->addWidget(l);

    dialog.setLayout(layout);
    dialog.exec();
}

void MainWindow::on_savebtn_clicked()
{
    storage_test();

    QString name = ui->lineEdit->text();
    //std::cout << name.toStdString() << std::endl;

    QString text = ui->textEdit->toPlainText();
    //std::cout << text.toStdString() << std::endl;

    QDateTime datetime = ui->dateTimeEdit->dateTime();
    QDateTime current = QDateTime::currentDateTime();

    if(current > datetime){
        showDialog(this, "нельзя создавать события в прошлом");
        return;
    }

    if(text.length() > ts::DISC_LEN){
        showDialog(this, "слишком многобукаф");
        return;
    }

    /*if(text.isEmpty()){
        showDialog(this, "текст пустой");
        return;
    }*/

    if(name.length() > ts::DISC_LEN){
        showDialog(this, "слишком длинное имя");
        return;
    }

    if(name.isEmpty()){
        showDialog(this, "имя пустое");
        return;
    }

    ts::Task * task = new ts::Task;

    strcpy(task->name, name.toStdString().c_str());
    strcpy(task->disc, text.toStdString().c_str());
    task->done = false;
    task->expired = false;

    task->date = datetime.toTime_t();

    try {
        QVector<ts::Task> tasks = ts::read();
        for(int i = 0; i < tasks.length(); i++)
            printf("name: %s \tdisc: %s\t done: %d\t expired: %d\ttime: %s", tasks[i].name, tasks[i].disc, tasks[i].done, tasks[i].expired, asctime(localtime(&(tasks[i].date))));
        tasks.append(*task);
        ts::save(tasks);
    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }
}

void MainWindow::on_loadbtn_clicked()
{

}

void MainWindow::on_exportbtn_clicked()
{

}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    int lenght = text.length();
    QString l;
    QTextStream(&l) << lenght << "/" << ts::DISC_LEN;

    if(lenght > ts::DISC_LEN){
        l = "<font color='#FF0000'>" + l + "</font>";
    }
    ui->charcount->setText(l);
}

void MainWindow::on_charcount_linkHovered(const QString &link)
{

}

void MainWindow::on_dateTimeEdit_dateChanged(const QDate &date)
{

}

void MainWindow::on_scrollArea_customContextMenuRequested(const QPoint &pos)
{

}
