#pragma once
#include <iostream>
#include "MyClass.h"
#include "Structures.h"

using namespace std;

class MassA : public MyClass
{
protected:
	TALK* c = nullptr;
	int k = 0;
public:
	friend ostream& operator<<(ostream& op, MassA& af);
	friend ofstream& operator<<(ofstream& file, MassA& afile);
	MassA();
	~MassA();
	MassA(MassA& z);
	MassA& operator=(MassA& z);
	void sort(bool (*compare) (const TALK& a, const TALK& b));
	void findNumber();
	void saveFind(MassA& target);
};
ofstream& operator<<(ofstream& file, MassA& afile);