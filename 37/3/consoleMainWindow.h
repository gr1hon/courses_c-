//
// Created by grigo on 10.08.2023.
//

#ifndef QT_CONSOLE_CONSOLEMAINWINDOW_H
#define QT_CONSOLE_CONSOLEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QPushButton>

class ConsoleMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    ConsoleMainWindow(QWidget *parent = nullptr): QMainWindow(parent){}
    QLineEdit* volume_lineEdit = nullptr;
    QLineEdit* channel_lineEdit = nullptr;
public slots:
    void set0()
    {
        channel_lineEdit->setText("0");
    }
    void set1()
    {
        channel_lineEdit->setText("1");
    }
    void set2()
    {
        channel_lineEdit->setText("2");
    }
    void set3()
    {
        channel_lineEdit->setText("3");
    }
    void set4()
    {
        channel_lineEdit->setText("4");
    }
    void set5()
    {
        channel_lineEdit->setText("5");
    }
    void set6()
    {
        channel_lineEdit->setText("6");
    }
    void set7()
    {
        channel_lineEdit->setText("7");
    }
    void set8()
    {
        channel_lineEdit->setText("8");
    }
    void set9()
    {
        channel_lineEdit->setText("9");
    }
    void next_channel()
    {
        int k = channel_lineEdit->text().toInt();
        if (k < 9){
            channel_lineEdit->setText(QString::number(k+1));
        }
    }
    void prev_channel()
    {
        int k = channel_lineEdit->text().toInt();
        if (k > 0){
            channel_lineEdit->setText(QString::number(k-1));
        }
    }
    void volume_add()
    {
        int k = volume_lineEdit->text().toInt();
        if (k < 100){
            volume_lineEdit->setText(QString::number(k+10));
        }
    }
    void volume_sub()
    {
        int k = volume_lineEdit->text().toInt();
        if (k > 0){
            volume_lineEdit->setText(QString::number(k-10));
        }
    }
};
#endif //QT_CONSOLE_CONSOLEMAINWINDOW_H
