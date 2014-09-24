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

    //setter for the balance
    void setAmount(double givenAmt){
        amount = givenAmt;
    }

    void addAmount(double input){
        amount =+ input;
        cout << "\nYour new " << type << " account balance is: $" << amount << ".\n";
    }

    //a function to open a given account
    void open(){
        opened = true;
    }

    //function to close an account and clear it
    void close(){
        if(amount == 0){
            cout << "Closing " << type << " account.\n";
            opened = false;
        }else{
            cout << "Cannot close account, please withdraw all funds before closing.\n";
        }
    }

    string getType(){
    	if(type=="chequing" || type=="savings")
    		return type;
    }

    void setType(string setString){
        type = setString;
    }


    void getStatus(){
        if(type=="chequing"){
            cout << "\nAccount: " << type << "\n";
            if(isOpen()){
                cout << "Status: open. \n";
                cout << "Value: $" << amount << "\n";
            }else{
                cout << "Status: closed. \n";
                cout << "No Value.\n";
            }
        }else if(type=="savings"){
            cout << "\nAccount: " << type << "\n";
            if(isOpen()){
                cout << "Status: open. \n";
                cout << "Value: $" << amount << "\n";
            }else{
                cout << "Status: closed. \n";
                cout << "No Value.\n";
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
