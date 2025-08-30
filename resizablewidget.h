#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QCursor>
#include <QtWidgets/QMainWindow> // Include if using QMainWindow
#include <QDebug> // For debugging output

class ResizableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResizableWidget(QWidget *parent = nullptr);

protected:
    // Enum to represent the resizing direction
    enum ResizeDirection {
        None,
        Top,
        Bottom,
        Left,
        Right,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    // Calculate the resize direction based on the mouse position relative to the widget edges
    ResizeDirection getResizeDirection(const QPoint &pos) const {
        const int borderWidth = 8; // Width of the border area sensitive to resizing
        QRect rect = this->rect();
        QRect innerRect = rect.adjusted(borderWidth, borderWidth, -borderWidth, -borderWidth);

        if (!innerRect.contains(pos)) {
            bool left = pos.x() < borderWidth;
            bool top = pos.y() < borderWidth;
            bool right = pos.x() > rect.width() - borderWidth;
            bool bottom = pos.y() > rect.height() - borderWidth;

            if (top && left) return TopLeft;
            if (top && right) return TopRight;
            if (bottom && left) return BottomLeft;
            if (bottom && right) return BottomRight;
            if (left) return Left;
            if (top) return Top;
            if (right) return Right;
            if (bottom) return Bottom;
        }
        return None;
    }

    // Update the cursor shape based on the resize direction
    void updateCursorShape(const QPoint &pos) {
        ResizeDirection dir = getResizeDirection(pos);
        switch (dir) {
        case TopLeft:
        case BottomRight:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case TopRight:
        case BottomLeft:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case Left:
        case Right:
            setCursor(Qt::SizeHorCursor);
            break;
        case Top:
        case Bottom:
            setCursor(Qt::SizeVerCursor);
            break;
        default:
            unsetCursor(); // Reset to default cursor [[4]]
            break;
        }
    }

    // Handle mouse movement events [[6]]
    void mouseMoveEvent(QMouseEvent *event) override {
        if (m_isResizing) {
            // Calculate the offset from the initial mouse press position
            QPoint delta = event->globalPos() - m_lastMousePos;
            QRect newGeometry = m_startGeometry;

            // Adjust the widget's geometry based on the resize direction and mouse movement
            switch (m_resizeDirection) {
            case TopLeft:
                newGeometry.setTopLeft(newGeometry.topLeft() + delta);
                break;
            case TopRight:
                newGeometry.setTopRight(newGeometry.topRight() + delta);
                break;
            case BottomLeft:
                newGeometry.setBottomLeft(newGeometry.bottomLeft() + delta);
                break;
            case BottomRight:
                newGeometry.setBottomRight(newGeometry.bottomRight() + delta);
                break;
            case Left:
                newGeometry.setLeft(newGeometry.left() + delta.x());
                break;
            case Top:
                newGeometry.setTop(newGeometry.top() + delta.y());
                break;
            case Right:
                newGeometry.setRight(newGeometry.right() + delta.x());
                break;
            case Bottom:
                newGeometry.setBottom(newGeometry.bottom() + delta.y());
                break;
            default:
                break;
            }

            // Apply the new geometry to the widget
            setGeometry(newGeometry);
        } else {
            // If not resizing, update the cursor based on the current mouse position
            updateCursorShape(event->pos());
        }
        QWidget::mouseMoveEvent(event);
    }

    // Handle mouse press events to start resizing
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            m_isResizing = true;
            m_resizeDirection = getResizeDirection(event->pos());
            m_lastMousePos = event->globalPos(); // Store the initial global mouse position [[4]]
            m_startGeometry = geometry();       // Store the initial geometry
            // Optional: Capture mouse to ensure events are received even if mouse leaves widget
            // grabMouse();
        }
        QWidget::mousePressEvent(event);
    }

    // Handle mouse release events to stop resizing
    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && m_isResizing) {
            m_isResizing = false;
            m_resizeDirection = None;
            // Optional: Release mouse capture
            // releaseMouse();
            // Update cursor after releasing
            updateCursorShape(event->pos());
        }
        QWidget::mouseReleaseEvent(event);
    }

private:
    bool m_isResizing;                // Flag indicating if resizing is in progress
    ResizeDirection m_resizeDirection; // Current resize direction
    QPoint m_lastMousePos;            // Last recorded mouse position during resizing
    QRect m_startGeometry;            // Initial geometry when resizing started
};
