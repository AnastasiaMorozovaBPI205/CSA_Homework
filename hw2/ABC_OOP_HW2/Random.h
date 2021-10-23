//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_RANDOM_H
#define ABC_OOP_HW2_RANDOM_H

#include <cstdlib>
#include <ctime>

// Класс рандома.
class Random {
public:
    Random(int first_number, int last_number) {
        first_number_in_range = first_number;
        last_number_in_range = last_number;
    }

    // Генерация случайного числа в заданном диапазоне.
    int GetRandomNumber() {
        return rand() % (last_number_in_range - first_number_in_range + 1) + first_number_in_range;
    }
private:
    int first_number_in_range;
    int last_number_in_range;
};

#endif //ABC_OOP_HW2_RANDOM_H
