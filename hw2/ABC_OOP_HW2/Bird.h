//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_BIRD_H
#define ABC_OOP_HW2_BIRD_H

#include "Animal.h"

class Bird: public Animal {
public:
    virtual ~Bird() {}

    // Ввод параметров птицы из файла.
    virtual void FillIn(FILE* file);

    // Случайный ввод параметров птицы.
    virtual void FillInRnd();

    // Вывод параметров птицы в файл.
    virtual void PrintOut(FILE* file);

    // Вычисление частного для птицы.
    virtual double Quotient();
private:
    bool is_migratory;
    char name[15];
    int weight;
};


#endif //ABC_OOP_HW2_BIRD_H
