#include "mainwindow.h"
#include "ui_mainwindow.h"

#define HEIGHT 400
#define WIDTH 600
#define DISPLAYNORMAL 0
#define BRESENHAM 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        algNormalOuBresenham = DISPLAYNORMAL;
    } else {
        algNormalOuBresenham = BRESENHAM;
    }
    rgb[0] = ui->lineEdit->text().toFloat();
    rgb[1] = ui->lineEdit_2->text().toFloat();
    rgb[2] = ui->lineEdit_3->text().toFloat();
    tamanho = ui->lineEdit_4->text().toInt();
}

void MainWindow::on_pushButton2_clicked()
{
    desfazer = true;
}

void MainWindow::on_pushButton3_clicked()
{
    limparTela = true;
}

