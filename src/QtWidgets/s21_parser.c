#include "s21_SmartCalc.h"

void parcer(const char* str, stack** Node) {
  for (size_t i = 0; i < strlen(str); i++) {
    switch (str[i]) {
      case '+': {
        push_back(Node, 0, 1, PLUS);
        break;
      }
      case '-': {
        push_back(Node, 0, 1, MINUS);
        break;
      }
      case '*': {
        push_back(Node, 0, 2, MUL);
        break;
      }
      case '/': {
        push_back(Node, 0, 2, DIV);
        break;
      }
      case 'm': {
        push_back(Node, 0, 2, MOD);
        i += 2;
        break;
      }
      case '^': {
        push_back(Node, 0, 4, DEGREE);
        break;
      }
      case 'c': {
        push_back(Node, 0, 3, COS);
        i += 2;
        break;
      }
      case 't': {
        push_back(Node, 0, 3, TAN);
        i += 2;
        break;
      }
      case 's': {
        if (str[i + 1] == 'i') {
          push_back(Node, 0, 3, SIN);
          i += 2;
        } else {
          push_back(Node, 0, 4, SQRT);
          i += 3;
        }
        break;
      }
      case 'l': {
        if (str[i + 1] == 'n') {
          push_back(Node, 0, 3, LN);
          i += 1;
        } else {
          push_back(Node, 0, 3, LOG);
          i += 2;
        }
        break;
      }
      case 'a': {
        if (str[i + 1] == 'c') {
          push_back(Node, 0, 3, ACOS);
        } else if (str[i + 1] == 's') {
          push_back(Node, 0, 3, ASIN);
        } else {
          push_back(Node, 0, 3, ATAN);
        }
        i += 3;
        break;
      }
      case '(': {
        push_back(Node, 0, 5, LEFT_BRACKET);
        break;
      }
      case ')': {
        push_back(Node, 0, 5, RIGHT_BRACKET);
        break;
      }
      case '<': {
        push_back(Node, 0, 1, UNARY_MINUS);
        break;
      }
      case '>': {
        push_back(Node, 0, 1, UNARY_PLUS);
        break;
      }
      default: {
        if (is_number_char(str[i]) == CORRECT) {
          char number[256] = "";
          int j = 0;
          double number_stack = 0.0f;
          while ((is_number_char(str[i]) == CORRECT || str[i] == '.') &&
                 str[i] != '\0') {
            number[j++] = str[i];
            i++;
          }
          i -= 1;
          number_stack = atof(number);
          push_back(Node, number_stack, 0, NUMBER);
        } else {
          push_back(Node, 1, 0, X);
        }
        break;
      }
    }
  }
}

void RMN(stack** top, const char* str, const char* x) {
  parcer(str, top);
  reverse_stack(top);
  stack* Support = NULL;
  stack* Output = NULL;
  int last_priority = 0;
  //   print_stack(*top);
  while (*top != NULL) {
    if ((*top)->type == X) {
      (*top)->value = strtod(x, NULL);
      push_back(&Output, (*top)->value, (*top)->priority, NUMBER);
      pop_back(top);
    } else if ((*top)->type == NUMBER) {
      push_back(&Output, (*top)->value, (*top)->priority, NUMBER);
      pop_back(top);
    } else if ((*top)->type == UNARY_MINUS || (*top)->type == UNARY_PLUS) {
      push_back(&Output, (*top)->value, 0, NUMBER);
      push_back(&Support, (*top)->value, (*top)->priority,
                (*top)->type == UNARY_MINUS ? MINUS : PLUS);
      last_priority = (*top)->priority;
      pop_back(top);
    } else if ((*top)->type != LEFT_BRACKET &&
               ((*top)->type != RIGHT_BRACKET)) {
      if (last_priority < (*top)->priority) {
        push_back(&Support, (*top)->value, (*top)->priority, (*top)->type);
        last_priority = (*top)->priority;
        pop_back(top);
      } else {
        while (Support != NULL && (*top)->priority <= Support->priority &&
               Support->type != LEFT_BRACKET &&
               Support->type != RIGHT_BRACKET) {
          push_back(&Output, Support->value, Support->priority, Support->type);
          pop_back(&Support);
        }
        push_back(&Support, (*top)->value, (*top)->priority, (*top)->type);
        last_priority = (*top)->priority;
        pop_back(top);
      }

    } else if ((*top)->type == LEFT_BRACKET) {
      last_priority = 0;
      push_back(&Support, (*top)->value, (*top)->priority, (*top)->type);
      pop_back(top);
    } else {
      while (Support->type != LEFT_BRACKET) {
        push_back(&Output, Support->value, Support->priority, Support->type);
        pop_back(&Support);
      }
      pop_back(&Support);
      pop_back(top);
      last_priority = (Support == NULL ? 0 : Support->priority);
    }
  }
  while (Support != NULL) {
    push_back(&Output, Support->value, Support->priority, Support->type);
    pop_back(&Support);
  }
  reverse_stack(&Output);
  (*top) = Output;
}

double calculating_expression(stack** top) {
  double result = 0;
  stack* numbers = NULL;
  double first_number = 0.0f;
  double second_number = 0.0f;
  while (*top != NULL) {
    if ((*top)->type == NUMBER) {
      push_back(&numbers, (*top)->value, (*top)->priority, (*top)->type);
      pop_back(top);
    } else {
      switch ((*top)->type) {
        case PLUS:
        case MINUS:
        case MUL:
        case DIV:
        case DEGREE:
        case MOD: {
          first_number = numbers->value;
          pop_back(&numbers);
          second_number = numbers->value;
          if ((*top)->type == PLUS)
            result = (first_number + second_number);
          else if ((*top)->type == MINUS)
            result = (second_number - first_number);
          else if ((*top)->type == MUL)
            result = (first_number * second_number);
          else if ((*top)->type == DIV) {
            result = (second_number / first_number);
          } else if ((*top)->type == DEGREE)
            result = powf(second_number, first_number);
          else if ((*top)->type == MOD)
            result = fmod(second_number, first_number);
          pop_back(&numbers);
          pop_back(top);
          push_back(&numbers, result, 0, NUMBER);
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
          first_number = numbers->value;
          pop_back(&numbers);
          if ((*top)->type == SIN)
            result = sin(first_number);
          else if ((*top)->type == COS)
            result = cos(first_number);
          else if ((*top)->type == TAN)
            result = tan(first_number);
          else if ((*top)->type == ACOS)
            result = acos(first_number);
          else if ((*top)->type == ASIN)
            result = asin(first_number);
          else if ((*top)->type == ATAN)
            result = atan(first_number);
          else if ((*top)->type == SQRT)
            result = sqrt(first_number);
          else if ((*top)->type == LOG)
            result = log10(first_number);
          else if ((*top)->type == LN)
            result = log(first_number);
          pop_back(top);
          push_back(&numbers, result, 0, NUMBER);
          break;
        }
        default:
          break;
      }
    }
  }
  result = numbers->value;
  pop_back(&numbers);
  return result;
}