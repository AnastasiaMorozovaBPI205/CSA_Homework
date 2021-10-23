//
// Created by anastasia on 13.10.2021.
//

#include "Fish.h"
#include <cstring>

// Ввод параметров рыбы из файла.
void Fish::FillIn(FILE *file) {
    int fish_home_;
    char name_[15];

    for (int i = 0; i < 15; ++i) {
        name_[i] = 0;
    }

    // Читаем имя, вес, дом рыбы из файла.
    fscanf(file, "%s %i %i", name_, &weight, &fish_home_);

    for (int i = 0; i < sizeof(name_); ++i) {
        name[i] = name_[i];
    }

    if (fish_home_ == 0) {
        fish_home = lake;
    } else if (fish_home_ == 1) {
        fish_home = sea;
    } else if (fish_home_ == 2) {
        fish_home = river;
    }
}

// Случайный ввод параметров рыбы.
void Fish::FillInRnd() {
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
    // Рандомизируем дом рыбы.
    int random_variable = rnd03.GetRandomNumber();

    if (random_variable == 0) {
        fish_home = lake;
    } else if (random_variable == 1) {
        fish_home = sea;
    } else {
        fish_home = river;
    }
}

// Вывод параметров рыбы в файл.
void Fish::PrintOut(FILE *file) {
    if (fish_home == lake) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH; name: ", name,
                "; weight: ", weight,
                "; home: lake; func res: ", Quotient());
    } else if (fish_home == sea) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH; name: ", name,
                "; weight: ", weight,
                "; home: sea;  func res: ", Quotient());
    } else if (fish_home == river) {
        fprintf(file,
                "%s %s %s %i %s %f\n",
                "FISH; name: ", name,
                "; weight: ", weight,
                "; home: river; func res: ", Quotient());
    }
}

// Вычисление частного для рыбы.
double Fish::Quotient() {
    double sum = 0.0;
    for (int i = 0; i < sizeof(name); ++i) {
        sum += (int)(name[i]);
    }

    return  sum / weight;
}