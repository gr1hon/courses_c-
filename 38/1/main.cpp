#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaPlaylist>
#include <QMainWindow>
#include <iostream>


class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrButtonPixmap;
    QPixmap mButtonUpPixmap;
    QPixmap mButtonDownPixmap;
};
ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap(":images/up.png");
    mButtonDownPixmap = QPixmap(":images/down.png");
    mCurrButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);

    auto* player = new QMediaPlayer(this);
    QString filePath2 = "../button2/sound.mp3";
    player->setMedia(QUrl::fromLocalFile(filePath2));
    player->setVolume(25);

    connect(this, &QPushButton::clicked, [player]()
            {
                player->stop();
        std::cout << "click" << std::endl;
//                std::cout << filePath.toStdString() << std::endl;
                player->play();
            });

}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(300,300);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}
void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}
void ImageButton::setDown()
{
    mCurrButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(200, this, &ImageButton::setUp);

}
void ImageButton::setUp()
{
    mCurrButtonPixmap = mButtonUpPixmap;
    update();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ImageButton button(nullptr);
    button.setFixedSize(300,300);
    button.move(1000,500);
    button.show();

    return QApplication::exec();
}
#include "main.moc"
