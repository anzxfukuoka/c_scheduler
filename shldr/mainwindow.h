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

    void on_loadbtn_clicked();

    void on_exportbtn_clicked();

    void on_textEdit_textChanged();

    void on_charcount_linkHovered(const QString &link);

    void on_dateTimeEdit_dateChanged(const QDate &date);

    void on_scrollArea_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
