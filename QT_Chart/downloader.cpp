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
    QObject(parent)/*,
  m_StartDate(QDate::currentDate().addDays(-10).toString("yyyy-MM-dd")),
              m_EndDate(QDate::currentDate().toString("yyyy-MM-dd")),
              m_yAxisMin(0),
              m_yAxisMax(1500)*/
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
}
//QString Downloader::startDate() const
//{
//  return m_StartDate;
//}
//void Downloader::setStartDate(const QString &date){
//  this->m_StartDate = date;
//}



//QString Downloader::endDate() const {
//  return m_EndDate;
//}



//void Downloader::setEndDate(const QString &date){
//  this->m_EndDate = date;
//}



//double Downloader::yAxisMin() const {
//  return m_yAxisMin;
//}



//void Downloader::setYAxisMin(double value){
//  this->m_yAxisMin = value;
//}



//double Downloader::yAxisMax() const {
//  return m_yAxisMax;
//}



//void Downloader::setYAxisMax(double value){
//  this->m_yAxisMin = value;
//}

void Downloader::doDownload(const QString &CurrencyID)
{ 
    // Set & send the newtork request
    QString requestUrl = "https://www.alphavantage.co/query?";
    requestUrl += "function=DIGITAL_CURRENCY_DAILY";
    requestUrl += "&symbol=" + CurrencyID;
    requestUrl += "&market=USD";
    requestUrl += "&apikey=3F5NE805II9REK18";
  
    manager->get(QNetworkRequest(QUrl(requestUrl)));
  }


void Downloader::replyFinished (QNetworkReply *reply)
{
     QString CurrencyID = (reply->url().toString()).replace("https://www.alphavantage.co/query?function=DIGITAL_CURRENCY_DAILY&symbol=" , "").replace("&market=USD&apikey=3F5NE805II9REK18","");
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {


        QByteArray webData = reply->readAll();

        QFile *file = new QFile(QDir::currentPath() + "\\" + CurrencyID + ".txt");
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
            QString k = QDate::currentDate().addDays(-30).toString("yyyy-MM-dd");

            for (QString k :keys){
                QJsonObject dayValues = timeSeries[k].toObject();
                QString bitcoinValue = dayValues["4a. close (USD)"].toString();






                QPair<QString,QString> dataItem3;
                dataItem3.first = k;
                dataItem3.second = bitcoinValue;





                graphValuesBTC.append(dataItem3);


                } std::sort(graphValuesBTC.begin(), graphValuesBTC.end());
    } for (int i=0; i<graphValuesBTC.size(); i++){
            QPair<QString,QString> data = graphValuesBTC[i];
            float list=data.second.toFloat();
            QDateTime xAxisValue; xAxisValue.setDate(QDate::fromString(data.first,"yyyy-MM-dd"));
            xAxisValue.toMSecsSinceEpoch();
            emit presentData(QVariant(xAxisValue),QVariant(list));
        }


//        for (int i=0; i<graphValuesBTC.size(); i++) {
//            graphValuesBTC.removeAt(i);
//        }
}
 }
    
    
