#include<stdio.h>
#include<forward_list>
#include<string>
#include<iostream>
#include<stdlib.h>
#include "account.h"
#include "User.h"
#include "CustomerList.h"
#include "Test.h"
using namespace std;

//constant variable used to turn on/off testing mode
#define TEST 1

#define cheqString "chequing"

//global user variables, so we can always know what user is currently active, userType will be one of our three constants, userID will be their actual ID
int currentUserType;
int currentUserID;
bool loggedIn;
Account tempAccount;

bool checkAccountStatus(Account act){
	if(act.isOpen()){
		cout << "Opening chequing account.\n";
		return true;
	}else{
		cout << "Chequing account is not open.\n";
		cout << "Please open a chequing account before proceeding.\n";
	}
}

Account selectAccount(){
	string command;
	string cheqAct = "chequing";
	string savingsAct = "savings";
	while(true){
		cout << "Please select an account type ('chequing' or 'savings')\n";
		cin >> command;
		if(command.compare(cheqAct) == 0){
			if(checkAccountStatus(*currentCustomer.getChequing())){
				return *currentCustomer.getChequing();
                }
		}else if(command.compare(savingsAct) == 0){
			if(checkAccountStatus(*currentCustomer.getSavings())){
				return *currentCustomer.getSavings();
			}
		}
	}
}

bool withdraw(Account act){
	double value;
	cout << "Please enter a value to withdraw\n";
	cin >> value;
	/*if(value.compare("back")){
		cout << "Cancelling Withdrawal.";
		return false;
	}else*/ if(act.getAmount() - value < 0.0 ){
		cout << "Insufficient funds\n";
		cout << "You have only $" << act.getAmount() << "in your " << act.getType() << ".\n";
		return false;
	}else{
		//act.amount -= value;
		act.setAmount(act.getAmount() - value);
		return true;
	}
}

bool deposit(Account act){
	double value;
	//while(value == null){
		cout << "Please enter a value to deposit\n";
		cin >> value;
		/*if(value.compare("back")){
			return false;
		}else */
		if(value < 0){
			cout << "Cannot deposit a negative value\n";
		}else if(value > 0){
			cout << "Depositing: $" << value << "\n";
			//act.amount += value;
			return true;
		}
	//}
	return false;
}
// Transfer funds between accounts
bool Transfer(Account source,Account destination){
	int transferValue;
	/*
	while(true){
	cout << "Please enter the first account/n";
	cout << "(This will be the account funds are withdrawn from)/n";
	cin >> toWithdraw;
		if(toWithdraw.compare("back")){
				return false;
		}else if(toWithdraw !=null){
			withdraw(toWithdraw);
		}else{
			cout << "Please enter a valid account./n";
		}
	}

	while(true){
		cout << "Please enter the second account/n";
		cout << "(This will be the account funds are placed into)/n";
		cin >> toDeposit
		if(toDeposit.compare("back")){
				return false;
		}else if(toDeposit !=null){
			deposit(toDeposit);
		}else{
			cout << "Please enter a valid account./n";
		}
	}

	cout << "Successfully transferred funds!";
	cout << "Your new balances are: /n";
	cout << toWithdraw.name + " " + toWithdraw.value + " /n";
	cout << toDeposit.name + " " + toDeposit.value + " /n";*/
	return true;
}
/*
	/*
	*
	* Execution Trace functions
	*

class trace(){
	// Attributes for whatever data needs to be tracked
}

function writeToFile(){
	// take data and write to file
	// ** Find when file must be updated??
}

*/


void login(){
	//create necessary variables
    int id;
    int attempts = 0;
	bool logged = false;

    //begin login loop
    while (!logged && attempts < 3) {
        //prompt user, get ID input
        cout << "Please enter your id.\n";
        cin >> id;

        //if id matches managerial role, output welcome message, change id and type variables, change logged variable to indicate successful login
        if (id == MANAGER) {
            cout << "Welcome, manager.\n";
            currentUserID = id;
            currentUserType = MANAGER;
            logged = true;

        //if id matches maintenance role, output welcome message, change id and type variables, change logged variable to indicate successful login
        }else if(id == MAINTENANCE){
            cout << "Welcome, maintenance.\n";
            currentUserID = id;
            currentUserType = MAINTENANCE;
            logged  = true;

        //if id matches customer role, output welcome message, change id and type variables, change logged variable to indicate successful login
        }else if(id == CUSTOMER){
            cout << "Welcome, user.\n";
            currentUserID = id;
            currentUserType = CUSTOMER;
            logged  = true;

        //if id matches no roles, output error message and record another login attempt
        }else{
            cout << "Error, invalid ID given.\n";
            attempts++;
        }

        if(TEST){
            if(logged){
                cout << "TEST: userID = " << currentUserID << "\nTEST: userType = " << currentUserType << "\n";
            }else{
                cout << "TEST: did not log in. UserID " << id << " given\n";
            }
        }
    }

    if(TEST){
        cout << "login while loop exited\n" << attempts << " login attempts made\n";
    }

    if(attempts == 3){
        cout << "Too many unsuccessful login attempts, program ending.\n";
        exit(1);
    }
}

