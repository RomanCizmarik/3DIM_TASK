/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    controlDown(false)
{
    setRenderHint(QPainter::Antialiasing, true);


    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
}


void GraphicsView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        controlDown = true;

    QGraphicsView::keyPressEvent(event);

}

void GraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        controlDown = false;
    QGraphicsView::keyReleaseEvent(event);
}

void GraphicsView::wheelEvent(QWheelEvent* event) {

    //ctrl pressed => zoom
    if(controlDown){
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            // Zoom in
            scale(scaleFactor, scaleFactor);
        } else {
            // Zooming out
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
    }
    else
        QGraphicsView::wheelEvent(event);

}
