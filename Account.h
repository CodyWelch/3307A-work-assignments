//#ifndef ACCOUNT_H
//#define ACCOUNT_H
using namespace std;


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

    void getStatus(){
        if(type=="chequing"){
            cout << "Account: " << type << "\n";
            cout << getType();
            if(isOpen()){
                cout << "Value: $" << getAmount() << "\n";
                cout << "Account is open. \n";
            }else{
                cout << "Account is closed. \n";
            }
        }else if(type=="savings"){
            cout << "Account: " << type << "\n";
            cout << getType();
            if(isOpen()){
                cout << "Value: $" << getAmount() << "\n";
                cout << "Account is open. \n";
            }else{
                cout << "Account is closed. \n";
            }
        }else{
            cout << "No account type yet.\n";
        }
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

//#endif // ACCOUNT_H
