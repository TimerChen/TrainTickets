#include "servermainwindow.h"
#include "ui_servermainwindow.h"

#include "src_Timer/DataBase.h"

ServerMainWindow::ServerMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ServerMainWindow)
{
	ui->setupUi(this);
}

ServerMainWindow::~ServerMainWindow()
{
	delete ui;
}
