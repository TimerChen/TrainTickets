#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include "include/algorithm0.hpp"
#include "include/smartpoint.hpp"

class DataBase_Main;
namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ServerMainWindow(QWidget *parent = 0);
	~ServerMainWindow();

private:
	//shared_ptr<DataBase_Main>dataBase;
	Ui::ServerMainWindow *ui;
};

#endif // SERVERMAINWINDOW_H
