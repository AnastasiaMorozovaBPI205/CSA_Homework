//
// Created by anastasia on 05.10.2021.
//

#include "beast.h"
#include <stdlib.h>
#include "string.h"
#include "stdio.h"

// Метод получения данных о звере из файла.
void FillInBeast(FILE* file, struct beast *beast_) {
    int food_type;
    char name[15];

    // Читаем имя, вес и рацион зверя.
    fscanf(file, "%s %i %i", name, &beast_->weight, &food_type);

    // Выделяем память для имени.
    memcpy(beast_->name, name, 15);

    if (food_type == 0) {
        beast_->animal_food_type = carnivores;
    } else if (food_type == 1) {
        beast_->animal_food_type = herbivores;
    } else if (food_type == 2) {
        beast_->animal_food_type = insectivores;
    }
}

// Метод вывода данных о звере в файл.
void PrintOutBeast(struct beast *beast_, FILE* file) {
    if (beast_->animal_food_type == carnivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST name: ", beast_->name,
                "; weight: ", beast_->weight,
                "; this beast is carnivores; func res: ", QuotientBeast(beast_));
    } else if (beast_->animal_food_type == herbivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST name: ", beast_->name,
                "; weight: ", beast_->weight,
                "; this beast is herbivores; func res: ", QuotientBeast(beast_));
    } else if (beast_->animal_food_type == insectivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST name: ", beast_->name,
                "; weight: ", beast_->weight,
                "; this beast is insectivores; func res: ", QuotientBeast(beast_));
    }
}

// Метод для создания рандомных данных о звере.
void FillInRndBeast(struct beast *beast_) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r',
                         's', 't', 'u', 'x', 'y', 'w', 'q', 'h', 'v', 'z'};

    // Рандомизируем длину имени.
    int name_len = rand() % (6) + 5;

    // Рандомизируем имя.
    for (int i = 0; i < name_len; i++) {
        beast_->name[i] = alphabet[rand() % (25)];
    }

    // Рандомизируем вес.
    beast_->weight = rand() % (96) + 5;

    // Рандомизируем рацион питания зверя.
    int random_variable = rand() % 3;

    if (random_variable == 0) {
        beast_->animal_food_type = carnivores;
    } else if (random_variable == 1) {
        beast_->animal_food_type = herbivores;
    } else {
        beast_->animal_food_type = insectivores;
    }
}

// Метод вычисления частного от деления суммы кодов символов имени зверя на его вес.
double QuotientBeast (struct beast *beast_) {
    double sum = 0.0;
    for (int i = 0; i < sizeof(beast_->name); i++) {
        sum += (int)(beast_->name[i]);
    }

    return  sum / beast_->weight;
}