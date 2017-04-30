# smartpoint 和 vector使用说明
## smartpoint 
包含：
1. shared_ptr

	使用方法：
	const shared_ptr<T> 相当于会自动析构的 T* const
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
	3. 对shared_ptr进行+操作返回的都将是normal_ptr
	4. 改变shared_ptr指向地址的行为都有可能造成原地址中的内容被删除!
	5. shared_ptr不支持++和--以及-、+=和-=操作!

2. const_shared_ptr
	使用方法：
	* 作为1的补充
	* 相当于会自动析构的const T*
	* const const_shared_ptr<T> 相当于会自动析构的 const T* const
	注意：
	1. 对const_shared_ptr进行+操作返回的都将是const_normal_ptr

2. normal_ptr
	
	使用方法：

	* 和正常指针完全相同
	* const normal_ptr<T> 相当于 T *const

	注意：

	1. 该指针不会自动析构new出的对象
	2. 就是字面意思，和正常指针完全相同

3. const_normal_ptr

	使用方法：
	* 作为2的补充
	* 相当于const T*
	* const const_normal_ptr 相当于 const T* const



## vector

就当vector用吧，该有的功能应该都有，就是可能会慢一些。