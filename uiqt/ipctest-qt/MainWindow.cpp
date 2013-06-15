
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Command.h"
#include "Log.h"
#include "RunContext.h"
#include "TestBase.h"
using namespace std;

LOGINIT     // Must be done once in program


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , context_(*new ipctest::RunContext)
    , testBase_(*new ipctest::TestBase)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete &testBase_;
    delete &context_;
}

bool MainWindow::setup(const std::string& defFilename, const std::string& testFilename)
{
    bool ret = false;

    if (defFilename.empty() || testFilename.empty())
        return ret;

    // Open definitions
    if (!testBase_.readIpcDefs(defFilename))
        return ret;

    // Open test file
    if (!testBase_.deserialize(testFilename))
    {
        LOG << "Error reading commands from " << testFilename << endl;
        return ret;
    }

    ipctest::CommandList& commandList = testBase_.commandList();
    LOG << "Read in " << commandList.size() << " commands." << endl;

    const std::vector<std::string>& builtIns = testBase_.builtinCommandNames();
    std::vector<std::string>::const_iterator it;
    for (it = builtIns.begin(); it != builtIns.end(); ++it)
    {
        QString qstr((*it).c_str());
        ui->commands->addItem(qstr);
    }
    ret = true;

    LOG << "MainWindow setup " << (ret ? "suceeded" : "failed") << endl;

    return ret;
}
