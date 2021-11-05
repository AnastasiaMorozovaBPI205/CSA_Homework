import random
import string
from random import randrange

from Animal import *

from enum import Enum


# Класс перечисления для дома рыб.
class FishHome(Enum):
    LAKE = 1
    SEA = 2
    RIVER = 3


# Класс рыбы, наследник класса животного.
class Fish(Animal):
    # Конструктор.
    def __init__(self):
        self.weight = 0
        self.name = ""
        self.home = FishHome.LAKE

    # Метод чтения из файла.
    def readStrArray(self, strArray, i):
        # i - позиция при чтении.
        if i >= len(strArray) - 1:
            return 0

        self.name = strArray[i]
        self.weight = int(strArray[i + 1])

        if strArray[i + 2] == 0:
            self.home = FishHome.LAKE
        elif strArray[i + 2] == 1:
            self.home = FishHome.SEA
        else:
            self.home = FishHome.RIVER
        i += 3

        return i

    # Метод рандомизации элемента.
    def randomAnimal(self):
        self.weight = randrange(1, 100)

        size = randrange(5, 15)
        self.name = ''.join(random.choice(string.ascii_lowercase) for _ in range(size))

        fish_home_number = randrange(1, 3)
        self.home = FishHome(fish_home_number)
        pass

    # Метод для записи информации о животном в файл.
    def write(self, outputStream):
        outputStream.write("It's a Fish: name = {},  weight = {}, home = {}, func res = {}".format(
            self.name, self.weight, self.home, self.quotient()))
        pass

    # Метод для вычисления частного от деления суммы кодов имени животного на его вес.
    def quotient(self):
        summa = 0.0

        for i in range(0, len(self.name)):
            summa += ord(self.name[i])

        return summa / self.weight
