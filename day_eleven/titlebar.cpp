#include "titlebar.h"
#include "ui_titlebar.h"

Titlebar::Titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Titlebar)
{
    ui->setupUi(this);
    this->setFixedSize(600,30);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label->setText(tr("Output as picture"));
    connect(ui->clostBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

Titlebar::~Titlebar()
{
    delete ui;
}
