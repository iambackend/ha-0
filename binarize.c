#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarize.h"

void binarize_u(unsigned long long x) {
    char a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = '0';
    }
    bool is_ll = false;
    for (int i = 0; i < 31; i++) {
        a[i] = x % 2 + '0';
        x /= 2;
    }
    if (x != 0) {
        for (int i = 31; i < 63; i++) {
            a[i] = x % 2 + '0';
            x /= 2;
        }
        is_ll = true;
    }
    for (int i = (is_ll ? 63 : 31); i >= 0; i--) {
        printf("%c", a[i]);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

void binarize_s(signed long long y) {
    bool is_negative = y < 0;
    y = llabs(y);
    char a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = '0';
    }
    bool is_ll = false;
    for (int i = 0; i < 31; i++) {
        a[i] = y % 2 + '0';
        y /= 2;
    }
    if (y != 0) {
        for (int i = 31; i < 63; i++) {
            a[i] = y % 2 + '0';
            y /= 2;
        }
        is_ll = true;
    }

    if (is_negative) {
        for (int i = 0; i < (is_ll ? 64 : 32); i++) {
            a[i] = (a[i] == '1' ? '0' : '1');
        }

        for (int i = 0; i < (is_ll ? 64 : 32); i++) {
            a[i]++;
            if (a[i] == '2')
                a[i] = '0';
            else break;
        }
    }

    for (int i = (is_ll ? 63 : 31); i >= 0; i--) {
        printf("%c", a[i]);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}