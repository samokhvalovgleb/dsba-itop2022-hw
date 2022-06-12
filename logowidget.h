#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include <QWidget>

class logoWidget : public QWidget
{
  Q_OBJECT
public:
  logoWidget (QWidget *parent) {}
protected:
  void paintEvent (QPaintEvent *event) override;
};

#endif // LOGOWIDGET_H
