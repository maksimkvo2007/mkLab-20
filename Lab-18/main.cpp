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






};

int main (){
    string lines[12];
}