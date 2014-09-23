class Test
{
    public:
       //a helper function to test out our code
    void test(){
        cout << "\n" << "Being Tests:\n";

        cout << "\nTesting customer list:";

        //test customer insertion and printing
        customerList list;
        cout << "\nList created.\n";

        cout << "\nTesting Customer creation:";
        Customer c1(123);
        Customer c2(124);
        Customer c3(125);

        cout << "\nCustomers created\n";

        cout<< "\nTesting Customer insertion:";
        list.insert(c1);
        list.insert(c2);
        list.insert(c3);

        cout << "\nCustomers inserted";

        cout<< "\nAttempting to find the three inserted customers:";
        cout << "\nCustomer 1: " << list.contains(123);

        cout << "\nCustomer 2: " << list.contains(124);

        cout << "\nCustomer 3: " << list.contains(125) << "\n";

        cout << "\nTesting print() method:\nPrint all Customers:\n";
        list.print();


        cout << "\nTesting editing customers:";
        //test the find method and its methodology
        try {
            Customer * c1Place = list.find(123);
            c1Place->setID(555);
            cout << "\nEdited customer.\nPrint all Customers to check for changes:\n";
            list.print();
        } catch (char const* message) {
            cout << message;
        }

        cout << "\nTesting removal:\n";
        try{
            list.remove(555);
            cout << "Remove method called.\nPrint all Cusomters to check for changes:\n";
            list.print();
        }catch(char const* message){
            cout << message;
        }

        cout << "\nTest looking for a non-existant customer:\nlist.contains() value: " << list.contains(123);
        cout << "\nTry finding it:\n";
        try {
            list.find(123);
        } catch (char const* message) {
            cout << message;
        }

        cout << "\nTest removing a non-existant customer:\nlist.contains() value: " << list.contains(123);
        cout << "\nTry removing it:\n";
        try {
            list.remove(123);
        } catch (char const* message) {
            cout << message;
        }

        cout << "\nTest inserting an already existing customer:\nlist.contains() value: " << list.contains(124);
        cout<<"\nTry inserting a duplicate:\n";
        try {
            list.insert(124);
        } catch (char const* message) {
            cout << message;
        }
        cout << "\nEnd of tests\n";

    }

};
