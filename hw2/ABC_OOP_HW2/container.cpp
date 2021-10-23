//
// Created by anastasia on 13.10.2021.
//

#include "container.h"
#include "Animal.h"

// Конструктор контейнера.
Container::Container(): len{0} { }

// Деструктор контейнера.
Container::~Container() {
    Clear();
}

// Очистка контейнера от элементов (освобождение памяти).
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete array[i];
    }

    len = 0;
}

// Ввод содержимого контейнера.
void Container::FillIn(FILE* file) {
    // Ключ здесь - это ключ к перечислению с животными.
    int key = 0;
    while (fscanf(file, "%i", &key) != EOF) {
        if ((array[len] = Animal::StaticFillIn(file, key)) != nullptr) {
            len++;
        }

        // Проверка на кол-во вводимых структур.
        if (len == 10000) {
            printf("Quantity of structures must be < 10001.");
            return;
        }
    }
}

// Случайный ввод содержимого контейнера.
void Container::FillInRnd(int size) {
    while(len < size) {
        if((array[len] = Animal::StaticFillInRnd()) != nullptr) {
            len++;
        }
    }
}

// Вывод содержимого контейнера.
void Container::PrintOut(FILE* file) {
    fprintf(file, "%s %i %s \n", "Container contains ", len, " elements.");

    for (int i = 0; i < len; i++) {
        fprintf(file, "%i %s", i, " class: ");
        array[i]->PrintOut(file);
    }
}

// Сортировка всех животных в контейнере.
void Container::ShakerSort() {
    int length = len;

    Animal* tmp;

    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (array[j]->Quotient() > array[j - 1]->Quotient()) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j-1] = tmp;
            }
        }

        length--;

        for(int j = length - 1; j > i; --j) {
            if (array[j]->Quotient() > array[j - 1]->Quotient()) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j-1] = tmp;
            }
        }
    }
}