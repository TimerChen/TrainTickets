#ifndef SYSLOG_H
#define SYSLOG_H

#include <QDialog>

namespace Ui {
class sysLog;
}

class sysLog : public QDialog {
    Q_OBJECT

   public:
    explicit sysLog(QString _adminID, QWidget *parent = 0);
    ~sysLog();

   private:
    Ui::sysLog *ui;
    QString adminID;
};

#endif  // SYSLOG_H
