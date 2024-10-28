#include <stdio.h>
#include <time.h>

int main(void) {
    struct tm tm_info;
    char buffer[20];

    printf("Введите дату и время в формате (ДД-ММ-ГГГГ ЧЧ:ММ:СС:)");
    fgets(buffer, 20, stdin);

    if(strptime(buffer, "%d-%m-%Y %H:%M:%S", &tm_info) == NULL) {
        printf("Введён неверный формат номера телефона.");
        return 1;
    }

    time_t time = mktime(&tm_info);

    printf("Entered date time: %s", asctime(&tm_info));

    return 0;
}