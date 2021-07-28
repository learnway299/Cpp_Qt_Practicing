#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include<QFile>
#include<QString>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->ouput,SIGNAL(clicked(bool)),this,SLOT(on_ouput_clicked()));
    this->setFixedSize(600, 627);
    // this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    //实现可拖动
    this->setSizeGripEnabled(true);

    ui->label1->setText(tr("Page output"));
    ui->label12->setText(tr("Page converge"));
    ui->label21->setText(tr("The watermark"));
    ui->label22->setText(tr("Save to"));
    ui->label23->setText(tr("Picture quality"));
    ui->label24->setText(tr("Image format"));
    ui->lineEdit1->setText(tr("Secret Samples Forbidden to copy"));
    ui->lineEdit_2->setText(QString::fromStdString("D:"));




    loadStyleSheet(tr("main"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/res/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void Dialog::on_pushButton_clicked()
{
    QString SavePath = QFileDialog::getExistingDirectory();
    ui->lineEdit_2->setText(SavePath);
}

void Dialog::on_ouput_clicked()
{

}
