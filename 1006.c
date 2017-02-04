#include <stdio.h>

int main(int argc, char **argv) {
    int p_cycle = 23, e_cycle = 28, i_cycle = 33;
    
    int p, e, i, d;
    
    int n = 0;
    
    while (scanf("%d %d %d %d", &p, &e, &i, &d) == 4 && p != -1) {
        n++;
        
        int p_s = p % p_cycle;
        int e_s = e % e_cycle;
        int i_s = i % i_cycle;
        
        int triple_p = p_s;
        while ((triple_p - e_s) % e_cycle != 0 || (triple_p - i_s) % i_cycle != 0) {
            triple_p += p_cycle;
        }
        
        for (; triple_p <= d; triple_p += 21252)
            ;
        
        printf("Case %d: the next triple peak occurs in %d days.\n", n, triple_p - d);
    }
}
