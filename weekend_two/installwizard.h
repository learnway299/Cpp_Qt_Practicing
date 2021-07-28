#ifndef INSTALLWIZARD_H
#define INSTALLWIZARD_H

#include <QWizard>

namespace Ui {
class InstallWizard;
}

class InstallWizard : public QWizard
{
    Q_OBJECT

public:
    explicit InstallWizard(QWidget *parent = nullptr);
    ~InstallWizard();
    virtual bool validateCurrentPage() override;//不同意协议禁用


public slots:

    void slot_ProgressValue();//进度条
    void on_agreecheck_clicked();//处理是否同意用户协议

    void on_allUser_stateChanged(int arg1);//处理标记用户

    void on_currentUser_stateChanged(int arg1);//处理标记用户

    void on_checkBoxDoc_stateChanged(int arg1);//处理是否兼容DOC、XLS、PPT

    void on_checkBoxEpue_stateChanged(int arg1);//处理是否兼容EPUBE

    void on_checkBoxPdf_stateChanged(int arg1);//处理是否兼容PDF

    void on_checkBoxPng_stateChanged(int arg1);//处理是否兼容PNG、JEPG

    void on_Install_clicked();//处理是否安装

    void on_comboBoxChoose_activated(int index);//处理激活方式

    void on_activationButton_clicked();//处理激活

    void on_skipcheck_clicked();//处理是否跳过激活



private:
    Ui::InstallWizard *ui;
    int flg00=0;//标记是否同意用户协议 1同意
    int flg01=0;//标记是否跳过激活
    int fla02=0;//标记用户 0当前用户 1所有用户
    int fla10=0;//标记是否兼容DOC、XLS、PPT
    int fla11=0;//标记是否兼容PDF
    int fla12=0;//标记是否兼容PNG、JEPG
    int fla13=0;//标记是否兼容EPUBE

    int flg30=0;//标记激活方式
    bool flg31=false;//标记是否成功激活;
    QString InstallPath;
    QString Activation="ESDDX-SDFGB-YGCXS-DDFCC";
    QString account="kingsoft@kin.com";
    QString password="kingsoft";

};

#endif // INSTALLWIZARD_H
