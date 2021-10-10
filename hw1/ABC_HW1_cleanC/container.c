//
// Created by anastasia on 05.10.2021.
//

#include "container.h"
#include "animal.h"
#include <stdio.h>

// Метод для инициализации контейнера.
void Initialize(struct container *c) {
    c->len = 0;
}

// Метод для очистки контейнера.
void Clear(struct container *c) {
    c->len = 0;
}

// Ввод с рандомайзером.
void FillInRnd(struct container* c, int size) {
    while(c->len < size) {
        if(FillInRndAnimal(&(c->array[c->len]))) {
            c->len++;
        }
    }
}

// Шейкер-сортировка. (Усовершенствование сортировки пузырьком.)
// Поочередно проходим по массиву справа и слева, меняя местами элементы.
void ShakerSort(struct container* c) {
    int length = c->len;

    struct animal tmp;

    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (QuotientAnimal(&(c->array[j])) > QuotientAnimal(&(c->array[j - 1]))) {
                tmp = c->array[j];
                c->array[j] = c->array[j - 1];
                c->array[j-1] = tmp;
            }
        }

        length--;

        for(int j = length - 1; j > i; --j) {
            if(QuotientAnimal(&(c->array[j])) > QuotientAnimal(&(c->array[j - 1]))){
                tmp = c->array[j];
                c->array[j] = c->array[j - 1];
                c->array[j-1] = tmp;
            }
        }
    }
}

// Ввод элементов контейнера из файла.
void FillIn(struct container* c, FILE* file) {
    // Ключ здесь - это ключ к перечислению с животными.
    int key = 0;
    while (fscanf(file, "%i", &key) != EOF) {
        if (FillInAnimal(file, &c->array[c->len], key)) {
            c->len++;
        }

        // Проверка на кол-во вводимых структур.
        if (c->len == 10000) {
            printf("Quantity of structures must be < 10001.");
            return;
        }
    }
}

// Вывод контейнера в файл.
void PrintOut(struct container* c, FILE* file) {
    fprintf(file, "%s %i %s \n", "Container contains ", c->len, " elements.");

    for (int i = 0; i < c->len; i++) {
        fprintf(file, "%i %s", i, " structure: ");
        PrintOutAnimal(&(c->array[i]), file);
    }
}

