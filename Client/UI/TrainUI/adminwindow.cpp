#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "include/smartpoint.hpp"
#include "uistructs.h"

AdminWindow::AdminWindow(
    ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminWindow), nowaccount(_now) {
    ui->setupUi(this);
}

AdminWindow::~AdminWindow() { delete ui; }
