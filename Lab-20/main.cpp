#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
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
        cout << legs << " legs, prices: ";
        for (int i = 0; i < SIZE; i++) {
            cout << "$" << fixed << setprecision(2) << prices[i] << " ";
        }
        cout << "| avg: $" << getAveragePrice() << endl;
    }

};

int main(){

    Chair c1; //Default constructor
    c1.print();

    double prices[SIZE] = {450.50, 425.00, 480.99};//Parameter constructor
    Chair c2(4, prices);
    c2.print();

    Chair collection[3]; //Array using default constructor
    for (int i = 0; i < 3; i++) {
        collection[i].print();
    }


}