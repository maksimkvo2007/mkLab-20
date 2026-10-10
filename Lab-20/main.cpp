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

    Chair(int l, double p[]) {
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    void setLegs(int l){
        legs = l; 
    }
    int getLegs() const { 
        return legs;
    }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrice() const {
        double sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += prices[i];
        }
        return sum / SIZE;
    }

    void print() const {
        cout << "CHAIR DATA:" << endl;
        cout << "Legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++) {
            cout << "$" << fixed << setprecision(2) << prices[i] << " ";
        }
        cout << endl;
        cout << "Average: $" << getAveragePrice() << endl << endl;
    }

}

int main(){




}