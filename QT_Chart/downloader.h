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

    void doDownload();
    void doDownload1();
    void doDownload2();

signals:
    void presentData(QVariant x, QVariant y);
    void presentData2(QVariant x, QVariant y);
    void presentData3(QVariant x, QVariant y);

public slots:
    void replyFinished (QNetworkReply *reply);
    void replyFinished1(QNetworkReply *reply1);
    void replyFinished2(QNetworkReply *reply2);




};

#endif // DOWNLOADER_H

