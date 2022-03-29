#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QCursor>

#include "Backend.h"
#include "OrderManage.h"
#include "Menu.h"

Menu *menu;
QObject *object;
RBLog *rblog;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    menu = new Menu();

    rblog = new RBLog();

    rblog->AddLogLine("================================");

    app.setOverrideCursor(QCursor(Qt::BlankCursor));
    qmlRegisterType<Backend>("io.qt.Backend", 1, 0, "Backend");
    qmlRegisterType<OrderManage>("io.qt.OrderManage", 1, 0, "OrderManage");

    QQmlEngine engine;
    QQmlComponent component(&engine, "qrc:/main.qml");
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());
    object = component.create();

    QObject::connect((QObject*)&engine, SIGNAL(quit()), &app, SLOT(quit()));

    return app.exec();
}
