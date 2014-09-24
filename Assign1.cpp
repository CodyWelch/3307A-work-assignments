#include<stdio.h>
#include<forward_list>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "account.h"
#include "User.h"
#include "CustomerList.h"
#include "Test.h"
#include "eTrace.h"
#include<limits>
using namespace std;

//constant variable used to turn on/off testing mode
#define TEST 0

#define cheqAccount     "chequing"
#define savingsAccount  "savings"
#define moneyIn         "deposit"
#define moneyOut        "withdraw"
#define help            "help"
#define logout          "logout"
//string help = "help";
//string logout = "logout";

//global user variables, so we can always know what user is currently active, userType will be one of our three constants, userID will be their actual ID
int currentUserType;
int currentUserID;
bool loggedIn;
string command;

Account tempAccount;
eTrace traceObj;
bool traceActive;
customerList list;

void execTrace(string trace){
    if(traceActive){
        time_t currentTime = time(0);
        char* currentTimeString = ctime(&currentTime);
        traceObj.addToFile(trace,currentTimeString);
    }
}

void traceSwitch(bool onOff){
    if(onOff){
        traceActive = true;
        execTrace("Trace switched on.");
    }else{
        cout << "\nTurning trace off.\n";
        execTrace("Trace switched off. ");
        traceActive = false;
        traceObj.writeFile();
    }
}

bool checkAccountHasValue(Account act){
    if(act.getAmount() > 0){
        return true;
    }else{
        return false;
    }
    cout << "Invalid account.\n";
}

bool checkAccountStatus(Account act){
	if(act.isOpen()){
		return true;
	}else{
		return false;
	}
}

bool checkAccountsOpen(){
    if(currentCustomer.getChequing()->isOpen() || currentCustomer.getSavings()->isOpen()){
        return true;
    }else{
        cout << "No accounts open.\n";
        cout << "Please open an account before performing an account action.\n";
        return false;
    }
}

bool checkBothAccountsOpen(){
    if(currentCustomer.getChequing()->isOpen() && currentCustomer.getSavings()->isOpen()){
        return true;
    }else{
        cout << "\nTransfer failed.\n";
        cout << "Both accounts must be open before transferring funds.\n";

        // Trace Update   ****************************************
        execTrace("Transfer Failed, at least one account is closed.");

        return false;
    }
}

Account selectAccount(){
    while(true){
        cout << "\nPlease select an account type ('chequing' or 'savings')\n";
        if(currentCustomer.getChequing()->isOpen()){
            cout << "Chequing account is open.\n";
        }
        if(currentCustomer.getSavings()->isOpen()){
            cout << "Savings account is open.\n";
        }
        cin >> command;
        if(command.compare(cheqAccount) == 0){
            if(checkAccountStatus(*currentCustomer.getChequing())){
                return *currentCustomer.getChequing();
                }
        }else if(command.compare(savingsAccount) == 0){
            if(checkAccountStatus(*currentCustomer.getSavings())){
                return *currentCustomer.getSavings();
            }
        }
    }
}

bool withdraw(Account act){
	double value;
	cout << "\nPlease enter a value to withdraw, ('0' to cancel)\n";
	cin >> value;
	if(value < 0 || value == 0){
        return false;

        // Trace Update   ****************************************
        execTrace("Cancelled Withdrawal");
	}
    if(act.getAmount() - value < 0.0 ){
		cout << "Insufficient funds\n";
		cout << "You have only $" << act.getAmount() << "in your " << act.getType() << " account.\n";

		// Trace Update   ****************************************
		execTrace("Withdrawl cancelled, not enough funds.");
		return false;
	}else{
		act.setAmount(act.getAmount() - value);

        // Trace Update   ****************************************
        string loginData;
        stringstream convert;
        convert << "Withdrew: " << value << " from " << act.getType() << " account.";
        loginData = convert.str();
        execTrace(loginData);
		return true;
	}
}

bool deposit(Account act){
	double value;
		cout << "\nPlease enter a value to deposit\n";
		cout << "Enter 0 to cancel.\n";
		cin >> value;
		if(value < 0){
			cout << "Cannot deposit a negative value.\n";
		}else if(value > 0){
			cout << "Depositing: $" << value << ".\n";
			act.addAmount(value);

            // Trace Update   ****************************************
            string loginData;
            stringstream convert;
            convert << "Deposited: $" << value << " into " << act.getType() << " account.";
            loginData = convert.str();
            execTrace(loginData);
			return true;
		}
		// Trace Update   ****************************************
		execTrace("Deposit cancelled.");
	return false;
}

