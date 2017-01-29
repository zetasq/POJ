#include <stdio.h>
#include <string.h>

void trimEndingZero(char *s) {
    size_t length = strlen(s);
    int hasDot = 0;
    size_t lastNoneZeroPos = 0;
    
    for (size_t pos = length - 1; pos > 0; pos--) {
        if (s[pos] != '0' && lastNoneZeroPos == 0) {
            lastNoneZeroPos = pos;
        }
        
        if (s[pos] == '.') {
            hasDot = 1;
        }
    }
    
    if (hasDot && lastNoneZeroPos != 0) {
        if (s[lastNoneZeroPos] == '.') {
            s[lastNoneZeroPos] = '\0';
        } else {
            s[lastNoneZeroPos + 1] = '\0';
        }
    }
}

void removeDot(char *s) {
    char *dotPtr = strchr(s, '.');
    
    if (dotPtr != NULL) {
        while (*dotPtr != '\0') {
            *dotPtr = *(dotPtr + 1);
            dotPtr++;
        }
    }
}

void trimLeftZero(char *s) {
    size_t len = strlen(s);
    char *firstNonZeroPtr = NULL;
    
    for (size_t i = 0; i < len; i++) {
        if (s[i] != '0') {
            firstNonZeroPtr = s + i;
            break;
        }
    }
    
    if (firstNonZeroPtr == NULL) {
        s[0] = '0';
        s[1] = '\0';
    } else {
        if (firstNonZeroPtr != s) {
            size_t diff = firstNonZeroPtr - s;
            for (size_t i = 0; i < len - diff; i++) {
                s[i] = s[i + diff];
            }
            s[len - diff] = '\0';
        }
    }
}

void strMul(char *a, char *b) {
    int reversed_map[1000] = { 0 };
    size_t len_a = strlen(a), len_b = strlen(b);
    
    for (size_t i = len_a; i > 0; i--) {
        for (size_t j = len_b; j > 0; j--) {
            reversed_map[(len_a - i) + (len_b - j)] += (int)(a[i - 1] - '0') * (int)(b[j - 1] - '0');
        }
    }
    
    size_t result_len = 1;
    
    for (size_t i = 0; i < sizeof(reversed_map) / sizeof(reversed_map[0]) - 1; i++) {
        int dividend = reversed_map[i];
        int quotient = dividend / 10;
        int remainder = dividend % 10;
        
        reversed_map[i] = remainder;
        reversed_map[i + 1] += quotient;
    }
    
    for (size_t i = (sizeof(reversed_map) / sizeof(reversed_map[0])); i > 0; i--) {
        if (reversed_map[i - 1] != 0) {
            result_len = i;
            break;
        }
    }
    
    for (size_t i = result_len; i > 0; i--) {
        a[result_len - i] = '0' + reversed_map[i - 1];
    }
    
    a[result_len] = '\0';
}

size_t strNumberSignificance(char *s) {
    size_t len = strlen(s);
    
    for (size_t i = len; i > 0; i--) {
        if (s[i - 1] == '.') {
            return len - i;
        }
    }
    
    return 0;
}

int main() {
    char r[1000];
    int d;
    char s_d[1000];
    char r_temp[1000];
    
    char result[1000];
    
    while (scanf("%s%d", r, &d) == 2) {
        sprintf(s_d, "%d", d);
        trimEndingZero(r);

        size_t significance = strNumberSignificance(r);
        size_t result_significance = significance * d;
        
        removeDot(r);
        trimLeftZero(r);
        
        strcpy(r_temp, r);
        
        if (d > 1) {
            for (int i = 0; i < d - 1; i++) {
                strMul(r, r_temp);
            }
        }
        
        size_t result_len = strlen(r);
        if (result_significance > 0) {
            if (result_significance >= result_len) {
                result[0] = '.';
                
                for (size_t i = 0; i < result_significance - result_len; i++) {
                    result[1 + i] = '0';
                }
                
                for (size_t i = 0; i < result_len; i++) {
                    result[1 + result_significance - result_len + i] = r[i];
                }
                
                result[1 + result_significance] = '\0';
            } else {
                for (size_t i = 0; i < (result_len - result_significance); i++) {
                    result[i] = r[i];
                }
                
                result[result_len - result_significance] = '.';
                for (size_t i = result_len - result_significance + 1; i < result_len + 1; i++) {
                    result[i] = r[i - 1];
                }
                
                result[result_len + 1] = '\0';
            }
        } else {
            strcpy(result, r);
        }
        printf("%s\n", result);
    }
}
