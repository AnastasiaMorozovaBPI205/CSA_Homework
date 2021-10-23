//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_FISH_H
#define ABC_OOP_HW2_FISH_H

#include "Animal.h"

class Fish: public Animal {
public:
    virtual ~Fish() {}

    // Ввод параметров рыбы из файла.
    virtual void FillIn(FILE* file);

    // Случайный ввод параметров рыбы.
    virtual void FillInRnd();

    // Вывод параметров рыбы в файл.
    virtual void PrintOut(FILE* file);

    // Вычисление частного для рыбы.
    virtual double Quotient();
private:
    enum home {
        lake,
        sea,
        river
    };

    enum home fish_home;
    char name[15];
    int weight;
};

#endif //ABC_OOP_HW2_FISH_H
