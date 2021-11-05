import random
import string
from random import randrange

from Animal import *


class Bird(Animal):
    # Конструктор.
    def __init__(self):
        self.weight = 0
        self.name = ""
        self.is_migratory = False

    # Метод чтения из файла.
    def readStrArray(self, strArray, i):
        # i - позиция при чтении.
        if i >= len(strArray) - 1:
            return 0

        self.name = strArray[i]
        self.weight = int(strArray[i + 1])
        self.is_migratory = bool(strArray[i + 2])
        i += 3

        return i

    # Метод рандомизации элемента.
    def randomAnimal(self):
        self.weight = randrange(1, 100)

        size = randrange(5, 15)
        self.name = ''.join(random.choice(string.ascii_lowercase) for _ in range(size))

        self.is_migratory = bool(random.getrandbits(1))
        pass

    # Метод для записи информации о животном в файл.
    def write(self, outputStream):
        outputStream.write("It's a Bird: name = {},  weight = {}, is migratory = {}, func res = {}".format(
            self.name, self.weight, self.is_migratory, self.quotient()))
        pass

    # Метод для вычисления частного от деления суммы кодов имени животного на его вес.
    def quotient(self):
        summa = 0.0

        for i in range(0, len(self.name)):
            summa += ord(self.name[i])

        return summa / self.weight
