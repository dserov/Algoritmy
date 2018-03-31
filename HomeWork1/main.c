/*
 * Dmitrij Serov
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

// declaration
void test_3();

void solution1();

void solution2();

void solution3_a(int *a, int *b);

void solution3_b(int *a, int *b);

void solution4();

void solution5();

void solution6();

void solution7();

void solution8();

void solution9();

void solution10();

void solution11();

void solution12();

void solution13_a();

void solution13_b();

void solution14();
unsigned int isAutoMorfNumber(unsigned int uiOriginNumber);

// implementation
int main() {
    printf("Enter number of solution (1-14 or -1 for exit)\n");
    int num = 0;
    scanf("%d", &num);
    switch (num) {
        case -1:
            return 0;
        case 1:
            solution1();
            break;
        case 2:
            solution2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            solution4();
            break;
        case 5:
            solution5();
            break;
        case 6:
            solution6();
            break;
        case 7:
            solution7();
            break;
        case 8:
            solution8();
            break;
        case 9:
            solution9();
            break;
        case 10:
            solution10();
            break;
        case 11:
            solution11();
            break;
        case 12:
            solution12();
            break;
        case 13:
            solution13_a();
            solution13_b();
            break;
        case 14:
            solution14();
            break;
    }
    return 0;
}

/**
 * 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела
 * по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
 */
void solution1() {
    int iMassa = 0;
    int iRost = 0;
    double dRost = 0.0;

    printf("Calc IMB\nEnter massa (kg):\n");
    scanf("%d", &iMassa);
    printf("Enter rost (in sm):\n");
    scanf("%d", &iRost);
    dRost = (double) iRost / 100;
    printf("Index IMB = %.2f", (double) iMassa / (dRost * dRost));
}

/**
 * 2. Найти максимальное из четырех чисел. Массивы не использовать.
 */
void solution2() {
    int i1, i2, i3, i4;
    printf("Enter chislo 1:\n");
    scanf("%d", &i1);
    printf("Enter chislo 2:\n");
    scanf("%d", &i2);
    printf("Enter chislo 3:\n");
    scanf("%d", &i3);
    printf("Enter chislo 4:\n");
    scanf("%d", &i4);

    int iMax = i1;
    if (iMax < i2) iMax = i2;
    if (iMax < i3) iMax = i3;
    if (iMax < i4) iMax = i4;

    printf("Max chislo: %d\n", iMax);
}

/**
 * 3. Написать программу обмена значениями двух целочисленных переменных:
 *    a. с использованием третьей переменной;
 *    b. *без использования третьей переменной.
 */
void test_3() {
    int a = 12;
    int b = 34;
    printf("a)before: a=%d, b=%d\n", a, b);
    solution3_a(&a, &b);
    printf("a)after: a=%d, b=%d\n", a, b);
    printf("b)before: a=%d, b=%d\n", a, b);
    solution3_b(&a, &b);
    printf("b)after: a=%d, b=%d\n", a, b);
}

void solution3_a(int *a, int *b) {
    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}

