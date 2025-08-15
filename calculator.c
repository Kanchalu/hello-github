#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

double getValidDouble(const char* prompt) {
    double num;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf%c", &num, &term) != 2 || term != '\n') {
            printf("Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
        } else {
            return num;
        }
    }
}

int getValidInt(const char* prompt) {
    int num;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &num, &term) != 2 || term != '\n') {
            printf("Invalid input! Please enter a valid integer.\n");
            clearInputBuffer();
        } else {
            return num;
        }
    }
}

int main() {
    double num1, num2;
    int int1, int2;
    char operator;
    char choice;

    do {
        printf("\n===========================\n");
        printf("    Simple C Calculator\n");
        printf("===========================\n");

        num1 = getValidDouble("Enter first number: ");
        num2 = getValidDouble("Enter second number: ");

        printf("Enter an operator (+, -, *, /, %%, ^): ");
        scanf(" %c", &operator);
        clearInputBuffer();

        if (operator == '%') {
            int1 = (int)num1;
            int2 = (int)num2;
        }

        switch (operator) {
            case '+':
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 != 0) {
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
            case '%':
                if (int2 != 0) {
                    printf("Result: %d %% %d = %d\n", int1, int2, int1 % int2);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
            case '^':
                printf("Result: %.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
                break;
            default:
                printf("Error: Invalid operator!\n");
        }

        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        clearInputBuffer();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}
