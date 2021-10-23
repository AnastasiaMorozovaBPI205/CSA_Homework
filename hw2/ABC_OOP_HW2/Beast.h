//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_BEAST_H
#define ABC_OOP_HW2_BEAST_H

#include "Animal.h"

class Beast: public Animal {
public:
    virtual ~Beast() {}

    // Ввод параметров зверя из файла.
    virtual void FillIn(FILE* file);

    // Случайный ввод параметров зверя.
    virtual void FillInRnd();

    // Вывод параметров зверя в файл.
    virtual void PrintOut(FILE* file);

    // Вычисление частного для зверя.
    virtual double Quotient();
private:
    enum food_type {
        carnivores,
        herbivores,
        insectivores
    };

    enum food_type animal_food_type;
    char name[15];
    int weight;
};

#endif //ABC_OOP_HW2_BEAST_H
