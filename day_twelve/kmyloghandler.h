#ifndef KMYLOGHANDLER_H
#define KMYLOGHANDLER_H
#include <QMainWindow>
#include <time.h>
#include<QFileSystemWatcher>

QT_BEGIN_NAMESPACE
namespace Ui { class KMyLogHandler; }
QT_END_NAMESPACE

class KMyLogHandler : public QMainWindow
{
    Q_OBJECT

public:
    KMyLogHandler(QWidget *parent = nullptr);//打开
    ~KMyLogHandler(); //关闭

private slots:
    void on_tofileButton_clicked();//文本格式写

    void on_tobinaryButton_clicked();//二进制写

    void on_fromfileButton_clicked();//文本格式读

    void on_frombinaryButton_clicked();//二进制读

    void inputTolog(QString);//记录到日志文件
    void outputlog();//监控日志文件

private:
    Ui::KMyLogHandler *ui;
    QString fileName1=("log.txt");//日志文件
    QFileSystemWatcher *watcher;

};

#endif // KMYLOGHANDLER_H
