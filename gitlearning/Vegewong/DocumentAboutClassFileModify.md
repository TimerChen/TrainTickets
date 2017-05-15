# FileModify类说明

* 本文件已经经过测试,各项功能均运作正常

* 一 . include库及名字空间:

  ```c++
  #include <string>
  #include <fstream>
  using namespace std;
  ```

* 二 . 接口简介:

  ```c++
  class FileModify
  {
    private:
      fstream file_ptr;                    //文件操作流

    public:
      string file;					   //保存的文件名
      
      FileModify(const string &fname) : file(fname)  //构造函数
      {}

      ~FileModify()					
      {
          if (!file_ptr.is_open())
              file_ptr.close();
      }

      void reset();					   //清空文件内容,调用该函数后处于与文件关联状态
      string read(int &record, int length);//读函数
      void write(const string &data);      //写函数
      void open();					   //建立关联
      void close();					   //取消关联
  ```

* 三 . open() , close() :

  ```c++
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
  ```

  在FileModify类的构造函数被调用后,文件流和文件并没有建立管理,必须显式调用open()函数,close()函数则会在类析构时被调用.

  ### open情况下再次open操作会被忽略,close同理

* 四 . reset():

  ```c++
  void FileModify::reset()
  {
      if (file_ptr.is_open())
          file_ptr.close();
      file_ptr.open(file.c_str(), ios::trunc | ios::in | ios::out | ios::binary);
  }
  ```

  以trunc方式打开文件,因此调用后默认与文件建立关联

* 五 . write():

  ```c++
  void FileModify::write(const string &data)
  {
      file_ptr.write(data.c_str(), sizeof(char) * (data.size()));
  }
  ```

  参数为string

* 六 . read()

  ```c++
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
      return string_read;
  }
  ```

  record参数返回了在本次read()操作中读取的字符个数,length参数采用默认值-1或大于文件当前长度表示读到文件末尾,否则读取length长度字符