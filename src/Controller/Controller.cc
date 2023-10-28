#include "Controller.h"

namespace s21 {
Controller::Controller(Model* model_) : model(model_) {}
double Controller::calculate(const char* str, const char* x) {
  model->calculate(str, x);
  return model->get_data();
}
void Controller::set_Xmax(const double& d) noexcept { model->set_Xmax(d); }
void Controller::set_Xmin(const double& d) noexcept { model->set_Xmin(d); }
void Controller::set_Ymin(const double& d) noexcept { model->set_Ymin(d); }
void Controller::set_Ymax(const double& d) noexcept { model->set_Ymax(d); }
void Controller::set_nameFunction(const char* str) noexcept {
  model->set_nameFunction(str);
}
void Controller::insertData() { model->insertData(); }
double Controller::get_Xmax() const noexcept { return model->get_Xmax(); }
double Controller::get_Xmin() const noexcept { return model->get_Xmin(); }
double Controller::get_Ymax() const noexcept { return model->get_Ymax(); }
double Controller::get_Ymin() const noexcept { return model->get_Ymin(); }
std::vector<double> Controller::get_xValueFunction() const noexcept {
  return model->get_xValueFunction();
}
std::vector<double> Controller::get_yValueFunction() const noexcept {
  return model->get_yValueFunction();
}

std::string Controller::get_nameFunction() const noexcept {
  return model->get_nameFunction();
}

void Controller::annuityPaymentCalculation(const char* monthString,
                                           const char* loanAmounString,
                                           const char* interestRateString) {
  model->annuityPaymentCalculation(monthString, loanAmounString,
                                   interestRateString);
}
double Controller::get_data_annuityRatio() const noexcept {
  return model->get_data_annuityRatio();
}
double Controller::get_data_overpaymentLoan() const noexcept {
  return model->get_data_overpaymentLoan();
}
double Controller::get_data_totalPayout() const noexcept {
  return model->get_data_totalPayout();
}
void Controller::differentiatedPayment(const char* monthString,
                                       const char* loanAmounString,
                                       const char* interestRateString) {
  model->differentiatedPayment(monthString, loanAmounString,
                               interestRateString);
}
double Controller::get_data_month() const noexcept {
  return model->get_data_month();
}
const double* Controller::get_data_arrayOfMonthlyPayment_differentiatedPayment()
    const noexcept {
  return model->get_data_arrayOfMonthlyPayment_differentiatedPayment();
}
}  // namespace s21