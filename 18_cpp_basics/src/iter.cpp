#include <iostream>
#include <list>

int main() {
    std::list<int> l = {1, 2, 3, 4, 5, 6};

    // Используем auto, чтобы не писать std::list<int>::iterator
    auto iter = l.begin();
    std::cout << *iter << "\n";  // печатаем начальный элемент
    ++iter;  // сдвигаемся к следующему элементу
    std::cout << *iter << "\n";  // печатаем следующий за начальным элемент
    --iter;  // возвращаемся назад
    std::cout << *iter << "\n";  // печатаем снова начальный элемент

    std::cout << "\n";

    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        std::cout << *iter << " ";  // печатаем элементы списка через итератор
    }
    std::cout << "\n";

    for (auto iter = l.rbegin(); iter != l.rend(); ++iter) {
        std::cout << *iter << " ";  // проход по списку в обратном порядке
    }

    std::cout << "\n\n";

    // Удаляем из списка чётные числа
    for (auto iter = l.begin(); iter != l.end(); ) {
        if (*iter % 2 == 0) {
            iter = l.erase(iter);  // возвращается итератор на элемент, следующий за удалённым
        } else {
            ++iter;
        }
    }

    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        std::cout << *iter << " ";  // печатаем элементы списка через итератор
    }
    std::cout << "\n";

}