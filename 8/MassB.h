#pragma once
#include <iostream>
#include "MassA.h"
#include "Structures.h"

using namespace std;

class MassB : public MassA
{
protected:
	TALK* b = nullptr;
	int k = 0;
public:
	friend ostream& operator<<(ostream& op, MassB& bf);
	friend ofstream& operator<<(ofstream& file, MassB& bfile);
	MassB();
	~MassB();
	MassB(MassB& z);
	MassB& operator=(MassB& z);
	void sort(bool(*compare)(const TALK& a, const TALK& b));
	void makePerech();
	void savePerech(MassB& target);
};

ofstream& operator<<(ofstream& file, MassB& bfile);