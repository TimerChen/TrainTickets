class FileModify
{
public:
	string file;
	FileModify( const string &fname ):file(fname)
	void reset();
	string read();
	void write( const string &data );
	void open();
	void close();
};
