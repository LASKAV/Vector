
/*
 В контейнере типа vector хранится набор целых чисел. Создайте функторы для решения следующих задач:
1) Увеличение значений всех элементов контейнера на заданную константу;
2) Удаление из контейнера элементов, равных искомому значению.
 */
#include <iostream>
#include <vector>
#include <algorithm>

// 1) Увеличение значений всех элементов контейнера на заданную константу
class IncreaseByConstant {
public:
    IncreaseByConstant(int constant) : constant_(constant) {}

    void operator() (int& elem) {
        elem += constant_;
    }

private:
    int constant_;
};

// 2) Удаление из контейнера элементов, равных искомому значению
class RemoveByValue {
public:
    RemoveByValue(int value) : value_(value) {}

    bool operator() (int elem) {
        return elem == value_;
    }

private:
    int value_;
};

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    int constant = 10;
    int value = 3;

    // Применяем функтор IncreaseByConstant к каждому элементу контейнера
    std::for_each(v.begin(), v.end(), IncreaseByConstant(constant));

    // Удаляем из контейнера все элементы со значением value
    v.erase(std::remove_if(v.begin(), v.end(), RemoveByValue(value)), v.end());

    // Выводим на экран элементы контейнера после применения функторов
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

