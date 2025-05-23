#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v = {4, 15, 42, 20};
    int target = 15;
    
    // Сортировка диапазона вектора от начала до конца
    std::sort(v.begin(), v.end());

    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    int x;
    std::vector<int> data;
    while (std::cin >> x) {  // читаем числа, пока не закончится ввод
        data.push_back(x);  // добавляем очередное число в вектор
        std::cout << data.back();
    }
    
    while (!data.empty() && data.back() == 0) {
        // Пока вектор не пуст и последний элемент равен нулю
        data.pop_back();  // удаляем этот нулевой элемент
    }
    

    return 0;
}