#include "Document.h"

Documents::Documents()
{

}

Documents::~Documents()
{

}

void Documents::createFile(QString _FileName)
{
    QFile File(_FileName);
    File.open(QIODevice::ReadOnly);
    File.close();
}


QString Documents::openJsonFileForReading(QString _FileName)
{
    QFile File;
    QString TempString;

    File.setFileName(_FileName);

    File.open(QIODevice::ReadOnly | QIODevice::Text);
    TempString = File.readAll();
    File.close();

    return TempString;
}

QString Documents::openQSSFileForReading(QString _FileName)
{
    QFile File(_FileName);
    File.open(QIODevice::ReadOnly);

    QString TempString(File.readAll());
    return TempString;
}

void Documents::openJsonFileForWriting(QString _FileName, QString _Key, QString _StringForWrite)
{
    QFile File;
    File.setFileName(_FileName);
    File.open(QIODevice::ReadOnly| QIODevice::Text);
    QString TempString = File.readAll();
    File.close();

    QJsonDocument JsonDocument = QJsonDocument::fromJson(TempString.toUtf8());

    File.open(QIODevice::WriteOnly| QIODevice::Truncate |QIODevice::Text);

    QJsonObject JsonObject = JsonDocument.object();
    JsonObject.insert(_Key, _StringForWrite);
    QJsonDocument JsonDocumentTwo(JsonObject);
    TempString = JsonDocumentTwo.toJson(QJsonDocument::Indented);
    QTextStream stream(&File);
    stream << TempString;
    File.close();
}
