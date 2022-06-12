#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QWidget>

namespace Ui {
class about_window;
}

class logoWidget;

class about_window : public QWidget
{
    logoWidget *logo;
    Q_OBJECT

public:
    explicit about_window(QWidget *parent = nullptr);
    ~about_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::about_window *ui;
};

#endif // ABOUT_WINDOW_H
