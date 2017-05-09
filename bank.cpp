#include <iostream>

using namespace std;

class Account {
	protected:
		double balance;
	public:
		Account(double bal){
			if(bal > 0)
				balance = bal;
			else balance = 0;
		}
		void credit(double amount){
			balance += amount;
		}
		void debit(double amount){
			if(balance < amount)
				cout << "Insufficient Funds." << endl;
			else
				balance -= amount;
		}
		double getBalance(){
			return balance;
		}

};

class CheckingAccount: public Account{
	private:
		double fee;
	public:
		CheckingAccount(double bal, double f):
			Account(bal)
		{
			fee = f;
		}
		void debit(double amount){
			if(balance < amount+fee)
				cout << "Insufficient Funds." << endl;
			else
				balance = balance-amount-fee;
		}
};

int main()
{
	CheckingAccount acc(1000,0.5);
	cout << "Balance: $" << acc.getBalance() << endl;
	cout << "Crediting $100" << endl;
	acc.credit(100);
	cout << "Balance: $" << acc.getBalance() << endl;
	cout << "Debiting $100" << endl;
	acc.debit(100);
	cout << "Balance: $" << acc.getBalance() << endl;
	cout << "Debiting $1001" << endl;
	acc.debit(1001);
	cout << "Balance: $" << acc.getBalance() << endl;
	cout << "Debiting $999" << endl;
	acc.debit(999);
	cout << "Balance: $" << acc.getBalance() << endl;
	return 0;
}
