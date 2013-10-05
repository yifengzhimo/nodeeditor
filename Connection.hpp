#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsObject>

class Connection: public QGraphicsObject
{
  Q_OBJECT

public:
  enum Dragging { SOURCE, SINK, NONE };

public:
  Connection(int BlockOutID, int BlockInID);

  QRectF
  boundingRect() const override;

  void
  advance(int phase);

  void
  timerEvent(QTimerEvent* event);

  void
  mousePressEvent(QGraphicsSceneMouseEvent* event) override;

  void
  mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

  void
  mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

protected:
  void
  paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;

  /**
   * dataTransfer
   * */

private:
  QPointF _source;
  QPointF _sink;
  QPointF _lastPoint;

  Dragging _dragging;

  double _pointDiameter;

  int _animationPhase;
};

#endif // CONNECTION_H