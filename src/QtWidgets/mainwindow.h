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

extern "C" {
#include "s21_SmartCalc.h"
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Graph_Windows * win_graph;
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
