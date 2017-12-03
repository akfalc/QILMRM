#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

    void doDownload(const qint8 &CurrencyId);

signals:
    void valueUpdated(QVariant x, QVariant y);
    void valueUpdated2(QVariant x, QVariant y);
    void valueUpdated3(QVariant x, QVariant y);
public slots:
    void replyFinished (QNetworkReply *reply);


private:
   QNetworkAccessManager *manager;

};

#endif // DOWNLOADER_H
