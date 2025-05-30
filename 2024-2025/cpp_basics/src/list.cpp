#include <iostream>
#include <list>

int main() {
    std::list<int> l = {1, 2, 3};
    l.push_front(0);
    l.push_front(-1);

    l.push_back(4);
    l.push_back(5);

    l.pop_front();
    l.pop_back();

    for (int x : l) {
        std::cout << x << "\n";  // 0 1 2 3 4
    }
}