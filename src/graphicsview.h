/******************************
 * Author by: Roman Cizmarik
 ******************************/


#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QWidget * parent = 0);

public slots:

    void zoomIn();
    void zoomOut();
    void zoom(int scaleF);

protected:
    /**
     * @brief wheelEvent
     * @param event
     * Wheel event used for zooming
     */
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    bool controlDown;
    double scaleFactor;
};

#endif // GRAPHICSVIEW_H
