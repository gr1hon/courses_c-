#include <QApplication>
#include "playermainwindow.h"
#include "./ui_player.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PlayerMainWindow window(nullptr);
    Ui::MainWindow player;
    player.setupUi(&window);
    window.resize(480, 640);
    window.show();
    return QApplication::exec();

//    QApplication app(argc, argv);
//    CalculatorMainWindow window(nullptr);
//    Ui::MainWindow calculator;
//    calculator.setupUi(&window);
//    window.firstLineEdit = calculator.lineEdit_2;
//    window.secondLineEdit = calculator.lineEdit;
//    window.resultLineEdit = calculator.lineEdit_3;
//    window.resize(480, 640);
//    window.show();
//    return app.exec();
}
