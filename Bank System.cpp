#include<iostream>
#include<string>
#define ll long long 
using namespace std;

class Bank
{
public:
	struct Stack {
		string typeOfProcess;
		int ID = 1500;
		string firstName, secondName;
		string TypeOfCurrency;
		ll TotalBalance = 0, intial = 0, process = 0;
		Stack* next;
	};
	struct Node {
		int ID = 1500, age, count, Telephone;
		string firstName, secondName;
		string TypeOfCurrency, TypeOfAccount;
		ll TotalBalance = 0, intial = 0, depoist = 0, withdraw = 0, temp = 0;
		Node* next;
		Stack* newNode;
	};

	Stack* top = NULL; // stack
	Node* head = NULL; // linkedlist
	Node* temp = NULL; // looping
	Node* temp2 = NULL; // looping
	bool check = true;

	void push(Node* node, string typeOfProcess, double money) {
		node->newNode = new Stack;
		node->newNode->typeOfProcess = typeOfProcess;
		node->newNode->ID = node->ID;
		node->newNode->firstName = node->firstName;
		node->newNode->secondName = node->secondName;
		node->newNode->TypeOfCurrency = node->TypeOfCurrency;
		node->newNode->TotalBalance = node->TotalBalance;
		node->newNode->intial = node->temp;
		node->newNode->process = money;
		node->newNode->next = top;
		top = node->newNode;
	}
	void display(Node* found) {
		struct Stack* ptr;
		if (top == NULL)
			cout << "\nNO Data to show\n\n";
		else {
			ptr = top;
			cout << "\nYour Process Histroy:-\n\n";
			while (ptr != NULL)
			{
				if (ptr->ID == found->ID) {
					cout << "The Type of the process is : " << ptr->typeOfProcess
						<< "\n\n\tAccount Number : " << ptr->ID
						<< "\t\tAccount Holder : " << ptr->firstName << " " << ptr->secondName
						<< "\t\tAccount Type of Currency : " << ptr->TypeOfCurrency
						<< "\n\n\tThe amount of money of " << ptr->typeOfProcess << " : " << ptr->process << " " << ptr->TypeOfCurrency;
					cout << "\n\n---------------------------------------------------------------\n\n";
				}
				ptr = ptr->next;
				
			}

		}
	}


