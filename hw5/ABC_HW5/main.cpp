#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// Для сборки программы нужен компилятор g++-11.
// Чтобы собрать программу, надо ввести - "g++-11 -std=c++20 main.cpp -o main -lpthread" в папке с main.cpp.

// Чтобы запустить - "./main количество_секунд_в_которые_будут_работать_программисты" в том же каталоге.

bool should_continue; // true - если рабочий день еще не окончен и надо продолжать

// Класс программы.
class Program {
public:
    int author; // автор творения
    int reviewer; // проверяющий
    bool is_correct; // правильность программы
};

// Класс программиста.
class Programmer{
public:
    Programmer* list[2]{}; // два других программиста в отделе
    int id; // идентификатор программиста

    // очередь программ, присланных программисту -
    // как его уже проверенные, так и чужие на проверку
    std::queue<Program> programs;

    // Метод для написания программы.
    void write_program(int reviewer_index) {
        std::cout << id << " writes program.\n";

        // создаем программу
        auto* program = new Program();
        program->author = id;

        // отдаем ее проверяющему
        std::cout << id << " sends program to " << list[reviewer_index]->id << " to check\n";
        list[reviewer_index]->programs.push(*program);
    }

    // Метод для проверки проргаммы на правильность.
    bool is_program_correct_rnd() {
        int is_another_program_correct = rand() % 2;

        if (is_another_program_correct == 1) {
            return true;
        }

        return false;
    }

    void check_program(Program* next_program) {
        std::cout << id << " is checking " << next_program->author << ".\n";

        // Проверяем программу
        next_program->reviewer = id;
        next_program->is_correct = is_program_correct_rnd();

        // и отправляем обратно.
        for (int j = 0; j < 2; ++j) {
            if (list[j]->id == next_program->author) {
                list[j]->programs.push(*next_program);
            }
        }
    }

    // Метод для работы программиста.
    void* run(void* ptr) {
        // пока рабочий день не закончен - программисты работают
        while(should_continue) {
            int reviewer_index = rand() % 2; // выбираем какому программисту отправим работу
            write_program(reviewer_index); // пишем и отправляем работу

            bool is_my_program_checked = false;
            // Пока работа данного программиста не проверена, он не может начать новую работу.
            while (!is_my_program_checked) {
                // Программист спит на рабочем месте, пока в очереди программ ничего нет -
                // те пока его работа не проверена, или пока ему не пришлют работу на проверку.
                while (programs.empty()) {
                    // Если рабочий день заканчивается - программист просыпается и спешит домой.
                    if (!should_continue) {
                        return nullptr;
                    }
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                Program *next_program;
                // Пока очередь не пустая, разбираемся с задачами в ней.
                while (!programs.empty()) {
                    next_program = &programs.front();
                    programs.pop();

                    if (next_program->author == id) {
                        // Если пришла проверенная программа данного программиста
                        if (next_program->is_correct) {
                            // и она правильная - то начинаем писать новую программу.
                            std::cout << id << " program was correct -> we have to write a new one.\n";
                            is_my_program_checked = true;
                            break;
                        } else {
                            // А если неправильная, то переделываем.
                            std::cout << id << " program was incorrect -> we have to rewrite it.\n";
                            for (int j = 0; j < 2; ++j) {
                                if (list[j]->id == next_program->reviewer) {
                                    write_program(j);
                                }
                            }
                        }
                    } else {
                        // Если это не программа данного программиста - ее нужно проверить.
                        check_program(next_program);
                    }
                }
            }
        }
        return nullptr;
    }

    // Конструктор.
    explicit Programmer(int id) {
        this->id = id;
    }

    // Метод для записывания в список программистов коллег.
    void set_list(Programmer* first, Programmer* second) {
        list[0] = first;
        list[1] = second;
    }

    ~Programmer() = default;

};

int main(int argc, char* argv[]) {
    if (argc != 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 60) {
        std::cout << "Incorrect command arguments.\n";
        return 0;
    }

    should_continue = true;
    std::cout << "Working day has started.\n";

    Programmer* first_programmer;
    Programmer* second_programmer;
    Programmer* third_programmer;

    first_programmer = new Programmer(1);
    second_programmer = new Programmer(2);
    third_programmer = new Programmer(3);

    first_programmer->set_list(second_programmer, third_programmer);
    second_programmer->set_list(first_programmer, third_programmer);
    third_programmer->set_list(second_programmer, first_programmer);

    std::thread programmer_thread_1(&Programmer::run, first_programmer, nullptr);
    std::thread programmer_thread_2(&Programmer::run, second_programmer, nullptr);
    std::thread programmer_thread_3(&Programmer::run, third_programmer, nullptr);

    // Основной поток спит, пока идет рабочий день.
    std::this_thread::sleep_for(std::chrono::seconds(atoi(argv[1])));

    // После этого оповещает программистов, что рабочий день кончился.
    should_continue = false;

    programmer_thread_1.join();
    programmer_thread_2.join();
    programmer_thread_3.join();

    delete first_programmer;
    delete second_programmer;
    delete third_programmer;

    std::cout << "\nWorking day is over. Programmers are going home.\n";

    return 0;
}
