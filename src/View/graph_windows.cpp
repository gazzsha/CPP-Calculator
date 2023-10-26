#include "graph_windows.h"
#include "ui_graph_windows.h"
Graph_Windows::Graph_Windows(s21::Controller * controller_, QWidget *parent) :
     controller(controller_),
    ui(new Ui::Graph_Windows),
   QDialog(parent)
{
    ui->setupUi(this);
    ui->widget->hide();
    ui->lineEdit_X_min->setPlaceholderText("Xmin");
    ui->lineEdit_X_min->setToolTip("Минимальное значение X");
    ui->lineEdit_X_max->setPlaceholderText("Xmax");
    ui->lineEdit_X_max->setToolTip("Максимальное значение X");
    ui->lineEdit_X_max->setValidator(new QDoubleValidator(-1000000, 1000000, 7, this));
    ui->lineEdit_X_min->setValidator(new QDoubleValidator(-1000000, 1000000, 7, this));
    ui->lineEdit_Y_min->setPlaceholderText("Ymin");
    ui->lineEdit_Y_min->setToolTip("Минимальное значение Y");
    ui->lineEdit_Y_max->setPlaceholderText("Ymax");
    ui->lineEdit_Y_max->setToolTip("Максимальное значение Y");
    ui->lineEdit_Y_max->setValidator(new QDoubleValidator(-1000000, 1000000, 7, this));
    ui->lineEdit_Y_min->setValidator(new QDoubleValidator(-1000000, 1000000, 7, this));
    ui->lineEdit_expression->setPlaceholderText("Введите выражение");
}


Graph_Windows::~Graph_Windows()
{
    delete ui;
}

void Graph_Windows::on_pushButton_clicked()
{
  //  print();
}

//void Graph_Windows::print()
//{

//    ui->widget->show();
//    ui->widget->addGraph();
//    if (ui->lineEdit_X_max->isModified() || ui->lineEdit_X_min->isModified() || ui->lineEdit_Y_max->isModified()
//        || ui->lineEdit_Y_min->isModified() || ui->lineEdit_expression->isModified()) flag_change = 1; else flag_change = 0;
//    if (ui->lineEdit_X_max->isModified()) {
//        x_max = ui->lineEdit_X_max->text().replace(',','.').toDouble();
//    }
//    if (ui->lineEdit_X_min->isModified()) {
//        x_min = ui->lineEdit_X_min->text().replace(',','.').toDouble();
//    }
//    if (ui->lineEdit_Y_max->isModified()) {
//        y_max = ui->lineEdit_Y_max->text().replace(',','.').toDouble();
//    }
//    if (ui->lineEdit_Y_min->isModified()) {
//        y_min = ui->lineEdit_Y_min->text().replace(',','.').toDouble();
//    }
//    if (ui->lineEdit_expression->isModified()) {
//        name_function = ui->lineEdit_expression->text();
//    }
//    QByteArray QByte_name_function = name_function.toLocal8Bit();
//    char * str_name_function = QByte_name_function.data();
//    if (!is_valid_expression(str_name_function) && (name_function.contains('x') || name_function.contains('X'))) {
//    if (flag_change) change_data();
//    ui->widget->graph(0)->addData(x,y);
//    ui->widget->xAxis->setRange(x_min,x_max);
//    ui->widget->yAxis->setRange(y_min,y_max);
//    ui->widget->xAxis->setLabel("Ox");
//    ui->widget->yAxis->setLabel("Oy");
//    ui->widget->xAxis->grid()->setSubGridVisible(true);
//     ui->widget->yAxis->grid()->setSubGridVisible(true);
//    ui->widget->xAxis->setNumberFormat("gbc"); // g Гибкий формат, B Прекрасная форма индекса, C-масштаб C-увеличение изменяется на ×
//    ui->widget->xAxis->setNumberPrecision (1);
//    ui->widget->replot();
//    flag_change = 0;
//    } else {
//    QMessageBox::critical(this,"Предупреждение","Введите коррентную функцию");
//    }
//}

//void Graph_Windows::change_data()
//{
//    ui->widget->graph(0)->data()->clear();
//    x.clear();
//    y.clear();
//    QByteArray QByte_name_function = name_function.toLocal8Bit();
//    char * str_name_function = QByte_name_function.data();
//    for (X=x_min; X <= x_max; X += h) {
//        x.push_back(X);
//        QString Qx = QString::number(X);
//        QByteArray QByte_x = Qx.toLocal8Bit();
//        char * str_x = QByte_x.data();
//        y.push_back(calculate(str_name_function,str_x));
//    }
//}

