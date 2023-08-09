#include <QApplication>
#include <QMainWindow>
#include "calculatormainwindow.h"
#include "./ui_calculator.h"
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.firstLineEdit = calculator.lineEdit_2;
    window.secondLineEdit = calculator.lineEdit;
    window.resultLineEdit = calculator.lineEdit_3;
    window.resize(480, 640);
    window.show();
    return app.exec();
}