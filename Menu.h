#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QDebug>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#define MENU_DB_PATH    "MENU/MENU.db"


class Menu : QObject
{
    Q_OBJECT
public:
    Menu();

    void LoadMenu();

private:
    QSqlDatabase menuDB;
};

#endif // MENU_H
