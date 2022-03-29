#include "RBLog.h"

RBLog RBLog::instance;

RBLog::RBLog()
{
    logfile = new QFile();
    filename = GetFilename();
    logfile->setFileName(filename);
    logfile->open(QIODevice::Append | QIODevice::Text);
}

void RBLog::AddLogLine(const QString &_data){
    QString text = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]") + "  " + _data + "\n";
//    QTextStream out(instance.logfile);

    QString tempname = instance.GetFilename();
    if(tempname != instance.filename){
        if(instance.logfile->isOpen()){
            instance.logfile->close();
            delete instance.logfile;
        }
        instance.filename = tempname;
        instance.logfile = new QFile;
        instance.logfile->setFileName(instance.filename);
        instance.logfile->open(QIODevice::Append | QIODevice::Text);
        qDebug() << "make " << instance.filename;
    }
    QTextStream out(instance.logfile);
    out.setCodec("UTF-8");

    if(instance.logfile != nullptr){
        out << text;
    }
    qDebug() << text;
}

QString RBLog::GetFilename(){
    QString tempname = QDate().currentDate().toString("LOG/log_yyyy_MM_dd") + ".txt";

    return tempname;
}
