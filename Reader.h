#include<iostream>
#include<fstream>
using namespace std;

class Reader
{
    ifstream readFile;
    string readData;
    public:
        Reader(){
            readData = "";
        }

        bool activateReader(){
            cout << "Reader activated\n.";
            //return true;
            readFile.open("testfile.txt");
            int i = 0;
            while(!readFile.eof()){
                readFile >> readData;
            }
            return false;
        }
};
