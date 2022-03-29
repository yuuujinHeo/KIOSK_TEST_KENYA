#include "Menu.h"
#include <iostream>

QVector<ST_MENU_TYPE> menuTypeList;
QVector<MENU_DETAILS> menuList;
QMap<QString, QString> mapMenuImage;
QMap<QString, QString> mapMixxImage;
QMap<QString, QString> mapMenuEng;

extern RBLog *rblog;
Menu::Menu()
{
    std::cout << "MENU" << std::endl;
    LoadMenu();
}


void Menu::LoadMenu(){
    menuTypeList.clear();
    menuList.clear();

    menuDB = QSqlDatabase::addDatabase("QSQLITE", "LocalDB");
    menuDB.setDatabaseName(MENU_DB_PATH);

    if(!menuDB.open()){
        qDebug() << "Menu Database open fail";
        rblog->AddLogLine("[Menu]       menuDBopen : fail");

    }

    QString select_str("select * from TypeList");
    QSqlQuery query(menuDB);
    query.exec(select_str);
    while(query.next()){
        ST_MENU_TYPE temp_type;
        temp_type.kor = query.value(1).toString();
        temp_type.eng = query.value(2).toString();
        menuTypeList.push_back(temp_type);
        MENU_DETAILS tempDetail;
        menuList.push_back(tempDetail);
    }

    QString select_str2("select * from MenuList");
    query.exec(select_str2);
    while(query.next()){
        QString type = query.value(2).toString();
        int type_index = -1;
        for(int i=0; i<menuTypeList.size(); i++){
            if(menuTypeList[i].kor == type){
                type_index = i;
                break;
            }
        }
        if(type_index < 0){
            qDebug() << "Menu Database menu type error -- " << type;
            break;
        }

        ST_MENU_DETAIL menu;
        menu.code = query.value(0).toString();
        menu.kor = query.value(3).toString();
        menu.eng = query.value(4).toString();
        menu.price = query.value(5).toInt();
        menu.image = query.value(6).toString();
        menu.description = query.value(7).toString().replace("\\n", "\n");
        menuList[type_index].push_back(menu);

        mapMenuImage[menu.kor] = menu.image;
        mapMenuEng[menu.kor] = menu.eng;

        QString mixx_image = query.value(7).toString();
        if(mixx_image != ""){
            mapMixxImage[menu.kor] = mixx_image;
        }
    }

    for(int i=0; i<menuTypeList.size(); i++){
        qDebug() << menuTypeList[i].kor << ", " << menuTypeList[i].eng;
    }

    for(int i=0; i<menuList.size(); i++){
        for(int j=0; j<menuList[i].size(); j++){
            qDebug() << menuList[i][j].kor << ", " << menuList[i][j].eng << ", " << menuList[i][j].price;
        }
    }
    rblog->AddLogLine("[Menu]       menuDBopen : menuTypeList "+QString().sprintf("%d",menuTypeList.size()));
    rblog->AddLogLine("[Menu]       menuDBopen : menuList "+QString().sprintf("%d",menuList.size()));

}
