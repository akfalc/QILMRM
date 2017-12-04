#include <QtWidgets/QMainWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include <QQuickView>
#include <downloader.h>
#include <QNetworkAccessManager>



int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);



    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;
    Downloader* manager = new Downloader();
    manager->doDownload();
    engine.rootContext()->setContextProperty("downloadManager",manager);
    Downloader* manager2 = new Downloader();
     manager2->doDownload1();
      engine.rootContext()->setContextProperty("downloadManager2",manager2);
     Downloader* manager3 = new Downloader();
     manager3->doDownload2();




engine.rootContext()->setContextProperty("downloadManager3",manager3);




    return app.exec();
}
