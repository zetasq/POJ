#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    
    double x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        
        double r = sqrt(x * x + y * y);
        double area = 3.14159 * r * r / 2;
        int year = ceil(area / 50);
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
    }
    
    printf("END OF OUTPUT.");
}
