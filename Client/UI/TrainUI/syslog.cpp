#include "syslog.h"
#include "ui_syslog.h"

#include "mainwindow.h"

sysLog::sysLog(QString _adminID, QWidget *parent)
    : QDialog(parent), ui(new Ui::sysLog), adminID(_adminID) {
    ui->setupUi(this);
    QString log;
    ///发送 frontask::getsyslog
    ///发送 adminID
	///获得QString

	log =
		((MainWindow*)(parentWidget()->parentWidget()))->
			query_log_remote();
	ui->viewLogTextBrowser->setText(log);
}

sysLog::~sysLog() { delete ui; }
