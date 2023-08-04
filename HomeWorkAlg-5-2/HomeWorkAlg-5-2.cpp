#include <iostream>

class Heap {
private:
    int* data;
public:
    Heap(int* data) {
        this->data = data;
    }

    int from_index(int index) {
        return data[index];
    }

    int left_index(int parent_index) {
        return 2 * parent_index + 1;
    }

    int right_index(int parent_index) {
        return 2 * parent_index + 2;
    }

    int parent_index(int child_index) {
        return (child_index - 1) / 2;
    }

    void print_node(int index, int level) {
        std::cout << "Вы находитесь здесь: ";
        std::cout << level << " ";
        if (level == 0) {
            std::cout << "root " << this->from_index(index);
        }
        else {
            if (index % 2 == 0) {
                std::cout << "right(";
            }
            else {
                std::cout << "left(";
            }
            std::cout << this->from_index(this->parent_index(index)) << ") " << this->from_index(index);
        }
    }
};

void print_mass(int* arr, int size) {
    std::cout << "Исходный массив: ";
    for (int i{}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_pyramid(int* arr, int size) {
    std::cout << "0 root " << arr[0] << std::endl;
    int level{ 1 }, counter{};
    for (int i{ 1 }; i < size; ++i) {
        if (counter == std::pow(2, level)) {
            level++;
            counter = 0;
        }
        counter++;
        std::cout << level << " ";
        if (i % 2 == 0) {
            std::cout << "right(";
        }
        else {
            std::cout << "left(";
        }
        std::cout << arr[(i - 1) / 2] << ") ";
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size{ 10 };
    print_mass(arr, size);
    print_pyramid(arr, size);
    std::cout << std::endl;
    std::string com{};
    Heap heap(arr);
    int actual_index{}, level{};
    while (true) {
        heap.print_node(actual_index, level);
        std::cout << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> com;
        if (com == "exit") {
            break;
        }
        else if (com == "up") {
            if (level == 0) {
                std::cout << "Ошибка! Отсутствует родитель." << std::endl;
            }
            else {
                std::wcout << "OK" << std::endl;
                level--;
                actual_index = heap.parent_index(actual_index);
            }
        }
        else if (com == "left") {
            if (heap.left_index(actual_index) >= size) {
                std::cout << "Ошибка! Левый ребёнок отсутствует." << std::endl;
            }
            else {
                std::wcout << "OK" << std::endl;
                level++;
                actual_index = heap.left_index(actual_index);
            }
        }
        else if (com == "right") {
            if (heap.right_index(actual_index) >= size) {
                std::cout << "Ошибка! Правый ребёнок отсутствует." << std::endl;
            }
            else {
                std::wcout << "OK" << std::endl;
                level++;
                actual_index = heap.right_index(actual_index);
            }
        }
        else {
            std::cout << "Ошибка! Данная команда отсутствует." << std::endl;
        }
    }
    return 0;
}