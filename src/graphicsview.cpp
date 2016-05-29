/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "graphicsview.h"
#include <QDebug>
GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    controlDown(false),
    scaleFactor(1.15)
{
    setRenderHint(QPainter::Antialiasing, true);


    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
}

void GraphicsView::zoomIn()
{
    scale(scaleFactor, scaleFactor);
}

void GraphicsView::zoomOut()
{
    scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}

void GraphicsView::zoom(int scaleF)
{
    resetTransform();
    scale(scaleF,scaleF);
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
        if(event->delta() > 0) {
            zoomIn();

        } else {
            zoomOut();

        }
    }
    else
        QGraphicsView::wheelEvent(event);

}
