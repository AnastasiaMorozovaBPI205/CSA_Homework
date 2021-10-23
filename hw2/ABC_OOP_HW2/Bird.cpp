//
// Created by anastasia on 13.10.2021.
//

#include "Bird.h"

#include <cstring>

// Ввод параметров птицы из файла.
void Bird::FillIn(FILE *file) {
    char name_[15];

    for (int i = 0; i < 15; ++i) {
        name_[i] = 0;
    }

    // Читаем имя, вес, перелетная птица или нет.
    fscanf(file, "%s %i %i", name_, &weight, &is_migratory);

    for (int i = 0; i < sizeof(name_); ++i) {
        name[i] = name_[i];
    }
}

// Случайный ввод параметров птицы.
void Bird::FillInRnd() {
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

    Random rnd2(0, 1);
    // Рандомизируем - перелетная птица или нет.
    int random_variable = rnd2.GetRandomNumber();

    if (random_variable == 0) {
        is_migratory = true;
    } else if (random_variable == 1) {
        is_migratory = false;
    }
}

// Вывод параметров птицы в файл.
void Bird::PrintOut(FILE *file) {
    if (is_migratory) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BIRD; name: ", name,
                "; weight: ", weight,
                "; this bird is migratory; func res: ", Quotient());
    } else {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "BIRD; name: ", name,
                "; weight: ", weight,
                "; this bird is not migratory; func res: ", Quotient());
    }
}

// Вычисление частного для птицы.
double Bird::Quotient() {
    double sum = 0.0;
    for (int i = 0; i < sizeof(name); ++i) {
        sum += (int)(name[i]);
    }

    return  sum / weight;
}