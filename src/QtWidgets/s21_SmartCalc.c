#include "s21_SmartCalc.h"

void valid_RIGHT_BRACKET(int *count_bracket, int *return_value, const char c) {
  if (*count_bracket > 0) {
    (*count_bracket)--;
    if (is_left_brecket(c) || is_operator_math(c)) *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_plus_and_minus(int *return_value, const size_t i, const char *str) {
  if (symbol_is_null(str[i + 1]))
    *return_value = INCORRECT;
  else if (is_right_brecket(str[i + 1]) == YES ||
           is_operator_math(str[i + 1]) == YES)
    *return_value = INCORRECT;
}

void valid_mul_and_div(int *return_value, const size_t i, const char *str) {
  if (symbol_is_null(str[i + 1]))
    *return_value = INCORRECT;
  else if (i != 0) {
    if ((is_left_brecket(str[i - 1]) == YES) ||
        is_right_brecket(str[i + 1]) == YES ||
        is_operator_math(str[i - 1]) == YES ||
        is_operator_math(str[i + 1]) == YES)
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_degree(int *return_value, const size_t i, const char *str) {
  if (symbol_is_null(str[i + 1]))
    *return_value = INCORRECT;
  else if (i != 0) {
    if ((is_left_brecket(str[i - 1]) == YES) ||
        is_right_brecket(str[i + 1]) == YES ||
        is_operator_math(str[i - 1]) == YES ||
        is_operator_math(str[i + 1]) == YES)
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_mod(int *return_value, size_t *i, const char *str) {
  if (strlen(str + *i) > 3) {
    int pos_last = *i;
    if (is_mod(str + *i) == YES)
      *i += 2;
    else
      *return_value = INCORRECT;
    if (*return_value == CORRECT) {
      if (is_operator_math(str[pos_last - 1]) == YES ||
          is_operator_math(str[*i + 1]) == YES ||
          is_left_brecket(str[pos_last - 1]) == YES ||
          is_right_brecket(str[*i + 1]) == YES)
        *return_value = INCORRECT;
    }
  } else
    *return_value = INCORRECT;
}

void valid_cos(int *return_value, size_t *i, const char *str) {
  if (strlen(str + *i) > 3) {
    if (is_cos(str + *i) == YES)
      *i += 2;
    else
      *return_value = INCORRECT;
    if (*return_value == CORRECT) {
      if (is_operator_math(str[*i + 1]) == YES ||
          is_right_brecket(str[*i + 1]) == YES)
        *return_value = INCORRECT;
    }
  } else
    *return_value = INCORRECT;
}
void valid_sqrt_and_sin(int *return_value, size_t *i, const char *str) {
  if (str[*i + 1] == 'i') {
    if (strlen(str + *i) > 3) {
      if (is_sin(str + *i) == YES)
        *i += 2;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if (is_operator_math(str[*i + 1]) == YES ||
            is_right_brecket(str[*i + 1]) == YES)
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else if (str[*i + 1] == 'q') {
    if (strlen(str + *i) > 4) {
      if (is_sqrt(str + *i) == YES)
        *i += 3;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if (is_operator_math(str[*i + 1]) == YES ||
            is_right_brecket(str[*i + 1]) == YES)
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}
void valid_tan(int *return_value, size_t *i, const char *str) {
  if (strlen(str + *i) > 3) {
    if (is_tan(str + *i) == YES)
      *i += 2;
    else
      *return_value = INCORRECT;
    if (*return_value == CORRECT) {
      if (is_operator_math(str[*i + 1]) == YES ||
          is_right_brecket(str[*i + 1]) == YES)
        *return_value = INCORRECT;
    }
  } else
    *return_value = INCORRECT;
}

void valid_asin_acos_atan(int *return_value, size_t *i, const char *str) {
  if (str[*i + 1] == 's') {
    if (strlen(str + *i) > 4) {
      if (is_asin(str + *i) == YES)
        *i += 3;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if ((is_operator_math(str[*i + 1]) == YES) ||
            is_right_brecket(str[*i + 1] == YES))
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else if (str[*i + 1] == 'c') {
    if (strlen(str + *i) > 4) {
      if (is_acos(str + *i) == YES)
        *i += 3;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if ((is_operator_math(str[*i + 1]) == YES) ||
            is_right_brecket(str[*i + 1] == YES))
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else if (str[*i + 1] == 't') {
    if (strlen(str + *i) > 4) {
      if (is_atan(str + *i) == YES)
        *i += 3;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if ((is_operator_math(str[*i + 1]) == YES) ||
            is_right_brecket(str[*i + 1] == YES))
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_log_ln(int *return_value, size_t *i, const char *str) {
  if (str[*i + 1] == 'o') {
    if (strlen(str + *i) > 3) {
      if (is_log(str + *i) == YES)
        *i += 2;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if ((is_operator_math(str[*i + 1]) == YES) ||
            is_right_brecket(str[*i + 1] == YES))
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else if (str[*i + 1] == 'n') {
    if (strlen(str + *i) > 2) {
      if (is_ln(str + *i) == YES)
        *i += 1;
      else
        *return_value = INCORRECT;
      if (*return_value == CORRECT) {
        if ((is_operator_math(str[*i + 1]) == YES) ||
            is_right_brecket(str[*i + 1] == YES))
          *return_value = INCORRECT;
      }
    } else
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_dot(int *return_value, const size_t i, const char *str) {
  if (i != 0) {
    if (symbol_is_null(str[i + 1]))
      *return_value = INCORRECT;
    else if (is_number_char(str[i - 1]) == INCORRECT ||
             is_number_char(str[i + 1]) == INCORRECT)
      *return_value = INCORRECT;
  } else
    *return_value = INCORRECT;
}

void valid_x(int *return_value, const char *str, const int i) {
  if (is_number_char(str[i - 1]) == CORRECT ||
      is_number_char(str[i + 1]) == CORRECT || str[i + 1] == '.' ||
      str[i - 1] == '.' || str[i + 1] == 'x' || str[i + 1] == 'X')
    *return_value = INCORRECT;
}
int is_valid_expression(const char *str) {
  int return_value = CORRECT;
  if (str == NULL)
    return_value = INCORRECT;
  else if (strlen(str) == 0)
    return_value = INCORRECT;
  else {
    int count_of_bracket = 0;
    for (size_t i = 0; i < strlen(str); ++i) {
      switch (str[i]) {
        case '(': {
          count_of_bracket++;
          break;
        }
        case ')': {
          valid_RIGHT_BRACKET(&count_of_bracket, &return_value, str[i - 1]);
          break;
        }
        case '+':
        case '-': {
          valid_plus_and_minus(&return_value, i, str);
          break;
        }
        case '*':
        case '/': {
          valid_mul_and_div(&return_value, i, str);
          break;
        }
        case '^': {
          valid_degree(&return_value, i, str);
          break;
        }
        case 'm': {
          valid_mod(&return_value, &i, str);
          break;
        }
        case 'c': {
          valid_cos(&return_value, &i, str);
          break;
        }
        case 's': {
          valid_sqrt_and_sin(&return_value, &i, str);
          break;
        }
        case 't': {
          valid_tan(&return_value, &i, str);
          break;
        }
        case 'l': {
          valid_log_ln(&return_value, &i, str);
          break;
        }
        case 'a': {
          valid_asin_acos_atan(&return_value, &i, str);
          break;
        }
        case '.': {
          valid_dot(&return_value, i, str);
          break;
        }
        case 'x': {
          valid_x(&return_value, str, i);
          break;
        }
        case 'X': {
          valid_x(&return_value, str, i);
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
          return_value = INCORRECT;
          break;
      }
    }
    if (count_of_bracket != 0) return_value = INCORRECT;
  }
  return return_value;
}

int is_number_char(const char c) {
  int return_value = INCORRECT;
  if (c >= '0' && c <= '9') return_value = CORRECT;
  return return_value;
}

int symbol_is_null(const char c) { return c == '\0' ? YES : NO; }

int is_left_brecket(const char c) { return c == '(' ? YES : NO; }
int is_right_brecket(const char c) { return c == ')' ? YES : NO; }

int is_plus(const char c) { return c == '+' ? YES : NO; }
int is_minus(const char c) { return c == '-' ? YES : NO; }

int is_mul(const char c) { return c == '*' ? YES : NO; }
int is_div(const char c) { return c == '/' ? YES : NO; }
int is_degree(const char c) { return c == '^' ? YES : NO; }

int is_operator_math(const char c) {
  int return_value = NO;
  if (is_div(c) == YES || is_div(c) == YES || is_mul(c) == YES ||
      is_mul(c) == YES || is_plus(c) == YES || is_plus(c) == YES ||
      is_minus(c) == YES || is_minus(c) == YES || is_degree(c) == YES)
    return_value = YES;
  return return_value;
}

int is_mod(const char *str) {
  const char str_mod[] = "mod";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}

int is_cos(const char *str) {
  const char str_mod[] = "cos";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}

int is_sin(const char *str) {
  const char str_mod[] = "sin";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_tan(const char *str) {
  const char str_mod[] = "tan";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_sqrt(const char *str) {
  const char str_mod[] = "sqrt";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_log(const char *str) {
  const char str_mod[] = "log";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_ln(const char *str) {
  const char str_mod[] = "ln";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_acos(const char *str) {
  const char str_mod[] = "acos";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_asin(const char *str) {
  const char str_mod[] = "asin";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}
int is_atan(const char *str) {
  const char str_mod[] = "atan";
  char *pos_str_mod = strstr(str, str_mod);
  return (pos_str_mod - str == 0) ? YES : NO;
}

void upgrade_str(char *str) {
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

char *new_str(char *str) {
  char *str_upgrade = (char *)malloc(sizeof(char) * strlen(str) + 1);
  strcpy(str_upgrade, str);
  upgrade_str(str_upgrade);
  return str_upgrade;
}

// YES == 1 - VALID, NO == 0, NOT VALID
int valid_number(const char *str) {
  int return_value = YES;
  int count_dot = 0;
  for (size_t i = 0; i < strlen(str); ++i) {
    if (is_number_char(str[i]) == CORRECT)
      continue;
    else if (str[i] == '.' && count_dot == 0 &&
             is_number_char(str[i + 1]) == CORRECT) {
      ++count_dot;
    } else
      return_value = NO;
  }
  return return_value;
}

void valid_data_credit(const char *month_string, const char *loan_amount_string,
                       const char *interest_rate_string, double *month,
                       double *loan_amount, double *interest_rate,
                       int *return_value) {
  if (valid_number(month_string)) {
    *month = strtod(month_string, NULL);
    if ((*month - (int)*month) > 1e-6 && *month < 1) *return_value = 1;
  } else
    *return_value = 1;
  if (*return_value == 0 && valid_number(loan_amount_string)) {
    *loan_amount = strtod(loan_amount_string, NULL);
  } else if (*return_value == 0)
    *return_value = 2;
  if (*return_value == 0 && valid_number(interest_rate_string)) {
    *interest_rate = strtod(interest_rate_string, NULL);
    if (*interest_rate < 0.01 || *interest_rate > 999) *return_value = 3;
  } else if (*return_value == 0)
    *return_value = 3;
}

void annuity_payment_calculation(double interest_rate, double month,
                                 double loan_amount, double *annuity_ratio,
                                 double *overpayment_loan,
                                 double *total_payout) {
  double monthly_interest_rate = interest_rate / (12.f * 100.f);
  *annuity_ratio =
      ((monthly_interest_rate * powl(1.f + monthly_interest_rate, month)) /
       (powl(1 + monthly_interest_rate, month) - 1.f)) *
      loan_amount;
  *total_payout = (*annuity_ratio * month);
  *overpayment_loan = *total_payout - loan_amount;
}
// 0 - CORRECT, 1 - INCORRECT MONTH, 2 - INCORRECT LOAN_AMOUNT, 3 - INCORRECT
// INTEREST_RATE
int annuity_payment(const char *month_string, const char *loan_amount_string,
                    char *interest_rate_string, double *annuity_ratio,
                    double *overpayment_loan, double *total_payout) {
  int return_value = 0;
  double month = 0;
  double loan_amount = 0;
  double interest_rate = 0;
  valid_data_credit(month_string, loan_amount_string, interest_rate_string,
                    &month, &loan_amount, &interest_rate, &return_value);
  if (return_value == 0) {
    annuity_payment_calculation(interest_rate, month, loan_amount,
                                annuity_ratio, overpayment_loan, total_payout);
  }
  return return_value;
}

int differentiated_payment(const char *month_string,
                           const char *loan_amount_string,
                           char *interest_rate_string, double annuity_ratio[],
                           double *overpayment_loan, double *total_payout) {
  int return_value = 0;
  double month = 0;
  double loan_amount = 0;
  double interest_rate = 0;
  valid_data_credit(month_string, loan_amount_string, interest_rate_string,
                    &month, &loan_amount, &interest_rate, &return_value);
  if (return_value == 0) {
    double payment_main_body = loan_amount / month;
    double main_left = loan_amount;
    for (int i = 0; i < (int)month; i++) {
      annuity_ratio[i] = main_left * interest_rate / (100.f * 12.f);
      *overpayment_loan += annuity_ratio[i];
      main_left -= payment_main_body;
    }
    *total_payout = loan_amount + *overpayment_loan;
  }
  return return_value;
}

double calculate(char *str, const char *x) {
  char *str_upgrade = new_str(str);
  stack *Node = NULL;
  RMN(&Node, str_upgrade, x);
  free(str_upgrade);
  return calculating_expression(&Node);
}