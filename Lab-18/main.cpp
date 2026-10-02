#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Node { //Node Struct
    double score;
    string text;
    Node* next;
};

class Movie { //Movie Class
private:
    string name;
    Node* head;

    public:
    
    Movie() {// Constructor
        name = "";
        head = nullptr;
    }

    void setName(string n) {//Name setter
        name = n;
    }


    ~Movie() {//Destructor
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }









};