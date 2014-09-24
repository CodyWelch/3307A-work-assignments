#include<iostream>
#include<fstream>
using namespace std;
class WriteData
{
    string toBeWritten;

    public:
        WriteData(){
            toBeWritten = "";
        }

    void writeOldDataToFile(string old){

    }
     void addUserDataToFile(string newData,string timeData){
        toBeWritten += newData;
        toBeWritten += " ";
        toBeWritten += timeData;
        toBeWritten += "\n";
    }

    void writeUserDataToFile(){
        cout << "Writing to file\n";
        ofstream myfile;
        myfile.open ("UserData.txt");
        myfile << toBeWritten;
        myfile.close();
    }
};
