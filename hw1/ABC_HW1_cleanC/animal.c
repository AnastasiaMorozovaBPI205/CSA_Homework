//
// Created by anastasia on 05.10.2021.
//

#include "animal.h"
#include "stdlib.h"
#include <stdio.h>

// Метод переотправляет структуру животного в более специфицеский метод для чтения из файла.
bool FillInAnimal(FILE* file, struct animal* animal_, int key) {
    switch(key) {
        case 1:
            animal_->k = FISH;
            FillInFish(file, &animal_->fish_);
            return true;
        case 2:
            animal_->k = BIRD;
            FillInBird(file, &animal_->bird_);
            return true;
        case 3:
            animal_->k = BEAST;
            FillInBeast(file, &animal_->beast_);
            return true;
        default:
            return false;
    }
}

// Метод переотправляет структуру животного в более специфицеский метод для рандомизации.
bool FillInRndAnimal(struct animal* animal_) {
    int key = rand() % (3) + 1;
    switch(key) {
        case 1:
            animal_->k = FISH;
            FillInRndFish(&animal_->fish_);
            return true;
        case 2:
            animal_->k = BIRD;
            FillInRndBird(&animal_->bird_);
            return true;
        case 3:
            animal_->k = BEAST;
            FillInRndBeast(&animal_->beast_);
            return true;
        default:
            return false;
    }
}

// Метод переотправляет структуру животного в более специфицеский метод для вывода.
void PrintOutAnimal(struct animal* animal_, FILE* file) {
    switch(animal_->k) {
        case FISH:
            PrintOutFish(&(animal_->fish_), file);
            break;
        case BIRD:
            PrintOutBird(&(animal_->bird_), file);
            break;
        case BEAST:
            PrintOutBeast(&(animal_->beast_), file);
            break;
        default:
            fprintf(file, "%s", "No such animal.");
    }
}

// Метод переотправляет структуру животного в более специфицеский метод для того,
// чтобы посчитать частное от деления суммы кодов строки имени животного на его вес.
double QuotientAnimal(struct animal* animal_) {
    switch (animal_->k) {
        case FISH:
            return QuotientFish(&(animal_->fish_));
        case BIRD:
            return QuotientBird(&(animal_->bird_));
        case BEAST:
            return QuotientBeast(&(animal_->beast_));
        default:
            return 0.0;
    }
}