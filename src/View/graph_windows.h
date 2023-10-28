#ifndef GRAPH_WINDOWS_H
#define GRAPH_WINDOWS_H

#include <QDialog>
#include <QVector>

#include "../Controller/Controller.h"
#include "qcustomplot.h"
namespace Ui {
class Graph_Windows;
}

class Graph_Windows : public QDialog {
  Q_OBJECT

 public:
  explicit Graph_Windows(s21::Controller *controller_,
                         QWidget *parent = nullptr);
  ~Graph_Windows();
  void print();
  //   int flag_change;
 private:
  s21::Controller *controller;
  Ui::Graph_Windows *ui;

 private slots:
  void on_pushButton_clicked();
};

#endif  // GRAPH_WINDOWS_H
