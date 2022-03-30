#include "Menu.h"
#include <iostream>

//QVector<MENU_DETAILS> menuList;
//QMap<QString, QString> mapMenuImage;
//QMap<QString, QString> mapMixxImage;
//QMap<QString, QString> mapMenuEng;
//QMap<QString, QString> mapMenuID;

extern RBLog *rblog;
Menu::Menu(QObject *parent)
    : QObject(parent)
{
    std::cout << "MENU" << std::endl;
    LoadMenu();
}


void Menu::LoadMenu(){
    menu_List.clear();

    menuDB = QSqlDatabase::addDatabase("QSQLITE", "LocalDB");
    menuDB.setDatabaseName(MENU_DB_PATH);

    if(!menuDB.open()){
        qDebug() << "Menu Database open fail";
    }

    QString select_str("select * from MenuList");
    QSqlQuery query(menuDB);
    query.exec(select_str);
    while(query.next()){
        ST_MENU_DETAIL temp_menu;

        temp_menu.menu_id = query.value(0).toString();
        temp_menu.menu_type = query.value(1).toString();
        temp_menu.menu_name = query.value(2).toString();
        temp_menu.image = query.value(3).toString();

        menu_List[temp_menu.menu_type].push_back(temp_menu);
    }

    QList<QString> key_list = menu_List.keys();
    for(int i=0; i<key_list.size(); i++){
        qDebug() << key_list[i] << "=====================";

        for(int j=0; j<menu_List[key_list[i]].size(); j++){
            qDebug() << menu_List[key_list[i]][j].menu_id << " : " << menu_List[key_list[i]][j].menu_name;
        }
    }


    qDebug() << menu_List["커피"].size();
}

QString Menu::getMenuName(QString menu_id){
    QList<QString> key_list = menu_List.keys();
    for(int i=0; i<key_list.size(); i++){
        for(int j=0; j<menu_List[key_list[i]].size(); j++){
            if(menu_List[key_list[i]][j].menu_id == menu_id){
                qDebug() << "getName " << menu_id << menu_List[key_list[i]][j].menu_name;
                return menu_List[key_list[i]][j].menu_name;
            }
        }
    }
    qDebug() << "getName " << menu_id;
    return "";
}

QString Menu::getMenuImage(QString menu_id){
    QList<QString> key_list = menu_List.keys();
    for(int i=0; i<key_list.size(); i++){
        for(int j=0; j<menu_List[key_list[i]].size(); j++){
            if(menu_List[key_list[i]][j].menu_id == menu_id){
                return menu_List[key_list[i]][j].image;
            }
        }
    }
    return "";
}
QString Menu::getMenuImagename(QString menu_name){
    QList<QString> key_list = menu_List.keys();
    for(int i=0; i<key_list.size(); i++){
        for(int j=0; j<menu_List[key_list[i]].size(); j++){
            if(menu_List[key_list[i]][j].menu_name == menu_name){
                qDebug() << menu_List[key_list[i]][j].image;
                return menu_List[key_list[i]][j].image;
            }
        }
    }
    return "";
}

QString Menu::getMenuID(QString menu_name){
    QList<QString> key_list = menu_List.keys();
    for(int i=0; i<key_list.size(); i++){
        for(int j=0; j<menu_List[key_list[i]].size(); j++){
            if(menu_List[key_list[i]][j].menu_name == menu_name){
                qDebug() << menu_List[key_list[i]][j].menu_id;
                return menu_List[key_list[i]][j].menu_id;
            }
        }
    }
    return "";
}
QString Menu::getMenuName(QString type, int num){
    qDebug() << type << num;
    qDebug() << menu_List[type].size();
    qDebug() << menu_List.size();
    if(menu_List[type].size() > num){
        qDebug() <<menu_List[type][num].menu_name;
        return menu_List[type][num].menu_name;
    }

    return "";
}

QString Menu::getMenuImage(QString type, int num){
    qDebug() << type << num;
    qDebug() <<menu_List[type].size();
    qDebug() << menu_List.size();
    if(menu_List[type].size() > num){
        qDebug() <<menu_List[type][num].image;
        return menu_List[type][num].image;
    }

    return "";
}

int Menu::getMenuNum(QString type){
    return menu_List[type].size();
}
