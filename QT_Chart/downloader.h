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
#include <QList>
#include <QVariant>

class Downloader : public QObject
{
    Q_OBJECT
    QNetworkAccessManager* manager;

public:
    explicit Downloader(QObject *parent = nullptr);


Q_INVOKABLE void doDownload(const QString &currencyID);

signals:
    void presentData(QVariant x, QVariant y);


public slots:
    void replyFinished (QNetworkReply *reply);





};

#endif // DOWNLOADER_H

