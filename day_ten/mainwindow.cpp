#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setViewport(50, 50, width() - 100, height() - 100);
    // painter.setWindow(-10, 4, 20, -8);
    painter.fillRect( 50, 50, width() - 100, height() - 100,Qt::white);
    drawOlympicrings();
}

void MainWindow::drawOlympicrings()
{
    QPainter painter(this);
    painter.setViewport(50, 50, width() - 100, height() - 100);

    QFont font("Courier", 24);
    painter.setFont(font);
    painter.drawText(width() / 2 -60, height() / 2 -60, "The Olympic Games");

    painter.setPen(QPen(QBrush(Qt::blue), 1));
    QRectF rectangle1(width() / 2, height() / 2, 100, 100);
    painter.drawEllipse(rectangle1);

    painter.setPen(QPen(QBrush(Qt::black), 1));
    QRectF rectangle2(width() / 2 + 120, height() / 2, 100, 100);
    painter.drawEllipse(rectangle2);

    painter.setPen(QPen(QBrush(Qt::red), 1));
    QRectF rectangle3(width() / 2  + 240, height() / 2, 100, 100);
    painter.drawEllipse(rectangle3);

    painter.setPen(QPen(QBrush(Qt::yellow), 1));
    QRectF rectangle4(width() / 2 +60, height() / 2 - 50, 100, 100);
    painter.drawEllipse(rectangle4);

    painter.setPen(QPen(QBrush(Qt::green), 1));
    QRectF rectangle5(width() / 2 + 180, height() / 2 - 50, 100, 100);
    painter.drawEllipse(rectangle5);
}
