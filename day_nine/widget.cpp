#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->flg=true;
    this->num=0;
    this->str="";
    ui->setupUi(this);
    //点击+ - C =处理
    connect(ui->pushButton01,SIGNAL(clicked(bool)),this,SLOT(slot_caladd()));
    connect(ui->pushButton02,SIGNAL(clicked(bool)),this,SLOT(slot_calsubtraction()));
    connect(ui->pushButton03,SIGNAL(clicked(bool)),this,SLOT(slot_caldel()));
    connect(ui->pushButton04,SIGNAL(clicked(bool)),this,SLOT(slot_calout()));
    //点击1-9处理
    connect(ui->pushButton1,SIGNAL(clicked(bool)),this,SLOT(slot_cal1()));
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(slot_cal2()));
    connect(ui->pushButton3,SIGNAL(clicked(bool)),this,SLOT(slot_cal3()));
    connect(ui->pushButton4,SIGNAL(clicked(bool)),this,SLOT(slot_cal4()));
    connect(ui->pushButton5,SIGNAL(clicked(bool)),this,SLOT(slot_cal5()));
    connect(ui->pushButton6,SIGNAL(clicked(bool)),this,SLOT(slot_cal6()));
    connect(ui->pushButton7,SIGNAL(clicked(bool)),this,SLOT(slot_cal7()));
    connect(ui->pushButton8,SIGNAL(clicked(bool)),this,SLOT(slot_cal8()));
    connect(ui->pushButton9,SIGNAL(clicked(bool)),this,SLOT(slot_cal9()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_caladd()
{
    this->flg=true;
    this->str=this->str+"+";
    ui->result->setText(str);
}

void Widget::slot_calsubtraction()
{
    this->flg=false;
    this->str=this->str+"-";
    ui->result->setText(str);
}

void Widget::slot_caldel()
{
    this->flg=true;
    this->num=0;
    this->str="";
    ui->result->setText(str);
}

void Widget::slot_calout()
{
    this->str=QString::number(this->num);
    ui->result->setText(this->str);
}

void Widget::slot_cal1()
{
    if(this->flg){
        this->num+=1;
    }else{
        this->num-=1;
    }
    this->str=this->str+QString::number(1);
    ui->result->setText(str);
}

void Widget::slot_cal2()
{
    if(this->flg){
        this->num+=2;
    }else{
        this->num-=2;
    }
    this->str=this->str+QString::number(2);
    ui->result->setText(str);
}

void Widget::slot_cal3()
{
    if(this->flg){
        this->num+=3;
    }else{
        this->num-=3;
    }
    this->str=this->str+QString::number(3);
    ui->result->setText(str);
}

void Widget::slot_cal4()
{
    if(this->flg){
        this->num+=4;
    }else{
        this->num-=4;
    }
    this->str=this->str+QString::number(4);
    ui->result->setText(str);
}

void Widget::slot_cal5()
{
    if(this->flg){
        this->num+=5;
    }else{
        this->num-=5;
    }
    this->str=this->str+QString::number(5);
    ui->result->setText(str);
}

void Widget::slot_cal6()
{
    if(this->flg){
        this->num+=6;
    }else{
        this->num-=6;
    }
    this->str=this->str+QString::number(6);
    ui->result->setText(str);
}

void Widget::slot_cal7()
{
    if(this->flg){
        this->num+=7;
    }else{
        this->num-=7;
    }
    this->str=this->str+QString::number(7);
    ui->result->setText(str);
}

void Widget::slot_cal8()
{
    if(this->flg){
        this->num+=8;
    }else{
        this->num-=8;
    }
    this->str=this->str+QString::number(8);
    ui->result->setText(str);
}

void Widget::slot_cal9()
{
    if(this->flg){
        this->num+=9;
    }else{
        this->num-=9;
    }
    this->str=this->str+QString::number(9);
    ui->result->setText(str);
}
