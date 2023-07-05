#include <stdio.h>

// ������� ��� ����������� ��� ���� �����
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    // ���������� ��������� ������� gcd() � ����������� b �� a % b
    return gcd(b, a % b);
}

// ������� ��� ����������� ��� ���� �����
int lcm(int a, int b) {
    // ��� ����� ������ �� ��������: ���(a,b) = a * b / ���(a,b)
    // ���� ��������� ������� gcd() �� ��������� ��������� �� ��������
    return (a * b) / gcd(a, b);
}

int main() {
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251) ;
    int n, a, b;
    // ������� ������� �����
    scanf("%d", &n);
    // ������� ����� �����
    scanf("%d", &a);
    // ��������� �� ���� ����� �� ��������� �� ���
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        a = lcm(a, b);
    }
    // �������� ���������
    printf("%d\n", a);
    return 0;
}
