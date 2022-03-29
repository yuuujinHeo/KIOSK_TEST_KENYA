#ifndef RBLOG_H
#define RBLOG_H

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QDateTime>
using namespace std;

class RBLog : QObject
{
    Q_OBJECT
    static RBLog instance;
public:
    RBLog();
    void AddLogLine(const QString &_data);
    int isOpenfile();

    QString GetFilename();
private:
    QString filename;
    QFile *logfile;
};

#endif // RBLOG_H
