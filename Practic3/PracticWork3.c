#include <stdio.h> 
 
int main() { 
    SetConsoleCP (1251); 
    SetConsoleOutputCP (1251) ;
    int p; 
    printf("Введіть кількість розрядів (p ≤ 30): "); 
    scanf("%d", &p); 
 
    // Ініціалізуємо масив dp, який буде містити кількість "хороших" комбінацій 
    // dp[i][0] - кількість комбінацій з числами 5 та 9 на i-му розряді, де на останньому розряді стоїть 5 
    // dp[i][1] - кількість комбінацій з числами 5 та 9 на i-му розряді, де на останньому розряді стоїть 9 
    long long dp[31][2]; 
    dp[1][0] = dp[1][1] = 1; 
 
    // Обчислюємо кількість "хороших" комбінацій для розрядів від 2 до p 
    for (int i = 2; i <= p; i++) { 
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // Для dp[i][0] можливий перехід з dp[i-1][0] або dp[i-1][1] 
        dp[i][1] = dp[i - 1][0]; // Для dp[i][1] можливий перехід тільки з dp[i-1][0] 
    } 
 
    // Знаходимо загальну кількість комбінацій, яка складається з "хороших" та "поганих" комбінацій 
    long long result = dp[p][0] + dp[p][1]; 
 
    // Виводимо результат 
    printf("Кількість чисел із %d розрядів: %lld\n", p, result); 
 
    return 0; 
}
