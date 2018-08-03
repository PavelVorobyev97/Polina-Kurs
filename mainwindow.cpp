#include "Film.h"
#include "Library.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QDebug>
#include <QTextEdit>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    horizontalHeader.append("Фильм");
    horizontalHeader.append("Жанр");
    horizontalHeader.append("Год");
    horizontalHeader.append("Режиссер");
    horizontalHeader.append("Студия");
    horizontalHeader.append("Актеры");
    model->setHorizontalHeaderLabels(horizontalHeader);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int i = ui->spinBox->text().toInt();
    qDebug()<<i;
    Library tmp(i);
    num = i;
    lib = tmp;
    count = 0;
    if(i > 0)
    {
        ui->pushButton_2->setDisabled(false);
        ui->pushButton_3->setDisabled(false);
        ui->pushButton_4->setDisabled(false);
        ui->pushButton_2->setText("Добавить " + QString::number(0) + "/" + QString::number(num));
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    if(count < num && ui->lineEdit_3->text().toInt() > 1900)
    {
        ui->pushButton_2->setText("Добавить " + QString::number(count+1) + "/" + QString::number(num));
        lib.arr[count].name = ui->lineEdit->text().toLower();
        lib.arr[count].genre = ui->lineEdit_2->text().toLower();
        lib.arr[count].year = ui->lineEdit_3->text().toLower();
        lib.arr[count].director = ui->lineEdit_4->text().toLower();
        lib.arr[count].studio = ui->lineEdit_5->text().toLower();
        lib.arr[count].actors = ui->lineEdit_7->text().split(';');
        qDebug()<<lib.arr[count].actors;



        lib.arr[count].name.replace(0, 1,lib.arr[count].name.at(0).toUpper());
        lib.arr[count].genre.replace(0, 1,lib.arr[count].genre.at(0).toUpper());
        lib.arr[count].director.replace(0, 1,lib.arr[count].director.at(0).toUpper());
        lib.arr[count].studio.replace(0, 1,lib.arr[count].studio.at(0).toUpper());

        item = new QStandardItem(lib.arr[count].name);
        model->setItem(count, 0, item);

        item = new QStandardItem(lib.arr[count].genre);
        model->setItem(count, 1, item);

        item = new QStandardItem(lib.arr[count].year);
        model->setItem(count, 2, item);

        item = new QStandardItem(lib.arr[count].director);
        model->setItem(count, 3, item);

        item = new QStandardItem(lib.arr[count].studio);
        model->setItem(count, 4, item);

        item = new QStandardItem(lib.arr[count].actors.join('\n'));
        model->setItem(count, 5, item);

        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        count++;

    }else{
        QMessageBox msgBox;
        msgBox.setText("Введите корректные данные");
        msgBox.exec();
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_7->clear();

}

void MainWindow::on_pushButton_3_clicked()
{
    lib.sort();
    for(int i = 0; i < num; i++)
    {
        item = new QStandardItem(lib.arr[i].name);
        model->setItem(i, 0, item);

        item = new QStandardItem(lib.arr[i].genre);
        model->setItem(i, 1, item);

        item = new QStandardItem(lib.arr[i].year);
        model->setItem(i, 2, item);

        item = new QStandardItem(lib.arr[i].director);
        model->setItem(i, 3, item);

        item = new QStandardItem(lib.arr[i].studio);
        model->setItem(i, 4, item);

        item = new QStandardItem(lib.arr[i].actors.join('\n'));
        model->setItem(i, 5, item);

        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString tmp = " ";
    tmp = QInputDialog::getText(nullptr,"Изменение","Введите новые данные: ", QLineEdit::Normal);
    tmp.replace(0, 1, tmp.at(0).toUpper());

    if(index.column() == 0)  lib.arr[index.row()].name = tmp;
    if(index.column() == 1)  lib.arr[index.row()].genre = tmp;
    if(index.column() == 2)
    {
        while(tmp.toInt() < 1900 || tmp.toInt() > 3000)
        {
            tmp = QInputDialog::getText(nullptr,"Изменение","Введите корректный год: ", QLineEdit::Normal);
        }
        lib.arr[index.row()].year = tmp;
    }
    if(index.column() == 3)  lib.arr[index.row()].director = tmp;
    if(index.column() == 4)  lib.arr[index.row()].studio = tmp;
    if(index.column() == 5)  lib.arr[index.row()].actors = tmp.split(';');


    for(int i = 0; i < num; i++)
    {
        item = new QStandardItem(lib.arr[i].name);
        model->setItem(i, 0, item);

        item = new QStandardItem(lib.arr[i].genre);
        model->setItem(i, 1, item);

        item = new QStandardItem(lib.arr[i].year);
        model->setItem(i, 2, item);

        item = new QStandardItem(lib.arr[i].director);
        model->setItem(i, 3, item);

        item = new QStandardItem(lib.arr[i].studio);
        model->setItem(i, 4, item);

        item = new QStandardItem(lib.arr[i].actors.join('\n'));
        model->setItem(i, 5, item);


        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();

    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QString dir, year, genre, list;
    dir = QInputDialog::getText(nullptr,"Поиск","Введите режиссера: ", QLineEdit::Normal).toLower();
   // dir.replace(0, 1, dir.at(0).toUpper());

    year = QInputDialog::getText(nullptr,"Поиск","Введите год: ", QLineEdit::Normal);

    genre = QInputDialog::getText(nullptr,"Поиск","Введите жанр: ", QLineEdit::Normal).toLower();
   // genre.replace(0, 1, genre.at(0).toUpper());

    for(int i = 0; i < num; i++)
    {
        if(dir.toLower() == lib.arr[i].director.toLower() && genre.toLower() == lib.arr[i].genre.toLower() && year.toLower() == lib.arr[i].year.toLower()){
            list.append(lib.arr[i].name + "; ");
        }
    }
    ui->lineEdit_6->setText(list);
}
