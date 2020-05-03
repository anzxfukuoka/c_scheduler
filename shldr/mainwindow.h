#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_savebtn_clicked();

    void on_exportbtn_clicked();

    void on_textEdit_textChanged();

    void on_calendarWidget_selectionChanged();

    void on_weekbtn_clicked();

    void on_alltimebtn_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_newbtn_clicked(bool checked);

    void on_deletebtn_clicked();

    void on_importbtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
