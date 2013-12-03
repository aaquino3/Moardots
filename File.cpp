/*
 * File.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: tech
 */

#include "File.h"



int File::openRead()
{
	fin.open(readFileName.c_str());

	if(fin.is_open())
		return 0;

	return -1;
}


int File::openWrite()
{
	fout.open(writeFileName.c_str());

	// check if file opened
	if(fout.is_open())
		return 0;

	return -1;
}

void File::setReadFileName(string readFileName)
{
	this->readFileName = readFileName;
}

void File::setWriteFileName(string writeFileName)
{
	this->writeFileName = writeFileName;
}

string File::getReadFileName()
{
	return readFileName;
}

string File::getWriteFileName()
{
	return writeFileName;
}

int File::readLine()
{
	// check to see if file is open
	if(fin.is_open() == false)
		return -1;

	string temp = "";

	getline(fin, temp);

	// check if getline() read something will return 0 if it did
	if(fin)
	{
		lineRead = temp;
		return 0;
	}

	// if it read EOF(end of file) or some other read error it will return -1
	return -1;
}

string File::getLine()
{
	return lineRead;
}

int File::writeLine(string line)
{
	// checks to see if file is open
	if(fout.is_open() == false)
		return -1;

	fout << line << endl;

	return 0;
}

int File::closeRead()
{
	// check if file is open
	if(fin.is_open() == true)
		fin.close();

	// check again to see if fin is closed
	if(fin.is_open() == false)
		return 0;

	// return -1 on fail
	return -1;
}

int File::closeWrite()
{
	// check if file is open
	if(fout.is_open() == true)
		fout.close();

	// check again if fout is closed
	if(fout.is_open() == false)
		return 0;

	// return -1 on fail
	return -1;
}

File::~File()
{

	// check if any file is open if it is then close them

	if(fin.is_open() == true)
		closeRead();

	if(fout.is_open() == true)
		closeWrite();
}
