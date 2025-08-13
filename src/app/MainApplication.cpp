
#include <app/MainApplication.hpp>

#include <QLabel>

namespace app
{
    MainApplication::MainApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    {
        // Create a simple label window
        QLabel* label = new QLabel("Hello, Qt!");
        label->resize(200, 100);
        label->show();
    }

}

int main(int argc, char *argv[])
{
    app::MainApplication app{argc, argv};

    return app.exec();
}