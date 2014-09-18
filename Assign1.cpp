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
bool loggedIn;

//the base class Account used for modeling different accounts
class Account{
	bool opened;
    double amount;
    
public:
    //constructor
    Account(){
        amount = 0;
        opened = false;
    }
    
    //function to check if the account is open
    bool isOpen(){
        if(opened){
            return true;
        }else{
            return false;
        }
    }
    
    //getter for the current balance
    double getAmount(){
        return amount;
    }
    
    //setter for teh balance
    void setAmount(double givenAmt){
        amount = givenAmt;
    }
    
    //a function to open a given account
    void open(){
        opened = true;
    }
    
    //function to close an account and clear it
    void close(){
        opened = false;
        amount = 0;
    }

};

//the subclass Chequing
class Chequing : public Account{
    double limit;
    double fine;
    
public:
    //default constructor
    Chequing(){
        limit = 1000.0;
        fine = 2.0;
    }
    
    //overloaded constructor for setting a limit and fine too
    Chequing(double givenLim, double givenFine){
        limit = givenLim;
        fine = givenFine;
    }
    
    //getter for limit
    double getLimit(){
        return limit;
    }
    
    //getter for fine
    double getFine(){
        return fine;
    }
    
    //setter for limit
    void setLimit(double givenLim){
        limit = givenLim;
    }
    
    //setter for the fine
    void setFine(double givenFine){
        fine = givenFine;
    }
};

//the UserType class used for denoting a user's type
class UserType{
    //the three bools used for determining which type the user is
	bool manager;
    bool maintenace;
    bool customer;
    
    public:
    //basic constructor
    UserType(){
        manager = false;
        maintenace = false;
        customer = false;
    }
    
    //overloaded constructor
    UserType(int givenType){
        if (givenType > 002) {
            throw "Attempted to create a UserType with an invalid type value.\n";
        } else {
            if (givenType == MANAGER) {
                manager = true;
                maintenace = false;
                customer = false;
            }else if(givenType == MAINTENANCE){
                manager = false;
                maintenace = true;
                customer =false;
            }else{
                manager = false;
                maintenace =false;
                customer = true;
            }
        }

    }
    
    //setters
    void setType(int givenType){
        if (givenType > 002) {
            throw "Attempted to set UserType to an invalid type.\n";
        } else {
            if (givenType == MANAGER) {
                manager = true;
                maintenace = false;
                customer = false;
            }else if(givenType == MAINTENANCE){
                manager = false;
                maintenace = true;
                customer =false;
            }else{
                manager = false;
                maintenace =false;
                customer = true;
            }
        }
    }
    
    //getter
    int getType(){
        if (manager == true && maintenace == false && customer == false) {
            return MANAGER;
        }else if(manager == false && maintenace == true && customer == false){
            return MAINTENANCE;
        }else if(manager == false && maintenace == false && customer == true){
            return CUSTOMER;
        }else{
            throw "userType is set to an invalid value";
        }
    }
    
    
    
    
};

class User{
	UserType type;
	int userID;
};


class Customer: public User{
	Account savings;
    Chequing chequing;
    
}currentCustomer;




//if(User.UserType.Manager){}

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
	// savings account/chequings account only his/her account permissions
	// can use multiple operations within one session
	int id;
};
*/
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
*/

bool deposit(/*Account act*/){
	//string value;
	float value;
	//value = null;
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
/*
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


void userSession(){
	// Initialize
	string command = "";
	string moneyIn = "deposit";
	//int moneyInAmt = 0;
	string moneyOut = "withdraw";
	//int moneyOutAmt = 0; 
		
	loggedIn = true;
	// User interface
	while(loggedIn){
		cout << "Please enter a command (help for cmd list)\n";
		cin >> command;
		
		// Deposit & Withdraw
		if(command.compare(moneyIn) == 0){
			
			deposit(/*currentCustomer.act*/);
		}/*else if(command.compare(moneyOut) == 0){
			cin >> command;
			withdraw(user, moneyOutAmt);
		}else if(command.compare(transfer) == 0){
			transfer();	
		}else if(command.compare(transfer) == 0){
			transfer();	
		}else if{command.compare(help)
			cout << "'withdraw' to take money out your account";
			cout << "'deposit' to put money into your account";
			cout << "'manage' to open or close an new account";
		}*/
	}
}

int main(){
	login();
	userSession();
}

