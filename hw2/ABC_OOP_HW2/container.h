//
// Created by anastasia on 13.10.2021.
//

#ifndef ABC_OOP_HW2_CONTAINER_H
#define ABC_OOP_HW2_CONTAINER_H

#include <cstdio>
#include "Animal.h"

// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного файла.
    void FillIn(FILE* file);

    // Случайный ввод содержимого контейнера.
    void FillInRnd(int size);

    // Вывод содержимого контейнера в указанный файл.
    void PrintOut(FILE* file);

    // Шейкер сортировка элементов.
    void ShakerSort();
private:
    // Очистка контейнера от элементов (освобождение памяти).
    void Clear();
    int len;
    Animal* array[10000];
};

#endif //ABC_OOP_HW2_CONTAINER_H
