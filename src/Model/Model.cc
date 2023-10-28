#include "Model.h"

namespace s21 {
bool Validator::isValidExpression(const char *str) const noexcept {
  bool return_value = true;
  if (str == NULL)
    return_value = false;
  else if (strlen(str) == 0)
    return_value = false;
  else {
    size_t count_of_bracket = 0;
    for (size_t i = 0; i < strlen(str); ++i) {
      switch (str[i]) {
        case '(': {
          count_of_bracket++;
          break;
        }
        case ')': {
          validRightBracket(count_of_bracket, return_value, str[i - 1]);
          break;
        }
        case '+':
        case '-': {
          validPlusMinus(return_value, i, str);
          break;
        }
        case '*':
        case '/': {
          validMulDiv(return_value, i, str);
          break;
        }
        case '^': {
          validDegree(return_value, i, str);
          break;
        }
        case 'm': {
          validMod(return_value, i, str);
          break;
        }
        case 'c': {
          validCos(return_value, i, str);
          break;
        }
        case 's': {
          validSqrtSin(return_value, i, str);
          break;
        }
        case 't': {
          validTan(return_value, i, str);
          break;
        }
        case 'l': {
          validLogOrLn(return_value, i, str);
          break;
        }
        case 'a': {
          validAsinAcosAtan(return_value, i, str);
          break;
        }
        case '.': {
          validDot(return_value, i, str);
          break;
        }
        case 'x': {
          validX(return_value, str, i);
          break;
        }
        case 'X': {
          validX(return_value, str, i);
          break;
        }
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0': {
          break;
        }
        default:
          return_value = false;
          break;
      }
    }
    if (count_of_bracket != 0) return_value = false;
  }
  return return_value;
}

void graphModel::set_Xmax(const double &d) noexcept { xMax = d; }

void graphModel::set_Xmin(const double &d) noexcept { xMin = d; }

void graphModel::set_Ymax(const double &d) noexcept { yMax = d; }

void graphModel::set_Ymin(const double &d) noexcept { yMin = d; }

void graphModel::set_nameFunction(const char *str) noexcept {
  nameFunction = std::move(std::string(str));
}

double graphModel::get_Xmax() const noexcept { return xMax; }
double graphModel::get_Xmin() const noexcept { return xMin; }

double graphModel::get_Ymax() const noexcept { return yMax; }

double graphModel::get_Ymin() const noexcept { return yMin; }
double graphModel::get_step() const noexcept { return step; }
std::string graphModel::get_nameFunction() const noexcept {
  return nameFunction;
}

Model::~Model() {
  AllocTraits::deallocate(alloc, arrayOfMonthlyPayment, get_data_month());
}

double Model::get_data() const noexcept { return result; }

bool Model::get_valid() const noexcept { return isValid; }

double Model::get_data_annuityRatio() const noexcept { return annuityRatio; }

double Model::get_data_overpaymentLoan() const noexcept {
  return overpaymentLoan;
}

double Model::get_data_totalPayout() const noexcept { return totalPayout; }

const double *Model::get_data_arrayOfMonthlyPayment_differentiatedPayment()
    const noexcept {
  return arrayOfMonthlyPayment;
}

double Model::get_data_month() const noexcept { return monthPayment; }

void Model::calculate(const char *str, const char *x) {
  isValid = isValidExpression(str);
  if (isValid) {
    std::string s(str);
    char *strNew = s.data();
    upgrade_str(strNew);
    RMN(strNew, x);
    calculatingExpression();
  } else
    throw std::logic_error("Wrong expression!");
}

void Model::reverseStack() noexcept {
  std::stack<symbol> support;
  while (!stackOfSymbols.empty()) {
    support.emplace(stackOfSymbols.top().get_value(),
                    stackOfSymbols.top().get_priority(),
                    stackOfSymbols.top().get_type());
    stackOfSymbols.pop();
  }
  stackOfSymbols = std::move(support);
}

