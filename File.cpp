#include "File.h"

File::File()
{
    fin = 0;
    fout = 0;
}

void File::setReadFileName(string fileName)
{
    readFileName = fileName;
}

void File::setWriteFileName(string fileName)
{
    writeFileName = fileName;
}

string File::getReadFileName()
{
    return readFileName;
}

string File::getWriteFileName()
{
    return writeFileName;
}

string File::readLine()
{
    string temp;
    getline(*fin,temp);
    return temp;
}

void File::writeLine(string data)
{
    *fout << data << '\n';
}

void File::writeLine(int data)
{
    *fout << data << '\n';
}

void File::writeLine(bool data)
{
    *fout << data << '\n';
}

File::~File()
{
    if(fin != 0)
    {
        delete fin;
        fin = 0;
    }

    if(fout != 0)
    {
        delete fout;
        fout = 0;
    }
}
