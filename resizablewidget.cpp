#include "resizablewidget.h"


ResizableWidget::ResizableWidget(QWidget *parent) : QWidget(parent), m_isResizing(false), m_resizeDirection(None) {
    // Enable mouse tracking to receive mouseMoveEvents even when no button is pressed
    setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    // Set a minimum size for the widget
    //setMinimumSize(200, 150);

    // Optional: Set a background color to see the widget boundaries
    //setStyleSheet("background-color: lightblue; border: 1px solid gray;");
}
