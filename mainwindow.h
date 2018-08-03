#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include "film.h"
#include "library.h"
#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QDebug>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //создание библиотеки
    int num;
    int count = 0;
    Library lib;
    QString data;

    //для таблицы
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    QStringList horizontalHeader;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
