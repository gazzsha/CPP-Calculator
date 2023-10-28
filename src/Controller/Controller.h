#ifndef _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_
#define _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/Model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model* model_);
  double calculate(const char* str, const char* x);
  void set_Xmax(const double& d) noexcept;
  void set_Xmin(const double& d) noexcept;
  void set_Ymin(const double& d) noexcept;
  void set_Ymax(const double& d) noexcept;
  void set_nameFunction(const char* str) noexcept;
  void insertData();
  double get_Xmax() const noexcept;
  double get_Xmin() const noexcept;
  double get_Ymax() const noexcept;
  double get_Ymin() const noexcept;
  std::vector<double> get_xValueFunction() const noexcept;
  std::vector<double> get_yValueFunction() const noexcept;

  std::string get_nameFunction() const noexcept;

  void annuityPaymentCalculation(const char* monthString,
                                 const char* loanAmounString,
                                 const char* interestRateString);
  double get_data_annuityRatio() const noexcept;
  double get_data_overpaymentLoan() const noexcept;
  double get_data_totalPayout() const noexcept;
  void differentiatedPayment(const char* monthString,
                             const char* loanAmounString,
                             const char* interestRateString);
  double get_data_month() const noexcept;
  const double* get_data_arrayOfMonthlyPayment_differentiatedPayment()
      const noexcept;

 private:
  Model* model;
};
}  // namespace s21

#endif  // _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_