void Model::upgrade_str(char *str) const noexcept {
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == '+' || str[i] == '-') {
      if (i == 0) {
        if (str[i] == '+')
          str[i] = '>';
        else
          str[i] = '<';
      } else {
        if (str[i - 1] == '(') {
          if (str[i] == '+') {
            str[i] = '>';
          } else {
            str[i] = '<';
          }
        }
      }
    }
  }
}
void Validator::parcer(const std::string &expression) noexcept {
  for (size_t i = 0; i < expression.length(); ++i) {
    switch (expression[i]) {
      case '+': {
        stackOfSymbols.emplace(0, 1, PLUS);
        break;
      }
      case '-': {
        stackOfSymbols.emplace(0, 1, MINUS);
        break;
      }
      case '*': {
        stackOfSymbols.emplace(0, 2, MUL);
        break;
      }
      case '/': {
        stackOfSymbols.emplace(0, 2, DIV);
        break;
      }
      case 'm': {
        stackOfSymbols.emplace(0, 2, MOD);
        i += 2;
        break;
      }
      case '^': {
        stackOfSymbols.emplace(0, 4, DEGREE);
        break;
      }
      case 'c': {
        stackOfSymbols.emplace(0, 3, COS);
        i += 2;
        break;
      }
      case 't': {
        stackOfSymbols.emplace(0, 3, TAN);

        i += 2;
        break;
      }
      case 's': {
        if (expression[i + 1] == 'i') {
          stackOfSymbols.emplace(0, 3, SIN);
          i += 2;
        } else {
          stackOfSymbols.emplace(0, 4, SQRT);
          i += 3;
        }
        break;
      }
      case 'l': {
        if (expression[i + 1] == 'n') {
          stackOfSymbols.emplace(0, 3, LN);
          i += 1;
        } else {
          stackOfSymbols.emplace(0, 3, LOG);
          i += 2;
        }
        break;
      }
      case 'a': {
        if (expression[i + 1] == 'c') {
          stackOfSymbols.emplace(0, 3, ACOS);
        } else if (expression[i + 1] == 's') {
          stackOfSymbols.emplace(0, 3, ASIN);
        } else {
          stackOfSymbols.emplace(0, 3, ATAN);
        }
        i += 3;
        break;
      }
      case '(': {
        stackOfSymbols.emplace(0, 5, LEFT_BRACKET);
        break;
      }
      case ')': {
        stackOfSymbols.emplace(0, 5, RIGHT_BRACKET);
        break;
      }
      case '<': {
        stackOfSymbols.emplace(0, 1, UNARY_MINUS);
        break;
      }
      case '>': {
        stackOfSymbols.emplace(0, 1, UNARY_PLUS);
        break;
      }
      default: {
        if (isNumberChar(expression[i])) {
          char number[256] = "";
          int j = 0;
          while ((isNumberChar(expression[i]) || expression[i] == '.') &&
                 expression[i] != '\0') {
            number[j++] = expression[i];
            i++;
          }
          i -= 1;
          stackOfSymbols.emplace(std::atof(number), 0, NUMBER);
        } else {
          stackOfSymbols.emplace(1, 0, X);
        }
        break;
      }
    }
  }
}

void Validator::validRightBracket(size_t &count_bracket, bool &return_value,
                                  const char &c) const noexcept {
  if (count_bracket > 0) {
    (count_bracket)--;
    if (isLeftBracket(c) || isOperatorMath(c)) return_value = false;
  } else
    return_value = false;
}

void Validator::validPlusMinus(bool &return_value, const size_t &i,
                               const char *str) const noexcept {
  if (symbolIsNull(str[i + 1]))
    return_value = false;
  else if (isRightBracket(str[i + 1]) || isOperatorMath(str[i + 1]))
    return_value = false;
}

void Validator::validMulDiv(bool &return_value, const size_t &i,
                            const char *str) const noexcept {
  if (symbolIsNull(str[i + 1]))
    return_value = false;
  else if (i != 0) {
    if ((isLeftBracket(str[i - 1])) || isRightBracket(str[i + 1]) ||
        isOperatorMath(str[i - 1]) || isOperatorMath(str[i + 1]))
      return_value = false;
  } else
    return_value = false;
}

