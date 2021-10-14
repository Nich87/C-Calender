#include <stdio.h>

int check_year(int); //Prototype宣言

int main(void) {
    int year, month;
    int month_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, cnt, tmp;
    int total = 0;

    // 西暦年入力
    do {
        printf("西暦: ");
        scanf_s("%d", &year);
    } while (year < 1);

    // 月日入力
    do {
        printf("月: ");
        scanf_s("%d", &month);
    } while (month < 1 || month > 12);

    // ずれ計算
    tmp = (year - 1) % 400;     // 400年ごとのずれは、0。
    total = (tmp / 100) * 5;    // 100年ごとのずれは、5。
    total += tmp % 100 / 4 * 5; //   4年ごとのずれは、5。
    total += tmp % 4;           //   1年ごとのずれは、1。

    if (check_year(year)) month_date[1]++; // 閏年の2月分

    for (i = 0; i < month - 1; i++) total = total + month_date[i];

    // カレンダーを表示する
    printf("\n\n\t%d年\n%4d月\n", year, month);
    printf(" 月 火 水 木 金 土 日\n");
    for (i = 1, cnt = 0; i <= total % 7; i++, cnt++)
        printf("   "); // その月の初日の曜日のずれを考慮 | 月曜->ずらさない 火曜->1日ずらす
    for (i = 1; i <= month_date[month - 1]; i++, cnt++) {
        if (cnt % 7 == 0) printf("\n");
        printf("%3d", i);
    }
    printf("\n");
    return 0;
}

//閏年は1を返す関数
int check_year(int year) {
    if (year % 400 == 0) return 1;
    if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}