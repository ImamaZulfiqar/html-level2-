#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  char operation;
  double num1, num2, result;

  printf("Enter an expression (e.g., 5+3): ");
  fgets(input, sizeof(input), stdin);

  // Remove the newline character from the input
  input[strcspn(input, "\n")] = 0;

  // Find the operator
  char *op = strchr(input, '+');
  if (op == NULL) {
    op = strchr(input, '-');
  }
  if (op == NULL) {
    op = strchr(input, '*');
  }
  if (op == NULL) {
    op = strchr(input, '/');
  }
  if (op == NULL) {
    printf("Invalid expression.\n");
    return 1;
  }

  // Get the operands
  num1 = atof(input);
  num2 = atof(op + 1);

  // Perform the calculation
  switch (*op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero.\n");
        return 1;
      }
      result = num1 / num2;
      break;
  }

  printf("Result: %f\n", result);

  return 0;
}