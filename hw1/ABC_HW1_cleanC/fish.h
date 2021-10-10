//
// Created by anastasia on 05.10.2021.
//

#ifndef ABC_HW1_CLEANC_FISH_H
#define ABC_HW1_CLEANC_FISH_H

#include <bits/types/FILE.h>

struct fish {
    enum home {
        lake,
        sea,
        river
    };

    enum home fish_home;
    char name[15];
    int weight;
};

void FillInFish(FILE* file, struct fish *fish_);

void FillInRndFish(struct fish *fish_);

void PrintOutFish(struct fish *fish_, FILE* file);

double QuotientFish(struct fish *fish_);

#endif //ABC_HW1_CLEANC_FISH_H
