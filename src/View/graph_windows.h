#ifndef GRAPH_WINDOWS_H
#define GRAPH_WINDOWS_H

#include <QDialog>
#include <QVector>
#include "qcustomplot.h"
#include "../Controller/Controller.h"
namespace Ui {
class Graph_Windows;
}


class Graph_Windows : public QDialog
{
    Q_OBJECT

public:
    explicit Graph_Windows(s21::Controller * controller_, QWidget *parent = nullptr);
    ~Graph_Windows();
    double xBegin,xEnd,h,X;
     QVector<double> x,y;
    double x_min,x_max,y_min,y_max;
     int flag_change;
    QString name_function;


private:
    Ui::Graph_Windows *ui;
    s21::Controller * controller;
    void print();
      void change_data();

private slots:
    void on_pushButton_clicked();

};

#endif // GRAPH_WINDOWS_H
