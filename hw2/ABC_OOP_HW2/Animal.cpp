//
// Created by anastasia on 13.10.2021.
//

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Beast.h"

Random Animal::rnd3(1,3);

// Ввод параметров обобщенного животного из файла.
Animal* Animal::StaticFillIn(FILE* file, int key) {
    Animal* animal_ = nullptr;

    switch(key) {
        case 1:
            animal_ = new Fish;
            break;
        case 2:
            animal_ = new Bird;
            break;
        case 3:
            animal_ = new Beast;
            break;
    }

    animal_->FillIn(file);
    return  animal_;
}

// Случайный ввод обобщенного животного.
Animal *Animal::StaticFillInRnd() {
    int key = Animal::rnd3.GetRandomNumber();
    Animal* animal_ = nullptr;

    switch(key) {
        case 1:
            animal_ = new Fish;
            break;
        case 2:
            animal_ = new Bird;
            break;
        case 3:
            animal_ = new Beast;
            break;
    }

    animal_->FillInRnd();
    return  animal_;
}