//
// Created by anastasia on 05.10.2021.
//

#ifndef ABC_HW1_CLEANC_CONTAINER_H
#define ABC_HW1_CLEANC_CONTAINER_H

#include <bits/types/FILE.h>
#include "animal.h"

struct container {
    enum {max_len = 10000};
    int len;
    struct animal array[max_len];
};

// Инициализация контейнера.
void Initialize(struct container* c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container* c);

// Ввод содержимого контейнера из указанного файла.
void FillIn(struct container* c, FILE* file);

// Случайный ввод содержимого контейнера.
void FillInRnd(struct container* c, int size);

// Вывод содержимого контейнера в указанный файл.
void PrintOut(struct container* c, FILE* file);

// Шейкер сортировка элементов.
void ShakerSort(struct container* c);

#endif //ABC_HW1_CLEANC_CONTAINER_H
