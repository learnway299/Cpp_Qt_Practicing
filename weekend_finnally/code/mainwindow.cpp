#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileIconProvider>
#include<QDir>
#include<QDebug>
#include<QTableWidget>
#include<QFileSystemWatcher>
#include<QDesktopServices>
#include<QUrl>
#include<QAction>
#include <QTextCodec>
#include"ZhToHead.h"
#include <windows.h>
#pragma comment(lib, "user32.lib")

#define HOT_KEY_SPACE_CTRL_M 0425

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 注册热键CTRL + Space
    if (RegisterHotKey(HWND(winId()),HOT_KEY_SPACE_CTRL_M, MOD_CONTROL, VK_SPACE))
    {
        //qDebug() << "注册热键  CTRL + SPACE ok.";
        qApp->installNativeEventFilter(this);
    }
    //获取Desktop路径
    deskPath=QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    //deskPath="C:\\Users\\1WQRMF3\\Desktop";
    setItem(deskPath);
    this->setWindowTitle("DeskTopSearch");
    ui->tablelist->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->tablelist->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
    m_pluginWatcher = new QFileSystemWatcher();
    m_pluginWatcher->addPath(deskPath);    // 添加监视文件的路径
    connect(m_pluginWatcher, SIGNAL(directoryChanged(QString)), this,SLOT(setItem(const QString &)));
    ui->tablelist->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tablelist, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenu(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setItem(const QString &dir_path)
{
    QStringList get_files;
    QFileIconProvider icon_provider;
    QDir dir(dir_path);
    if(!dir.exists())
    {
        qDebug() << "it is not true dir_path";
    }
    //设置过滤参数
    QFileInfoList info_list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    ui->tablelist->setRowCount(info_list.count());//行数
    ui->tablelist->setColumnCount(5);//列数
    ui->tablelist->setFrameShape(QFrame::NoFrame);

    for(int i= 0 ; i< info_list.count(); i++)
    {
        QFileInfo info = info_list.at(i);
        QIcon icon=icon_provider.icon(info);//文件图标
        QString file_name =info.fileName();//文件名称
        QString filetype=icon_provider.type(info);//文件类型
        QString filepath=info.absoluteFilePath();//文件路径
        QString filesize = QString::number(info.size())+QString("bytes");//文件大小
        QString tmpfile;
        getHeadbyCH(file_name,tmpfile);
        //qDebug()<<tmpfile<<filesize;
        ui->tablelist->setItem(i,0,new QTableWidgetItem(icon,file_name));
        ui->tablelist->setItem(i,1,new QTableWidgetItem(filetype));
        ui->tablelist->setItem(i,2,new QTableWidgetItem(filepath));
        ui->tablelist->setItem(i,3,new QTableWidgetItem(filesize));
        ui->tablelist->setItem(i,4,new QTableWidgetItem(tmpfile));
        ui->tablelist->setColumnHidden(4,true);//索引列设置用户不可见
    }
}

bool MainWindow::compareStr(QString &a, QString &b)
{
    int flg = 0;
    int i = 0;
    for ( int j = 0; j < b.size(); j++) {
        if (a[i] == b[j]) {
            flg += 1;
            i++;
        }
    }
    if (flg == a.size())
        return true;
    else
        return false;
}

void MainWindow::ui_init()
{
    for(int i=0;i<ui->tablelist->rowCount();i++){
        ui->tablelist->setRowHidden(i,false);
    }
}

void MainWindow::customMenu(QPoint)
{
    QMenu *menu= new QMenu(this); //添加菜单
    QAction *ope = new QAction("打开", this);
    QAction *del = new QAction("删除", this);
    menu->setTitle("选项");
    menu->addAction(ope); //添加动作
    menu->addSeparator();//添加分割线
    menu->addAction(del);//添加动作
    //创建动作和要执行的槽函数连接QObject::
    connect(ope,SIGNAL(triggered()),this,SLOT(openSlot()));
    connect(del,SIGNAL(triggered()),this,SLOT(deleteSlot()));
    menu->exec(QCursor::pos()); //在光标当前位置处出现

}

void MainWindow::openSlot()
{
    int tmprow=ui->tablelist->currentRow();
    QString filep=ui->tablelist->item(tmprow,2)->text();
    //qDebug()<<"openSlot()"<<filep;
    QDesktopServices::openUrl(QUrl::fromLocalFile(filep));

}

void MainWindow::deleteSlot()
{
    int tmprow=ui->tablelist->currentRow();
    QString filep=ui->tablelist->item(tmprow,2)->text();
    //qDebug()<<"deleteSlot()"<<filep;
    DeleteFileOrFolder(filep);
}

bool MainWindow::DeleteFileOrFolder(const QString &strPath)
{
    if( strPath.isEmpty() || !QDir().exists( strPath ) )
        return false;

    QFileInfo fileInfo( strPath );

    if( fileInfo.isFile() )
        QFile::remove( strPath );
    else if( fileInfo.isDir() )
    {
        QDir qDir( strPath );
        qDir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
        QFileInfoList fileInfoLst = qDir.entryInfoList();
        foreach( QFileInfo qFileInfo, fileInfoLst )
        {
            if( qFileInfo.isFile() )
                qDir.remove( qFileInfo.absoluteFilePath() );
            else
            {
                DeleteFileOrFolder( qFileInfo.absoluteFilePath() );
                qDir.rmdir( qFileInfo.absoluteFilePath() );
            }
        }
        qDir.rmdir( fileInfo.absoluteFilePath() );
    }

    return true;
}

bool MainWindow::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG") {
        MSG * pMsg = reinterpret_cast<MSG *>(message);
        if(((WM_HOTKEY == pMsg->message) && (MOD_CONTROL== (UINT)LOWORD(pMsg->lParam))&& (VK_SPACE == (UINT)HIWORD(pMsg->lParam))))
        {
            openflg=!openflg;
            //qDebug() << "热键  CTRL + SPACE active.";
            if(openflg){
                this->show();
                return true;
            }else{
                this->hide();
                return true;
            }
        }
        return false;
    }
}


void MainWindow::on_search_clicked()
{
    ui_init();
    QString temfilename;
    bool flg=false;
    if(!ui->lineEdit->text().isEmpty()){
        getHeadbyCH(ui->lineEdit->text(),searchitem);
        for(int i=0;i<ui->tablelist->rowCount();i++){
            temfilename=ui->tablelist->item(i,4)->text();
            flg=compareStr(searchitem,temfilename);
            //qDebug()<<temfilename<<flg;
            if(!flg){
                ui->tablelist->setRowHidden(i,true);}
        }
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui_init();
    QString temfilename;
    bool flg=false;
    if(!arg1.isEmpty()){
        getHeadbyCH(arg1,searchitem);
        for(int i=0;i<ui->tablelist->rowCount();i++){
            temfilename=ui->tablelist->item(i,4)->text();
            flg=compareStr(searchitem,temfilename);
            //            qDebug()<<temfilename<<searchitem<<flg;
            if(!flg){
                ui->tablelist->setRowHidden(i,true);}
        }
    }
}
