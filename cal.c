#include <stdio.h>

int check_year(int); //PrototypeéŒ¾

int main(void) {
    int year, month;
    int month_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, cnt;
    int total = 0;

    // ¼—ï”N“ü—Í
    do {
        printf("¼—ï: ");
        scanf_s("%d", &year);
    } while (year < 1);

    // Œ“ú“ü—Í
    do {
        printf("Œ: ");
        scanf_s("%d", &month);
    } while (month < 1 || month > 12);

    // “ú”ŒvZ
    for (i = 1; i <= year - 1; i++) {
        total = total + 365 + check_year(i);
    }

    if (check_year(year)) month_date[1]++; // ‰[”N‚Ì2Œ•ª

    for (i = 0; i < month - 1; i++) total = total + month_date[i];

    // ƒJƒŒƒ“ƒ_[‚ğ•\¦‚·‚é
    printf("\n\n\t%d”N\n%4dŒ\n", year, month);
    printf(" Œ ‰Î … –Ø ‹à “y “ú\n");
    for (i = 1, cnt = 0; i <= total % 7; i++, cnt++)
        printf("   "); // ‚»‚ÌŒ‚Ì‰“ú‚Ì—j“ú‚Ì‚¸‚ê‚ğl—¶ | Œ—j->‚¸‚ç‚³‚È‚¢ ‰Î—j->1“ú‚¸‚ç‚·
    for (i = 1; i <= month_date[month - 1]; i++, cnt++) {
        if (cnt % 7 == 0) printf("\n");
        printf("%3d", i);
    }
    printf("\n");
    return 0;
}

//‰[”N‚Í1‚ğ•Ô‚·ŠÖ”
int check_year(int year) {
    if (year % 400 == 0) return 1;
    else if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}