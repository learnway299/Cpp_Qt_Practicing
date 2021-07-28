#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>  //监听套接字
#include <QTcpSocket>  //通信套接字

QT_BEGIN_NAMESPACE
namespace Ui { class ServerDialog; }
QT_END_NAMESPACE

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    ServerDialog(QWidget *parent = nullptr);
    ~ServerDialog();

private slots:
    //给客户端发送消息
    void on_ServerpushButton_clicked();
    //断开连接
    void on_ServerQuit_clicked();

private:
    Ui::ServerDialog *ui;
    QTcpServer *pTcpServer;
    QTcpSocket *pTcpSocket;
};
#endif // SERVERDIALOG_H
