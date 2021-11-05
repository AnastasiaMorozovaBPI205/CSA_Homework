

# Класс контейнера.
class Container:
    # Конструктор.
    def __init__(self):
        self.store = []

    # Метод для записи информации об элементах контейнера в файл.
    def write(self, writeStream):
        writeStream.write("Container has {} elements:\n".format(len(self.store)))

        for element in self.store:
            element.write(writeStream)
            writeStream.write("\n")

        pass

    # Метод сортировки шейкером.
    def shakerSort(self):
        for i in range(len(self.store) - 1, 0, -1):
            swapped = False

            for j in range(i, 0, -1):
                if self.store[j].quotient() > self.store[j - 1].quotient():
                    self.store[j], self.store[j - 1] = self.store[j - 1], self.store[j]
                    swapped = True

            for j in range(i):
                if self.store[j].quotient() < self.store[j + 1].quotient():
                    self.store[j], self.store[j + 1] = self.store[j + 1], self.store[j]
                    swapped = True

            if not swapped:
                return self.store
