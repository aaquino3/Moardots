/*
 * File.h
 *
 *  Created on: Nov 19, 2013
 *  Notes:
 *  + recreated this class because first version was from prototype/ not complete
 *  + currently only overwrites output files / cannot append
 *
 *	description:
 *	Open files to read or write. some methods return int's for error's
 *
 *	errors include:
 *	-1 could not open file
 *	-2 reached end of file or error reading file I need to do this because
 *	   string can't detect End Of File (EOF);
 *
 *  use:
 *  1. create the File object
 *  2. set the file name for reading or writing
 *  3. open the file for reading or writing
 *  4. read or write to file
 *	5. close files or delete object
 *
 *  code example for reading:
 *  File file;
 *	file.setReadFileName("/home/tech/Downloads/CPPWorkspace/FileReader/src/test.txt");
 *	file.setWriteFileName("/home/tech/Downloads/CPPWorkspace/FileReader/src/out.txt");
 *
 *	// print out file locations
 *	cout << "Read file = " << file.getReadFileName() << endl;
 *	cout << "Write file = " << file.getWriteFileName() << endl;
 *
 *	string temp;
 *
 *	if(file.readLine() != 0)
 *		cout << "Error file not open" << endl;
 *	// open file
 *	if(file.openRead() == -1)
 *		cout << "Error opening file" << endl;
 *
 *	if(file.readLine() == 0)
 *		temp = file.getLine();
 *
 *	cout << "line read: " << temp << endl;
 *
 *	// close read file
 *	file.closeRead();
 *
 *	file.openWrite();
 *
 *	file.writeLine("Test");
 *  file.closeWrite();
 *
 */

#ifndef FILE_H_
#define FILE_H_
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;


class File {
	ifstream fin;
	ofstream fout;
	string readFileName;
	string writeFileName;
	string lineRead;

public:
	~File();						// will close open readFile or writeFile
	int openRead();					// opens a read file, returns 0 on success or -1 on fail
	int openWrite();				// opens a write file, returns 0 on success or -1 on fail
	void setReadFileName(string);	// sets the file Name for reading
	void setWriteFileName(string); 	// set the file Name for writing
	string getReadFileName();		// gets the file Name for reading
	string getWriteFileName();		// gets the file Name for writing
	int readLine();					// reads a line returns 0 on success or -1 on file not open / -2 on EOF/error
	string getLine();				// gets the last read string
	int writeLine(string);			// writes a line to the write file, return -1 on fail
	int closeRead();				// closes read file returns -1 on fail
	int closeWrite();				// closes write file return -1 on fail
};

#endif /* FILE_H_ */
