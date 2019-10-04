#include <iostream>
#include <string>
using namespace std;
using std::string;

class BrMoney{
private:
	string name;
	unsigned long long pounds;
	unsigned int shillings, pennies;
	int ID;
public:
	BrMoney(int);
	BrMoney(unsigned long long, unsigned int, unsigned int, string, int);
	void setMoney(unsigned long long, unsigned int, unsigned int);
	void setName(string);
	void printMoney();
	void getMoney(int[]);
	string getName();
	void copyMoney(BrMoney a);
	void addMoney(BrMoney a, BrMoney b);
	void subMoney(BrMoney a, BrMoney b);
	void divMoney();
	void multMoney();
	int getID();
};