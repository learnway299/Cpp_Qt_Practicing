#include "clientdialog.h"
#include "ui_clientdialog.h"
#include<QString>
#include <QHostAddress>

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    //    QString ip=("127.0.0.1");
    //    qint16 port = 8888;

    pTcpSocket = NULL;
    //分配空间，指定父对象
    pTcpSocket = new QTcpSocket(this);
    //弹出来一个提示而已
    connect(pTcpSocket, &QTcpSocket::connected,
            [=]()
    {
        ui->ClientOutput->setText("The connection server is successful.");
    }
    );

    //显示来自服务器的消息
    connect(pTcpSocket, &QTcpSocket::readyRead,
            [=]()
    {
        //从通信套接字中间取出内容
        QByteArray array = pTcpSocket->readAll();
        //QString temp2 = QString("");
        ui->ClientOutput->append("[Server:]" + array); //在后面追加新的消息
    }
    );

    connect(ui->ClientpushButton, &QPushButton::pressed,
            [=]()
    {
        QString str = "[Client:]" + ui->ClientInput->toPlainText();
        ui->ClientOutput->append(str); //在后面追加新的消息
    }
    );
}

ClientDialog::~ClientDialog()
{
    delete ui;
}

void ClientDialog::on_ClientpushButton_clicked()
{
    //获取编辑区域的内容
    QString str = ui->ClientInput->toPlainText();
    //给对方发送消息,编码使用utf8
    pTcpSocket->write(str.toUtf8().data());
}

void ClientDialog::on_ClientQuit_clicked()
{
    QString str ="Client quit and connection is over";
    ui->ClientOutput->append(str);
    pTcpSocket->write(str.toUtf8().data());
    pTcpSocket->disconnectFromHost();
}

void ClientDialog::on_connect_clicked()
{
    pTcpSocket->connectToHost(QHostAddress("127.0.0.1"),8888);

}
