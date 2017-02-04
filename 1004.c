#include <stdio.h>

#define MAX_CARDS_COUNT 276

int main(int argc, char **argv) {
    double sum = 0;
    
    double x;
    for (int i = 0; i < 12; i++) {
        scanf("%lf", &x);
        sum += x;
    }
    
    double avg = sum / 12;
    char s[100];
    snprintf(s, sizeof(s), "%.2f", avg);
    printf("$%s", s);
}
