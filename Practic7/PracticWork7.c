#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    double distance;
    int intersectionPoints;

    // Зчитуємо координати центрів та радіуси двох колів
    printf("Введіть координати центра першого кола (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Введіть радіус першого кола (r1): ");
    scanf("%lf", &r1);
    printf("Введіть координати центра другого кола (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Введіть радіус другого кола (r2): ");
    scanf("%lf", &r2);

    // Обчислюємо відстань між центрами колів за формулою sqrt((x2 - x1)^2 + (y2 - y1)^2)
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Перевіряємо випадки перетину колів
    if (distance > r1 + r2) {
        // Кола не перетинаються
        intersectionPoints = 0;
    } else if (distance < fabs(r1 - r2)) {
        // Одне коло знаходиться всередині іншого
        intersectionPoints = 0;
    } else if (distance == 0 && r1 == r2) {
        // Кола збігаються
        intersectionPoints = -1;
    } else if (distance == r1 + r2 || distance == fabs(r1 - r2)) {
        // Кола торкаються зовні або всередині
        intersectionPoints = 1;
    } else {
        // Кола перетинаються в двох точках
        intersectionPoints = 2;
    }

    // Вивод результата
    printf("Кількість точок перетину: %d\n", intersectionPoints);

    return 0;
}
