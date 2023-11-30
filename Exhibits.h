#ifndef EXHIBITS_H
#define EXIBITS_H
#include <iostream>
#include <vector>
#include "Objects.h"
using namespace std;

class Exibits
{ 
public:
    Exibits();
    string getExibitName();
    bool addObject(vector<Objects> stored);
    bool isEmpty();
    bool removeObject(vector<Objects> stored);
    int getID();





private:
    std::string exibitName;
    int idNum;
    vector<Objects> exibits;



};

#endif