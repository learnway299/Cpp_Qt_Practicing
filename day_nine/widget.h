#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void sig_caladd(int, int);
    void sig_calsubtraction(int, int);

public slots:
    void slot_caladd();//点击+处理函数
    void slot_calsubtraction();//点击-处理函数
    void slot_caldel();//点击C处理函数
    void slot_calout();//点击=处理函数
    void slot_cal1();//点击1处理函数
    void slot_cal2();//点击2处理函数
    void slot_cal3();//点击3处理函数
    void slot_cal4();//点击4处理函数
    void slot_cal5();//点击5处理函数
    void slot_cal6();//点击6处理函数
    void slot_cal7();//点击7处理函数
    void slot_cal8();//点击8处理函数
    void slot_cal9();//点击9处理函数
private:
    Ui::Widget *ui;
    bool flg; //标记符号
    int num; //运算结果
    QString str; //运算过程
};
#endif // WIDGET_H
