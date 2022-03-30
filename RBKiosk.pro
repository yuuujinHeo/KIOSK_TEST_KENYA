QT += quick network multimedia sql
CONFIG += c++11
CONFIG += resources_big
#CONFIG += console


QMAKE_CXXFLAGS += /utf-8

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += _MBCS

#TEMPLATE = lib
#DEFINES += SMTP_BUILD
#win32:CONFIG += dll

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += websocket


SOURCES += \
    Menu.cpp \
    OrderManage.cpp \
    RBLog.cpp \
    RBRobotConnector.cpp \
        main.cpp \
    Backend.cpp \
    RBPrinter.cpp \
    websocket/QtHttpClientWrapper.cpp \
    websocket/QtHttpHeader.cpp \
    websocket/QtHttpReply.cpp \
    websocket/QtHttpRequest.cpp \
    websocket/QtHttpServer.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    image/notice_page/background.png \
    image/notice_page/cleaning.png \
    image/notice_page/maintenance.png \
    image/notice_page/please_wait.png \
    image/notice_page/pre_cleaning.png \
    image/notice_page/pre_operation.png \
    websocket/libQt5HttpServer.pri \
    websocket/libQt5HttpServer.qbs

HEADERS += \
    GlobalHeader.h \
    Menu.h \
    OrderManage.h \
    Backend.h \
    RBLog.h \
    RBPrinter.h \
    RBRobotConnector.h \
    bxlconst.h \
    websocket/QtHttpClientWrapper.h \
    websocket/QtHttpHeader.h \
    websocket/QtHttpReply.h \
    websocket/QtHttpRequest.h \
    websocket/QtHttpServer.h \

#LIBS += -L$$PWD/ -lBXLPAPI
#LIBS += -L$$PWD/ -lREXOD_LIB

#win32: LIBS += -L$$PWD/./ -lREXOD_LIB

#SMTP_LIBRARY_LOCATION = $$PWD/lib/

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

LIBS += -L$$PWD/./ -lBXLPAPI
LIBS += -lUser32
