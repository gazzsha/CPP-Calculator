#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <iomanip>
#include <QDoubleValidator>
#include "graph_windows.h"
#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(s21::Controller * controller_, QWidget *parent = nullptr);
    ~MainWindow();
private:
    s21::Controller * controller;
    Graph_Windows * win_graph;
    Ui::MainWindow *ui;
private slots:
    void digit_buttom_numbers();
    void buttom_equal();
    void math_operand();
    void push_ac();
    void push_del();
    void set_constants();
    QString edit_textLine();
    void set_dot();
    void on_action_2_triggered();
    void on_action_3_triggered();
  void get_sum_of_month();
    void on_pushButton_graph_clicked();
};
#endif // MAINWINDOW_H
