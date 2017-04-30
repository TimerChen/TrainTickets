#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include "src_Timer/algorithm0.hpp"
#include "src_MW/smartpoint.hpp"

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
	shared_ptr<DataBase_Main>dataBase;
	Ui::ServerMainWindow *ui;
};

#endif // SERVERMAINWINDOW_H
