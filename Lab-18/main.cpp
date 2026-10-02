#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include <cstdlib>
#include <ctime>

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

void addReview(double s, string t) {
    Node* newNode = new Node;
    newNode->score = s;
    newNode->text = t;
    newNode->next = head; // Add to head
    head = newNode;
}

void print() {
    cout << "Movie Title: " << name << endl;
        
    Node* curr = head;
    int num = 1;
    double sum = 0;
    int count = 0;

        
    while (curr != nullptr) {
        cout << "  > Review #" << num << ": " 
        << fixed << setprecision(1) << curr->score 
        << ": " << curr->text << endl;
            
        sum += curr->score;
        count++;
        num++;
        curr = curr->next;
    }

        
    if (count > 0) { //Output
        double avg = sum / count;
        cout << "  > Average: " << fixed << setprecision(1) << avg << endl << endl;
    }
};
};
int main (){
    string lines[12];

    ifstream inFile("Lab-18/input.txt");
    for (int i = 0; i < 12; i++) {
        getline(inFile, lines[i]);
    }
    inFile.close();

    Movie movies[4];
    movies[0].setName("Lord of the Rings");
    movies[1].setName("The Godfather");
    movies[2].setName("Star Wars");
    movies[3].setName("Jurassic Park");

    int lineIdx = 0;
    for (int i = 0; i < 4; i++) { //movies
        for (int j = 0; j < 3; j++) { //reviews 
            //Random rating
            double val = 1.0 + (rand() % 41) / 10.0; 
            movies[i].addReview(val, lines[lineIdx]);
            lineIdx++;
        }
    }

    for (int i = 0; i < 4; i++) {
        movies[i].print();
    }
}