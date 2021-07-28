#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    //避免一开始用户点击Send按钮，结果程序会无法正常运行
    pTcpServer = NULL;
    pTcpSocket = NULL;


    //指定父对象，让其自动回收该区域的空间
    pTcpServer = new QTcpServer(this);

    //绑定当前网卡的所有IP，和监听的端口
    pTcpServer->listen(QHostAddress::Any, 8888);

    //只要一建立连接成功，就会自动触发newConnection函数
    connect(pTcpServer, &QTcpServer::newConnection,
            [=]()
    {
        //取出建立好的连接套接字
        pTcpSocket = pTcpServer->nextPendingConnection();

        //获得客户端的IP和端口
        QString ip = pTcpSocket->peerAddress().toString();
        qint16 port = pTcpSocket->peerPort();
        QString temp = QString("[%1:%2]:The client connection is successful.").arg(ip).arg(port);

        ui->ServerOutput->setText(temp);


        //-----------------------------------------------------------------------------------------------
        //接收到了内容之后，直接在显示区域显示消息
        /**/ connect(pTcpSocket, &QTcpSocket::readyRead,
                     /**/        [=]()
                     /**/        {
            /**/           //从通信套接字中间取出内容
            /**/           QByteArray array = pTcpSocket->readAll();
            /**/           //QString temp2 = QString("");
            /**/           ui->ServerOutput->append("[Client:]" + array); //在后面追加新的消息
            /**/        }
        /**/        );
        //-----------------------------------------------------------------------------------------------
    }
    );

    connect(ui->ServerpushButton, &QPushButton::pressed,
            [=]()
    {
        QString str = "[Server:]" + ui->ServerInput->toPlainText();
        ui->ServerOutput->append(str); //在后面追加新的消息
    }
    );

}

ServerDialog::~ServerDialog()
{
    delete ui;
}


void ServerDialog::on_ServerpushButton_clicked()
{
    //获取编辑区域的内容
    QString str = ui->ServerInput->toPlainText();
    //给对方发送消息,编码使用utf8
    pTcpSocket->write(str.toUtf8().data());
}

void ServerDialog::on_ServerQuit_clicked()
{
    QString str ="Server quit and connection is over";
    ui->ServerOutput->append(str);
    pTcpSocket->write(str.toUtf8().data());
    pTcpSocket->disconnectFromHost();
    pTcpSocket->close();
}
