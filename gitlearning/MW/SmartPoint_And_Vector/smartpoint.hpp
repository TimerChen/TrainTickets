#ifndef SMART_POINT
#define SMART_POINT

Template<typename T>
class SmartPoint;
Template<typename T>
class SmartPoint_Base {
	friend class SmartPoint<T>;
	int cnt;
	T *baseptr;
	SmartPoint_Base(T *_ptr):baseptr(_ptr),cnt(1){}
	~SmartPoint_Base(){
		delete[]ptr;
	}
};

Template<typename T>
class SmartPoint {
	SmartPoint_Base<T> * base;
public:
	SmartPoint(T* ptr):base(new SmartPoint_Base(ptr)){}
	SmartPoint(const SmartPoint &rs) {
		base = rs.base;
		++base->cnt;
	}
	T& operator*(){
		return *(base->baseptr);
	}
	T& operator[](int i){
		return (base->baseptr)[i];
	}
	
	~SmartPoint(){
		if (base->cnt <= 1){
			delete base;
		}
		else --base->cnt;
	}
};



#endif SMART_POINT