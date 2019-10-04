/*
	Комков Александр Сергеевич М8О-201Б-18
	Создать класс BritishMoney для работы с
	денежными суммами в старой британской
	системе. Сумма денег должна быть представлена 
	тремя полями: типа unsignedlong long 
	для фунтов стерлингов и типа unsigned 
	int для шиллингов и пенсов. Реализовать 
	сложение сумм, вычитание сумм, умножение 
	на дробное число, деление на дробное число 
	и операции сравнения.
*/


#include <iostream>
#include "BritishMoney.h"
#include <string>
using namespace std;
using std::string;

void Summation(int term1, int term2, int sum, int i, BrMoney*[]);
void Substraction (int min, int sub, int dif, int i, BrMoney*[]);
void Comparison(int op1, int op2, int i, BrMoney*[]);

int main(){
	const int N = 5;
	int action, i = 0, ID1, ID2, ID3;
	unsigned long long new_pounds;
	unsigned int new_shillings, new_pennies;
	string arg;
	BrMoney * a[N];

	do{
		cout << "Options:\n";
		cout << "1. Create person\n";
		cout << "2. Print all people\n";
		cout << "3. Sum up two people's money\n";
		cout << "4. Substract one person's money from another person's money\n";
		cout << "5. Divide person's money\n";
		cout << "6. Multiple person's money\n";
		cout << "7. Compare two people's money\n";
		cout << "8. Quit\n";
		cin >> action;

		switch (action){
			case 1:
			{
				if (i < N){
					cout << "enter person's name and values:\nNAME POUNDS SHILLINGS PENNIES\n";
					cin >> arg;
					cin >> new_pounds >> new_shillings >> new_pennies;
					a[i] = new BrMoney(i);
					a[i]->setMoney(new_pounds, new_shillings, new_pennies);
					a[i]->setName(arg);
					i++;
				}
				else cout << "You can't add any more people\n";
			}
			break;

			case 2:
			{
				for(int j = 0; j < i; ++j){
					a[j]->printMoney();
				}
			}
			break;

			case 3:
			{
				cout << "Do you want to create a new person? Y/N\n";
				cin >> arg;
				if (arg == "Y"){
					if (i < N){
						cout << "Enter person's name:\nNAME\n";
						cin >> arg;
						a[i] = new BrMoney(i);
						a[i]->setMoney(0, 0, 0);
						a[i]->setName(arg);
						i++;
						cout << "Enter IDs of terms: \n";
						cin >> ID1 >> ID2;
						Summation(ID1, ID2, i, i, a);
					}
					else {
						cout << "You can't add any more people, enter IDs of terms and sum: \n";
						cin >> ID1 >> ID2 >> ID3;
						Summation(ID1, ID2, ID3, i, a);	
					}
				}
				if (arg == "N") {
					cout << "Enter IDs of terms and sum: \n";
					cin >> ID1 >> ID2 >> ID3;
					Summation(ID1, ID2, ID3, i, a);
				}
			}
			break;

			case 4:
			{
				cout << "Do you want to create a new person? Y/N\n";
				cin >> arg;
				if (arg == "Y"){
					if (i < N){
						cout << "Enter person's name:\nNAME\n";
						cin >> arg;
						a[i] = new BrMoney(i);
						a[i]->setMoney(0, 0, 0);
						a[i]->setName(arg);
						i++;
						cout << "Enter IDs of minuend and substrahend: \n";
						cin >> ID1 >> ID2;
						Substraction(ID1, ID2, i, i, a);
					}
					else {
						cout << "You can't add any more people, enter IDs of minuend, substrahend and difference: \n";
						cin >> ID1 >> ID2 >> ID3;
						Substraction(ID1, ID2, ID3, i, a);	
					}
				}
				if (arg == "N") {
					cout << "Enter IDs of minuend, substrahend and difference: \n";
					cin >> ID1 >> ID2 >> ID3;
					Substraction(ID1, ID2, ID3, i, a);
				}
			}
			break;

			case 5:
			{
				cout << "Enter person's ID:\n";
				cin >> ID1;
				for (int j = 0; j < i; ++j)
					if (ID1 == a[j]->getID())
						a[j]->divMoney();
			}
			break;

			case 6:
			{
				cout << "Enter person's ID:\n";
				cin >> ID1;
				for (int j = 0; j < i; ++j)
					if (ID1 == a[j]->getID())
						a[j]->multMoney();
			}
			break;

			case 7:
			{
				cout << "Enter the IDs of the people whose money you wanna compare:\n";
				cin >> ID1 >> ID2;
				Comparison(ID1, ID2, i, a);
			}
			break;

			case 8: break;

			default:
			{
				cout << "unknown argument\n";
			}
			break;
		}
	}
	while (action != 8);

	return 0;
}

void Summation(int term1, int term2, int sum, int i, BrMoney * a[]){
	BrMoney tmpA(0,0,0,"tmpA", -1), tmpB(0,0,0,"tmpB", -1);
	for (int j = 0; j < i; ++j){
		if (term1 == a[j]->getID()){
			tmpA.copyMoney(*a[j]);
		}
		if (term2 == a[j]->getID()){
			tmpB.copyMoney(*a[j]);
		}
	}
	for (int j = 0; j < i; ++j)
		if (sum == a[j]->getID())
			a[j]->addMoney(tmpA, tmpB);
}

void Substraction (int min, int sub, int dif, int i, BrMoney * a[]){
	BrMoney tmpA(0,0,0,"tmpA", -1), tmpB(0,0,0,"tmpB", -1);
	for (int j = 0; j < i; ++j){
		if (min == a[j]->getID()){
			tmpA.copyMoney(*a[j]);
		}
		if (sub == a[j]->getID()){
			tmpB.copyMoney(*a[j]);
		}
	}
	for (int j = 0; j < i; ++j)
		if (dif == a[j]->getID())
			a[j]->subMoney(tmpA, tmpB);
}

void Comparison(int op1, int op2, int i, BrMoney * a[]){
	BrMoney tmpA(0,0,0,"tmpA", -1), tmpB(0,0,0,"tmpB", -1);
	for (int j = 0; j < i; ++j){
		if (op1 == a[j]->getID()){
			tmpA.copyMoney(*a[j]);
		}
		if (op2 == a[j]->getID()){
			tmpB.copyMoney(*a[j]);
		}
	}
	int A[3], B[3];
	tmpA.getMoney(A);
	tmpB.getMoney(B);
	int sumA, sumB;
	sumA = A[0]*240 + A[1]*12 + A[3];
	sumB = B[0]*240 + B[1]*12 + A[3];
	if (sumA > sumB){
		cout << tmpA.getName() << " has more money then " << tmpB.getName() << endl;
	}
	else if (sumB > sumA){
		cout << tmpB.getName() << " has more money then " << tmpA.getName() << endl;
	}
	else cout << "values of money of these people are equal" << endl;
}