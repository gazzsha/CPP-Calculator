#ifndef _CPP3_SMART_CALC__SRC_MODEL_MODEL_H_
#define _CPP3_SMART_CALC__SRC_MODEL_MODEL_H_

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>
namespace s21 {

typedef enum {
  NUMBER,
  X,
  PLUS,
  UNARY_PLUS,
  MINUS,
  UNARY_MINUS,
  MUL,
  DIV,
  MOD,
  SIN,
  COS,
  TAN,
  LN,
  LOG,
  ASIN,
  ACOS,
  ATAN,
  DEGREE,
  SQRT,
  LEFT_BRACKET,
  RIGHT_BRACKET
} type_t;

class symbol {
 public:
  constexpr symbol(double value_, std::size_t priority_, type_t type_) noexcept
      : value(value_), priority(priority_), type(type_) {}
  constexpr double get_value() const noexcept { return value; }
  constexpr std::size_t get_priority() const noexcept { return priority; }
  constexpr type_t get_type() const noexcept { return type; }

 private:
  double value;
  std::size_t priority;
  type_t type;
};

class Validator {
 public:
  Validator() {}
  void parcer(const std::string &) noexcept;
  bool isValidExpression(const char *str) const noexcept;
  double ValidDataCredit(const char *monthString, const char *loanAmounString,
                         const char *interestRateString) const noexcept;

 protected:
  std::stack<symbol> stackOfSymbols = {};

 private:
  void upgrade_str(char *str) const noexcept;
  void validPlusMinus(bool &return_value, const size_t &i,
                      const char *str) const noexcept;
  void validRightBracket(size_t &count_bracket, bool &return_value,
                         const char &c) const noexcept;
  void validMulDiv(bool &return_value, const size_t &i,
                   const char *str) const noexcept;
  void validDegree(bool &return_value, const size_t &i,
                   const char *str) const noexcept;
  void validMod(bool &return_value, size_t &i, const char *str) const noexcept;
  void validCos(bool &return_value, size_t &i, const char *str) const noexcept;
  void validSqrtSin(bool &return_value, size_t &i,
                    const char *str) const noexcept;
  void validTan(bool &return_value, size_t &i, const char *str) const noexcept;
  void validAsinAcosAtan(bool &return_value, size_t &i,
                         const char *str) const noexcept;
  void validLogOrLn(bool &return_value, size_t &i,
                    const char *str) const noexcept;
  void validDot(bool &return_value, const size_t &i,
                const char *str) const noexcept;
  void validX(bool &return_value, const char *str, const int &i) const noexcept;
  bool isNumberChar(const char &c) const noexcept;
  bool symbolIsNull(const char &c) const noexcept;
  bool isLeftBracket(const char &c) const noexcept;
  bool isRightBracket(const char &c) const noexcept;
  bool isPlus(const char &c) const noexcept;
  bool isMinus(const char &c) const noexcept;
  bool isMul(const char &c) const noexcept;
  bool isDiv(const char &c) const noexcept;
  bool isDegree(const char &c) const noexcept;
  bool isOperatorMath(const char &c) const noexcept;
  bool isMod(const char *str) const noexcept;
  bool isCos(const char *str) const noexcept;
  bool isSin(const char *str) const noexcept;
  bool isTan(const char *str) const noexcept;
  bool isSqrt(const char *str) const noexcept;
  bool isLog(const char *str) const noexcept;
  bool isLn(const char *str) const noexcept;
  bool isAcos(const char *str) const noexcept;
  bool isAsin(const char *str) const noexcept;
  bool isAtan(const char *str) const noexcept;
};

class graphModel {
 public:
  void set_Xmax(const double &) noexcept;
  void set_Xmin(const double &) noexcept;
  void set_Ymin(const double &) noexcept;
  void set_Ymax(const double &) noexcept;
  void set_nameFunction(const char *) noexcept;
  std::string get_nameFunction() const noexcept;
  double get_Xmax() const noexcept;
  double get_Xmin() const noexcept;
  double get_Ymin() const noexcept;
  double get_Ymax() const noexcept;
  double get_step() const noexcept;

 private:
  double step = 0.1;
  double xMin, xMax, yMin, yMax;
  std::string nameFunction;
};

class Model : public Validator, public graphModel {
 public:
  Model() {}
  ~Model();
  double get_data() const noexcept;
  std::vector<double> get_xValueFunction() const;
  std::vector<double> get_yValueFunction() const;
  bool get_valid() const noexcept;
  double get_data_annuityRatio() const noexcept;
  double get_data_overpaymentLoan() const noexcept;
  double get_data_totalPayout() const noexcept;
  double get_data_month() const noexcept;
  const double *get_data_arrayOfMonthlyPayment_differentiatedPayment()
      const noexcept;
  void calculate(const char *str, const char *x);
  void annuityPaymentCalculation(const char *monthString,
                                 const char *loanAmounString,
                                 const char *interestRateString);
  void differentiatedPayment(const char *monthString,
                             const char *loanAmounString,
                             const char *interestRateString);
  void insertData();

 private:
  using Alloc = std::allocator<double>;
  using AllocTraits = std::allocator_traits<Alloc>;
  double result = 0.0f;
  bool isValid = false;
  double annuityRatio = 0.0f;
  double overpaymentLoan = 0.0f;
  double totalPayout = 0.0f;
  double *arrayOfMonthlyPayment = nullptr;
  double monthPayment = 0.0f;
  std::vector<double> xValueFunction, yValueFunction;
  Alloc alloc;
  void reverseStack() noexcept;
  void RMN(const char *str, const char *x) noexcept;
  void upgrade_str(char *str) const noexcept;
  void calculatingExpression() noexcept;
};

}  // namespace s21

#endif  // _CPP3_SMART_CALC__SRC_MODEL_MODEL_H_
