#include <stdio.h>

// Функція для знаходження НСД двох чисел
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    // Рекурсивно викликаємо функцію gcd() з аргументами b та a % b
    return gcd(b, a % b);
}

// Функція для знаходження НСК двох чисел
int lcm(int a, int b) {
    // НСК можна знайти за формулою: НСК(a,b) = a * b / НСД(a,b)
    // Тому викликаємо функцію gcd() та повертаємо результат за формулою
    return (a * b) / gcd(a, b);
}

int main() {
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251) ;
    int n, a, b;
    // Зчитуємо кількість чисел
    scanf("%d", &n);
    // Зчитуємо перше число
    scanf("%d", &a);
    // Проходимо по решті чисел та знаходимо їх НСК
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        a = lcm(a, b);
    }
    // Виводимо результат
    printf("%d\n", a);
    return 0;
}
