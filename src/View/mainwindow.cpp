#include "mainwindow.h"

#include <QMessageBox>
#include <QStackedWidget>
#include <QVector>

#include "qcustomplot.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(s21::Controller *controller_, QWidget *parent)
    : controller(controller_), QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_number_0, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_1, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_2, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_3, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_4, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_5, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_6, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_7, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_8, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_number_9, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(buttom_equal()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operand()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operand()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operand()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operand()));
  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(push_ac()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(push_del()));
  connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(set_constants()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(set_constants()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(digit_buttom_numbers()));
  connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(edit_textLine()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(set_dot()));
  connect(ui->pushButton_getResult, SIGNAL(clicked()), this,
          SLOT(get_sum_of_month()));
  ui->lineEdit_count_month->setValidator(new QIntValidator(1, 10000));
  ui->lineEdit_sum->setValidator(new QDoubleValidator(0, 1e255, 2, this));
  ui->lineEdit_ratio->setValidator(new QDoubleValidator(0, 1e3, 2, this));
  ui->textBrowser->hide();
  ui->lineEdit_X_min->setPlaceholderText("Xmin");
  ui->lineEdit_X_min->setToolTip("Минимальное значение X");
  ui->lineEdit_X_max->setPlaceholderText("Xmax");
  ui->lineEdit_X_max->setToolTip("Максимальное значение X");
  ui->lineEdit->setPlaceholderText("X");
  ui->lineEdit->setToolTip("Введите значение X");
  ui->lineEdit->setValidator(new QDoubleValidator(-1e255, 1e255, 7, this));
  ui->lineEdit_X_max->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_X_min->setValidator(
      new QDoubleValidator(-1000000, 1000000, 7, this));
  ui->lineEdit_Y_min->setPlaceholderText("Ymin");
  ui->lineEdit_Y_min->setToolTip("Минимальное значение Y");
  ui->lineEdit_Y_max->setPlaceholderText("Ymax");
  ui->lineEdit_Y_max->setToolTip("Максимальное значение Y");
}

MainWindow::~MainWindow() {
  delete ui;
  //delete win_graph;
}

void MainWindow::digit_buttom_numbers() {
  if (ui->result_show->text() == "Incorrect") {
    ui->result_show->clear();
  }
  QString new_label = NULL;
  QPushButton *button = ((QPushButton *)sender());
  new_label += ui->result_show->text() + button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::buttom_equal() {
  QString expressionString = ui->result_show->text();
  ui->result_show->setText(expressionString);
  QByteArray str_bit = expressionString.toLocal8Bit();
  const char *expression = str_bit.data();
  QString double_x = MainWindow::edit_textLine();
  QByteArray str_bit_x = double_x.toLocal8Bit();
  const char *xValue = str_bit_x.data();
  try {
    double result = controller->calculate(expression, xValue);
    expressionString = QString::number(result, 'g', 15);
    ui->result_show->setText(expressionString);
  } catch (std::logic_error const &) {
    ui->result_show->setText("Incorrect");
  }
}

void MainWindow::math_operand() {
  QString new_label = NULL;
  QPushButton *button = ((QPushButton *)sender());
  new_label += ui->result_show->text() + button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::push_ac() { ui->result_show->clear(); }

void MainWindow::push_del() {
  QString expression = ui->result_show->text();
  if (!expression.isEmpty()) {
    expression.remove(expression.length() - 1, 1);
    ui->result_show->setText(expression);
  }
}

void MainWindow::set_constants() {
  QPushButton *button = ((QPushButton *)sender());
  if (button->objectName() == "pushButton_pi") {
    ui->result_show->setText(ui->result_show->text() + QString::number(M_PI));
  } else if (button->objectName() == "pushButton_exp") {
    ui->result_show->setText(ui->result_show->text() + QString::number(exp(1)));
  }
}

void MainWindow::set_dot() {
  if (!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text() + ".");
}

QString MainWindow::edit_textLine() {
  QString double_x =
      ui->lineEdit->text().isEmpty() ? QString("0") : ui->lineEdit->text();
  return double_x;
}

void MainWindow::on_action_2_triggered() {
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_action_3_triggered() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::get_sum_of_month() {
  ui->textBrowser->clear();
  ui->textBrowser->hide();
  if (ui->radioButton_an->isChecked()) {
    try {
      controller->annuityPaymentCalculation(
          ui->lineEdit_count_month->text().toLocal8Bit().data(),
          ui->lineEdit_sum->text().replace(',', '.').toLocal8Bit().data(),
          ui->lineEdit_ratio->text().replace(',', '.').toLocal8Bit().data());
      ui->result->setText(
          "Ежемесячный платеж - " +
          QString::number(controller->get_data_annuityRatio(), 'f', 7) +
          " P\n" + "Переплата по кредиту - " +
          QString::number(controller->get_data_overpaymentLoan(), 'f', 7) +
          " P\n" + "Общая выплата - " +
          QString::number(controller->get_data_totalPayout(), 'f', 7) + " P");
    } catch (...) {
      QMessageBox::critical(this, "Предупреждение", "Что-то пошло не так...");
    }
  } else {
    ui->textBrowser->show();
    try {
      controller->differentiatedPayment(
          ui->lineEdit_count_month->text().toLocal8Bit().data(),
          ui->lineEdit_sum->text().replace(',', '.').toLocal8Bit().data(),
          ui->lineEdit_ratio->text().replace(',', '.').toLocal8Bit().data());
      ui->result->setText(
          "Переплата по кредиту - " +
          QString::number(controller->get_data_overpaymentLoan(), 'f', 7) +
          " P\n" + "Общая выплата - " +
          QString::number(controller->get_data_totalPayout(), 'f', 7) + " P");
      ui->textBrowser->append("№ Платеж по процентам\n");
      const double *array =
          controller->get_data_arrayOfMonthlyPayment_differentiatedPayment();
      for (int i = 0; i < int(controller->get_data_month()); i++)
        ui->textBrowser->append(QString::number(i + 1) + " - " +
                                QString::number(array[i]) + "\n");
    } catch (...) {
      QMessageBox::critical(this, "Предупреждение", "Что-то пошло не так...");
    }
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  try {
    if (ui->lineEdit_X_max->isModified() && ui->lineEdit_X_min->isModified() &&
        ui->lineEdit_Y_max->isModified() && ui->lineEdit_Y_min->isModified() &&
        !ui->result_show->text().isEmpty()) {
      controller->set_Xmax(
          ui->lineEdit_X_max->text().replace(',', '.').toDouble());
      controller->set_Xmin(
          ui->lineEdit_X_min->text().replace(',', '.').toDouble());
      controller->set_Ymax(
          ui->lineEdit_Y_max->text().replace(',', '.').toDouble());
      controller->set_Ymin(
          ui->lineEdit_Y_min->text().replace(',', '.').toDouble());
      QString expressionString = ui->result_show->text();
      QByteArray strBit = expressionString.toLocal8Bit();
      const char *expression = strBit.data();
      controller->set_nameFunction(expression);
      win_graph = new Graph_Windows(controller, this);
      win_graph->show();
    } else {
      QMessageBox::critical(this, "Предупреждение", "Введите данные!");
    }
  } catch (...) {
    QMessageBox::critical(this, "Предупреждение", "Что-то пошло не так...");
  }
}
