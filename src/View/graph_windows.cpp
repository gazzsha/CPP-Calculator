#include "graph_windows.h"

#include "ui_graph_windows.h"
Graph_Windows::Graph_Windows(s21::Controller *controller_, QWidget *parent)
    : controller(controller_),
      QDialog(parent),
      ui(new Ui::Graph_Windows)

{
  ui->setupUi(this);
  ui->widget->hide();
  ui->lineEdit_X_min->setPlaceholderText("Xmin");
  ui->lineEdit_X_min->setToolTip("Минимальное значение X");
  ui->lineEdit_X_max->setPlaceholderText("Xmax");
  ui->lineEdit_X_max->setToolTip("Максимальное значение X");
  ui->lineEdit_X_max->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_X_min->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_Y_min->setPlaceholderText("Ymin");
  ui->lineEdit_Y_min->setToolTip("Минимальное значение Y");
  ui->lineEdit_Y_max->setPlaceholderText("Ymax");
  ui->lineEdit_Y_max->setToolTip("Максимальное значение Y");
  ui->lineEdit_Y_max->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_Y_min->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_expression->setPlaceholderText("Введите выражение");
}

Graph_Windows::~Graph_Windows() { delete ui; }

void Graph_Windows::on_pushButton_clicked() { print(); }

void Graph_Windows::print() {
  ui->widget->show();
  ui->widget->addGraph();
  if (ui->lineEdit_X_max->isModified()) {
    controller->set_Xmax(
        ui->lineEdit_X_max->text().replace(',', '.').toDouble());
  }
  if (ui->lineEdit_X_min->isModified()) {
    controller->set_Xmin(
        ui->lineEdit_X_min->text().replace(',', '.').toDouble());
  }
  if (ui->lineEdit_Y_max->isModified()) {
    controller->set_Ymax(
        ui->lineEdit_Y_max->text().replace(',', '.').toDouble());
  }
  if (ui->lineEdit_Y_min->isModified()) {
    controller->set_Ymin(
        ui->lineEdit_Y_min->text().replace(',', '.').toDouble());
  }
  if (ui->lineEdit_expression->isModified()) {
    QString expressionString = ui->lineEdit_expression->text();
    QByteArray strBit = expressionString.toLocal8Bit();
    const char *expression = strBit.data();
    controller->set_nameFunction(expression);
  }
  try {
    ui->widget->graph(0)->data()->clear();
    controller->insertData();
    std::vector<double> xValueFunction = controller->get_xValueFunction();
    std::vector<double> yValueFunction = controller->get_yValueFunction();
    QVector<double> xValueFunctionQt(xValueFunction.begin(),
                                     xValueFunction.end());
    QVector<double> yValueFunctionQt(yValueFunction.begin(),
                                     yValueFunction.end());
    ui->widget->graph(0)->addData(xValueFunctionQt, yValueFunctionQt);
    ui->widget->xAxis->setRange(controller->get_Xmin(), controller->get_Xmax());
    ui->widget->yAxis->setRange(controller->get_Ymin(), controller->get_Ymax());
    ui->widget->xAxis->setLabel("Ox");
    ui->widget->yAxis->setLabel("Oy");
    ui->widget->xAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->xAxis->setNumberFormat(
        "gbc");  // g Гибкий формат, B Прекрасная форма индекса, C-масштаб
                 // C-увеличение изменяется на ×
    ui->widget->xAxis->setNumberPrecision(1);
    ui->widget->replot();
  } catch (...) {
    QMessageBox::critical(this, "Предупреждение", "Введите коррентную функцию");
  }
}
