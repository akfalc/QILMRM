#include "downloader.h"
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QList>

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}

void Downloader::doDownload()
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("https://www.alphavantage.co/query?function=DIGITAL_CURRENCY_DAILY&symbol=BTC&market=USD&apikey=3F5NE805II9REK18")));
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {


        QByteArray webData = reply->readAll();

        QFile *file = new QFile(QDir::currentPath() + "\\BTCDATA.txt");
        if(file->open(QFile::Append))
        {
            file->write(webData);
            file->flush();
            file->close();
        }
        delete file;
        QList<QPair<QString,QString>> graphValuesBTC;
        QJsonDocument doc = QJsonDocument::fromJson(webData);

        if(doc.isArray()==true){
            QJsonArray rootArray = doc.array();
            //retrieve array
        }

        else if (doc.isObject() == true){

            QJsonObject rootObject = doc.object();

            QJsonObject timeSeries = rootObject["Time Series (Digital Currency Daily)"].toObject();
            QStringList keys = timeSeries.keys();

            for (QString k :keys){
                QJsonObject dayValues = timeSeries[k].toObject();
                QString bitcoinValue = dayValues["4a. close (USD)"].toString();






                QPair<QString,QString> dataItem3;
                dataItem3.first = k;
                dataItem3.second = bitcoinValue;





                graphValuesBTC.append(dataItem3);

                }
    } for (int i=0; i<graphValuesBTC.size(); i++){
            QPair<QString,QString> data = graphValuesBTC[i];
            float list=data.second.toFloat();
            QDateTime xAxisValue; xAxisValue.setDate(QDate::fromString(data.first,"yyyy-MM-dd"));
            xAxisValue.toMSecsSinceEpoch();
            emit presentData(QVariant(xAxisValue),QVariant(list));
        }
}
}
    void Downloader::doDownload1()
    {
        manager = new QNetworkAccessManager(this);

        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished1(QNetworkReply*)));

        manager->get(QNetworkRequest(QUrl("https://www.alphavantage.co/query?function=DIGITAL_CURRENCY_DAILY&symbol=AVT&market=USD&apikey=3F5NE805II9REK18")));
    }

    void Downloader::replyFinished1 (QNetworkReply *reply1)
    {
        if(reply1->error())
        {
            qDebug() << "ERROR!";
            qDebug() << reply1->errorString();
        }
        else
        {

            QByteArray webData1 = reply1->readAll();

            QFile *file1 = new QFile(QDir::currentPath() + "\\AVENTUSDATA.txt");
            if(file1->open(QFile::Append))
            {
                file1->write(webData1);
                file1->flush();
                file1->close();
            }
            delete file1;
            QList<QPair<QString,QString>> graphValuesAVT;
            QJsonDocument doc = QJsonDocument::fromJson(webData1);

            if(doc.isArray()==true){
                QJsonArray rootArray = doc.array();
                //retrieve array
            }

            else if (doc.isObject() == true){

                QJsonObject rootObject = doc.object();

                QJsonObject timeSeries = rootObject["Time Series (Digital Currency Daily)"].toObject();
                QStringList keys = timeSeries.keys();

                for (QString k :keys){
                    QJsonObject dayValues = timeSeries[k].toObject();
                    QString aventusValue = dayValues["4a. close (USD)"].toString();




                    QPair<QString,QString> dataItem2;
                    dataItem2.first = k;
                    dataItem2.second = aventusValue;






                    graphValuesAVT.append(dataItem2);


                    }
        }for (int i=0; i<graphValuesAVT.size(); i++){
                QPair<QString,QString> data = graphValuesAVT[i];
                float list=data.second.toFloat();
                QDateTime xAxisValue; xAxisValue.setDate(QDate::fromString(data.first,"yyyy-MM-dd"));
                xAxisValue.toMSecsSinceEpoch();
                emit presentData2(QVariant(xAxisValue),QVariant(list));
            }
    }
    }
    void Downloader::doDownload2()
    {
        manager = new QNetworkAccessManager(this);

        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished2(QNetworkReply*)));

        manager->get(QNetworkRequest(QUrl("https://www.alphavantage.co/query?function=DIGITAL_CURRENCY_DAILY&symbol=GAME&market=USD&apikey=3F5NE805II9REK18")));
    }

    void Downloader::replyFinished2 (QNetworkReply *reply2)
    {
        if(reply2->error())
        {
            qDebug() << "ERROR!";
            qDebug() << reply2->errorString();
        }
        else
        {

QByteArray webData2 = reply2->readAll();
            QFile *file = new QFile(QDir::currentPath() + "\\GAMEDATA.txt");
            if(file->open(QFile::Append))
            {
                file->write(webData2);
                file->flush();
                file->close();
            }
            delete file;
            QList<QPair<QString,QString>> graphValuesGAME;
            QJsonDocument doc = QJsonDocument::fromJson(webData2);

            if(doc.isArray()==true){
                QJsonArray rootArray = doc.array();
                //retrieve array
            }

            else if (doc.isObject() == true){

                QJsonObject rootObject = doc.object();

                QJsonObject timeSeries = rootObject["Time Series (Digital Currency Daily)"].toObject();
                QStringList keys = timeSeries.keys();

                for (QString k :keys){
                    QJsonObject dayValues = timeSeries[k].toObject();
                    QString gameValue = dayValues["4a. close (USD)"].toString();


                    QPair<QString,QString> dataItem;
                    dataItem.first = k;
                    dataItem.second = gameValue;





                    graphValuesGAME.append(dataItem);

                    }
        }
            for (int i=0; i<graphValuesGAME.size(); i++){
                QPair<QString,QString> data = graphValuesGAME[i];
                float list=data.second.toFloat();
                QDateTime xAxisValue; xAxisValue.setDate(QDate::fromString(data.first,"yyyy-MM-dd"));
                xAxisValue.toMSecsSinceEpoch();
                emit presentData3(QVariant(xAxisValue),QVariant(list));
            }
    }
    }
