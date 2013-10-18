#include "File.h"

File::File(string fileName)
{
    errorOpenTxt = "Error no file open";
    errorEofTxt = "EOF";
    errorLog = false;

    fileOpen(fileName);
}

/*
 * this will open a file with a string as the file name
 */
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


/*
 * will check if file is open if its not then
 * it will not do anything
 * if it is then it will close the file
 */
void File::fileClose()
{
    if(fin.is_open())
        fin.close();
}

/*
 * this will get a line of text from a file
 */
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

/*
 * Checks for the End Of File
 */
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

/*
 * Gets text from a file until it reaches a delimiter
 */
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

/*
 * allow us to toggle error messages
 */
void File::setErrorLog(bool toggle)
{
    errorLog = toggle;
}

/*
 * Destructor will call fileClose method;
 */
File::~File()
{
    fileClose();
}
