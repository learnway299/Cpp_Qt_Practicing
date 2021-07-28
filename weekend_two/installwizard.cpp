#include <QFileDialog>
#include <QDebug>
#include "installwizard.h"
#include "ui_installwizard.h"
#include<QThread>
InstallWizard::InstallWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::InstallWizard)
{
    this->setWindowTitle("安装向导");
    this->setButtonText(this->CancelButton,"取消");
    this->setButtonText(this->NextButton,"下一步~");
    this->setButtonText(this->FinishButton,"完成 ");
    ui->setupUi(this);

    connect(ui->agreecheck, SIGNAL(clicked()), this, SLOT(on_agreecheck_clicked()));
    connect(ui->allUser, SIGNAL(stateChanged(int)), this, SLOT(on_allUser_stateChanged(int)));
    connect(ui->currentUser, SIGNAL(stateChanged(int)), this, SLOT(on_currentUser_stateChanged(int)));
    connect(ui->checkBoxDoc, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxDoc_stateChanged(int)));
    connect(ui->checkBoxEpue, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxEpue_stateChanged(int)));
    connect(ui->checkBoxPdf, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxPdf_stateChanged(int)));
    connect(ui->checkBoxPng, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxPng_stateChanged(int)));
    connect(ui->Install,SIGNAL(clicked(bool)),this,SLOT(on_Install_clicked()));
    connect(ui->comboBoxChoose, SIGNAL(activated(int)), this, SLOT(on_comboBoxChoose_activated(int)));
    connect(ui->activationButton,SIGNAL(clicked(bool)),this,SLOT(on_activationButton_clicked()));
    connect(ui->skipcheck,SIGNAL(clicked(bool)),this,SLOT(on_skipcheck_clicked()));
    connect(ui->ProgressValue,SIGNAL(clicked()),this,SLOT(slot_ProgressValue()));

}

InstallWizard::~InstallWizard()
{
    delete ui;
}

bool InstallWizard::validateCurrentPage()
{
    if(currentId()==0){
        if(flg00==0){
            return false;
        }else {return true;}
    }else
    {return true;}
}

void InstallWizard::slot_ProgressValue()
{
    ui->progressBar->setRange(0,100);
    QString installFilepath="C:\\Windows\\Panther\\UnattendGC";//输出文件目录
    QDir *dir = new QDir(installFilepath) ;
    QStringList filter;
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    for(int i=0;i<fileInfo->count() ;i++)
    {
        QThread::sleep(1);
        int value=static_cast<int>((static_cast<double>(i)/fileInfo->count())*100);
        ui->progressBar->setValue(value);
        ui->outputFilename->append(fileInfo->at(i).absoluteFilePath());
    }
    ui->progressBar->setValue(100);
}

void InstallWizard::on_agreecheck_clicked()
{
    flg00=1;
}

void InstallWizard::on_allUser_stateChanged(int arg1)
{
    flg01=arg1;
}

void InstallWizard::on_currentUser_stateChanged(int arg1)
{
    if(arg1)
        flg01=0;
}

void InstallWizard::on_checkBoxDoc_stateChanged(int arg1)
{
    fla10=arg1;
}

void InstallWizard::on_checkBoxEpue_stateChanged(int arg1)
{
    fla13=arg1;
}

void InstallWizard::on_checkBoxPdf_stateChanged(int arg1)
{
    fla11=arg1;
}

void InstallWizard::on_checkBoxPng_stateChanged(int arg1)
{
    fla12=arg1;
}

void InstallWizard::on_Install_clicked()
{
    InstallPath = QFileDialog::getExistingDirectory();
    ui->installPath->setText(InstallPath) ;
}
void InstallWizard::on_comboBoxChoose_activated(int index)
{
    flg30=index;
}

void InstallWizard::on_activationButton_clicked()
{
    if(flg30){
        QString tmp=ui->orderLineEdit->text();
        if(Activation==tmp){
            flg31=true;
        }
    }else{
        QString accounttmp=ui->accountLineEdit->text();
        QString passwordtmp=ui->passwordLineEdit->text();
        if(account==accounttmp&&passwordtmp==password){
            flg31=true;
        }
    }
}
void InstallWizard::on_skipcheck_clicked()
{
    flg31=false;
}
