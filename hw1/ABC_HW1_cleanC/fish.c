//
// Created by anastasia on 05.10.2021.
//

#include "fish.h"
#include <stdlib.h>
#include "string.h"
#include "stdio.h"

// Метод получения данных о рыбе из файла.
void FillInFish(FILE* file, struct fish *fish_) {
    int fish_home;
    char name[15];

    // Читаем имя, вес, дом рыбы из файла.
    fscanf(file, "%s %i %i", name, &fish_->weight, &fish_home);

    // Выделяем память для имени.
    memcpy(fish_->name, name, 15);

    if (fish_home == 0) {
        fish_->fish_home = lake;
    } else if (fish_home == 1) {
        fish_->fish_home = sea;
    } else if (fish_home == 2) {
        fish_->fish_home = river;
    }
}

// Метод вывода данных о рыбе в файл.
void PrintOutFish(struct fish *fish_, FILE* file) {
    if (fish_->fish_home == lake) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH name: ", fish_->name,
                "; weight: ", fish_->weight,
                "; home: lake; func res: ", QuotientFish(fish_));
    } else if (fish_->fish_home == sea) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH name: ", fish_->name,
                "; weight: ", fish_->weight,
                "; home: sea;  func res: ", QuotientFish(fish_));
    } else if (fish_->fish_home == river) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH name: ", fish_->name,
                "; weight: ", fish_->weight,
                "; home: river; func res: ", QuotientFish(fish_));
    }
}

// Метод для создания рандомных данных о рыбе.
void FillInRndFish(struct fish *fish_) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r',
                         's', 't', 'u', 'x', 'y', 'w', 'q', 'h', 'v', 'z'};

    // Рандомизируем длину имени.
    int name_len = rand() % (6) + 5;

    // Рандомизируем имя.
    for (int i = 0; i < name_len; i++) {
        fish_->name[i] = alphabet[rand() % (25)];
    }

    // Рандомизируем вес.
    fish_->weight = rand() % (96) + 5;

    // Рандомизируем дом рыбы.
    int random_variable = rand() % 3;

    if (random_variable == 0) {
        fish_->fish_home = lake;
    } else if (random_variable == 1) {
        fish_->fish_home = sea;
    } else {
        fish_->fish_home = river;
    }
}

// Метод вычисления частного от деления суммы кодов символов имени рыбы на вес рыбы.
double QuotientFish(struct fish *fish_) {
    double sum = 0.0;
    for (int i = 0; i < sizeof(fish_->name); ++i) {
        sum += (int)(fish_->name[i]);
    }


    return  sum / fish_->weight;
}