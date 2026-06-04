#pragma once

#include <iostream>
#include "Structures.h"

using namespace std;

class MyClass
{
protected:
	TALK* a = nullptr;
	int n = 0;

public:
	friend ostream& operator<<(ostream& op, MyClass& f);
	friend ofstream& operator<<(ofstream& file, MyClass& ffile);
	friend ifstream& operator>>(ifstream& file, MyClass& ffile);
	MyClass();
	~MyClass();
	MyClass(MyClass& z);
	MyClass& operator=(MyClass& z);
	void menu();
	void getTable();
	void loadFromFile(MyClass& a);
	void saveInFile();
	void addData();
	void showData();
	void saveData(MyClass& target);
	void deleteData();
	void sort(bool(*compare)(const TALK&, const TALK&));
	void sortAlphabet();
	void sortTime();
	void sortDate();
	void clearMassive();
};
ofstream& operator<<(ofstream& file, MyClass& ffile);
ifstream& operator>>(ifstream& file, MyClass& ffile);