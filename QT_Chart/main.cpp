#include <QtWidgets/QMainWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include <QQuickView>
#include <downloader.h>
#include <QNetworkAccessManager>
#include <iostream>


int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);



    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext* context = engine.rootContext();
    Downloader d;
context->setContextProperty("downloadManager", &d);

    if (engine.rootObjects().isEmpty())
        return -1;

    




    return app.exec();
}
