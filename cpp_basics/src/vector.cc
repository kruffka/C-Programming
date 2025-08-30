#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 0};
    for (int i = 0; i < 16; i++) {
        std::cout << "[" << i << "] " << vec.size() << "\t" << vec.capacity() << "\n";
        vec.push_back(i);
    }

}
