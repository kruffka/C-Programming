#include <iostream>
#include <map>
#include <string>

int main() {
    // инициализируем map набором пар {ключ, значение}
    std::map<std::string, int> years = {
        {"Surgut", 431},
        {"Moscow", 878},
        {"Novosibirsk", 132},
    };

    for (const auto& [city, year] : years) {
        std::cout << city << ": " << year << "\n";
    }
}