#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{

private:
    ifstream *fin;
    ofstream *fout;
    string readFileName;
    string writeFileName;

public:
    File();
    ~File();
    void setReadFileName(string);
    void setWriteFileName(string);
    string getReadFileName();
    string getWriteFileName();
    string readLine();
    void writeLine(string);
    void writeLine(int);
    void writeLine(bool);
    void readOpen();
    void wrtieOpen();
    void readClose();
    void writeClose();


    /* remaking class since it was just a protoype for
     * console version
     * Old code
     *
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
        */
};
#endif // FILE_H
