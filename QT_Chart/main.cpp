#include <QtWidgets/QMainWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQuickView>
#include <downloader.h>



int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;
engine.rootContext()->setContextProperty("downloadManager",manager);
Downloader d;
d.doDownload();
d.doDownload1();
d.doDownload2();

    return app.exec();
}
