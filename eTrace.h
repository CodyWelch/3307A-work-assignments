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
    void addToFile(string newData,string timeData){
        cout << "Concatenating " << newData << " \n";
        toBeWritten += newData;
        toBeWritten += " ";
        toBeWritten += timeData;
        toBeWritten += "\n";
    }

    void writeFile(){
        cout << "writing to file\n";
        ofstream myfile;
        myfile.open ("LogFile.txt");
        myfile << toBeWritten;
        myfile.close();
    }
};
