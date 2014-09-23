#include<iostream>
#include<fstream>
using namespace std;

class eTrace
{
    string toBeWritten;
    public:
    eTrace(){
        toBeWritten = "";

    }
    void addToFile(string newData){
        cout << "Concatenating toBeWritten\n";
        toBeWritten += newData;
    }

    void writeFile(){
        cout << "writing to file\n";
        ofstream myfile;
        myfile.open ("LogFile.txt");
        myfile << toBeWritten;
        myfile.close();
    }
};
