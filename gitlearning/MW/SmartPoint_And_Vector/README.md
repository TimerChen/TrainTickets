# smartpoint 和 vector使用说明
## smartpoint 
包含：
1. shared_ptr

	使用方法：
	```cpp
	template <typename T, bool array = false, bool opnew = false>//最后一项为是否使用了operator new
	shared_ptr<int> a = new int;
	shared_ptr<int, true> b = new int[k];
	shared_ptr<int, true> c = b;
	shared_ptr<int, true> d;
	c = a;
	```
	其他如：解引用、箭头、[] 使用与正常指针相同
	
	注意：
	1. 该指针会自动在没有指针指向某new出的元素时，自动析构该元素，故无需使用delete操作。
	2. 请勿将该指针与裸指针混用，否则可能造成内存管理的错误 

2. normal_point
	
	使用方法：

	* 和正常指针完全相同

	注意：

	1. 该指针不会自动析构new出的对象
	2. 就是字面意思，和正常指针完全相同

## vector

就当vector用吧，该有的功能应该都有，就是可能会慢一些。