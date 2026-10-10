#include <iostream>
#include <iomanip>
using namespace std;


const int SIZE = 3;

class Chair {
private:
    int legs;
    double prices[SIZE];

    
public:
    Chair() {
        legs = (rand() % 2 == 0) ? 3 : 4;
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = ((rand() % (MAX - MIN + 1)) + MIN) / (double) 100;
        }
    }


}