#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"convertercontroller.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    ConverterModel model;
    ConverterController controlTemp {&model};

   // engine.loadFromModule("Temperature_Converter", "Main");
    engine.rootContext()->setContextProperty("controller", &controlTemp);

    engine.loadFromModule("Temperature_Converter", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
