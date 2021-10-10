//
// Created by anastasia on 05.10.2021.
//

#ifndef ABC_HW1_CLEANC_ANIMAL_H
#define ABC_HW1_CLEANC_ANIMAL_H

#include <stdbool.h>
#include <bits/types/FILE.h>
#include "fish.h"
#include "bird.h"
#include "beast.h"

struct animal {
    enum key {FISH, BIRD, BEAST};
    enum key k;

    union {
        struct fish fish_;
        struct bird bird_;
        struct beast beast_;
    };
};

bool FillInAnimal(FILE* file, struct animal* animal_, int key);

bool FillInRndAnimal(struct animal* animal_);

void PrintOutAnimal(struct animal* animal_, FILE* file);

double QuotientAnimal(struct animal* animal_);

#endif //ABC_HW1_CLEANC_ANIMAL_H