	void insert() {
		Node* new_node = new Node;
		set_data(new_node);
		if (check == false)
		{
			delete new_node;
			return;
		}
		new_node->next = NULL;
		if (head == NULL) {
			head = new_node;

		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new_node;
		}
	}
	void set_data(Node* a)
	{
		ll intialAmount = 0;
		int rando = rand();
		a->ID += rando;
		cout << "\n\n------------------- New Bank Account Process -------------------";
		cout << "\n\nEnter First Name Of holder : ";
		cin >> a->firstName;
		cout << "\nEnter second Name Of holder : ";
		cin >> a->secondName;
		cout << "\nEnter the Age Of holder : ";
		cin >> a->age;
		if (a->age < 18)
		{
			cout << "\nInvaild Number. It's not allowed at this age to create new Account.\n\n";
			check = false;
		}
		else
		{
			cout << "\nEnter Holder Telefon Number : ";
			cin >> a->Telephone;
			cout << "\nEnter type of Account (Silver | Gold | Platinium) : ";
			cin >> a->TypeOfAccount;

			while (a->TypeOfAccount != "Silver" && a->TypeOfAccount != "silver" && a->TypeOfAccount != "Gold" && a->TypeOfAccount != "gold" && a->TypeOfAccount != "Platinium" && a->TypeOfAccount != "platinium")
			{
				cout << "\nInvalid Type. Please try again: "; cin >> a->TypeOfAccount;
			}
			cout << "\nEnter Type Of Currency [P/$] : ";
			cin >> a->TypeOfCurrency;

			while (a->TypeOfCurrency != "P" && a->TypeOfCurrency != "p" && a->TypeOfCurrency != "$")
			{
				cout << "\nInvalid Currency . Please try again: "; cin >> a->TypeOfCurrency;
			}

			if (a->TypeOfAccount == "Silver" || a->TypeOfAccount == "silver")
			{

				cout << "\nPlease enter the intial value you put it to create the Account : ";
				cin >> intialAmount;
				while ((intialAmount < 500 && a->TypeOfCurrency == "$") || (intialAmount < 1000 && a->TypeOfCurrency == "P") || (intialAmount < 1000 && a->TypeOfCurrency == "p"))
				{
					if (a->TypeOfCurrency == "$") { cout << "\nThe intial amount is less than 500 Dollars. PLease try again : "; cin >> intialAmount; }
					if (a->TypeOfCurrency == "p" || a->TypeOfCurrency == "P") { cout << "\nThe intial amount is less than 1000 Pounds. PLease try again : "; cin >> intialAmount; }
				}

				set_intial(a, intialAmount);
				set_totalBalance(a);
				a->temp = a->intial;
				a->intial = 0;
				cout << "\n\t\tThe Account is created Sucessfully..... ";
				cout << "\n\n\t\t    Your Account Number Is : " << a->ID << endl;
				cout << "\n---------------------------------------------------------------\n\n";
			}
			else if (a->TypeOfAccount == "Gold" || a->TypeOfAccount == "gold")
			{
				cout << "\nPlease enter the intial value you put it to create the Account : ";
				cin >> intialAmount;
				while ((intialAmount < 1000 && a->TypeOfCurrency == "$") || (intialAmount < 2000 && a->TypeOfCurrency == "P") || (intialAmount < 2000 && a->TypeOfCurrency == "p"))
				{
					if (a->TypeOfCurrency == "$") { cout << "\nThe intial amount is less than 1000 Dollars. PLease try again : "; cin >> intialAmount; }
					if (a->TypeOfCurrency == "p" || a->TypeOfCurrency == "P") { cout << "\nThe intial amount is less than 2000 Pounds. PLease try again : "; cin >> intialAmount; }
				}

				set_intial(a, intialAmount);
				set_totalBalance(a);
				a->temp = a->intial;
				a->intial = 0;
				cout << "\n\t\tThe Account is created Sucessfully..... ";
				cout << "\n\n\t\t    Your Account Number Is : " << a->ID << endl;
				cout << "\n---------------------------------------------------------------\n\n";
			}
			else if (a->TypeOfAccount == "Platinium" || a->TypeOfAccount == "platinium")
			{
				cout << "\nPlease enter the intial value you put it to create the Account : ";
				cin >> intialAmount;
				while ((intialAmount < 2000 && a->TypeOfCurrency == "$") || (intialAmount < 4000 && a->TypeOfCurrency == "P") || (intialAmount < 4000 && a->TypeOfCurrency == "p"))
				{
					if (a->TypeOfCurrency == "$") { cout << "\nThe intial amount is less than 2000 Dollars. PLease try again : "; cin >> intialAmount; }
					if (a->TypeOfCurrency == "p" || a->TypeOfCurrency == "P") { cout << "\nThe intial amount is less than 4000 Pounds. PLease try again : "; cin >> intialAmount; }
				}

				set_intial(a, intialAmount);
				set_totalBalance(a);
				a->temp = a->intial;
				a->intial = 0;
				cout << "\n\t\tThe Account is created Sucessfully..... ";
				cout << "\n\n\t\t    Your Account Number Is : " << a->ID << endl;
				cout << "\n---------------------------------------------------------------\n\n";

			}
		}
	}
	void set_intial(Node* a, ll intialAmount)
	{
		a->intial += intialAmount;
	}

	void set_totalBalance(Node* found)
	{
		found->TotalBalance += found->intial + found->depoist - found->withdraw;
	}

