#ifndef GRAPH_WINDOWS_H
#define GRAPH_WINDOWS_H

#include <QDialog>
#include <QVector>
#include "qcustomplot.h"
namespace Ui {
class Graph_Windows;
}

extern "C" {
#include "s21_SmartCalc.h"
}

class Graph_Windows : public QDialog
{
    Q_OBJECT

public:
    explicit Graph_Windows(QWidget *parent = nullptr);
    ~Graph_Windows();
    double xBegin,xEnd,h,X;
     QVector<double> x,y;
    double x_min,x_max,y_min,y_max;
     int flag_change;
    QString name_function;


private:
    Ui::Graph_Windows *ui;
    void print();
      void change_data();

private slots:
    void on_pushButton_clicked();

};

#endif // GRAPH_WINDOWS_H
