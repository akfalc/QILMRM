#include <QApplication>
#include <QLabel>

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QLabel *label = new QLabel ("Hello world");
    label-> setWindowTitle("My First App");
    label-> resize(400,400);
            label->show();
return app.exec();
}
