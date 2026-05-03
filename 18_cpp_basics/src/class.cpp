#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Конструктор - метод, вызывающийся при создании объекта
    Person(std::string n, int a) : name(n), age(a) {}

    // Методы
    void introduce() {
        std::cout << "Меня зовут " << name << ", мне " << age << " лет." << std::endl;
    }

    // Сеттер и геттер - дают доступ к приватным полям
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
};

int main() {
    Person person("Иван", 25);
    person.introduce();
    person.setName("Петр");
    person.introduce();
    return 0;
}