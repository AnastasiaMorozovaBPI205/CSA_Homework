#include <cstdio>
#include "container.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

// Tests:
// ./ABC_OOP_HW2 -f input output
// ./ABC_OOP_HW2 -f input_1 output_1
// ./ABC_OOP_HW2 output_2 20
// ./ABC_OOP_HW2 output_3 9000
// ./ABC_OOP_HW2 output_4 10001
// ./ABC_OOP_HW2 output_4 0


int main(int argc, char* argv[]) {
    // На вход подается четыре аргумента - при чтении файла, три - при рандоме.
    // Иначе - выводится сообщение об ошибке.
    if (argc != 3 && argc != 4) {
        printf( "Incorrect command line.\n");
        return 0;
    }

    // Для формирования рандомных данных.
    srand(time(nullptr));

    bool isFile = false;
    if (argc == 4) {
        isFile = true;
    } else if (atoi(argv[2]) > 10000 || atoi(argv[2]) < 0) {
        printf("Quantity of elements must be < 10001 and > -1.\n");
        return 0;
    }

    printf("Start\n");

     Container container_;

    if (isFile) {
        FILE *input_file = fopen(argv[2], "r");

        container_.FillIn(input_file);

        fclose(input_file);
    } else {
        // Читаем размер контейнера.
        int size = atoi(argv[2]);

        container_.FillInRnd(size);
    }

    FILE *output_file;
    if (isFile) {
        output_file = fopen(argv[3], "w");
    }
    else {
        output_file = fopen(argv[1], "w");
    }

    fprintf(output_file, "%s", "Before sort function\n\n");
    container_.PrintOut(output_file);

    container_.ShakerSort();

    fprintf(output_file, "\n\n %s", "After sort function\n\n");
    container_.PrintOut(output_file);

    fclose(output_file);

    printf("End");

    return 0;
}
