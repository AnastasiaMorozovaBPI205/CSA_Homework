//
// Created by anastasia on 05.10.2021.
//

#ifndef ABC_HW1_CLEANC_BEAST_H
#define ABC_HW1_CLEANC_BEAST_H

#include <bits/types/FILE.h>

struct beast {
    enum food_type {
        carnivores,
        herbivores,
        insectivores
    };

    enum food_type animal_food_type;
    char name[15];
    int weight;
};

void FillInBeast(FILE* file, struct beast *beast_);

void FillInRndBeast(struct beast *beast_);

void PrintOutBeast(struct beast *beast_, FILE* file);

double QuotientBeast(struct beast *beast_);

#endif //ABC_HW1_CLEANC_BEAST_H
