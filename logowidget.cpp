#include "logowidget.h"
#include "qpen.h"
#include <QPainter>
#include <QFont>


void logoWidget::paintEvent (QPaintEvent *event)
{
  QFont newFont("Courier", 50, QFont::Bold, true);
  QPainter painter (this);
  painter.setBackground(QBrush (Qt::black));
  painter.setPen (QPen(Qt::blue));
  painter.setFont(newFont);
  painter.drawText(62, 112, "P");
  QPoint center_widget (width () / 2, height () / 2);
  int radius   = std::min (width (), height () / 3);
  painter.drawEllipse (center_widget, radius, radius);
}
