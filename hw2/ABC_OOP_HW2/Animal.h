//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_ANIMAL_H
#define ABC_OOP_HW2_ANIMAL_H

#include <cstdio>
#include "Random.h"

class Animal {
protected:
    static Random rnd3;
public:
    virtual ~Animal() {};

    // Ввод обобщенного животного.
    static Animal *StaticFillIn(FILE* file, int key);

    // Виртуальный метод для ввода обобщенного животного.
    virtual void FillIn(FILE* file) = 0;

    // Случайный ввод обобщенного животного.
    static Animal *StaticFillInRnd();

    // Виртуальный метод для ввода обобщенного животного.
    virtual void FillInRnd() = 0;

    // Вывод обобщенного животного.
    virtual void PrintOut(FILE* file) = 0;

    // Вычисление функции частного для животного.
    virtual double Quotient() = 0;
};

#endif //ABC_OOP_HW2_ANIMAL_H
