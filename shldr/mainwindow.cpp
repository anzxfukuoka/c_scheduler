/*
mainwindow.cpp
в файле реализованны функуии класса MainWindow: ui и основная логика работы программы

*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QDialog>
#include <QLabel>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QStringListModel>
#include <QString>
#include <QFileDialog>

#include <stdlib.h>
#include <iostream>

#include "storage.cpp"


//загруженные записями
QVector<ts::Task> tasks;
//указатели на те, что сейчас отображаются на экране в ListWidget
QVector<ts::Task*> currshowed;
//запись, с которой работаем в данный момент
ts::Task * selectedtask;

//qt каласс для выведения строк в qt виджетах
//модель представляющяя данные ввиде списка строк
//содержащая один столбик и n строчек, где n длинна списка.
QStringListModel *model;

//обнвение ListView
//показать определеннй список задач
void updateListW(Ui::MainWindow *ui, QVector<ts::Task*> tasklist){
    //список строк
    QStringList list;

    //обновляем сисок отображающихся
    currshowed = tasklist;

    //заполням список строк строками с информацией каждой записи
    //QString - qt aналлог std::string
    for(int i = 0; i < tasklist.length(); i++){
        list << QString::fromStdString(ts::to_string(*currshowed[i]));
    }

    //обновляем виджет
    model->setStringList(list);
    ui->listView->setModel(model);
}

//обнвение ListView
//показать все задачи
void updateListW(Ui::MainWindow *ui){
    //перерабатываем вектор записей в вектор указателей на записи
    QVector<ts::Task*> ptasks;
    for (int i = 0; i < tasks.length(); i++) {
        ptasks.append(&tasks[i]);
        std::cout << "++++++++++++" << tasks[i].name << std::endl;;
    }
    //...
    updateListW(ui, ptasks);
}

//загрузить записи
void load(){
    try {
        //чтение всех из файла в вектор
        tasks = ts::read();

        //настоящее время в системе
        QDateTime current = QDateTime::currentDateTime();

        //проверяем на просроченность
        for (int i = 0; i < tasks.length(); i++) {
            if(tasks[i].date < current.toTime_t()){
                tasks[i].expired = true;
            }
        }

    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }

}

//диалоговое окно с паролем
void showPassDialog(QWidget *p){
    //виджет диалогового окна
    QDialog dialog(p);
    dialog.setWindowTitle("вход");
    dialog.setMinimumSize(340, 80);

    //надпись в окне
    QLabel *l = new QLabel(&dialog);
    l->setText("пароль:");

    //
    QLineEdit *le = new QLineEdit(&dialog);

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dialog);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    MainWindow::connect(btn_box, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    MainWindow::connect(btn_box, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);


    QFormLayout *layout = new QFormLayout();
    layout->addWidget(l);
    layout->addWidget(le);
    layout->addWidget(btn_box);
    dialog.setLayout(layout);

    // В случае, если пользователь нажал "Ok".
    if(dialog.exec() == QDialog::Accepted) {
        char * pass = le->text().toLatin1().data();
        //strcpy(pass, );
        std::cout << "pass: " << (char*)pass << std::endl;
        //ts::setkey(pass);
        if(strlen(pass) > 0){

        }
    }
}

//конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

    //storage_test();
    //enc_test();

    showPassDialog(this);

    load();
    selectedtask = NULL;//&tasks[0];

    updateListW(ui);

}

//деконструктор
MainWindow::~MainWindow()
{
    delete ui;
}

//диалоговое окно с текстом ошибки
void showDialog(QWidget *p, QString msg){
    //виджет диалогового окна
    QDialog dialog(p);
    dialog.setWindowTitle("ошибка");
    dialog.setMinimumSize(340, 80);

    //надпись в окне
    QLabel *l = new QLabel(&dialog);
    l->setText(msg);

    //лейоут окна
    QFormLayout *layout = new QFormLayout();
    layout->addWidget(l);

    dialog.setLayout(layout);
    //показывает окно
    dialog.exec();
}

//обрабодчик события нажатия на кнопку сейв
void MainWindow::on_savebtn_clicked()
{
    //собираем информаию с виджетов
    QString name = ui->lineEdit->text();

    QString text = ui->textEdit->toPlainText();

    QDate date = ui->calendarWidget->selectedDate();
    QTime time = ui->timeEdit->time();
    QDateTime datetime = QDateTime(date, time);
    QDateTime current = QDateTime::currentDateTime();

    bool done = ui->checkBox->isChecked();

    //проверки
    if(current > datetime){
        showDialog(this, "нельзя создавать события в прошлом");
        return;
    }

    if(text.length() > ts::DISC_LEN){
        showDialog(this, "слишком длинное описание");
        return;
    }

    //заполнять поле описания не обязательно
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

    //срабатывет когда создается новая запись
    if(selectedtask == NULL){
        ts::Task task;
        task.expired = false;
        tasks.append(task);
        selectedtask = &tasks.last(); //tasks.end();
    }

    //обновляем запись
    strcpy(selectedtask->name, name.toStdString().c_str());
    strcpy(selectedtask->disc, text.toStdString().c_str());
    selectedtask->done = done;

    selectedtask->date = datetime.toTime_t();

    try {

        //сортировка по датам
        std::sort(tasks.begin(), tasks.end(), [&](ts::Task &a, ts::Task &b){ return a.date < b.date; });

        ts::Task task = *selectedtask;
        enc::encode((char*)selectedtask->name, (char*)&task.name, ts::NAME_LEN, ts::key, ts::KEY_LEN);
        enc::encode((char*)selectedtask->disc, (char*)&task.disc, ts::DISC_LEN, ts::key, ts::KEY_LEN);

        ts::save(tasks);

        //обновляем список
        updateListW(ui);

    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }
}

//очистка всех полей
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

//архивирование(експорт)
//обрабодчик события нажатия на кнопку експорт
void MainWindow::on_exportbtn_clicked()
{
    //диологовое окно выбора файла
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "C://",
                                                    tr("файлы архива (*.tarch)"));
    QFile::remove(fileName);
    QFile::copy(QString::fromStdString(ts::path), fileName);
}
//архивирование(импорт)
//обрабодчик события нажатия на кнопку импорт
void MainWindow::on_importbtn_clicked()
{
    //диологовое окно выбора файла
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C://",
                                                      tr("файлы архива (*.tarch)"));
    QFile::remove(QString::fromStdString(ts::path));
    QFile::copy(fileName ,QString::fromStdString(ts::path));

    load();
    updateListW(ui);
    clearUI(ui);
}

//обрабодчик события изменения текста в поле описания
void MainWindow::on_textEdit_textChanged()
{
    //обновление счетчика длинны текста
    QString text = ui->textEdit->toPlainText();
    int lenght = text.length();
    QString l;
    QTextStream(&l) << lenght << "/" << ts::DISC_LEN;

    //счетчик станет красным при привышении длинны
    if(lenght > ts::DISC_LEN){
        l = "<font color='#FF0000'>" + l + "</font>";
    }
    ui->charcount->setText(l);
}

//обрабодчик события изменения выбранной даты в календаре
void MainWindow::on_calendarWidget_selectionChanged()
{
    //сосавляем список планов на этот день
    QDate selected = ui->calendarWidget->selectedDate();
    QVector<ts::Task*> todaytasks;

    for (int i = 0; i < tasks.length(); i++) {
        if(QDateTime::fromTime_t(tasks[i].date).date() == selected){
            todaytasks.append(&tasks[i]);
        }
    }

    //обновляем виджет списком планов
    updateListW(ui, todaytasks);
}


//обрабодчик события нажатия на кнопку "на этой неделе"
void MainWindow::on_weekbtn_clicked()
{
    //сосавляем список планов на следующии 7 дней
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

    //обновляем виджет списком планов
    updateListW(ui, weektasks);
}

//обрабодчик события нажатия на кнопку "за все время"
void MainWindow::on_alltimebtn_clicked()
{
    updateListW(ui);
}



//обрабодчик события нажатия на элемент в ListWidget
void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    //находим указатель на запись по индексу
    int id = index.row();
    selectedtask = currshowed[id];

    //выводим информацию
    ui->lineEdit->setText(selectedtask->name);
    ui->textEdit->setText(selectedtask->disc);

    QDateTime dt = QDateTime::fromTime_t(selectedtask->date);
    ui->timeEdit->setTime(dt.time());
    ui->calendarWidget->setSelectedDate(dt.date());
    ui->calendarWidget->showSelectedDate();

    ui->checkBox->setChecked(selectedtask->done);
}

//обрабодчик события нажатия на кнопку new
void MainWindow::on_newbtn_clicked(bool checked)
{
    selectedtask = NULL;
    clearUI(ui);
}

//обрабодчик события нажатия на кнопку delete
void MainWindow::on_deletebtn_clicked()
{
    std::cout << selectedtask;
    if(selectedtask != NULL){
        try {
            tasks.erase(selectedtask);
            ts::save(tasks);

            selectedtask = NULL;
            clearUI(ui);
        } catch (char * somthing) {
             std::cout << somthing << std::endl;
        }
    }
}


