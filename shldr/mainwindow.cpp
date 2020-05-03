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

QVector<ts::Task> tasks;
QVector<ts::Task*> currshowed;

ts::Task * selectedtask;

QStringListModel *model;

void updateListW(Ui::MainWindow *ui, QVector<ts::Task*> tasklist){
    QStringList list;

    currshowed = tasklist;

    for(int i = 0; i < tasklist.length(); i++){
        list << QString::fromStdString(ts::to_string(*currshowed[i]));
    }

    model->setStringList(list);
    ui->listView->setModel(model);
}

void updateListW(Ui::MainWindow *ui){
    QVector<ts::Task*> ptasks;
    for (int i = 0; i < tasks.length(); i++) {
        ptasks.append(&tasks[i]);
        std::cout << "++++++++++++" << tasks[i].name << std::endl;;
    }

    currshowed = ptasks;
    updateListW(ui, ptasks);
}

void load(){
    try {
        tasks = ts::read();

        QDateTime current = QDateTime::currentDateTime();

        for (int i = 0; i < tasks.length(); i++) {
            if(tasks[i].date < current.toTime_t()){
                tasks[i].expired = true;
            }
        }

    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    //storage_test();

    load();
    selectedtask = NULL;//&tasks[0];

    updateListW(ui);

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

    //QDateTime datetime = ui->dateTimeEdit->dateTime();
    QDate date = ui->calendarWidget->selectedDate();
    QTime time = ui->timeEdit->time();
    QDateTime datetime = QDateTime(date, time);
    QDateTime current = QDateTime::currentDateTime();

    bool done = ui->checkBox->isChecked();

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

    if(name.length() > ts::NAME_LEN){
        showDialog(this, "слишком длинное имя");
        return;
    }

    if(name.isEmpty()){
        showDialog(this, "имя пустое");
        return;
    }

    if(selectedtask == NULL){
        ts::Task task;
        task.expired = false;
        tasks.append(task);
        selectedtask = &tasks.last();
    }

    strcpy(selectedtask->name, name.toStdString().c_str());
    strcpy(selectedtask->disc, text.toStdString().c_str());
    selectedtask->done = done;

    selectedtask->date = datetime.toTime_t();

    try {
        //QVector<ts::Task> tasks = ts::read();
        for(int i = 0; i < tasks.length(); i++)
            printf("name: %s \tdisc: %s\t done: %d\t expired: %d\ttime: %s", tasks[i].name, tasks[i].disc, tasks[i].done, tasks[i].expired, asctime(localtime(&(tasks[i].date))));
        //tasks.append(*selectedtask);

        //сортировка по датам
        //std::sort(tasks.begin(), tasks.end(), [&](ts::Task &a, ts::Task &b){ return a.date > b.date; });

        ts::save(tasks);

        //обновляем список
        updateListW(ui);

    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }
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



void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate selected = ui->calendarWidget->selectedDate();
    QVector<ts::Task*> todaytasks;

    //select tasks by date
    //QVector<ts::Task> todaytasks;
    //иттератор
    /*for(QVector<ts::Task>::iterator it =
        std::find_if(tasks.begin(), tasks.end(),
                     [&selected](ts::Task t) { return QDateTime::fromTime_t(t.date).date() == selected;});
        it != tasks.end(); ++it)
    {
        //std::cout << "Found : " << ts::to_string(*it) << std::endl;
        todaytasks.append(*it);
    }*/

    for (int i = 0; i < tasks.length(); i++) {
        if(QDateTime::fromTime_t(tasks[i].date).date() == selected){
            todaytasks.append(&tasks[i]);
        }
    }

    updateListW(ui, todaytasks);
}

void MainWindow::on_weekbtn_clicked()
{
    QDate current = QDate::currentDate();
    QDate week = current.addDays(7);
    std::cout << week.toString().toStdString() << std::endl;

    ui->calendarWidget->setSelectedDate(current);
    ui->calendarWidget->showSelectedDate();

    QVector<ts::Task*> weektasks;

    for (int i = 0; i < tasks.length(); i++) {
        if(QDateTime::fromTime_t(tasks[i].date).date() >= current && QDateTime::fromTime_t(tasks[i].date).date() <= week){
            weektasks.append(&tasks[i]);
        }
    }

    updateListW(ui, weektasks);
}

void MainWindow::on_alltimebtn_clicked()
{
    updateListW(ui);
}

void clearUI(Ui::MainWindow *ui){
    selectedtask = NULL;
    ui->lineEdit->clear();
    ui->textEdit->clear();

    QDateTime dt = QDateTime::currentDateTime();
    ui->timeEdit->setTime(dt.time());
    ui->calendarWidget->setSelectedDate(dt.date());
    ui->calendarWidget->showSelectedDate();

    ui->checkBox->setChecked(false);

    updateListW(ui);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    //dssstd::cout << index.row() << "yyyyyyyyyyyyyyyyyy" << currshowed.length();
    int id = index.row();

    selectedtask = currshowed[id];

    ui->lineEdit->setText(selectedtask->name);
    ui->textEdit->setText(selectedtask->disc);

    QDateTime dt = QDateTime::fromTime_t(selectedtask->date);
    ui->timeEdit->setTime(dt.time());
    ui->calendarWidget->setSelectedDate(dt.date());
    ui->calendarWidget->showSelectedDate();

    ui->checkBox->setChecked(selectedtask->done);
}



void MainWindow::on_newbtn_clicked(bool checked)
{
    selectedtask = NULL;
    clearUI(ui);
}

void MainWindow::on_deletebtn_clicked()
{
    if(selectedtask != NULL){
        tasks.erase(selectedtask);

        selectedtask = NULL;
        clearUI(ui);
    }
}
