#include "kmyloghandler.h"
#include "ui_kmyloghandler.h"
#include <QTextStream>
#include <QDataStream>
#include<QFileDialog>
#include<QDebug>
#include <QDateTime>
#include <iostream>
using namespace std;
#include<QString>
#include<QFileSystemWatcher>

KMyLogHandler::KMyLogHandler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KMyLogHandler)
{
    //监控日志文件
    //    QFileSystemWatcher* watcher;
    watcher = new QFileSystemWatcher();
    watcher->addPath(fileName1);
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &KMyLogHandler::outputlog);

    inputTolog(QString(" 软件打开 "));
    ui->setupUi(this);
    inputTolog(QString(" 初始化成功  "));
}

KMyLogHandler::~KMyLogHandler()
{
    inputTolog(QString(" 软件退出 "));
    delete ui;
}

void KMyLogHandler::on_tofileButton_clicked()
{
    //写入文本文件
    QString fileName= QFileDialog::getOpenFileName();
    QFile file(fileName);
    QString input=ui->tofileEdit->toPlainText();
    if (file.open(QIODevice::Append)){
        file.write(input.toStdString().c_str());
        file.close();
    }
    QString tolog(" 写入到文本文件 ");
    inputTolog(tolog.append(fileName));
}

void KMyLogHandler::on_tobinaryButton_clicked()
{
    //写入二进制文件
    QString fileName= QFileDialog::getOpenFileName();
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << ui->tobinaryEdit->toPlainText();
        file.close();
    }
    QString tolog("写入到二进制文件 ");
    inputTolog(tolog.append(fileName));
}

void KMyLogHandler::on_fromfileButton_clicked()
{
    //读取文本文件
    QString fileName= QFileDialog::getOpenFileName();
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray content = file.readAll();
        ui->fromfileBrowser->setText(content);
        //打开和关闭一定要成对操作，打开后必须要关闭
        file.close();
    }
    else
    {
        qDebug() << "Open Failed!";
    }
    QString tolog=(" 读取文本文件 ");
    inputTolog(tolog.append(fileName));
}

void KMyLogHandler::on_frombinaryButton_clicked()
{
    //读取二进制文件
    QString fileName= QFileDialog::getOpenFileName();
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        QString str;
        in >> str;
        file.close();
        ui->frombinaryBrowser->setText(str);
    }
    QString tolog(" 读取二进制文件 ");
    inputTolog(tolog.append(fileName));
}

void KMyLogHandler::inputTolog(QString input)
{
    QString nowtime=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzzz ");
    QString fileName2("log.tmp");//暂存日志文件
    QFile file1(fileName1);
    QFile file2(fileName2);
    //实现追加到第一行
    if (file2.open(QIODevice::Append)){
        file2.write((nowtime.append(input)+"\n").toStdString().c_str());
        //循环多行读取：
        if (file1.open(QIODevice::ReadOnly))
        {
            while (!file1.atEnd())
            {
                QByteArray lineArray = file1.readLine();
                file2.write(lineArray);
            }
            file1.close();
        }
        file2.close();
    }
    //写文件 覆盖原有内容
    if (file1.open(QIODevice::WriteOnly| QFile::Truncate))
    {
        if (file2.open(QIODevice::ReadOnly))
        {
            while (!file2.atEnd())
            {
                QByteArray lineArray = file2.readLine();
                file1.write(lineArray);
            }
            file2.close();
        }
        file1.close();
    }
    //删除暂存日志文件
    file2.open(QFile::WriteOnly | QFile::Truncate);
    file2.close();
}

void KMyLogHandler::outputlog()
{
    QFile file1(fileName1);
    if (file1.open(QIODevice::ReadOnly))
    {
        QByteArray content = file1.readAll();
        ui->output->setText(content);
        file1.close();
    }
}
