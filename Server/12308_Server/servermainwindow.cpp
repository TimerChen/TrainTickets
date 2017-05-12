#include "servermainwindow.h"
#include "ui_servermainwindow.h"

#include "include/database.h"

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
