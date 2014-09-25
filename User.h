#include<iostream>
#include<sstream>

using namespace std;

//constant values used (atm) for testing login
#define MANAGER 777
#define MAINTENANCE 999
#define CUSTOMER 002

class User{
	int type;
	int userID;
    bool manager;
    bool maintenance;
    bool customer;
    string role;
    string idString;

public:
    //constructor
    User(){

    }

    //overloaded constructor
    User(int givenType, int givenID){
        try{
          setType(givenType);
        }catch(char const* message){
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
            throw "Exception: userType is set to an invalid value";
        }
    }

    //getter for ID
    int getID(){
        return userID;
    }

    //setter for type
    void setType(int givenType){
        if (givenType > 002) {
            throw "Exception: Attempted to set UserType to an invalid type.\n";
        } else {
            if (givenType == MANAGER) {
                role = "manager";
                manager = true;
                maintenance = false;
                customer = false;
            }else if(givenType == MAINTENANCE){
                role = "maintenance";
                manager = false;
                maintenance = true;
                customer =false;
            }else{
                role = "customer";
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

    string toString(){
        string mainString;
        ostringstream convert;
        convert << userID;
        mainString = convert.str();
        mainString = role;
        return mainString;
    }
}currentUser, manager, maintenance;

//a class that extends our User class for the purpose of modelling customers
class Customer: public User{
	Account savings;
	Chequing chequing;

public:
	Customer(int ID):User(CUSTOMER, ID){

    }

    Customer(){
        savings.setType("savings");
        cout << "\n";
        chequing.setType("chequing");
    }
	Account *getSavings(){
		Account *acct = &savings;
        return acct;
	}
	Chequing *getChequing(){
		Chequing *cheq = &chequing;
        return cheq;
	}

    void getAccountStatus(){
        savings.getStatus();
        cout << "amount in savings: " << savings.getAmount() << "\n";
        chequing.getStatus();
        cout << "amount in chequing: " <<chequing.getAmount() << "\n";
    }

}currentCustomer,customers[100];
