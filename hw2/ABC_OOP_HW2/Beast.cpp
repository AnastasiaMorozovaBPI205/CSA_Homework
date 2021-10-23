//
// Created by anastasia on 13.10.2021.
//

#include "Beast.h"
#include <cstring>

// Ввод параметров зверя из файла.
void Beast::FillIn(FILE *file) {
    int food_type_;
    char name_[15];

    for (int i = 0; i < 15; ++i) {
        name_[i] = 0;
    }

    // Читаем имя, вес и рацион зверя.
    fscanf(file, "%s %i %i", name_, &weight, &food_type_);

    for (int i = 0; i < sizeof(name_); ++i) {
        name[i] = name_[i];
    }

    if (food_type_ == 0) {
        animal_food_type = carnivores;
    } else if (food_type_ == 1) {
        animal_food_type = herbivores;
    } else if (food_type_ == 2) {
        animal_food_type = insectivores;
    }
}

// Случайный ввод параметров зверя.
void Beast::FillInRnd() {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r',
                         's', 't', 'u', 'x', 'y', 'w', 'q', 'h', 'v', 'z'};

    Random rnd15(5, 15);
    // Рандомизируем длину имени.
    int name_len = rnd15.GetRandomNumber();

    Random rnd26(0, 25);
    // Рандомизируем имя.
    for (int i = 0; i < name_len; i++) {
        name[i] = alphabet[rnd26.GetRandomNumber()];
    }

    Random rnd100(1, 100);
    // Рандомизируем вес.
    weight = rnd100.GetRandomNumber();

    Random rnd03(0, 3);
    // Рандомизируем рацион зверя.
    int random_variable = rnd03.GetRandomNumber();

    if (random_variable == 0) {
        animal_food_type = carnivores;
    } else if (random_variable == 1) {
        animal_food_type = herbivores;
    } else {
        animal_food_type = insectivores;
    }
}

// Вывод параметров зверя в файл.
void Beast::PrintOut(FILE *file) {
    if (animal_food_type == carnivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST; name: ", name,
                "; weight: ", weight,
                "; this beast is carnivores; func res: ", Quotient());
    } else if (animal_food_type == herbivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST; name: ", name,
                "; weight: ", weight,
                "; this beast is herbivores; func res: ", Quotient());
    } else if (animal_food_type == insectivores) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BEAST; name: ", name,
                "; weight: ", weight,
                "; this beast is insectivores; func res: ", Quotient());
    }
}

// Вычисление частного для зверя.
double Beast::Quotient() {
    double sum = 0.0;
    for (int i = 0; i < sizeof(name); ++i) {
        sum += (int)(name[i]);
    }

    return  sum / weight;
}