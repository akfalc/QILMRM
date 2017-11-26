#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <stdio.h>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJsonObject json1
     {
        {"id", 1},
        {"name", "Akif"},
        {"Homework", "has to be done"}, };

    QJsonObject json2
     {
        {"id", 2},
        {"name", "ALIC"},
        {"Homework", "it is long work"}, };

    QJsonArray JSonArray {json1, json2};
    QJsonDocument Jsondoc(JSonArray);

    QFile file1("D:/2017-2018 new semester/Development of Software Applications/QtJSon/array2.json");
    QFile file2("D:/2017-2018 new semester/Development of Software Applications/QtJSon/array2.dat");

   Q_ASSERT(file1.open(QFile::WriteOnly) || file2.open(QFile::WriteOnly));

    file1.write(Jsondoc.toJson());
    file2.write(Jsondoc.toBinaryData());

}




