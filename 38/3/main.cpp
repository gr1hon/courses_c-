#include <QApplication>
#include <QtGui/QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QBitmap>
#include <QDir>
#include <QPainter>
#include <QGraphicsView>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <iostream>

QImage blurImage(QImage source)
{
     if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0,0, source.width(), source.height()));
    return result;
}

void processSingleImage(QString sourceFile, QString destFile)
{
    auto blured = blurImage(QImage(sourceFile));
    blured.save(destFile);
}

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    processSingleImage("foto.jpg", "blured_foto.jpg");
    std::cout << "end" << std::endl;
    return a.exec();
}

//#include <main.moc>