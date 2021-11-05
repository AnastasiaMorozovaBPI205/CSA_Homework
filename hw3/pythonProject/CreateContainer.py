from Fish import *
from Bird import *
from Beast import *

from random import randrange


# Метод для рандомизации элементов контейнера.
def randomContainer(container, size):
    for i in range(0, size):
        key = randrange(1, 4)

        if key == 1:
            animal = Fish()
        elif key == 2:
            animal = Bird()
        else:
            animal = Beast()

        animal.randomAnimal()
        container.store.append(animal)


# Метод для чтения элементов контейнера из файла,
# возвращающий позицию при чтении.
def readStrArray(container, strArray):
    container_len = len(strArray)

    i = 0
    position = 0

    while i < container_len:
        element = strArray[i]
        key = int(element)

        i += 1

        if key == 1:
            animal = Fish()
        elif key == 2:
            animal = Bird()
        else:
            animal = Beast()

        i = animal.readStrArray(strArray, i)

        if i == 0:
            return position

        position += 1

        container.store.append(animal)

    return position