bool transferWithdraw(Account act){
	double value;
	cout << "\nPlease enter a value to withdraw for the transfer\n";
	cin >> value;
    if(act.getAmount() - value < 0.0 ){
		cout << "Insufficient funds\n";
		cout << "You have only $" << act.getAmount() << "in your " << act.getType() << " account.\n";

		// Trace Update   ****************************************
		execTrace("Transfer withdraw failed");
		return false;
	}else{
		//act.amount -= value;
		act.setAmount(act.getAmount() - value);

        // Trace Update   ****************************************
        string loginData;
        stringstream convert;
        convert << "Withdrew: " << value << " from " << act.getType() << " account for transfer.";
        loginData = convert.str();
        execTrace(loginData);

		return true;
	}
}

bool transferDeposit(Account destination, int value){
    cout << "Transferring: $" << value << " to " << destination.getType() << " .\n";
    destination.addAmount(value);

    // Trace Update   ****************************************
    string loginData;
    stringstream convert;
    convert << "Deposited: " << value << " from " << destination.getType() << " account from transfer.";
    loginData = convert.str();
    execTrace(loginData);

    return true;
}

// Transfer funds between accounts
bool Transfer(Account source,Account destination){
	int transferValue;
	while(true){
        cout << "Note, funds will be lost if program cancelled before deposit complete.";
        cin >> transferValue;

        if(!transferWithdraw(source)){
            return false;
        }
        if(!transferDeposit(destination,transferValue)){
           return false;
        }

        cout << "Successfully transferred funds!";
        cout << "Your new balances are: /n";
        cout << source.getType()      << " " << source.getAmount()      << " /n";
        cout << destination.getType() << " " << destination.getAmount() << " /n";

        // Trace Update   ****************************************
        execTrace("Completed Transfer.");

        return true;
    }
}

void selectTransferAccounts(){
    cout << "\nEnter source account.\n";
    Account temp = selectAccount();
	if((temp.getType()).compare(cheqAccount) == 0){
		cout << "Source: chequing account. \n";
		cout << "Destination: savings account. \n";
		//Transfer(currentUser.getChequing(),currentUser.getSavings())
		Transfer(*currentCustomer.getChequing(),*currentCustomer.getSavings());
	}else if((temp.getType()).compare(savingsAccount) == 0){
		cout << "Source: savings account. n";
		cout << "Destination: chequing account. \n";
		//Transfer(currentUser.getSavings(),currentUser.getChequing())
		Transfer(*currentCustomer.getSavings(),*currentCustomer.getChequing());
	}

}

void closeAccount(){
    tempAccount = selectAccount();
    tempAccount.close();

    // Trace Update   ****************************************
    string loginData;
    stringstream convert;
    convert << "Account: " << tempAccount.getType()<< " was closed.";
    loginData = convert.str();
    execTrace(loginData);
}

void openAccount(){
	cout << "\nPlease choose what account type you want to open('chequing' or 'savings')\n";
	cin >> command;
	if(command.compare(cheqAccount) == 0){
		//if(!(currentCustomer.chequing.isOpen()){
		if(!currentCustomer.getChequing()->isOpen()){
			cout << "Chequing account is now open.\n";
			currentCustomer.getChequing()->open();

			// Trace Update   ****************************************
			execTrace("Opened chequing account.");
		}else{
			cout << "Savings account is already open.\n";

			// Trace Update   ****************************************
			execTrace("Failed to open savings account,account already open.");
		}
	}else if(command.compare(savingsAccount) == 0){
		if(!currentCustomer.getSavings()->isOpen()){
			cout << "Savings account is now open.\n";
			currentCustomer.getSavings()->open();

			// Trace Update   ****************************************
			execTrace("Opened Savings account.");
		}else{
			cout << "Savings account is already open.\n";

			// Trace Update   ****************************************
			execTrace("Failed to open savings account, account already open.");
		}
	}
}

