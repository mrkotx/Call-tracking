#pragma once
#include <iostream>
#include <sstream>
#include "Structures.h"

using namespace std;

class MyClass;
class MassA;
class MassB;

ostream& operator<<(ostream& op, const TALK& a);
stringstream& operator>>(stringstream& inp, TALK& a);
istream& operator>>(istream& is, TALK& a);

ostream& operator<<(ostream& op, MassA& af);
ostream& operator<<(ostream& op, MassB& bf);
ostream& operator<<(ostream& op, MyClass& f);