#include <QtWidgets/QMainWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQuickView>
#include <downloader.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
qmlRegisterType<Downloader>("DataChart", 1, 0, "DataChart");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
