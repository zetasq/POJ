#include <stdio.h>
#include <string.h>

int haab_name_to_n(const char *name);
const char *tzolkin_days_to_name(int days);
int tzolkin_days_to_number(int days);

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    
    int number_of_day, year;
    char month_name[10];
    
    int total_days;
    int number_of_haab_month;
    int tzolkin_year;
    int tzolkin_days_since_current_year;
    
    printf("%d\n", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d. %s %d", &number_of_day, month_name, &year);
        
        number_of_haab_month = haab_name_to_n(month_name);
        total_days = year * 365 + number_of_haab_month * 20 + number_of_day;
        
        tzolkin_year = total_days / 260;
        tzolkin_days_since_current_year = total_days % 260;
        
        const char *tzolkin_name = tzolkin_days_to_name(tzolkin_days_since_current_year);
        int tzolkin_number = tzolkin_days_to_number(tzolkin_days_since_current_year);
        
        printf("%d %s %d\n", tzolkin_number, tzolkin_name, tzolkin_year);
    }
}

int haab_name_to_n(const char *name) {
    static char *haab_month_names[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
    
    for (int i = 0; i < sizeof(haab_month_names) / sizeof(haab_month_names[0]); i++) {
        if (strcmp(name, haab_month_names[i]) == 0) {
            return i;
        }
    }
    
    return -1;
}

const char *tzolkin_days_to_name(int days) {
    static char *tzolkin_day_names[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
    return tzolkin_day_names[days % 20];
}

int tzolkin_days_to_number(int days) {
    return days % 13 + 1;
}
