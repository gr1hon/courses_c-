#include <QApplication>
#include <QMainWindow>
#include "consoleMainWindow.h"
#include "./ui_console.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ConsoleMainWindow window(nullptr);
    Ui::MainWindow console;
    console.setupUi(&window);
    window.channel_lineEdit = console.channel_lineEdit;
    window.volume_lineEdit = console.volume_lineEdit;
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
