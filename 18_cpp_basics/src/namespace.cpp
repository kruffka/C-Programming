#include <iostream>

using namespace std;


// Outer namespace
namespace outer {
    void func(){
        cout << "Inside outer namespace\n";
    }
    
    // Inner namespace
    namespace inner {
        void func() {
            cout << "Inside inner namespace\n";
        }
    }
}

namespace nmsp {
    void func(){
        cout << "You can extend me\n" << endl;
    }
}

// Extending the same namespace
namespace nmsp {
    void func2(){
        cout << "Adding new feature\n";
    }

    int hello = 5;
}

using namespace outer::inner;

inline namespace inline_space {
    void display() {
        cout << "Inside inline namespace\n";
    }
}

// Anonymous namespace
namespace {
    int value = 10;
}

int main() {

    outer::inner::func();  
    outer::func();  

    func(); // outer::inner из-за using namespace outer::inner;

    nmsp::func2();
    cout << nmsp::hello << "\n";

    // Direct access due to inline namespace
    display();

    // Accessing anonymous namespace variable
    cout << value; 
    return 0;
}