	Node* searchAccount(int accountNumber) {
		Node* current = head;
		while (current != NULL) {
			if (current->ID == accountNumber) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	void show_data(Node* found)
	{
		cout << "Account Number : " << found->ID
			<< "\t\tAccount Holder : " << found->firstName << " " << found->secondName
			<< "\t\tAccount Age : " << found->age
			<< "\n\n\tHolder Telefon Number : " << found->Telephone
			<< "\t\tType of account : " << found->TypeOfAccount
			<< "\n\n\nType of Currency : " << found->TypeOfCurrency
			<< "\t\t          Total Balance : " << found->TotalBalance << "\n\n";
		cout << "\n---------------------------------------------------------------\n\n";
	}
	void modify_Account(Node* founded)
	{

		char OldType = founded->TypeOfCurrency[0];
		int OldAge = founded->age;
		cout << "\n\n------------------- Modify Account Process -------------------";
		cout << "\n\nEnter The New First Name Of holder : ";
		string first;
		cin >> first;
		founded->firstName = first;
		cout << "\nEnter The New second Name Of holder : ";
		string second;
		cin >> second;
		founded->secondName = second;
		cout << "\nEnter The New Holder Telefon Number : ";
		int tel;
		cin >> tel;
		founded->Telephone = tel;
		cout << "\nEnter The New Holder Age : ";
		int age;
		cin >> age;
		while (OldAge > age)
		{
			cout << "Invalid Number. Please try again :"; cin >> age;
		}
		founded->age = age;
		cout << "\nEnter The New Type Of Account (Silver | Gold | Platinium) : ";
		cin >> founded->TypeOfAccount;
		cout << "\nEnter The New Type Of Currency [P/$] : ";
		cin >> founded->TypeOfCurrency;
		while (founded->TypeOfCurrency != "P" && founded->TypeOfCurrency != "p" && founded->TypeOfCurrency != "$")
		{
			cout << "\nInvalid character. Please try again: "; cin >> founded->TypeOfCurrency;
		}
		cout << founded->TypeOfCurrency[0];
		if (founded->TypeOfCurrency[0] != OldType && founded->TypeOfCurrency[0] != tolower(OldType) && founded->TypeOfCurrency[0] != toupper(OldType))
		{
			if (founded->TypeOfCurrency == "p" || founded->TypeOfCurrency == "P")
				founded->TotalBalance *= 40;
			else
				founded->TotalBalance /= 40;
		}
		cout << "\n\t\tThe Account is modified Sucessfully..... ";
		cout << "\n---------------------------------------------------------------\n\n";

	}

	void transfer(Node* accountFrom, Node* accountTo)
	{
		ll amount = 0, changeCurrency = 0;

		if (accountFrom != NULL && accountTo != NULL && accountFrom->ID != accountTo->ID) {
			cout << "Enter the amount of Money you will transfer : "; cin >> amount;
			if (accountFrom->TypeOfCurrency != accountTo->TypeOfCurrency)
			{
				if (accountFrom->TypeOfCurrency == "$")
				{
					changeCurrency = accountFrom->TotalBalance * 40;
					if (changeCurrency >= amount) {
						changeCurrency -= amount;
						accountTo->TotalBalance += amount;
						cout << "\nTransfer successful!" << endl;
						cout << "\n---------------------------------------------------------------\n\n";

						push(accountFrom, "Transfer out Money", amount/40);
						push(accountTo, "Transfer in Money", amount);
						accountFrom->TotalBalance = changeCurrency / 40;
					}
					else {
						cout << "\nInsufficient funds!" << endl;
						cout << "\n---------------------------------------------------------------\n\n";
					}
				}
				else if (accountFrom->TypeOfCurrency == "p" || accountFrom->TypeOfCurrency == "P")
				{
					changeCurrency = accountFrom->TotalBalance / 40;
					if (changeCurrency >= amount) {
						changeCurrency -= amount;
						accountTo->TotalBalance += amount;
						cout << "\nTransfer successful!" << endl;
						cout << "\n---------------------------------------------------------------\n\n";

						push(accountFrom, "Transfer out Money", amount*40);
						push(accountTo, "Transfer in Money", amount);
						accountFrom->TotalBalance = changeCurrency * 40;
					}
					else {
						cout << "\nInsufficient funds!" << endl;
						cout << "\n---------------------------------------------------------------\n\n";
					}
				}
			}
			else if (accountFrom->TotalBalance >= amount)
			{
				accountFrom->TotalBalance -= amount;
				accountTo->TotalBalance += amount;
				cout << "\nTransfer successful!" << endl;
				cout << "\n---------------------------------------------------------------\n\n";

				push(accountFrom, "Transfer out Money", amount);
				push(accountTo, "Transfer in Money", amount);
			}
			else {
				cout << "Insufficient funds!" << endl;
				cout << "\n---------------------------------------------------------------\n\n";
			}
		}
		else {
			cout << "One or both accounts not found!" << endl;
		}

	}

	void deleteAccount(int accountNumber) {
		if (head == NULL) {
			cout << "No accounts to delete!" << endl;
			return;
		}

		if (head->ID == accountNumber) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current = head;
		while (current->next != NULL) {
			if (current->next->ID == accountNumber) {
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				return;
			}
			current = current->next;
		}

		cout << "Account not found!" << endl;
	}

};
class Deposit : public Bank
{
public: double D_amount = 0;

	  void set_deposit(Node* found)
	  {
		  cout << "\n\n----------------------- Deposit Process -----------------------";
		  cout << "\n\nPlease Enter the amount of Money you will deposit it : ";
		  cin >> D_amount;
		  if (found->TypeOfAccount == "Silver" || found->TypeOfAccount == "silver")
		  {
			  if (D_amount >= 1000 && D_amount < 2000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.15 % at the end of the year";
			  }
			  else if (D_amount >= 2000 && D_amount < 3000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.3 % at the end of the year";
			  }
			  else if (D_amount >= 3000 && D_amount < 4000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.35 % at the end of the year";
			  }

		  }
		  if (found->TypeOfAccount == "Gold" || found->TypeOfAccount == "gold")
		  {
			  if (D_amount >= 1000 && D_amount < 2000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.3 % at the end of the year";
			  }
			  else if (D_amount >= 2000 && D_amount < 3000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.5 % at the end of the year";
			  }
			  else if (D_amount >= 3000 && D_amount < 4000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.75 % at the end of the year";
			  }

		  }
		  if (found->TypeOfAccount == "Platinium" || found->TypeOfAccount == "platinium")
		  {
			  if (D_amount >= 1000 && D_amount < 2000)
			  {
				  cout << "\nNow!! you have a commission in your account 0.75 % at the end of the year";
			  }
			  else if (D_amount >= 2000 && D_amount < 3000)
			  {
				  cout << "\nNow!! you have a commission in your account 1 % at the end of the year";
			  }
			  else if (D_amount >= 3000 && D_amount < 4000)
			  {
				  cout << "\nNow!! you have a commission in your account 1.75 % at the end of the year";
			  }

		  }


		  found->depoist = D_amount;
		  set_totalBalance(found);
		  found->depoist = 0;
		  cout << "\nThe Process is done Sucessfully.........\n";
		  cout << "\nYour Total Balance Now : " << found->TotalBalance;
		  cout << "\n\n---------------------------------------------------------------\n\n";
		  push(found, "Deposite", D_amount);
	  }
};

class Withdraw : public Deposit
{
public: double W_amount = 0;

	  void set_withdraw(Node* found)
	  {
		  cout << "\n\n---------------------- Withdraw Process ----------------------";
		  cout << "\n\n\nPlease Enter the amount of Money you will withdraw it:";
		  cin >> W_amount;
		  while (W_amount > found->TotalBalance || (found->TotalBalance - W_amount) < 1000)
		  {
			  cout << "!!!!!!!!!!!!!!!!!!!!! Alert !!!!!!!!!!!!!!!!!!!!!\nThe amount of the withdraw mustn't exceed the Total Balance while the minimum value for Total Balance is 1000.\n\nPlease Try Again : ";
			  cin >> W_amount;
		  }
		  found->withdraw = W_amount;
		  cout << "\nThe Process is done Sucessfully...........\n";
		  set_totalBalance(found);
		  found->withdraw = 0;
		  cout << "\nYour Total Balance Now : " << found->TotalBalance << endl << endl;
		  push(found, "Withdraw", W_amount);
	  }
};

void intro()
{
	cout << "****************************************************************************" << endl << endl;
	cout << "****************************************************************************" << endl << endl;
	cout << "                            BANK MANAGEMENT SYSTEM                          " << endl << endl;
	cout << "****************************************************************************" << endl;
	cout << "                               ::Main  Menu::                               " << endl;
	cout << "****************************************************************************" << endl << endl << endl;
	cout << "-Welcome To Our Banking System. \n\n";
}
int main()
{
	Withdraw w;
	int options = 9, n = 0, AccNum = 0, AccNum2 = 0;
	intro();
	while (n != options)
	{
		cout << "1. New Bank Account." << endl;
		cout << "2. Deposit Money." << endl;
		cout << "3. Withdraw Money." << endl;
		cout << "4. Balance Enquiry. " << endl;
		cout << "5. Modify Account. " << endl;
		cout << "6. Transfer Money. " << endl;
		cout << "7. Delete Account. " << endl;
		cout << "8. Display Account's Process Histroy. " << endl;
		cout << "9. Exit. " << endl;
		cout << "Please choose your Option from 1 to 9 : ";
		cin >> n;

		while (n > options || n == 0)
		{
			cout << endl << "Invalid Number Please try again: ";
			cin >> n;
		}

		switch (n)
		{
		case 1:
			system("cls");
			w.insert();

			break;
		case 2:
			system("cls");
			cout << "\nPlease enter your Account Number : ";
			cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			w.set_deposit(w.temp);
			cout << "\n\n---------------------- Your Account Data ---------------------\n\n";
			w.show_data(w.temp);
			w.temp = NULL;
			break;
		case 3:
			system("cls");
			cout << "\nPlease enter your Account Number : ";	cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			w.set_withdraw(w.temp);
			cout << "\n\n---------------------- Your Account Data ---------------------\n\n";
			w.show_data(w.temp);
			w.temp = NULL;
			break;
		case 4:
			system("cls");
			cout << "\nPlease enter your Account Number : ";	cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			cout << "\n\n---------------------- Your Account Data ---------------------\n\n";
			w.show_data(w.temp);
			w.temp = NULL;
			break;
		case 5:
			system("cls");
			cout << "\nPlease enter your Account Number : ";	cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			cout << "\n\n---------------------- Your Account Data ---------------------\n\n";
			w.show_data(w.temp);
			w.modify_Account(w.temp);
			cout << "\n\n---------------------- Your Modified Account Data ---------------------\n\n";
			w.show_data(w.temp);
			w.temp = NULL;
			break;
		case 6:
			system("cls");
			cout << "\n\nEnter your 1st Account Number : ";
			cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			cout << "\n\n---------------------- 1st Account Data ---------------------\n\n";
			w.show_data(w.temp);
			cout << "\n\nEnter your 2st Account Number : ";
			cin >> AccNum2;
			while (w.temp2 == NULL)
			{
				w.temp2 = w.searchAccount(AccNum2);
				if (w.temp2 == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			cout << "\n\n---------------------- 2st Account Data ---------------------\n\n";
			w.show_data(w.temp2);

			w.transfer(w.temp, w.temp2);
			w.temp = NULL;
			w.temp2 = NULL;
			break;
		case 7:
			system("cls");
			cout << "\n\nEnter your Account Number : ";
			cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			cout << "\n\n---------------------- Your Account Data ---------------------\n\n";
			w.show_data(w.temp);
			cout << "\nPlease Withdraw Your Total Balance to delete your Account :  " << w.temp->TotalBalance << endl;
			w.deleteAccount(AccNum);
			cout << "\n\t\tYour account deleted sucessfully........\n\n";
			intro();
			w.temp = NULL;
			break;
		case 8:
			system("cls");
			cout << "\n\nEnter your Account Number : ";
			cin >> AccNum;
			while (w.temp == NULL)
			{
				w.temp = w.searchAccount(AccNum);
				if (w.temp == NULL)
				{
					cout << "\nThe Account number that you have put it is wrong. Please try again : "; cin >> AccNum;
				}
			}
			w.display(w.temp);
			intro();
			w.temp = NULL;
			break;
		case 9:
			cout << "\n\t********************************************";
			cout << "\n\t*Thank you for choosing our Banking System.*";
			cout << "\n\t********************************************";
			break;

		}
	}
}
