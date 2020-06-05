#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <string>
#include <QFont>
#include <qstring.h>

using std::string;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void calculate();
private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
