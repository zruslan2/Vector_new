#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	int cur_size;
	int buf_size;
	double *els;
public:
	//cons
	Vector();	
	Vector(int size);
	Vector (const Vector &obj);
	int size()const { return cur_size; }
	//operators
	Vector operator=(const Vector &obj);
	Vector operator+(const Vector &obj);
	Vector operator-(const Vector &obj);
	bool operator==(const Vector &obj);
	double& operator[](int index);
	friend ostream& operator<<(ostream& os, Vector v);
	//metods
	double& push_back(double val);
	double& at(int index);
	//destructor
	~Vector() { delete[]els; }
		
};
