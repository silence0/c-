#ifndef NODE_H
#define NODE_H

#include<string>
#include"Edge.h"
using namespace std;

class Node
{

	int Id;
	string Name;
	int Value;
	bool isVisited;
public:
	Node(string name,int value = 0):Name(name),Id(-1),Value(value),isVisited(false){}
    int getId(){ return Id;}
    void setId(int id){ Id = id;}
    string getName(){ return Name;}
    int getValue(){ return Value;}
    void setValue(int value){ Value = value;}
    bool getIsVisited(){ return isVisited;}
    void setIsVisited(bool is_visited){ isVisited = is_visited;}
};

#endif