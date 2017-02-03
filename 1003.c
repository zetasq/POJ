#include <stdio.h>

#define MAX_CARDS_COUNT 276

int main(int argc, char **argv) {
    double overhangs[MAX_CARDS_COUNT + 1];
    
    double sum = 0;
    for (int i = 1; i < MAX_CARDS_COUNT + 1; i++) {
        double r = 1.0 / (i + 1);
        sum += r;
        overhangs[i] = sum;
    }
    
    double length;
    
    while (scanf("%lf", &length) == 1 && length > 0) {
        int lower = 1, upper = MAX_CARDS_COUNT;
        int middle;
        while (lower != upper) {
            middle = (lower + upper) / 2;
            if (length < overhangs[middle]) {
                upper = middle;
            } else if (length > overhangs[middle]) {
                lower = middle + 1;
            } else {
                lower = middle;
                upper = middle;
                break;
            }
        }
        
        printf("%d card(s)\n", lower);
    }
}
