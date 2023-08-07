#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPainter>
#include <QPushButton>
#include <QPaintEvent>
#include <iostream>

class Circle : public QWidget
{
    Q_OBJECT
public:
    Circle() = default;
    Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;
public slots:
    void setYellow();
    void setGreen();
    void setRed();
private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mCurrentCircle;
};

Circle::Circle(QWidget *parent)
{
    setParent(parent);
    setToolTip("Здесь есть кнопка");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mGreenCircle = QPixmap("..\\mGreenCircle.png");
    mRedCircle = QPixmap("..\\mRedCircle.png");
    mYellowCircle = QPixmap("..\\mYellowCircle.png");
    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect());
}

void Circle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}


QSize Circle::minimumSizeHint() const {
    return {100, 100};
}


void Circle::setYellow() {
    mCurrentCircle = mYellowCircle;
    update();
}
void Circle::setGreen() {
    mCurrentCircle = mGreenCircle;
    update();
}
void Circle::setRed() {
    mCurrentCircle = mRedCircle;
    update();
}



int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    auto *window = new QWidget;

    auto* slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    auto *circle = new Circle(window);

    QObject::connect(slider, &QSlider::valueChanged, [&slider, &circle](int newValue)
    {
        if (newValue < 34)
            circle->setGreen();
        else if (newValue < 67)
            circle->setYellow();
        else circle->setRed();
    });
    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    window->setFixedSize(500, 700);
    window->move(700, 200);
    circle->setFixedSize(500,500);
    window->show();
//    circle.show();
    return app.exec();
}

#include <main.moc>
