#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QDebug>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#define MENU_DB_PATH    "DB/MenuDB.db"


class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent = nullptr);

    void LoadMenu();

    Q_INVOKABLE QString getMenuName(QString menu_id);
    Q_INVOKABLE QString getMenuImage(QString menu_id);
    Q_INVOKABLE QString getMenuImagename(QString menu_name);
    Q_INVOKABLE QString getMenuID(QString menu_name);

    Q_INVOKABLE QString getMenuName(QString type, int num);
    Q_INVOKABLE QString getMenuImage(QString type, int num);

    Q_INVOKABLE int getMenuNum(QString type);

    QMap<QString, QVector<ST_MENU_DETAIL>> menu_List;

private:
    QSqlDatabase menuDB;

};

#endif // MENU_H
