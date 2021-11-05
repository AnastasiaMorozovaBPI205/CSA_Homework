import random
import string
from random import randrange

from Animal import *

from enum import Enum


class FoodType(Enum):
    CARNIVORES = 1
    HERBIVORES = 2
    INSECTIVORES = 3


class Beast(Animal):
    # Конструктор.
    def __init__(self):
        self.weight = 0
        self.name = ""
        self.food_type = FoodType.CARNIVORES

    # Метод чтения из файла.
    def readStrArray(self, strArray, i):
        # i - позиция при чтении.
        if i >= len(strArray) - 1:
            return 0

        self.name = strArray[i]
        self.weight = int(strArray[i + 1])

        if strArray[i + 2] == 0:
            self.food_type = FoodType.CARNIVORES
        elif strArray[i + 2] == 1:
            self.food_type = FoodType.HERBIVORES
        else:
            self.food_type = FoodType.INSECTIVORES

        i += 3

        return i

    # Метод рандомизации элемента.
    def randomAnimal(self):
        self.weight = randrange(1, 100)

        size = randrange(5, 15)
        self.name = ''.join(random.choice(string.ascii_lowercase) for _ in range(size))

        food_type_number = randrange(1, 3)
        self.food_type = FoodType(food_type_number)
        pass

    # Метод для записи информации о животном в файл.
    def write(self, outputStream):
        outputStream.write("It's a Beast: name = {},  weight = {}, food type = {}, func res = {}".format(
            self.name, self.weight, self.food_type, self.quotient()))
        pass

    # Метод для вычисления частного от деления суммы кодов имени животного на его вес.
    def quotient(self):
        summa = 0.0

        for i in range(0, len(self.name)):
            summa += ord(self.name[i])

        return summa / self.weight
