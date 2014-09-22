#include<stdio.h>
#include<forward_list>
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
    string type;
    
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
    
    string getType(){
    	if(type=="chequing" || type=="savings")
    		return type;
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


class User{
	int type;
	int userID;
    bool manager;
    bool maintenance;
    bool customer;
    
public:
    //constructor
    User(){
        
    }
    
    //overloaded constructor
    User(int givenType, int givenID){
        try{
          setType(givenType);
        }catch(string message){
            throw message;
        }
        setID(givenID);
    }
    
    //getter for type
    int getType(){
        if (manager == true && maintenance == false && customer == false) {
            return MANAGER;
        }else if(manager == false && maintenance == true && customer == false){
            return MAINTENANCE;
        }else if(manager == false && maintenance == false && customer == true){
            return CUSTOMER;
        }else{
            throw "userType is set to an invalid value";
        }
    }
    
    //getter for ID
    int getID(){
        return userID;
    }
    
    //setter for type
    void setType(int givenType){
        if (givenType > 002) {
            throw "Attempted to set UserType to an invalid type.\n";
        } else {
            if (givenType == MANAGER) {
                manager = true;
                maintenance = false;
                customer = false;
            }else if(givenType == MAINTENANCE){
                manager = false;
                maintenance = true;
                customer =false;
            }else{
                manager = false;
                maintenance =false;
                customer = true;
            }
        }
    }
    
    //setter for ID
    void setID(int givenID){
        userID = givenID;
    }
    
    //method to see if the user is a manager
    bool isManager(){
        return manager;
    }
    
    //method to see if they user is maintenance
    bool isMaintenance(){
        return maintenance;
    }
    
    //method to see if the user is a customer
    bool isCustomer(){
        return customer;
    }
    
}currentUser, manager, maintenance;


class Customer: public User{
	public:
		Account savings;
	    Chequing chequing;
}currentCustomer;

//declaring customer data structure
forward_list<Customer> customerList;

/*public:
    //function to see whether the customer has a savings account
    bool hasSavings(){
        return savings.isOpen();
    }
    
    //function to see whether the customer has a chequings account
    bool hasChequing(){
        return chequing.isOpen();
    }
  
};*/

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
	*/
bool withdraw(Account act){
	//string value;
	double value;
	// null checks	
	cout << "Please enter a value to withdraw\n";
	cin >> value;
	//val = value;

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
/*
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

bool deposit(Account act){
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

bool checkAccountStatus(Account act){
	if(act.isOpen()){
		cout << "Opening chequing account.\n";
		return true;
	}else{
		cout << "Chequing account is not open.\n";
		cout << "Please open a chequing account before proceeding.\n";
	}
}

void openAccount(){
	string command;
	string cheqAct = "chequing";
	string savingsAct = "savings";
	cout << "Please choose what account type you want to open('chequing' or 'savings')\n";
	cin >> command;
	
	if(command.compare(cheqAct) == 0){
		if(!currentCustomer.chequing.isOpen()){
			cout << "Chequing account is now open.\n";
			currentCustomer.chequing.open();
		}else{
			cout << "Savings account is already open.\n";
		}
	}else if(command.compare(savingsAct) == 0){
		if(!currentCustomer.savings.isOpen()){
			cout << "Savings account is now open.\n";
			currentCustomer.savings.open();
		}else{
			cout << "Savings account is already open.\n";
		}
	}
}

void closeAccount(){	
}

Account selectAccount(){
	string command;
	string cheqAct = "chequing";
	string savingsAct = "savings";
	while(true){
		cout << "Please select an account type ('chequing' or 'savings')\n";
		cin >> command;
	
		if(command.compare(cheqAct) == 0){
			//if(checkAccountStatus(currentCustomer.chequing)){
				return currentCustomer.chequing;
			//}
		}else if(command.compare(savingsAct) == 0){
			//if(checkAccountStatus(currentCustomer.savings)){
				return currentCustomer.savings;
			//}
		}
	}
}

void selectTransferAccounts(){
	string command;
	string cheqAct = "chequing";
	string savingsAct = "savings";
	
	cout << "Please enter the source account type ('chequing' or 'savings')\n";
	cin >> command;
	if(command.compare(cheqAct) == 0){
		cout << "Source: chequing account. \n";
		cout << "Destination: savings account. \n";
		//Transfer(currentUser.getChequing(),currentUser.getSavings())
	}else if(command.compare(savingsAct) == 0){
		cout << "Source: savings account. n";
		cout << "Destination: chequing account. \n";
		//Transfer(currentUser.getSavings(),currentUser.getChequing())
		Transfer(currentCustomer.savings,currentCustomer.chequing);
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
			//cout << currentCustomer.chequing << "\n";
		}else if(command.compare(savingsAccount) == 0){
			//cout << currentCustomer.savings << "\n";
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
void test(){
    
}

int main(){
    if(TEST){
        test();
    }else{
        login();
        userSession();
    }
}

