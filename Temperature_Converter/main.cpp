#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"convertercontroller.h"
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Fusion");
    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    ConverterModel model;
    ConverterController controlTemp {&model};


    engine.rootContext()->setContextProperty("controller", &controlTemp);
    engine.loadFromModule("Temperature_Converter", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
