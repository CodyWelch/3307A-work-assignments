#include<stdio.h>

#include<string>
#include<iostream>
using namespace std;

//constant values used (atm) for testing login
#define MANAGER 000
#define MAINTENANCE 001
#define CUSTOMER 002

//constant variable used to turn on/off testing mode
#define TEST 1

//global user variables, so we can always know what user is currently active, userType will be one of our three constants, userID will be their actual ID
int currentUserType;
int currentUserID;


	/*
	*
	*Classes
	*
	
class Manager{
	//open & close accounts
	// see view critical details or 1 or all customers
	// -in a formatted display
	int id;
};

class Customer{
	// manageable # (Ex: 100)
	// must has either or both a 
	// savings account/chequings account
	// -only his/her account permissions
	// can use multiple operations within
	// -one session
	int id;
};

class Account{
	bool open;
	bool close;
	public:
		float amount;
};


	/*
	*
	* Helper Functions
	*
	
bool withdraw(Account act){
	string value;
	float val;
	// null checks
	
	cout << "Please enter a value to withdraw";
	cin >> value;
	val = value;

	if(value.compare("back")){
		cout << "Cancelling Withdrawal.";
		return false;
	} else if(act.amount - ()value < 0 ){
		cout << "Insufficient funds";
		return false;
	}else{
		act.amount -= value;
		return true;
	}	
	// flag for success
}

// overload for transfering funds
float withdraw(Account act,float value){
	
	cout << "Please enter a value to transfer";
	cin >> value;
	while(true){
		if(value.compare("back")){
			cout << "Cancelling Withdrawal for transfer."
			return null;
		} else if(act.amount - value < 0 ){
			cout << "Insufficient funds";
		}else{
			act.amount -= value;
			return value;
		}	
	}
}

bool deposit(Account act, int value){
	string value;
	value = null;
	while(value == null){
		cout << "Please enter a value to deposit";
		cin >> value;
		if(value.compare("back")){
			return false;
		}else if(value < 0){
			cout << "Cannot deposit a negative value";
		}else if(value > 0){
			act.amount += value;
			return true;	
		}
	}
	return false;
}

bool transfer(account act){
	account toWithdraw;
	account toDeposit;
	int transferValue;
	
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
	cout << toDeposit.name + " " + toDeposit.value + " /n";
	return true;	
}
	
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

/*
function userSession(customer user){
	// Initialize
	string command = "";
	string moneyIn = "deposit";
	//int moneyInAmt = 0;
	string moneyOut = "withdraw";
	//int moneyOutAmt = 0; 
		
	// User interface
	cout << "Please enter a command (help for cmd list)";
	cin >> command;
	
	// Deposit & Withdraw
	// Could use a switch, or more efficient route...
	if(command.compare(moneyIn) = 0){
		deposit(user);
	}else if(command.compare(moneyOut) = 0){
		cin >> command;
		withdraw(user, moneyOutAmt);
	}else if(command.compare(transfer) = 0){
		transfer();	
	}else if(command.compare(transfer) = 0){
		transfer();	
	}else if{command.compare(help)
		cout << "'withdraw' to take money out your account";
		cout << "'deposit' to put money into your account";
		cout << "'manage' to open or close an new account";
	}
}*/

int main(){
	login();
	//userSession();
}

