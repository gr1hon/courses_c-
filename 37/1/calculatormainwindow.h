//
// Created by grigo on 09.08.2023.
//

#ifndef QTTUTORIAL_CALCULATORMAINWINDOW_H
#define QTTUTORIAL_CALCULATORMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CalculatorMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    CalculatorMainWindow(QWidget *parent = nullptr): QMainWindow(parent){}
    QLineEdit* firstLineEdit = nullptr;
    QLineEdit* secondLineEdit = nullptr;
    QLineEdit* resultLineEdit = nullptr;
public slots:
    void addition()
    {
        int k = firstLineEdit->text().toInt() + secondLineEdit->text().toInt();
        QString s = QString::number(k);
        resultLineEdit->setText(s);
    };
    void subtraction()
    {
        int k = firstLineEdit->text().toInt() - secondLineEdit->text().toInt();
        QString s = QString::number(k);
        resultLineEdit->setText(s);
    };
    void multiplication()
    {
        int k = firstLineEdit->text().toInt() * secondLineEdit->text().toInt();
        QString s = QString::number(k);
        resultLineEdit->setText(s);
    };
    void division()
    {
        if (secondLineEdit->text().toFloat() != 0 ){
            float k = firstLineEdit->text().toFloat() / secondLineEdit->text().toFloat();
            QString s = QString::number(k);
            resultLineEdit->setText(s);
        } else
            resultLineEdit->setText("Division by zero!");
    };
};
#endif //QTTUTORIAL_CALCULATORMAINWINDOW_H
