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

}
