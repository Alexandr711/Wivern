#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#include <QFile>
#include <QJsonDocument>
#include <QString>
#include <QJsonObject>

class Documents
{

public:
    Documents();
    ~Documents();

    void openJsonFileForWriting(QString, QString, QString);
    void createFile(QString);
    QString openJsonFileForReading(QString);
    QString openQSSFileForReading(QString);

};

#endif // DOCUMENTS_H
