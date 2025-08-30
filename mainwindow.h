#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include "framelessmainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public FramelessMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_window_clicked();

    void on_pushButton_small_clicked();

private:
    Ui::MainWindow *ui;
    bool bIsWindow_=true;
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);;

private:
    void Init();


};
#endif // MAINWINDOW_H
