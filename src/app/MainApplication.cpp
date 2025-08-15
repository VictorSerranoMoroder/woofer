
#include <app/MainApplication.hpp>

#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QLabel>

namespace app
{
    MainApplication::MainApplication(int &argc, char **argv)
    : QGuiApplication(argc, argv)
    {

        QQmlApplicationEngine engine;
        // Load your QML file
        engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

        // Set the global style to Material
        QQuickStyle::setStyle("Material");

        if (!engine.rootObjects().isEmpty())
            exec();
    }

}

int main(int argc, char *argv[])
{
    app::MainApplication app{argc, argv};

    return app.exec();
}