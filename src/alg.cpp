// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return value;
    } else {
        return pown(value, n - 1) * value;
    }
}

uint64_t fact(uint16_t n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double SumOfItem = 0;
    for (uint16_t i = 0; i < count + 1; i++) {
        SumOfItem += calcItem(x, i);
    }
    return SumOfItem;
}

double sinn(double x, uint16_t count) {
    double SumOfItem = 0;
    for (uint16_t i = 1; i < count + 1; i++) {
        if (i % 2 == 0) {
            SumOfItem -= calcItem(x, 2 * i - 1);
        } else {
            SumOfItem += calcItem(x, 2 * i - 1);
        }
    }
    return SumOfItem;
}

double cosn(double x, uint16_t count) {
    double SumOfItem = 1;
    for (uint16_t i = 2; i < count + 1; i++) {
        if (i % 2 == 0) {
            SumOfItem -= calcItem(x, 2 * i - 2);
        } else {
            SumOfItem += calcItem(x, 2 * i - 2);
        }
    }
    return SumOfItem;
}