void openAccount(){
	string command;
	string cheqAct = "chequing";
	string savingsAct = "savings";
	cout << "Please choose what account type you want to open('chequing' or 'savings')\n";
	cin >> command;

	if(command.compare(cheqAct) == 0){
		//if(!(currentCustomer.chequing.isOpen()){
		if(!currentCustomer.getChequing()->isOpen()){
			cout << "Chequing account is now open.\n";
			currentCustomer.getChequing()->open();
		}else{
			cout << "Savings account is already open.\n";
		}
	}else if(command.compare(savingsAct) == 0){
		if(!currentCustomer.getSavings()->isOpen()){
			cout << "Savings account is now open.\n";
			currentCustomer.getSavings()->open();
		}else{
			cout << "Savings account is already open.\n";
		}
	}
}

void closeAccount(){
}

void selectTransferAccounts(){
	string command;
	string cheqAccount = "chequing";
	string savingsAccount = "savings";
    Account temp = selectAccount();
	//cout << "Please enter the source account type ('chequing' or 'savings')\n";
	//cin >> command;
	//if(command.compare(cheqAccount) == 0){
	if((temp.getType()).compare(cheqAccount) == 0){
		cout << "Source: chequing account. \n";
		cout << "Destination: savings account. \n";
		//Transfer(currentUser.getChequing(),currentUser.getSavings())
	}else if((temp.getType()).compare(savingsAccount) == 0){
		cout << "Source: savings account. n";
		cout << "Destination: chequing account. \n";
		//Transfer(currentUser.getSavings(),currentUser.getChequing())
		Transfer(*currentCustomer.getSavings(),*currentCustomer.getChequing());
	}

}

void userSession(){
	// Initialize
	string command = "";
	string moneyIn = "deposit";
	string moneyOut = "withdraw";
	string cheqAccount = "chequing";
	string savingsAccount = "savings";
	string transfer = "transfer";
	string help = "help";
	string open = "open";
	string close = "close";

	Account currentAccount;
	Account otherAccount;

	loggedIn = true;
	// User interface
	while(loggedIn){
		cout << "Please enter a valid command (help for cmd list)\n";
		cin >> command;

		// Deposit & Withdraw
		if(command.compare(moneyIn) == 0){
			currentAccount = selectAccount();
			if(checkAccountStatus(currentAccount)){
				deposit(currentAccount);
			}
		}else if(command.compare(moneyOut) == 0){
			currentAccount = selectAccount();
			if(checkAccountStatus(currentAccount)){
				withdraw(currentAccount);
			}
		}else if(command.compare(transfer) == 0){
			selectTransferAccounts();
		}else if(command.compare(open) == 0){
				openAccount();
		}else if(command.compare(close) == 0){
				//closeAccount();
		}else if(command.compare(cheqAccount) == 0){
			currentCustomer.getAccountStatus();
		}else if(command.compare(savingsAccount) == 0){
			currentCustomer.getAccountStatus();
		}else if(command.compare(help) == 0){
			cout << "'withdraw' to take money out your account\n";
			cout << "'deposit' to put money into your account\n";
			cout << "'open' to open a new account\n";
			cout << "'close' to close a new account\n";
			cout << "'chequing' to view balance in chequing account\n";
			cout << "'savings' to view balance in savings account\n";
		}
	}
}

//a function for all setup operations
void setUp(){
    //create and prepare the manager and maintenance users
    manager.setType(MANAGER);
    manager.setID(000);
    maintenance.setType(MAINTENANCE);
    maintenance.setID(001);
}

//a helper function to test out our code
/*void test(){
}*/

int main(){
    Test tester;
    if(TEST){
        tester.test();
    }else{
        login();
        userSession();
    }
}

