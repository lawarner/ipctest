#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>


// FORWARD CLASS DECLARATIONS
namespace Ui {
class MainWindow;
}

namespace ipctest
{
class Command;
class RunContext;
class TestBase;
typedef std::vector<Command *> CommandList;
}
class MessagesModel;


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    bool setup(const std::string& defFilename, const std::string& testFilename);

private:
    Ui::MainWindow *ui;

    ipctest::RunContext& context_;
    ipctest::TestBase&   testBase_;
    MessagesModel* messagesModel_;
};

#endif // MAINWINDOW_H
