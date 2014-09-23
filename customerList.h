//a class for storing our customer list in
#define TEST 1
class customerList{
    forward_list<Customer> list;

public:
    //method for printing all contents of the class
    void print(){
        forward_list<Customer>::iterator startIter = list.begin();
        forward_list<Customer>::iterator endIter = list.end();
        Customer temp;
        cout << "Customer ID\tChequing\tSavings\n";

        for (; startIter!=endIter; ++startIter) {
            temp = *startIter;
            cout << temp.getID() << "\t\t" << temp.getChequing()->getAmount() << "\t\t" << temp.getSavings()->getAmount() << "\n";
        }
    }

    //method for checking whether a Customer with a given ID already exists in the database
    bool contains(int id){
        forward_list<Customer>::iterator startIter = list.begin();
        forward_list<Customer>::iterator endIter = list.end();
        Customer temp;

        for (; startIter != endIter; ++startIter) {
            temp = *startIter;

            if(temp.getID() == id){
                return true;
            }
        }

        return false;
    }

    //method for inserting new Customers into the list
    void insert(Customer cust){
        if(contains(cust.getID())){
            throw "Exception: List already contains a Customer with that ID\n";
        }else{
            list.push_front(cust);
        }
    }

    //method for finding a particular Customer
    Customer * find(int id){
        if (!contains(id)) {
            throw "Exception: There is no customer with the given ID\n";
        } else {
            forward_list<Customer>::iterator startIter = list.begin();
            forward_list<Customer>::iterator endIter = list.end();
            Customer * itemAddress;

            for (; startIter != endIter; ++startIter) {
                itemAddress = &*startIter;

                if(itemAddress->getID() == id){
                    return itemAddress;
                }
            }

            throw "Exception: Error: Customer not found\n";

        }
    }

    //method for removing a particular customer
    void remove(int id){
        if (!contains(id)) {
            throw "Exception: Attempted to remove a non-existent customer\n";
        } else {
            //output for testing
            if(TEST){
                cout << "Target id is: " << id << "\n";
            }
            //create the iterators used to step through the code
            forward_list<Customer>::iterator iter1 = list.before_begin();
            forward_list<Customer>::iterator iter2 = list.begin();
            forward_list<Customer>::iterator endIter = list.end();

            //create boolean to indicate success
            bool found = false;

            for(; iter2 != endIter; iter1 = iter2, ++iter2 ){
                //output for testing
                if(TEST){
                    cout << "Iterator points to: " << iter2->getID() << "\n";
                }
                //if the target is found, remove it
                if (iter2->getID()==id) {
                    list.erase_after(iter1);
                    found = true;
                    break;
                }
            }

            if(!found){
                throw "Exception: Removal target was not found\n";
            }

        }
    }
};
