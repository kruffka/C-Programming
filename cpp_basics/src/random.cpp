#include <iostream>
#include <random>
using namespace std;

int main()
{
    // Define range
    int min = 1;
    int max = 20;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    int randomValue = distrib(gen);
    cout << "Random number between " << min << " and "
         << max << " is " << randomValue << endl;

    return 0;
}