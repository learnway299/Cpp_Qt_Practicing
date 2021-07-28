#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QTcpSocket> //通信套接字

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = nullptr);
    ~ClientDialog();

private slots:
    //给服务器发送消息
    void on_ClientpushButton_clicked();
    //断开连接
    void on_ClientQuit_clicked();
    //和服务器建立连接
    void on_connect_clicked();

private:
    Ui::ClientDialog *ui;
    QTcpSocket *pTcpSocket;
};

#endif // CLIENTDIALOG_H
