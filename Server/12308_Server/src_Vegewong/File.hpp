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
    FileModify(const string &fname) : file(fname){}
    ~FileModify()
    {
        if (!file_ptr.is_open())
            file_ptr.close();
    }

    void reset();
    string read(int &record, int length);
    void write(const string &data);
    void open();
    void close();
};



void FileModify::open()
{
    if (!file_ptr.is_open())
        file_ptr.open(file.c_str(), ios::app | ios::binary);
}

void FileModify::close()
{
    if (file_ptr.is_open())
	    file_ptr.close();
}

void FileModify::reset()
{
    if (file_ptr.is_open())
        file_ptr.close();
    file_ptr.open(file.c_str(), ios::trunc | ios::in | ios::out | ios::binary);
}

string FileModify::read(int &record, int length)
{ 
    file_ptr.flush();
    char *tmp;
    file_ptr.seekg(0, ios::end);
    int readlength = file_ptr.tellg();
    file_ptr.seekg(ios::beg);

    if(length == -1 || length > readlength)
    {
        tmp = new char [readlength];
        file_ptr.read(tmp, readlength);
        record = readlength;
    }
    else
    {
        tmp = new char [length];
        file_ptr.read(tmp, length);
        record = length;
    }
    
    string string_read(&tmp[0], &tmp[record]);
    delete [] tmp;
    return string_read;
}

void FileModify::write(const string &data)
{
    file_ptr.write(data.c_str(), sizeof(char) * (data.size()));
}