void solution3_b(int *a, int *b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

/**
 * 4. Написать программу нахождения корней заданного квадратного уравнения.
 * ax<sup>2</sup> + bx + c = 0
 */
void solution4() {
    double a = 12;
    double b = 10;
    double c = 5;

    // find D = b<sup>2</sup> - 4ac
    double d = b * b + 4 * a * c;
    if (d == 0) {
        double x = (-1 * b + sqrt(d)) / 2 * a;
        printf("x1 = x2 = %f\n", x);
        return;
    }

    double x1 = (-1 * b + sqrt(d)) / 2 * a;
    double x2 = (-1 * b - sqrt(d)) / 2 * a;
    printf("x1 = %f, x2 = %f\n", x1, x2);
}

/**
 * 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
 */
void solution5() {
    printf("Vvedite nomer mesyaca(1-12):\n");
    int iMonth = 0;
    scanf("%d", &iMonth);
    if (iMonth < 1 || iMonth > 12) {
        printf("Vne diapazona\n");
        return;
    }
    char *cMec[] = {"zima", "vesna", "leto", "osen"};
    char *cVremyagoda;
    switch (iMonth) {
        case 12:
        case 1:
        case 2:
            cVremyagoda = cMec[0];
            break;
        case 3:
        case 4:
        case 5:
            cVremyagoda = cMec[1];
            break;
        case 6:
        case 7:
        case 8:
            cVremyagoda = cMec[2];
            break;
        default:
            cVremyagoda = cMec[3];
            break;
    }
    printf("You select %s\n", cVremyagoda);
}

/**
 * 6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
 */
void solution6() {
    printf("Vvedite vozrast(1-150):\n");
    int iAge = 0;
    scanf("%d", &iAge);
    if (iAge < 1 || iAge > 150) {
        printf("Vne diapazona\n");
        return;
    }
    char *pszArray[] = {"god", "goda", "let"};
    char *pszEnding = NULL;
    int iLastDigit = iAge % 10;
    int iPreLastDigit = 0;
    if (iAge > 9)iPreLastDigit = (iAge / 10) % 10;
    if (iLastDigit == 0)
        pszEnding = pszArray[2];
    else if (iPreLastDigit == 0) {
        switch (iLastDigit) {
            case 1:
                pszEnding = pszArray[0];
                break;
            case 2:
                pszEnding = pszArray[1];
                break;
            case 3:
                pszEnding = pszArray[1];
                break;
            case 4:
                pszEnding = pszArray[1];
                break;
            default:
                pszEnding = pszArray[2];
                break;
        }
    } else if (iPreLastDigit == 1) {
        pszEnding = pszArray[2];
    } else if (iPreLastDigit >= 2) {
        switch (iLastDigit) {
            case 1:
                pszEnding = pszArray[0];
                break;
            case 2:
            case 3:
            case 4:
                pszEnding = pszArray[1];
                break;
            default:
                pszEnding = pszArray[2];
                break;
        }
    }
    printf("Vash vozrast %d %s\n", iAge, pszEnding);
}

/**
 * 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
 *    Требуется определить, относятся ли к поля к одному цвету или нет.
 */
void solution7() {
    int x1, x2, y1, y2;
    printf("Enter x1:\n");
    scanf("%d", &x1);
    printf("Enter y1:\n");
    scanf("%d", &y1);
    printf("Enter x2:\n");
    scanf("%d", &x2);
    printf("Enter y2:\n");
    scanf("%d", &y2);

    // белое поле, если х нечетное, то и у - нечетное. Или четный х и четный у.
    int bColor1 = (x1 % 2) ^(y1 % 2); // 0 - white color, 1 - black color
    int bColor2 = (x2 % 2) ^(y2 % 2);
    if (bColor1 == bColor2)
        printf("Odin cvet\n");
    else
        printf("Raznye cveta\n");
}

/**
 * 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
 */
void solution8() {
    int a, b;
    printf("Enter a: \n");
    scanf("%d", &a);
    printf("Enter b: \n");
    scanf("%d", &b);
    if (a > b) {
        printf("Error: a > b\n");
        return;
    }
    while (a <= b) {
        // Для возведения в куб быстрее перемножить целые числа, чем заниматься приведением типов в pow
        printf("%d^2=%d,  %d^3=%d\n", a, a * a, a * a * a);
        a++;
    }
}

/**
 * 9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания,
 *    найти частное от деления нацело N на K, а также остаток от этого деления.
 */
void solution9() {
    int iN = 123;
    int iK = 20;
    int iC = 0; // частное
    int iO = 0; // остаток
    int i = iN;
    while (i > iK) {
        iC++;
        i -= iK;
    }
    iO = i;

    printf("Chastnoe ot deleniya %d/%d = %d, ostatok %d\n", iN, iK, iC, iO);
}

/**
 * 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,
 *     имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
 */
void solution10() {
    int iN = 122466;
    int iResult = 0; // 0 - нет нечетных цифр
    int i = iN;
    while (iResult == 0 && i > 0) {
        iResult = (i % 10) % 2;
        i /= 10;
    }
    printf("Chislo %d - %s imeet nechetnyh cifr", iN, (iResult) ? "" : "ne");
}

/**
 * 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое
 *     всех положительных четных чисел, оканчивающихся на 8.
 */
void solution11() {
    unsigned int iNumberCount = 0;
    unsigned int iTotalSumma = 0;
    int iEnteredNumber = 0;
    for (;;) {
        printf("Please, enter integer number: \n");
        scanf("%d", &iEnteredNumber);
        if (iEnteredNumber == 0) break;
        if (iEnteredNumber > 0 && (iEnteredNumber % 2 == 0) && (iEnteredNumber % 10 == 8)) {
            iNumberCount++;
            iTotalSumma += iEnteredNumber;
        }
    }

    if (iNumberCount == 0) {
        printf("You not enter valid numbers!");
        return;
    }

    printf("You average sum is: sum=%d, count=%d, average result=%lf",
           iTotalSumma, iNumberCount, (double) iTotalSumma / iNumberCount);
}

/**
 * 12. Написать функцию нахождения максимального из трех чисел.
 */
void solution12() {
    int iA = 123,
            iB = 345,
            iC = 243,
            iMax = 0;

    iMax = (iA > iB ? iA : iB);
    iMax = (iMax > iC ? iMax : iC);
    printf("Maximum is: %d", iMax);
}

/**
 * 13. * Написать функцию, генерирующую случайное число от 1 до 100.
 *     с использованием стандартной функции rand()
 *     без использования стандартной функции rand()
 */
void solution13_a() {
    srand((int) time(NULL));
    printf("Random with rand() function: %u\n", rand() % 100 + 1);
}

/**
 * https://en.wikipedia.org/wiki/Linear-feedback_shift_register
 */
void solution13_b() {
    uint16_t start_state = 0xABCDu;  /* Any nonzero start state will work. */
    uint16_t lfsr = start_state;
    uint16_t bit;                    /* Must be 16bit to allow bit<<15 later in the code */
    do {
        /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
        lfsr = (lfsr >> 1) | (bit << 15);
    } while (lfsr != start_state);
    printf("Random without rand() function: %u\n", lfsr % 100 + 1);
}

/**
 * 14. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
 *     Например, 25 \ :sup: 2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран
 *     все автоморфные числа, не превосходящие N.
 */
void solution14() {
    unsigned int uiMaxLimit = 0;
    for (;;) {
        printf("Enter integer positive number N: \n");
        scanf("%u", &uiMaxLimit);
        if (uiMaxLimit > 0) break;
    }

    for (unsigned int i = 0; i <= uiMaxLimit; i++) {
        // check is automorph
        if (isAutoMorfNumber(i)) printf("Number: %u, i^2: %lu\n", i, i * i);
    }
}

unsigned int isAutoMorfNumber(unsigned int uiOriginNumber) {
    unsigned long ulSqureNumber = uiOriginNumber * uiOriginNumber;
    while (uiOriginNumber > 0) {
        if (uiOriginNumber % 10 != ulSqureNumber % 10) return 0; // not automorf
        uiOriginNumber /= 10;
        ulSqureNumber /= 10;
    }
    return 1; // we found it!
}