void Validator::validDegree(bool &return_value, const size_t &i,
                            const char *str) const noexcept {
  if (symbolIsNull(str[i + 1]))
    return_value = false;
  else if (i != 0) {
    if ((isLeftBracket(str[i - 1])) || isRightBracket(str[i + 1]) ||
        isOperatorMath(str[i - 1]) || isOperatorMath(str[i + 1]))
      return_value = false;
  } else
    return_value = false;
}

void Validator::validMod(bool &return_value, size_t &i,
                         const char *str) const noexcept {
  if (strlen(str + i) > 3) {
    size_t pos_last = i;
    if (isMod(str + i))
      i += 2;
    else
      return_value = false;
    if (return_value) {
      if (isOperatorMath(str[pos_last - 1]) || isOperatorMath(str[i + 1]) ||
          isLeftBracket(str[pos_last - 1]) || isRightBracket(str[i + 1]))
        return_value = false;
    }
  } else
    return_value = false;
}

void Validator::validCos(bool &return_value, size_t &i,
                         const char *str) const noexcept {
  if (strlen(str + i) > 3) {
    if (isCos(str + i))
      i += 2;
    else
      return_value = false;
    if (return_value == true) {
      if (isOperatorMath(str[i + 1]) || isRightBracket(str[i + 1]))
        return_value = false;
    }
  } else
    return_value = false;
}
void Validator::validSqrtSin(bool &return_value, size_t &i,
                             const char *str) const noexcept {
  if (str[i + 1] == 'i') {
    if (strlen(str + i) > 3) {
      if (isSin(str + i))
        i += 2;
      else
        return_value = false;
      if (return_value) {
        if (isOperatorMath(str[i + 1]) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else if (str[i + 1] == 'q') {
    if (strlen(str + i) > 4) {
      if (isSqrt(str + i))
        i += 3;
      else
        return_value = false;
      if (return_value) {
        if (isOperatorMath(str[i + 1]) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else
    return_value = false;
}
void Validator::validTan(bool &return_value, size_t &i,
                         const char *str) const noexcept {
  if (strlen(str + i) > 3) {
    if (isTan(str + i))
      i += 2;
    else
      return_value = false;
    if (return_value == true) {
      if (isOperatorMath(str[i + 1]) || isRightBracket(str[i + 1]))
        return_value = false;
    }
  } else
    return_value = false;
}
void Validator::validAsinAcosAtan(bool &return_value, size_t &i,
                                  const char *str) const noexcept {
  if (str[i + 1] == 's') {
    if (strlen(str + i) > 4) {
      if (isAsin(str + i))
        i += 3;
      else
        return_value = false;
      if (return_value) {
        if ((isOperatorMath(str[i + 1])) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else if (str[i + 1] == 'c') {
    if (strlen(str + i) > 4) {
      if (isAcos(str + i))
        i += 3;
      else
        return_value = false;
      if (return_value) {
        if ((isOperatorMath(str[i + 1]) == true) ||
            isRightBracket(str[i + 1] == true))
          return_value = false;
      }
    } else
      return_value = false;
  } else if (str[i + 1] == 't') {
    if (strlen(str + i) > 4) {
      if (isAtan(str + i))
        i += 3;
      else
        return_value = false;
      if (return_value == true) {
        if ((isOperatorMath(str[i + 1])) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else
    return_value = false;
}
void Validator::validLogOrLn(bool &return_value, size_t &i,
                             const char *str) const noexcept {
  if (str[i + 1] == 'o') {
    if (strlen(str + i) > 3) {
      if (isLog(str + i))
        i += 2;
      else
        return_value = false;
      if (return_value) {
        if ((isOperatorMath(str[i + 1])) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else if (str[i + 1] == 'n') {
    if (strlen(str + i) > 2) {
      if (isLn(str + i))
        i += 1;
      else
        return_value = false;
      if (return_value) {
        if ((isOperatorMath(str[i + 1])) || isRightBracket(str[i + 1]))
          return_value = false;
      }
    } else
      return_value = false;
  } else
    return_value = false;
}

void Validator::validDot(bool &return_value, const size_t &i,
                         const char *str) const noexcept {
  if (i != 0) {
    if (symbolIsNull(str[i + 1]))
      return_value = false;
    else if (isNumberChar(str[i - 1]) == false ||
             isNumberChar(str[i + 1]) == false)
      return_value = false;
  } else
    return_value = false;
}

void Validator::validX(bool &return_value, const char *str,
                       const int &i) const noexcept {
  if (i != 0) {
    if (isNumberChar(str[i - 1]) || isNumberChar(str[i + 1]) ||
        str[i + 1] == '.' || str[i - 1] == '.' || str[i + 1] == 'x' ||
        str[i + 1] == 'X')
      return_value = false;
  }
}
bool Validator::isNumberChar(const char &c) const noexcept {
  int return_value = false;
  if (c >= '0' && c <= '9') return_value = true;
  return return_value;
}
bool Validator::symbolIsNull(const char &c) const noexcept {
  return c == '\0' ? true : false;
}
bool Validator::isLeftBracket(const char &c) const noexcept {
  return c == '(' ? true : false;
}
bool Validator::isRightBracket(const char &c) const noexcept {
  return c == ')' ? true : false;
}
bool Validator::isPlus(const char &c) const noexcept {
  return c == '+' ? true : false;
}
bool Validator::isMinus(const char &c) const noexcept {
  return c == '-' ? true : false;
}
bool Validator::isMul(const char &c) const noexcept {
  return c == '*' ? true : false;
}
bool Validator::isDiv(const char &c) const noexcept {
  return c == '/' ? true : false;
}
bool Validator::isDegree(const char &c) const noexcept {
  return c == '^' ? true : false;
}

bool Validator::isOperatorMath(const char &c) const noexcept {
  bool return_value = false;
  if (isDiv(c) || isMul(c) || isPlus(c) || isMinus(c) || isDegree(c))
    return_value = true;
  return return_value;
}

bool Validator::isMod(const char *str) const noexcept {
  const char str_mod[] = "mod";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}

bool Validator::isCos(const char *str) const noexcept {
  const char str_mod[] = "cos";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}

bool Validator::isSin(const char *str) const noexcept {
  const char str_mod[] = "sin";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isTan(const char *str) const noexcept {
  const char str_mod[] = "tan";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isSqrt(const char *str) const noexcept {
  const char str_mod[] = "sqrt";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isLog(const char *str) const noexcept {
  const char str_mod[] = "log";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isLn(const char *str) const noexcept {
  const char str_mod[] = "ln";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isAcos(const char *str) const noexcept {
  const char str_mod[] = "acos";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isAsin(const char *str) const noexcept {
  const char str_mod[] = "asin";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}
bool Validator::isAtan(const char *str) const noexcept {
  const char str_mod[] = "atan";
  const char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? true : false;
}

void Model::calculatingExpression() noexcept {
  std::stack<symbol> numbers;
  double first_number = 0.0f;
  double second_number = 0.0f;
  while (!stackOfSymbols.empty()) {
    if (stackOfSymbols.top().get_type() == NUMBER) {
      numbers.emplace(stackOfSymbols.top().get_value(),
                      stackOfSymbols.top().get_priority(),
                      stackOfSymbols.top().get_type());
      stackOfSymbols.pop();
    } else {
      switch (stackOfSymbols.top().get_type()) {
        case PLUS:
        case MINUS:
        case MUL:
        case DIV:
        case DEGREE:
        case MOD: {
          first_number = numbers.top().get_value();
          numbers.pop();
          second_number = numbers.top().get_value();
          if (stackOfSymbols.top().get_type() == PLUS)
            result = (first_number + second_number);
          else if (stackOfSymbols.top().get_type() == MINUS)
            result = (second_number - first_number);
          else if (stackOfSymbols.top().get_type() == MUL)
            result = (first_number * second_number);
          else if (stackOfSymbols.top().get_type() == DIV) {
            result = (second_number / first_number);
          } else if (stackOfSymbols.top().get_type() == DEGREE)
            result = std::pow(second_number, first_number);
          else if (stackOfSymbols.top().get_type() == MOD)
            result = std::fmod(second_number, first_number);
          numbers.pop();
          stackOfSymbols.pop();
          numbers.emplace(result, 0, NUMBER);
          break;
        }
        case COS:
        case SIN:
        case TAN:
        case LOG:
        case LN:
        case ACOS:
        case ASIN:
        case ATAN:
        case SQRT: {
          first_number = numbers.top().get_value();
          numbers.pop();
          if (stackOfSymbols.top().get_type() == SIN)
            result = std::sin(first_number);
          else if (stackOfSymbols.top().get_type() == COS)
            result = std::cos(first_number);
          else if (stackOfSymbols.top().get_type() == TAN)
            result = std::tan(first_number);
          else if (stackOfSymbols.top().get_type() == ACOS)
            result = std::acos(first_number);
          else if (stackOfSymbols.top().get_type() == ASIN)
            result = std::asin(first_number);
          else if (stackOfSymbols.top().get_type() == ATAN)
            result = std::atan(first_number);
          else if (stackOfSymbols.top().get_type() == SQRT)
            result = std::sqrt(first_number);
          else if (stackOfSymbols.top().get_type() == LOG)
            result = std::log10(first_number);
          else if (stackOfSymbols.top().get_type() == LN)
            result = std::log(first_number);
          stackOfSymbols.pop();
          numbers.emplace(result, 0, NUMBER);
          break;
        }
        default:
          break;
      }
    }
  }
  result = numbers.top().get_value();
  numbers.pop();
}

void Model::RMN(const char *str, const char *x) noexcept {
  parcer(str);
  reverseStack();
  std::stack<symbol> support;
  std::stack<symbol> output;
  size_t last_priority = 0;
  while (!stackOfSymbols.empty()) {
    if (stackOfSymbols.top().get_type() == X) {
      output.emplace(strtod(x, NULL), stackOfSymbols.top().get_priority(),
                     NUMBER);
      stackOfSymbols.pop();
    } else if (stackOfSymbols.top().get_type() == NUMBER) {
      output.emplace(stackOfSymbols.top().get_value(),
                     stackOfSymbols.top().get_priority(),
                     stackOfSymbols.top().get_type());
      stackOfSymbols.pop();
    } else if (stackOfSymbols.top().get_type() == UNARY_MINUS ||
               stackOfSymbols.top().get_type() == UNARY_PLUS) {
      output.emplace(stackOfSymbols.top().get_value(), 0, NUMBER);
      support.emplace(
          stackOfSymbols.top().get_value(), stackOfSymbols.top().get_priority(),
          stackOfSymbols.top().get_type() == UNARY_MINUS ? MINUS : PLUS);
      last_priority = stackOfSymbols.top().get_priority();
      stackOfSymbols.pop();
    } else if (stackOfSymbols.top().get_type() != LEFT_BRACKET &&
               (stackOfSymbols.top().get_type() != RIGHT_BRACKET)) {
      if (last_priority < stackOfSymbols.top().get_priority()) {
        support.emplace(stackOfSymbols.top().get_value(),
                        stackOfSymbols.top().get_priority(),
                        stackOfSymbols.top().get_type());
        last_priority = stackOfSymbols.top().get_priority();
        stackOfSymbols.pop();
      } else {
        while (!support.empty() &&
               stackOfSymbols.top().get_priority() <=
                   support.top().get_priority() &&
               support.top().get_type() != LEFT_BRACKET &&
               support.top().get_type() != RIGHT_BRACKET) {
          output.emplace(support.top().get_value(),
                         support.top().get_priority(),
                         support.top().get_type());
          support.pop();
        }
        support.emplace(stackOfSymbols.top().get_value(),
                        stackOfSymbols.top().get_priority(),
                        stackOfSymbols.top().get_type());
        last_priority = stackOfSymbols.top().get_priority();
        stackOfSymbols.pop();
      }

    } else if (stackOfSymbols.top().get_type() == LEFT_BRACKET) {
      last_priority = 0;
      support.emplace(stackOfSymbols.top().get_value(),
                      stackOfSymbols.top().get_priority(),
                      stackOfSymbols.top().get_type());
      stackOfSymbols.pop();
    } else {
      while (support.top().get_type() != LEFT_BRACKET) {
        output.emplace(support.top().get_value(), support.top().get_priority(),
                       support.top().get_type());
        support.pop();
      }
      support.pop();
      stackOfSymbols.pop();
      last_priority = (support.empty() ? 0 : support.top().get_priority());
    }
  }
  while (!support.empty()) {
    output.emplace(support.top().get_value(), support.top().get_priority(),
                   support.top().get_type());
    support.pop();
  }
  stackOfSymbols = output;
  reverseStack();
}

// 0 - CORRECT, 1 - INCORRECT MONTH, 2 - INCORRECT LOAN_AMOUNT, 3 - INCORRECT
// INTEREST_RATE
double Validator::ValidDataCredit(
    const char *monthString, const char *loanAmounString,
    const char *interestRateString) const noexcept {
  double month = strtod(monthString, NULL);
  if ((month - (int)month) > 1e-6 || month < 1) return 0;
  double loanAmount = strtod(loanAmounString, NULL);
  if (loanAmount < 0) return 0;
  double interestRate = strtod(interestRateString, NULL);
  if (interestRate < 0.01 || interestRate > 999) return 0;
  return 1;
}

void Model::annuityPaymentCalculation(const char *monthString,
                                      const char *loanAmounString,
                                      const char *interestRateString) {
  if (ValidDataCredit(monthString, loanAmounString, interestRateString)) {
    double monthTemp = strtod(monthString, NULL);
    double loanAmountTemp = strtod(loanAmounString, NULL);
    double interestRateTemp = strtod(interestRateString, NULL);
    double monthlyInterestRate = interestRateTemp / (12.f * 100.f);
    annuityRatio = ((monthlyInterestRate *
                     std::pow(1.f + monthlyInterestRate, monthTemp)) /
                    (std::pow(1 + monthlyInterestRate, monthTemp) - 1.f)) *
                   loanAmountTemp;
    totalPayout = (annuityRatio * monthTemp);
    overpaymentLoan = totalPayout - loanAmountTemp;
  } else
    throw std::logic_error("Wrong input!");
}

void Model::differentiatedPayment(const char *monthString,
                                  const char *loanAmounString,
                                  const char *interestRateString) {
  if (ValidDataCredit(monthString, loanAmounString, interestRateString)) {
    monthPayment = strtod(monthString, NULL);
    double loanAmountTemp = strtod(loanAmounString, NULL);
    double interestRateTemp = strtod(interestRateString, NULL);
    double paymentMainBody = loanAmountTemp / monthPayment;
    double mainLeft = loanAmountTemp;
    overpaymentLoan = 0;
    totalPayout = 0;
    arrayOfMonthlyPayment = AllocTraits::allocate(alloc, monthPayment);
    for (auto i = 0; i < (int)monthPayment; ++i) {
      AllocTraits::construct(alloc, arrayOfMonthlyPayment + i,
                             mainLeft * interestRateTemp / (100.f * 12.f));
      overpaymentLoan += arrayOfMonthlyPayment[i];
      mainLeft -= paymentMainBody;
    }
    totalPayout = loanAmountTemp + overpaymentLoan;
  } else
    throw std::logic_error("Wrong input!");
}

void Model::insertData() {
  xValueFunction.clear();
  yValueFunction.clear();
  std::string function = get_nameFunction();
  for (auto value = get_Xmin(); value < get_Xmax(); value += get_step()) {
    xValueFunction.push_back(value);
    calculate(function.c_str(), std::to_string(value).c_str());
    yValueFunction.push_back(get_data());
  }
}

std::vector<double> Model::get_xValueFunction() const { return xValueFunction; }

std::vector<double> Model::get_yValueFunction() const { return yValueFunction; }

}  // namespace s21
