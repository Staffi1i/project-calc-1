//////#include"Header.h"
//////using namespace std;
//////int main() {
//////	setlocale(LC_ALL, "Rus");
//////	int n = 1, cnt_v_1 = 0, cnt_v_2 = 0, len1 = 0, len2 = 0;
//////	char a1[100], a2[100];
//////	cout << "Введите первое число: "; cin >> a1;
//////	cout << "Введите второе число: "; cin >> a2;
//////	lenstr(len1, a1);
//////	lenstr(len2, a2);
//////	int p_len1 = len1 + 1, p_len2 = len2 + 1;
//////
//////	int** a = (int**)malloc(n * sizeof(int*));
//////	for (int i = 0; i < n; i++)
//////		a[i] = (int*)malloc(len1 * sizeof(int));
//////
//////	int** b = (int**)malloc(n * sizeof(int*));
//////	for (int i = 0; i < n; i++)
//////		b[i] = (int*)malloc(len2 * sizeof(int));
//////	for (int i = 0; i < n; i++)
//////		for (int j = 0; j < len1; j++)
//////			a[i][j] = a1[len1 - 1 - j]- '0';
//////	for (int i = 0; i < n; i++)
//////		for (int j = 0; j < len1; j++)
//////			cout << a[i][j] << " ";
//////}
////#include <iostream>
////#include <cstring>
////#include <algorithm>
////using namespace std;
////
////const int MAXN = 10005;
////int a[MAXN], b[MAXN], c[MAXN], d[MAXN], e[MAXN], f[MAXN];
////char s1[MAXN], s2[MAXN];
////
////int main()
////{
////    cin >> s1 >> s2;
////
////    int len1 = strlen(s1);
////    int len2 = strlen(s2);
////
////    for (int i = 0; i < len1; i++) {
////        a[i] = s1[len1 - 1 - i] - '0';
////    }
////
////    for (int i = 0; i < len2; i++) {
////        b[i] = s2[len2 - 1 - i] - '0';
////    }
////
////    int len = max(len1, len2);
////
////    // addition
////    int carry = 0;
////    for (int i = 0; i < len; i++) {
////        c[i] = a[i] + b[i] + carry;
////        carry = c[i] / 10;
////        c[i] %= 10;
////    }
////    if (carry) c[len++] = carry;
////
////    // subtraction
////    int borrow = 0;
////    for (int i = 0; i < len; i++) {
////        d[i] = a[i] - b[i] - borrow;
////        if (d[i] < 0) {
////            d[i] += 10;
////            borrow = 1;
////        }
////        else {
////            borrow = 0;
////        }
////    }
////    while (len > 1 && d[len - 1] == 0) len--;
////
////    // multiplication
////    for (int i = 0; i < len1; i++) {
////        int carry = 0;
////        for (int j = 0; j < len2; j++) {
////            e[i + j] += a[i] * b[j] + carry;
////            carry = e[i + j] / 10;
////            e[i + j] %= 10;
////        }
////        if (carry) e[i + len2] += carry;
////    }
////    len = len1 + len2;
////    while (len > 1 && e[len - 1] == 0) len--;
////
////    // division
////    int divisor = b[0];
////    int dividend = 0;
////    int k = 0;
////    for (int i = len1 - 1; i >= 0; i--) {
////        dividend = dividend * 10 + a[i];
////        f[i] = dividend / divisor;
////        dividend %= divisor;
////    }
////    reverse(f, f + len1);
////    while (len1 > 1 && f[len1 - 1] == 0) len1--;
////
////    // output
////    cout << "Addition: ";
////    for (int i = len - 1; i >= 0; i--) cout << c[i];
////    cout << endl;
////
////    cout << "Subtraction: ";
////    if (borrow) cout << "-";
////    for (int i = len - 1; i >= 0; i--) cout << d[i];
////    cout << endl;
////
////    cout << "Multiplication: ";
////    for (int i = len - 1; i >= 0; i--) cout << e[i];
////    cout << endl;
////
////    cout << "Division: ";
////    for (int i = 0; i < len1; i++) cout << f[i];
////    cout << endl;
////
////    return 0;
////}
//#include <stdio.h>
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#define N 1000
//
//int main()
//{
//    int dividend[N], divisor[N], quotient[N], remainder[N];
//    int dividend_length, divisor_length, quotient_length = 0, remainder_length;
//    int i, j;
//
//    // Инициализация массивов
//    for (i = 0; i < N; i++) {
//        dividend[i] = divisor[i] = quotient[i] = remainder[i] = 0;
//    }
//
//    // Ввод делимого и делителя
//    printf("Введите делимое: ");
//    scanf("%s", dividend);
//    printf("Введите делитель: ");
//    scanf("%s", divisor);
//
//    // Вычисление длин делимого и делителя
//    dividend_length = strlen(dividend);
//    divisor_length = strlen(divisor);
//    remainder_length = divisor_length;
//
//    // Инициализация остатка
//    for (i = 0; i < divisor_length; i++) {
//        remainder[i] = dividend[i] - '0';
//    }
//
//    // Основной цикл деления
//    for (i = 0; i < dividend_length - divisor_length + 1; i++) {
//        // Вычисление частного
//        quotient[i] = remainder[i] / (divisor[0] - '0');
//        // Вычисление нового остатка
//        for (j = 0; j < divisor_length; j++) {
//            remainder[i + j] -= quotient[i] * (divisor[j] - '0');
//        }
//        // Корректировка остатка
//        for (j = 0; j < divisor_length; j++) {
//            if (remainder[i + j] < 0) {
//                remainder[i + j + 1] -= 1;
//                remainder[i + j] += 10;
//            }
//        }
//    }
//
//    // Вычисление длины частного
//    for (i = N - 1; i >= 0; i--) {
//        if (quotient[i] != 0) {
//            quotient_length = i + 1;
//            break;
//        }
//    }
//
//    // Вывод частного и остатка
//    printf("Частное: ");
//    for (i = quotient_length - 1; i >= 0; i--) {
//        printf("%d", quotient[i]);
//    }
//    printf("\nОстаток: ");
//    /*for (i = remainder_length - 1; i >= 0; i--)*/
//}