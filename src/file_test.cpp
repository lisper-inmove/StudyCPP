#include <iostream>
#include <fstream>

using namespace std;

void file_test() {
	fstream file;
	file.open("test.txt", ios::out | ios::binary);
	file << "Hello, World!" << endl;
	file.close();

	ofstream ofile;
	ofile.open("test.txt", ios::out | ios::app);
	ofile.write("name", 4);
}