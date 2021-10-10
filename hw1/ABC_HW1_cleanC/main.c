#include <stdio.h>
#include <stdbool.h>
#include "container.h"
#include "stdlib.h"
#include <time.h>
#include "string.h"

int main(int argc, char* argv[]) {
    // На вход подается четыре аргумента - при чтении файла, три - при рандоме.
    // Иначе - выводится сообщение об ошибке.
    if (argc != 3 && argc != 4) {
        printf( "Incorrect command line.\n");
        return 0;
    }

    // Для формирования рандомных данных.
    srand(time(NULL));

    bool isFile = false;
    if (argc == 4) {
       isFile = true;
    } else if (atoi(argv[2]) > 10000 || atoi(argv[2]) < 0) {
        printf("Quantity of structures must be < 10001 and > -1.\n");
        return 0;
    }

    printf("Start\n");

    struct container container;
    Initialize(&container);

    if (isFile) {
        FILE *input_file = fopen(argv[2], "r");

        FillIn(&container, input_file);

        fclose(input_file);
    } else {
        // Читаем размер контейнера.
        int size = atoi(argv[2]);

        FillInRnd(&container, size);
    }

    FILE *output_file;
    if (isFile) {
        output_file = fopen(argv[3], "w");
    }
    else {
        output_file = fopen(argv[1], "w");
    }

    fprintf(output_file, "%s", "Before sort function\n\n");
    PrintOut(&container, output_file);

    ShakerSort(&container);

    fprintf(output_file, "\n\n %s", "After sort function\n\n");
    PrintOut(&container, output_file);

    fclose(output_file);

    Clear(&container);
    printf("End");

    return 0;
}
