# Калькулятор по отображению функций
Этот калькулятор преобразует математическое выражение в польскую нотацию (постфиксную форму) и выводит график на экран с разрешением 25 на 80 точек.

## Запуск приложения
Для запуска необходимо выполнить следующие шаги:

Выполнить команду makefile all, чтобы скомпилировать файл calc.
Запустить скомпилированный файл calc.
Ввести математическую функцию для анализа.
Примеры функций для тестирования
Cos(Sin(x))
x*x*x
sin(sin(sin(sin(1/ln(x*x))))
### Поддерживаемые функции
+ - сложение
- - унарный и бинарный минус
* - умножение
/ - деление
() - скобки
sin(x)
cos(x)
tan(x)
ctg(x)
sqrt(x)
ln(x)
### Обработка ошибок
Калькулятор обрабатывает следующие ошибки ввода:

Деление на 0
Извлечение квадратного корня из отрицательного числа
Различные вариации неправильного ввода, такие как sim, sib, cod, coa и т. д.
