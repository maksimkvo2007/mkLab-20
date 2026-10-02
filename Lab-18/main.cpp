#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    double score;
    string text;
    Node* next;
};