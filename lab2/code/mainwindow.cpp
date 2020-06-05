#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Shape.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calculate();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);             // 创建QPainter一个对象
        QPen pen;


        //画圆
        painter.drawEllipse(QPoint(width()/2,height()/2),100,100);

        // 画一个四边形
        QPolygonF polygon;
        polygon << QPointF(350.0, 20.0) << QPointF(430.0, 30.0) << QPointF(430.0, 80.0) << QPointF(370.0, 90.0);
        painter.drawPolygon(polygon, Qt::WindingFill);


        // 画一个空心正方形
        pen.setColor(Qt::black);
        painter.setPen(pen);
        painter.drawRect(QRect(1, 1, 100, 100));

        // 画一个实心正方形
        QBrush bruch(Qt::green);     // 画刷
        painter.setBrush(bruch);        // 设置画刷
        painter.drawRect(QRect(110, 1, 200, 100));


        // 画一个多边形
        QPolygonF polygon2;
        polygon2 << QPointF(200.0, 320.0) << QPointF(230.0, 230.0) << QPointF(300.0, 320.0) << QPointF(260.0, 400.0)<< QPointF(200.0, 400.0);
        painter.drawPolygon(polygon2, Qt::WindingFill);




}

void MainWindow::calculate()
{
    Square square(1,1,200);  
    string a=u8"正方形的面积是: "+std::to_string(square.getArea());

    Quadrangle aa(10,10,20,20,30,30,40,40);
    string b=u8"无规则四边形的周长是"+std::to_string(aa.getPerimeter());
    string c=u8"无规则四边形的面积是"+std::to_string(aa.getArea() );

    Circle ci(1,2,3);
    string d=u8"圆的面积是:"+std::to_string(ci.getArea());
    string e=u8"圆的周长是:"+std::to_string(ci.getPerimeter());
    string temp=a+'\n'+b+'\n'+c+'\n'+d+'\n'+e;
    ui->textEdit->setText(QString::fromStdString(temp));

}


