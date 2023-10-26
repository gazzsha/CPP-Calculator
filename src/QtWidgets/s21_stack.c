#include "s21_SmartCalc.h"

// const char *name_operand[] = {
//     "NUMBER",       "X",    "PLUS",   "UNARY_PLUS", "MINUS",
//     "UNARY_MINUS",  "MUL",  "DIV",    "MOD",        "SIN",
//     "COS",          "TAN",  "LN",     "LOG",        "ASIN",
//     "ACOS",         "ATAN", "DEGREE", "SQRT",       "LEFT_BRACKET",
//     "RIGHT_BRACKET"};

void push_back(stack **top, double value, int priority, type_t type) {
  stack *Node = NULL;
  Node = (stack *)malloc(sizeof(stack));
  Node->value = value;
  Node->priority = priority;
  Node->type = type;
  Node->next = *top;
  (*top) = Node;
}

// int is_empty(stack * top) {
//     return top == NULL;
// }

void pop_back(stack **top) {
  if (*top != NULL) {
    stack *Node = NULL;
    Node = *top;
    (*top) = (*top)->next;
    free(Node);
  }
}

void reverse_stack(stack **top) {
  stack *reverse_stack = NULL;
  while (*top != NULL) {
    push_back(&reverse_stack, (*top)->value, (*top)->priority, (*top)->type);
    pop_back(top);
  }
  *top = reverse_stack;
}

// stack *pop(stack *top) {
//   stack *Node = (stack *)malloc(sizeof(stack));
//   Node = top;
//   return Node;
// }

// void clear_stack(stack ** top) {
//     while (*top != NULL) {
//         pop_back(top);
//     }
// }

// void print_stack(stack * top) {
//     while (top != NULL) {
//         printf("Value :%f\nPriority: %d\nType:
//         %s\n",top->value,top->priority,name_operand[top->type]); top =
//         top->next;
//     }
// }