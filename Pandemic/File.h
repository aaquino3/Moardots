#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{
    private:
        ifstream fin;
        string errorOpenTxt;
        string errorEofTxt;
        bool errorLog;
    public:
        File(string);
        ~File();
        void fileOpen(string);
        void fileClose();
        string getStr();
        // will read untill a delimiter character
        string getStr(char);
        void setErrorLog(bool);
        bool eof();
        int countWords();
        string* getWords();
};
#endif // FILE_H
