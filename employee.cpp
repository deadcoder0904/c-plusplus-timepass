#include <iostream>
#include <sstream>

using namespace std;

class Employee
{
	private: 
		string name;
		double pay;	
	public:
		Employee(){
			name = "";
			pay = 0;	
		};
		Employee(string empName,double payRate){
			setName(empName);
			setPay(payRate);
		};
		void setName(string empName){
			name = empName;
		}
		string getName(){
			return name;
		}
		void setPay(double payRate){
			pay = payRate;
		}
		double getPay(){
			return pay;
		}
		string toString(){
			stringstream stm;
			stm << name << ": " << pay;
			return stm.str();
		}	
};

class Manager: public Employee
{
	private:
		bool salaried;
	public:
		Manager(string empName, double payRate, bool isSalaried) : Employee(empName,payRate){
			salaried = isSalaried;
		}
		bool isSalaried(){
			return salaried;
		}
};

int main()
{
	Employee emp1("Akbar Hatela",12135);
	Employee emp2("Amar Fatela",67135);
	Employee emp3("Jahanum Thakela",7135);
	Manager emp4("Funaki",895035,true);
	cout << emp1.toString() << endl;
	cout << emp2.toString() << endl;
	cout << emp3.getName() << endl;
	cout << emp3.getPay() << endl;
	cout << emp4.toString() << " \nisSalaried? " << emp4.isSalaried() << endl;
	return 0;
}