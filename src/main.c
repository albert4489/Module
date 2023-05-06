/**
	@file main.c
	Калькулятор
	@author Bohuslavskiy A. КН-922B
*/

/**
	Заголовковий файл
*/

/**

	Ввод строки
	
	@return код помилки (0)
	
	@param formula вхідна строка
	@param MAX максимально допустиме значення строки

*/
#include "lib.h"
int main() {
/**
	Точка входа в програму. Демонстрація рішення.
*/
char *formula = malloc(MAX * sizeof(char));
printf("Введіть математичний вираз: ");
fgets(formula, MAX, stdin);

formula[strlen(formula) - 1] = '\0';

int result = calculator(formula);
printf("Результат: %d\n", result);
free(formula);
return 0;
}
