#ifndef S21_CALS_H
#define S21_CALS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum VALID_EXPRESSION { CORRECT, INCORRECT };
enum YES_OR_NOT { NO, YES };

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
// const char * name_operands[] =
// {"Number","x","Plus","Minus","Mul","Div","Mod","Sin","Cos","Tan","Ln","Log","Asin","Acos","Atan","Degree","Sqrt","(",")"};
typedef struct stack {
  double value;
  int priority;
  type_t type;
  struct stack* next;
} stack;

/// @brief проверяет на валидность строки выражения
/// @param str
/// @return correct or incorrect
int is_valid_expression(const char* str);

void valid_RIGHT_BRACKET(int* count_bracket, int* return_value, const char c);
void valid_plus_and_minus(int* return_value, const size_t i, const char* str);
void valid_mul_and_div(int* return_value, const size_t i, const char* str);
void valid_degree(int* return_value, const size_t i, const char* str);
void valid_mod(int* return_value, size_t* i, const char* str);
void valid_cos(int* return_value, size_t* i, const char* str);
void valid_sqrt_and_sin(int* return_value, size_t* i, const char* str);
void valid_tan(int* return_value, size_t* i, const char* str);
void valid_asin_acos_atan(int* return_value, size_t* i, const char* str);
void valid_log_ln(int* return_value, size_t* i, const char* str);
void valid_dot(int* return_value, const size_t i, const char* str);
void valid_x(int* return_value, const char* str, const int i);
void upgrade_str(char* str);
char* new_str(char* str);
double calculate(char* str, const char* x);

/// @brief проверяет символ числа от 0 до 9
/// @param c
/// @return corrert or inccorect
int is_number_char(const char c);

int symbol_is_null(const char c);

int is_right_brecket(const char c);
int is_left_brecket(const char c);
int is_plus(const char c);
int is_minus(const char c);
int is_mul(const char c);
int is_div(const char c);
int is_operator_math(const char c);
int is_mod(const char* str);
int is_cos(const char* str);
int is_sin(const char* str);
int is_tan(const char* str);
int is_sqrt(const char* str);
int is_log(const char* str);
int is_ln(const char* str);
int is_atan(const char* str);
int is_asin(const char* str);
int is_acos(const char* str);

// STACK
// push
void push_back(stack** top, double value, int priority, type_t type);
// void print_stack(stack * top);
void pop_back(stack** top);
// int is_empty(stack * top);
// void clear_stack(stack ** top);
void reverse_stack(stack** top);

// PARCER
void parcer(const char* str, stack** Node);

void RMN(stack** top, const char* str, const char* x);
double calculating_expression(stack** top);
// CREDIT
int valid_number(const char* str);
void valid_data_credit(const char* month_string, const char* loan_amount_string,
                       const char* interest_rate_string, double* month,
                       double* loan_amount, double* interest_rate,
                       int* return_value);
void annuity_payment_calculation(double interest_rate, double month,
                                 double loan_amount, double* annuity_ratio,
                                 double* overpayment_loan,
                                 double* total_payout);
int annuity_payment(const char* month_string, const char* loan_amount_string,
                    char* interest_rate_string, double* annuity_ratio,
                    double* overpayment_loan, double* total_payout);
// dif
int get_days(int month, int year);
int differentiated_payment(const char* month_string,
                           const char* loan_amount_string,
                           char* interest_rate_string, double annuity_ratio[],
                           double* overpayment_loan, double* total_payout);
#endif
