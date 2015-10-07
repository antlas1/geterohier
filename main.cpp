#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtQuick/QQuickView>
#include "Models/SubListedListModel.h"
#include "Models/devicemodelitem.h"

int main(int argc, char *argv[])
{
    //Запуск как в примере с touch
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Models::ListModel* devicesModel = new Models::SubListedListModel(new DeviceModelItem());
    //DEBUG
    devicesModel->appendRow(new DeviceModelItem());
    devicesModel->appendRow(new DeviceModelItem());
    devicesModel->appendRow(new DeviceModelItem());
    devicesModel->appendRow(new DeviceModelItem());
    devicesModel->appendRow(new DeviceModelItem());
    engine.rootContext()->setContextProperty("deviceModel",devicesModel);
    engine.load(QUrl("qrc:///qml/main.qml"));
    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel); \
    if ( !window ) {
        qWarning("Error: Your root item has to be a Window."); \
        return -1;
    }
    window->show();

    return app.exec();
}
