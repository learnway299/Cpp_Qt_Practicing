#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemWatcher>
#include<QAbstractNativeEventFilter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow ,public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool compareStr(QString& a, QString& b);//判别字符串是否匹配
    void ui_init();//取消行隐藏
    bool DeleteFileOrFolder( const QString& strPath );//删除
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;//捕获热键信号并处理


private slots:
    void setItem(const QString &dir_path);//获取文件信息
    void on_search_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void openSlot();//菜单打开
    void deleteSlot();//菜单删除
    void customMenu(QPoint); //meau
private:
    Ui::MainWindow *ui;
    QString searchitem;//输入路径
    QString deskPath;//桌面路径
    QFileSystemWatcher *m_pluginWatcher;//监视文件夹变化
    bool openflg=true;
};
#endif // MAINWINDOW_H
