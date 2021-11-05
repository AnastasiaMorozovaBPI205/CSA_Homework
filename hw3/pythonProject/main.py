import sys

from Container import *
from CreateContainer import readStrArray, randomContainer

# Tests
# python3 main.py -f input output
# python3 main.py -f input_1 output_1
# python3 main.py output_2 20
# python3 main.py output_3 10000
# python3 main.py output_4 0
# python3 main.py output_5 10001

if __name__ == '__main__':
    print('Start')

    container = Container()

    # На вход может подаваться либо 3 (при рандомизации данных),
    # либо 4 аргумента (при чтении из файла).
    if len(sys.argv) == 3:
        outputFile = sys.argv[1]

        if int(sys.argv[2]) > 10000 or int(sys.argv[2]) < 0:
            print("The size of the container must be <= 10000 and >= 0.")
            exit()

        randomContainer(container, int(sys.argv[2]))
    elif len(sys.argv) == 4:
        inputFile = sys.argv[2]
        outputFile = sys.argv[3]

        inputStream = open(inputFile)
        data = inputStream.read()
        inputStream.close()

        strArray = data.replace("\n", " ").split(" ")
        position = readStrArray(container, strArray)
    else:
        print("Incorrect command line.")
        exit()

    outputStream = open(outputFile, 'w')
    outputStream.write("Before sorting:\n")
    container.write(outputStream)

    container.shakerSort()

    outputStream.write("\n\nAfter sorting:\n")
    container.write(outputStream)
    outputStream.close()

    print('End')
