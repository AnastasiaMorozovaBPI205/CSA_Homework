//
// Created by anastasia on 05.10.2021.
//

#include "bird.h"
#include <stdlib.h>
#include "string.h"
#include "stdio.h"

// Метод вычисления частного от деления суммы кодов символов имени птице на ее вес.
double QuotientBird(struct bird *bird_) {
    double sum = 0.0;
    for (int i = 0; i < sizeof(bird_->name); ++i) {
        sum += (int)(bird_->name[i]);
    }

    return  sum / (bird_->weight);
}

// Метод для создания рандомных данных о птице.
void FillInRndBird(struct bird *bird_) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r',
                         's', 't', 'u', 'x', 'y', 'w', 'q', 'h', 'v', 'z'};

    // Рандомизируем длину имени.
    int name_len = rand() % (6) + 5;

    // Рандомизируем имя.
    for (int i = 0; i < name_len; i++) {
        bird_->name[i] = alphabet[rand() % 25];
    }

    // Рандомизируем вес.
    bird_->weight = rand() % (96) + 5;

    // Рандомизируем - перелетная птица или нет.
    int random_variable = rand() % 2;

    if (random_variable == 0) {
        bird_->is_migratory = true;
    } else if (random_variable == 1) {
        bird_->is_migratory = false;
    }
}

// Метод вывода данных о птице в файл.
void PrintOutBird(struct bird *bird_, FILE* file) {
    if (bird_->is_migratory) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BIRD name: ", bird_->name,
                "; weight: ", bird_->weight,
                "; this bird is migratory; func res: ", QuotientBird(bird_));
    } else {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BIRD name: ", bird_->name,
                "; weight: ", bird_->weight,
                "; this bird is not migratory; func res: ", QuotientBird(bird_));
    }
}

// Метод получения данных о птице из файла.
void FillInBird(FILE* file, struct bird *bird_) {
    char name[15];

    // Читаем имя, вес, перелетная птица или нет.
    fscanf(file, "%s %i %i", name, &bird_->weight, &bird_->is_migratory);

    // Выделяем память для имени.
    memcpy(bird_->name, name, 15);
}