bool login(){

	// Variables for login
    int inputId;
    int minNum;
    int maxNum;
    int attempts = 0;
	bool logged = false;
	string loginData;
    minNum = 0;
    maxNum = 1000;

    // Login loop
    while (!logged && attempts < 3) {
        //prompt user, get ID input
        cout << "Please enter your id.\n";
        cout << "(customer 1-100,manager 777, maintenance 999)\n";
        while(!(cin >> inputId)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(inputId > minNum && inputId < maxNum){
                // On Successful login set id and type
                // set logged in check to true
            if(list.contains(inputId)){
                cout << "Welcome, user.\n";
                currentUserType = CUSTOMER;
                currentUserID = inputId;
                list.find(inputId);
                logged = true;

                // Trace Update   ****************************************
                stringstream convert;
                convert << "Customer with userId:" << inputId << " logged in.";
                loginData = convert.str();
                execTrace(loginData);

                return true;
            }
            else if (inputId == MANAGER) {
                cout << "Welcome, manager.\n";
                currentUserType = MANAGER;
                currentUserID = inputId;
                logged  = true;

                // Trace Update   ****************************************
                stringstream convert;
                convert << "Manager with userId:" << inputId << " logged in.";
                loginData = convert.str();
                execTrace(loginData);

                return true;
            }else if(inputId == MAINTENANCE){
                cout << "Welcome, maintenance.\n";
                cout << "\n Note* trace data will be stored in '~/LogFile.txt'.\n";
                currentUserType = MAINTENANCE;
                currentUserID = inputId;
                logged  = true;

                // Trace Update   ****************************************
                stringstream convert;
                convert << "Maintenance with userId:" << inputId << " logged in.";
                loginData = convert.str();
                execTrace(loginData);

                return true;
            }

        //if id matches no roles, output error message and record another login attempt
        }else{
            cout << "Error, invalid ID given.\n";

            // Trace Update   ****************************************
            execTrace("Failed log in attempt.");

            attempts++;
            cin.clear();
        }
    }
    cout << "\nToo many login attempts. Resetting. \n";
    return false;
}

void userSession(){
    // Command check variables
	string transfer = "transfer";
	string status = "status";
	string open = "open";
	string close = "close";

    // temporary account for transfer function
	Account currentAccount;

    // while loggedIn is true, Main User Interface is available to currentUser
	loggedIn = true;

	// Main User Interface
	while(loggedIn){
		cout << "\nPlease enter a valid command (type 'help' for cmd list)\n";
		cin >> command;

		// Access deposit function
		if(command.compare(moneyIn) == 0){
            if(checkAccountsOpen()){
                currentAccount = selectAccount();
                if(checkAccountStatus(currentAccount)){
                    deposit(currentAccount);
                }
            }
        // Access withdraw function
		}else if(command.compare(moneyOut) == 0){
		    if(checkAccountsOpen()){
                currentAccount = selectAccount();
                if(checkAccountStatus(currentAccount)){
                    withdraw(currentAccount);
                }
		    }
        // Access transfer function
		}else if(command.compare(transfer) == 0){
		    if(checkBothAccountsOpen()){
                selectTransferAccounts();
		    }
        // Access openfunction
		}else if(command.compare(open) == 0){
				openAccount();
		// Access close function
		}else if(command.compare(close) == 0){
				closeAccount();
		// Access compare function
		}else if(command.compare(status) == 0){
			//*currentCustomer.getAccountStatus();
			execTrace("Printed account status.");
		// List available commands
		}else if(command.compare(help) == 0){
			cout << "'withdraw' to take money out your account.\n";
			cout << "'deposit' to put money into your account.\n";
			cout << "'transfer' to move a sum from one account to another.\n";
			cout << "'open' to open a new account.\n";
			cout << "'close' to close a new account.\n";
			cout << "'status' to view account balances and account open/close status.\n";
            cout << "'logout' to end this usersession.\n";
        // Logout of current user session
		}else if(command.compare(logout) == 0){
		    cout << "\nLogging out.";
		    loggedIn = false;
        // Clear invalid input
		}else{
		    cin.clear();
            cout << "The command was invalid.\n";
            cout << "Type 'help' for command list.\n";
		}
	}
}

//a function for all setup operations
void setUp(){
    //create and prepare the manager and maintenance users
    manager.setType(MANAGER);
    manager.setID(777);
    maintenance.setType(MAINTENANCE);
    maintenance.setID(999);
}

void managerSession(){
    loggedIn = true;
    while(loggedIn){
        cout << "\nPlease enter a valid command (type 'help' for cmd list)\n";
        cin >> command;
    }
    // Transfer accounts
    // open/close accounts

}
void maintenanceSession(){
    string traceOn,traceOff;
    traceOn = "traceon";
    traceOff = "traceoff";
    loggedIn = true;
    while(loggedIn){
        cout << "\nPlease enter a valid command (type 'help' for cmd list)\n";
        cin >> command;
        if(command.compare(traceOn)){
            traceSwitch(true);
        }else if(command.compare(traceOff)){
            traceSwitch(false);
        }else if(command.compare(help)){
            cout << "'logout' to end this usersession.\n";
            cout << "'traceon' to switch trace on.\n";
            cout << "'traceoff' to switch trace off.\n";
        }else if(command.compare(logout) == 0){
            cout << "\nLogging out.\n";
            loggedIn = false;
        }
    }
}

void populateDataBaseDemo(){
    int type;
    int id;
    Customer dude(10);

    // Populate Customers
    type = 1;
    id = 1;
    while(id!=100){
        customers[id].setID(id);
        dude = customers[id];
        list.insert(customers[id]);
        id++;
    }

    // Populate Managers
    type = 3;
    id = 777;
    User managePerson(2,777);

    // Populate Maintenance
    type = 3;
    id = 999;
    User maintenancePerson;
}

int main(){
    traceActive = false;
    Test tester;
    if(TEST){
        tester.test();
    }
    populateDataBaseDemo();
    while(true){
        if(login()){
            if(currentUserType==CUSTOMER){
                userSession();
            }else if(currentUserType==MANAGER){
                managerSession();
            }else if(currentUserType==MAINTENANCE){
                maintenanceSession();
            }
        }
    }
}

