#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,9,0,0,0,1,0,0,1,
10,0,0,0,0,0,1,0,0,0,0,0,0,0,56,0,
0,0,0,0,1,0,0,0,0,0,0,0,138,0,0,0,
0,0,1,0,0,0,0,0,0,0,190,0,0,0,0,0,
1,0,0,0,0,0,0,0,8,0,0,0,0,0,1,0,
0,0,0,0,0,0,32,0,0,0,0,0,1,0,0,0,
0,0,0,0,234,0,0,0,0,0,1,0,0,0,0,0,
0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,
160,0,0,0,0,0,1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,9,13,132,252,220,0,80,0,
97,0,103,0,101,0,49,0,46,0,113,0,109,0,108,0,
9,13,133,252,220,0,80,0,97,0,103,0,101,0,50,0,
46,0,113,0,109,0,108,0,19,7,36,221,28,0,68,0,
114,0,105,0,110,0,107,0,73,0,116,0,101,0,109,0,
79,0,112,0,116,0,105,0,111,0,110,0,46,0,113,0,
109,0,108,0,16,14,107,19,220,0,77,0,101,0,110,0,
117,0,80,0,97,0,103,0,101,0,95,0,84,0,101,0,
97,0,46,0,113,0,109,0,108,0,8,8,1,90,92,0,
109,0,97,0,105,0,110,0,46,0,113,0,109,0,108,0,
12,14,233,102,252,0,67,0,97,0,114,0,116,0,80,0,
97,0,103,0,101,0,46,0,113,0,109,0,108,0,19,8,
201,136,220,0,77,0,101,0,110,0,117,0,80,0,97,0,
103,0,101,0,95,0,67,0,111,0,102,0,102,0,101,0,
101,0,46,0,113,0,109,0,108,0,13,13,160,249,28,0,
68,0,114,0,105,0,110,0,107,0,73,0,116,0,101,0,
109,0,46,0,113,0,109,0,108,0,12,3,145,102,60,0,
67,0,97,0,114,0,116,0,73,0,116,0,101,0,109,0,
46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__CartItem_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__DrinkItem_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__MenuPage_Coffee_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CartPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__MenuPage_Tea_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__DrinkItemOption_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Page2_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Page1_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/CartItem.qml"), &QmlCacheGeneratedCode::_0x5f__CartItem_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/DrinkItem.qml"), &QmlCacheGeneratedCode::_0x5f__DrinkItem_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MenuPage_Coffee.qml"), &QmlCacheGeneratedCode::_0x5f__MenuPage_Coffee_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CartPage.qml"), &QmlCacheGeneratedCode::_0x5f__CartPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MenuPage_Tea.qml"), &QmlCacheGeneratedCode::_0x5f__MenuPage_Tea_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/DrinkItemOption.qml"), &QmlCacheGeneratedCode::_0x5f__DrinkItemOption_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Page2.qml"), &QmlCacheGeneratedCode::_0x5f__Page2_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Page1.qml"), &QmlCacheGeneratedCode::_0x5f__Page1_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}
const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
