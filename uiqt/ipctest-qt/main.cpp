#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::string defFile("../../examples/t.json");
    std::string testFile("../../examples/t.its");
    QApplication app(argc, argv);

    MainWindow w;
    w.setup(defFile, testFile);
    w.show();
    
    return app.exec();
}
