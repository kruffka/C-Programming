#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v = {4, 15, 42, 20};
    int target = 15;
    
    auto it = std::find(v.begin(), v.end(), target);
    if (it != v.end()) {
        std::cout << "Element pos: " << it - v.begin() << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}