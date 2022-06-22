#include "about_window.h"
#include "logowidget.h"
#include "ui_about_window.h"

about_window::about_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_window)
{
    ui->setupUi(this);
    logo = new logoWidget(this);
    logo->setFixedSize(180,180);
    ui->gridLayout->addWidget(logo, 0, 0);
}

about_window::~about_window()
{
    delete ui;
}

void about_window::on_pushButton_clicked()
{
    this->close();
}

