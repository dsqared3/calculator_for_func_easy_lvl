# Калькулятор по отображению функций
Этот калькулятор преобразует математическое выражение в польскую нотацию (постфиксную форму) и выводит график на экран с разрешением 25 на 80 точек.

## Запуск приложения
Для запуска необходимо выполнить следующие шаги:

Выполнить команду makefile all, чтобы скомпилировать файл calc.
Запустить скомпилированный файл calc.
Ввести математическую функцию для анализа.
Примеры функций для тестирования
- Cos(Sin(x))
- x*x*x
- sin(sin(sin(sin(1/ln(x*x))))
### Поддерживаемые функции
- сложение
- унарный и бинарный минус
- умножение
- деление
- () скобки
- sin(x) синус
- cos(x) косинус
- tan(x) тангенс
- ctg(x) катангенс
- sqrt(x) квадратный корень
- ln(x) натуральный логарифм
### Обработка ошибок
Калькулятор обрабатывает следующие ошибки ввода:

1. Деление на 0.
2. Извлечение квадратного корня из отрицательного числа.
3. Различные вариации неправильного ввода, такие как sim, sib, cod, coa и т. д.
