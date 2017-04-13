#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileModify
{
 private:
 	fstream file_ptr;
 public:
	string file;
	FileModify(const string &fname ):file(fname){}
	void reset();
	string read();
	void write( const string &data );
	void open();
	void close();
};

void FileModify::open()
{
	file_ptr.open(file.c_str(), ios::app);
}

void FileModify::close()
{
	if(file_ptr.good())
		file_ptr.close();
}

void FileModify::reset()
{
	if(file_ptr.good())
	{
		file_ptr.close();
		file_ptr.open(file.c_str(), ios::trunc | ios::in | ios::out);
	}
}

string FileModify::read()
{
	fstream file_out;
	file_out.open(file.c_str());
	string string_read;
	string tmp;
	
	getline(file_out, string_read);
	while(getline(file_out, tmp))
	{
		string_read += '\n';
		string_read += tmp;
	}
	file_out.close();
	return string_read;
	
}

void FileModify::write(const string &data)
{
	file_ptr << data << endl;
}
