#include <QApplication>
#include <QPushButton>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto* window = new QWidget;
    auto* hbox = new QHBoxLayout(window);

    auto* text = new QPlainTextEdit;
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    text->setSizePolicy(spLeft);
    hbox->addWidget(text);

    auto* webView = new QWebEngineView;
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(1);
    webView->setSizePolicy(spRight);
    hbox->addWidget(webView);
    QObject::connect(text, &QPlainTextEdit::textChanged, [webView, text](){
        auto html = text->toPlainText();
        webView->setHtml(html);
    });
    window->show();
    window->resize(600, 600);
    return a.exec();
}
