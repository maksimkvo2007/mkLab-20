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

    Movie(const Movie& other) {
        name = other.name;
        head = nullptr;
        
        if (other.head == nullptr) {
            return;
        }

        head = new Node;
        head->score = other.head->score;
        head->text = other.head->text;
        head->next = nullptr;

        Node* curr = head;
        Node* otherCurr = other.head->next;

        while (otherCurr != nullptr) {
            curr->next = new Node;
            curr->next->score = otherCurr->score;
            curr->next->text = otherCurr->text;
            curr->next->next = nullptr;
            
            curr = curr->next;
            otherCurr = otherCurr->next;
        }
    }

    Movie& operator=(const Movie& other) {
        if (this == &other) {
            return *this;
        }

        // Delete old
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        head = new Node;
        head->score = other.head->score;
        head->text = other.head->text;
        head->next = nullptr;

        Node* myCurr = head;
        Node* otherCurr = other.head->next;

        while (otherCurr != nullptr) {
            myCurr->next = new Node;
            myCurr->next->score = otherCurr->score;
            myCurr->next->text = otherCurr->text;
            myCurr->next->next = nullptr;
            
            myCurr = myCurr->next;
            otherCurr = otherCurr->next;
        }

        return *this;


    }
};


int main (){
    string lines[12];

    ifstream inFile("Lab-18/input.txt");
    for (int i = 0; i < 12; i++) {
        getline(inFile, lines[i]);
    }
    inFile.close();
}