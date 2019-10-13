#include <iostream>
#include <string>
using namespace std;
using std::string;

#include "BritishMoney.h"

BrMoney::BrMoney(int new_ID){
	string new_name;
	setName(new_name);
	setMoney(0,0,0);
	ID = new_ID + 1;
}
BrMoney::BrMoney(unsigned long long new_pounds, unsigned int new_shillings, unsigned int new_pennies, string new_name, int new_ID){
	setName(new_name);
	setMoney(new_pounds, new_shillings, new_pennies);
	ID = new_ID + 1;
}
void BrMoney::setMoney(unsigned long long new_pounds, unsigned int new_shillings, unsigned int new_pennies){
	pounds = new_pounds;
	shillings= new_shillings;
	pennies = new_pennies;
}
void BrMoney::setName(string new_name){
	name = new_name;
}
void BrMoney::printMoney(){
	cout << "Name: " << name << " Pounds: " << pounds << " Shillings: " << shillings << " Pennies: " << pennies << " ID: " << ID << "\n";
}
void BrMoney::getMoney(int m[]){
	m[0] = pounds;
	m[1] = shillings;
	m[2] = pennies;
}
string BrMoney::getName(){
	return name;
}
void BrMoney::copyMoney(BrMoney a){
	pennies = a.pennies;
	shillings = a.shillings;
	pounds = a.pounds;
}

void BrMoney::copyAll(BrMoney a){
	pennies = a.pennies;
	shillings = a.shillings;
	pounds = a.pounds;
	ID = a.ID;
	name = a.name;
}

void BrMoney::addMoney(BrMoney a, BrMoney b){
	setMoney(0,0,0);
	pennies += a.pennies + b.pennies;
	if (pennies >= 12){
		shillings++;
		pennies %= 12;
	}
	shillings += a.shillings + b.shillings;
	if (shillings >= 20){
		pounds++;
		shillings %= 20;
	}
	pounds += a.pounds + b.pounds;
}
void BrMoney::subMoney(BrMoney a, BrMoney b){
	setMoney(0,0,0);
	if (a.pounds < b.pounds){
		cout << "Error. You cannot get negative amount of money\n";
		return;
	}
	else {
		pounds += a.pounds - b.pounds;
		if (a.shillings < b.shillings){
			if (pounds == 0){
				cout << "Error. You cannot get negative amount of money\n";
				return;
			}
			else {
				pounds--;
				a.shillings += 20;
			}
		}
		shillings += a.shillings - b.shillings;
		if (a.pennies < b.pennies){
			if(shillings == 0 && pounds == 0){
				cout << "Error. You cannot get negative amount of money\n";
				return;
			}
			else if (shillings > 0){
				shillings--;
				a.pennies += 12;
			}
			else {
				pounds--;
				shillings = 19;
				a.pennies += 12;
			}
		}
		pennies += a.pennies - b.pennies;
	}
}

void BrMoney::divMoney(BrMoney a, double divr){
	double general = 0;
	int igen;
	general += a.pennies + a.shillings*12 + a.pounds*240;
	if (divr != 0){
		general /= divr;
		igen = (int)general;
		pounds = igen / 240;
		igen %= 240;
		shillings = igen / 12;
		igen %= 12;
		pennies = igen;
	}
	else cout << "You can't divide on 0\n";
}

void BrMoney::multMoney(BrMoney a, int mult){
	pennies = a.pennies * mult;
	shillings = a.shillings*mult + pennies/12;
	pennies %= 12;
	pounds = a.pounds*mult + shillings/20;
	shillings %= 20;
}

int BrMoney::getID(){
	return ID;
}

BrMoney operator+(BrMoney a, BrMoney b){
	BrMoney kek(-1);
	kek.addMoney(a, b);
	return kek;
}

BrMoney operator-(BrMoney a, BrMoney b){
	BrMoney kek(-1);
	kek.subMoney(a, b);
	return kek;
}

BrMoney operator*(BrMoney a, int mult){
	BrMoney kek(-1);
	kek.multMoney(a, mult);
	return kek;
}
BrMoney operator/(BrMoney a, double divr){
	BrMoney kek(-1);
	kek.divMoney(a, divr);
	return kek;
}