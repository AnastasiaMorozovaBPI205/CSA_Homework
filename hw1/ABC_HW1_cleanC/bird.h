//
// Created by anastasia on 05.10.2021.
//

#ifndef ABC_HW1_CLEANC_BIRD_H
#define ABC_HW1_CLEANC_BIRD_H

#include <stdbool.h>
#include <bits/types/FILE.h>

struct bird {
    bool is_migratory;
    char name[15];
    int weight;
};

void FillInBird(FILE* file, struct bird *bird_);

void FillInRndBird(struct bird *bird_);

void PrintOutBird(struct bird *bird_, FILE* file);

double QuotientBird(struct bird *bird_);

#endif //ABC_HW1_CLEANC_BIRD_H
