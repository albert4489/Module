/**
	@file lib.c
	Калькулятор
	@author Bohuslavskiy A. КН-922B
*/

/**
	Заголовковий файл
*/
#include "lib.h"
/**
	Функція перевіряє чи символ операндом
	@param ch Чи є символ операндом
*/
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

/**
	Функція видає пріорітет операторам
	@param operator операторам
*/
int getPriority(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return 0;
}

/**
	Функція для виконання операції над двома числами
	@param num1 Число 1
	@param num2 Число 2
	@param operator оператор
*/
int primeoperation(int num1, int num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return num1 % num2;
        case '^':
            return pow(num1, num2);
        default:
            return 0;
    }
}

/**
	
	Функція для виконання операції над двома числами
	@param length змінна яка зберігає довжину рядка
	@param values масив який використовується для збереження чисел
	@param operators масив, який використовується для збереження операторів
	@param valueIndex  змінна яка вказує на наступний вільний індекс у масиві values
	@param operatorIndex змінна яка вказує на наступний вільний індекс у масиві operators
	@param num1 Число 1
	@param num2 Число 2
	@param op  змінна яка зберігає оператор для виконання операції
	@param result  змінна яка зберігає результат виконання операції над num1 та num2 за допомогою оператора op
	@param final змінна яка зберігає кінцевий результат обчислення виразу
*/
int calculator(char* formula) {
    int length = strlen(formula);
    int* values = (int*)malloc(length * sizeof(int));  // Масив для збереження чисел
    char* operators = (char*)malloc(length * sizeof(char));  // Масив для збереження операторів
    int valueIndex = 0;
    int operatorIndex = 0;

    for (int i = 0; i < length; i++) {
        if (formula[i] == ' ') {
            continue;  // Пропускаємо пробіли
        } else if (isdigit(formula[i])) {
            int value = 0;

            while (i < length && isdigit(formula[i])) {
                value = (value * 10) + (formula[i] - '0');
                i++;
            }

            values[valueIndex++] = value;
            i--;
        } else if (isOperator(formula[i])) {
            while (operatorIndex > 0 && isOperator(operators[operatorIndex - 1]) && 
                   getPriority(operators[operatorIndex - 1]) >= getPriority(formula[i])) {
// Виконуємо попередню операцію, якщо маємо відповідні числа та оператор
    int num2 = values[--valueIndex];
    int num1 = values[--valueIndex];
    char op = operators[--operatorIndex];
    int result = primeoperation(num1, num2, op);
    values[valueIndex++] = result;
}
operators[operatorIndex++] = formula[i];
    } else if (formula[i] == '(') {
        operators[operatorIndex++] = formula[i];
    } else if (formula[i] == ')') {
        while (operatorIndex > 0 && operators[operatorIndex - 1] != '(') {
            // Виконуємо операції всередині дужок
            int num2 = values[--valueIndex];
            int num1 = values[--valueIndex];
            char op = operators[--operatorIndex];
            int result = primeoperation(num1, num2, op);
            values[valueIndex++] = result;
        }

        // Видаляємо відкриваючу дужку 
        operatorIndex--;
    }
}
while (operatorIndex > 0) {
    // Виконуємо залишившіся операції
    int num2 = values[--valueIndex];
    int num1 = values[--valueIndex];
    char op = operators[--operatorIndex];
    int result = primeoperation(num1, num2, op);
    values[valueIndex++] = result;
}

int final = values[0];
free(values);
free(operators);

return final;
}
