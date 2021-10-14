#include <stdio.h>

int check_year(int); //Prototype�錾

int main(void) {
    int year, month;
    int month_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, cnt, tmp;
    int total = 0;

    // ����N����
    do {
        printf("����: ");
        scanf_s("%d", &year);
    } while (year < 1);

    // ��������
    do {
        printf("��: ");
        scanf_s("%d", &month);
    } while (month < 1 || month > 12);

    // ����v�Z
    tmp = (year - 1) % 400;     // 400�N���Ƃ̂���́A0�B
    total = (tmp / 100) * 5;    // 100�N���Ƃ̂���́A5�B
    total += tmp % 100 / 4 * 5; //   4�N���Ƃ̂���́A5�B
    total += tmp % 4;           //   1�N���Ƃ̂���́A1�B

    if (check_year(year)) month_date[1]++; // �[�N��2����

    for (i = 0; i < month - 1; i++) total = total + month_date[i];

    // �J�����_�[��\������
    printf("\n\n\t%d�N\n%4d��\n", year, month);
    printf(" �� �� �� �� �� �y ��\n");
    for (i = 1, cnt = 0; i <= total % 7; i++, cnt++)
        printf("   "); // ���̌��̏����̗j���̂�����l�� | ���j->���炳�Ȃ� �Ηj->1�����炷
    for (i = 1; i <= month_date[month - 1]; i++, cnt++) {
        if (cnt % 7 == 0) printf("\n");
        printf("%3d", i);
    }
    printf("\n");
    return 0;
}

//�[�N��1��Ԃ��֐�
int check_year(int year) {
    if (year % 400 == 0) return 1;
    if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}