#include "File.h"

File::File(string fileName)
{
    errorOpenTxt = "Error no file open";
    errorEofTxt = "EOF";
    errorLog = false;

    fileOpen(fileName);
}

void File::fileOpen(string fileName)
{
    fin.open(fileName.c_str());
    if(!fin.is_open())
    {
        if(errorLog == true)
        cout << errorOpenTxt << endl;
        return;
    }
}
void File::fileClose()
{
    if(fin.is_open())
        fin.close();
}
string File::getStr()
{
    string tempStr = "";
    getline(fin, tempStr);
    if(eof())
    {
        return "nullEOF";
    }
    return tempStr;
}

bool File::eof()
{
    if(!fin)
    {
        if(errorLog == true)
            cout << errorEofTxt << endl;
        return true;
    }

    return false;
}
string File::getStr(char delimiter)
{
    string tempStr = "";
    getline(fin, tempStr, delimiter);

    if(eof())
    {
        return "nullEOF";
    }

    // read rest of line till return
    getStr();

    return tempStr;
}
void File::setErrorLog(bool toggle)
{
    errorLog = toggle;
}
File::~File()
{
    fileClose();
}
