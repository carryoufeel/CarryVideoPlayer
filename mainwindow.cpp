#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <windows.h>
MainWindow::MainWindow(QWidget *parent) : FramelessMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setMouseTracking(true);
    this->setTitleBar(ui->widget_title);
    this->setStyleSheet("background-color:rgb(229,229,234);");
    ui->widget_title->setStyleSheet("QWidget {border: none;}");
    ui->widget_head->setStyleSheet("QWidget {border: none;}");
    ui->pushButton_close->setStyleSheet("QPushButton {"
                                  " border-radius: 5px;"
                                  "  background-color: rgba(0,0,0,0);"
                                  "  border: 0px solid #D3D3D3;"
                                  "  color:black;"
                                  "}"
                                  // 设置按钮在鼠标悬浮时的样式
                                  "QPushButton:hover {"

                                  "  background-color: rgba(0,0,0,0);"
                                  "  border: 1px solid #87CEFA;"
                                  "}"
                                  // 设置按钮在被按下时的样式
                                  "QPushButton:pressed {"
                                  "  background-color: rgba(0,0,0,0);"
                                  "  border: 1px solid #00BFFF;"
                                  "}");
    ui->pushButton_small->setStyleSheet("QPushButton {"
                                        " border-radius: 5px;"
                                        "  background-color: rgba(0,0,0,0);"
                                        "  border: 0px solid #D3D3D3;"
                                        "  color:black;"
                                        "}"
                                        // 设置按钮在鼠标悬浮时的样式
                                        "QPushButton:hover {"

                                        "  background-color: rgba(0,0,0,0);"
                                        "  border: 1px solid #87CEFA;"
                                        "}"
                                        // 设置按钮在被按下时的样式
                                        "QPushButton:pressed {"
                                        "  background-color: rgba(0,0,0,0);"
                                        "  border: 1px solid #00BFFF;"
                                        "}");
    ui->pushButton_close->setText("×");
    ui->pushButton_small->setText("-");
    ui->pushButton_close->setFixedSize(50,20);
    ui->pushButton_small->setFixedSize(50,20);
    QFont fontTitle;
    fontTitle.setFamily("黑体");
    fontTitle.setPixelSize(20);
    ui->pushButton_close->setFont(fontTitle);
    ui->pushButton_small->setFont(fontTitle);
    ui->centralwidget->setStyleSheet(R"(
        QWidget {
            background-color: palette(window);
            border: 1px solid gray;
            border-radius: 10px;
        }
    )");

    ui->centralwidget->setAttribute(Qt::WA_TranslucentBackground);
    shadow->setOffset(0, 0);
    shadow->setColor(Qt::black);
    shadow->setBlurRadius(10);
    ui->centralwidget->setGraphicsEffect(shadow);
    bIsWindow_=true;
    ui->pushButton_window->setVisible(false);
    //connect(ui->pushButton_window, &QPushButton::clicked, this, &FramelessMainWindow::showMaximized);
}


void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_window_clicked()
{
    // HWND hwnd = reinterpret_cast<HWND>(this->winId());
    // if(bIsWindow_)
    // {
    //     QPointF localPos(ui->widget->width() / 2.0, ui->widget->height() / 2.0);
    //     // globalPos 是屏幕上的绝对坐标
    //     QPointF globalPos = ui->widget->mapToGlobal(localPos.toPoint());

    //     LRESULT hitTestResult = SendMessage(hwnd, WM_NCHITTEST, 0, MAKELPARAM(globalPos.x(), globalPos.y()));
    //     qDebug() << "Hit Test Result:" << hitTestResult; // 应该是 HTCAPTION (2) 或其他区域值
    //     bIsWindow_=false;
    // }
    // else
    // {
    //     QPointF localPos(ui->widget->width() / 2.0, ui->widget->height() / 2.0);
    //     // globalPos 是屏幕上的绝对坐标
    //     QPointF globalPos = ui->widget->mapToGlobal(localPos.toPoint());

    //     // 创建并发送第一次鼠标按下事件
    //     QMouseEvent pressEvent1(QEvent::MouseButtonPress, localPos, globalPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    //     QMouseEvent releaseEvent1(QEvent::MouseButtonRelease, localPos, globalPos, Qt::LeftButton, Qt::NoButton, Qt::NoModifier);
    //     QMouseEvent pressEvent2(QEvent::MouseButtonPress, localPos, globalPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    //     QMouseEvent releaseEvent2(QEvent::MouseButtonRelease, localPos, globalPos, Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    //     QApplication::sendEvent(ui->widget, &pressEvent1);
    //     QApplication::sendEvent(ui->widget, &releaseEvent1);
    //     QApplication::sendEvent(ui->widget, &pressEvent2);
    //     QApplication::sendEvent(ui->widget, &releaseEvent2);
    //     bIsWindow_=true;
    // }
}


void MainWindow::on_pushButton_small_clicked()
{
    this->showMinimized();
}



