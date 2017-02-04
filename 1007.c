#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_M 100

int calculate_inversion(char *dna, int len);
void bubble_sort_dna(int lower, int higher);
void swap_dna(int idx_1, int idx_2);

char dnas[MAX_M][MAX_N + 1];
int n, m;

char *dna_ptrs[MAX_M] = {};
int dna_inversions[MAX_M] = {};

int main(int argc, char **argv) {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        do {
            fgets(dnas[i], sizeof(dnas[0]), stdin);
        } while (strlen(dnas[i]) == 0 || dnas[i][0] == '\n');

        dnas[i][n] = 0;
        dna_ptrs[i] = dnas[i];
        
        dna_inversions[i] = calculate_inversion(dnas[i], n);
    }
    
    bubble_sort_dna(0, m - 1);
    
    for (int i = 0; i < m; i++) {
        printf("%s\n", dna_ptrs[i]);
    }
}

int calculate_inversion(char *dna, int len) {
    int inversion = 0;
    for (char *ch = dna + 1; ch < dna + len; ch++) {
        for (char *prev = dna; prev < ch; prev++) {
            if (*prev > *ch) {
                inversion++;
            }
        }
    }
    return inversion;
}

void bubble_sort_dna(int lower, int higher) {
    if (lower >= higher) {
        return;
    }
    
    for (int i = higher; i > lower; i--) {
        for (int j = lower; j < i; j++) {
            if (dna_inversions[j] > dna_inversions[j + 1]) {
                swap_dna(j, j + 1);
            }
        }
    }
}

void swap_dna(int idx_1, int idx_2) {
    char *temp_s = dna_ptrs[idx_1];
    dna_ptrs[idx_1] = dna_ptrs[idx_2];
    dna_ptrs[idx_2] = temp_s;
    
    int temp_inversion = dna_inversions[idx_1];
    dna_inversions[idx_1] = dna_inversions[idx_2];
    dna_inversions[idx_2] = temp_inversion;
}
