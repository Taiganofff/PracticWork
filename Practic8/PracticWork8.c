#include <stdio.h>
#include <string.h>

// Функція для обміну значеннями двох змінних
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Функція для друку анаграм
void printAnagrams(char *word, int left, int right, int *count)
{
    int i;
    if (left == right) // Базовий випадок, коли left == right
        (*count)++;
    else
    {
        for (i = left; i <= right; i++)
        {
            swap((word + left), (word + i)); // Змінюємо першу букву з іншими буквами
            printAnagrams(word, left + 1, right, count); // Рекурсивно викликаємо функцію для решти букв
            swap((word + left), (word + i)); // Повертаємо першу букву на своє місце
        }
    }
}

int main()
{
    SetConsoleCP (1251); 
    SetConsoleOutputCP (1251) ;
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int n = strlen(word);
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i; // Обчислюємо факторіал довжини слова
    }

    int count = 0;
    printAnagrams(word, 0, n - 1, &count); // Рахуємо кількість анаграм

    printf("Кількість анаграм: %d\n", count); // Виводимо кількість анаграм

    return 0;
}
