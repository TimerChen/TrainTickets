#ifndef SMART_POINT
#define SMART_POINT

Template<typename T>
class SmartPoint;
Template<typename T>
class SmartPoint_Base {
	friend class SmartPoint<T>;
private:
	int cnt;
	T *baseptr;
	SmartPoint_Base(T *_ptr):baseptr(_ptr),cnt(1){}
	void AddNewPoint(){++cnt;}
	void distruction(){
		--cnt;
		if (cnt <= 0) ~SmartPoint_Base();
	}
	~SmartPoint_Base(){
		delete[]ptr;
	}
};

Template<typename T>
class SmartPoint {
	SmartPoint_Base<T> * base;
public:
	SmartPoint():base(nullptr){}
	SmartPoint(T* ptr):base(new SmartPoint_Base<T> (ptr)){}
	SmartPoint(const SmartPoint &rs) {
		base = rs.base;
		base->AddNewPoint();
	}
	T& operator*(){
		return *(base->baseptr);
	}
	T& operator[](int i){
		return (base->baseptr)[i];
	}
	T* operator->(){
		return base->baseptr;
	}
	SmartPoint& operator=(const SmartPoint &rs) {
		if (!base) {
			base = rs.base;
			base->AddNewPoint();
		}
		else {
			base->distruction();
			base = rs.base;
			base->AddNewPoint();
		}
		return *this;
	}
	SmartPoint& operator=(const T *rt) {
		if (base){
			base->distruction();
		}
		base = new SmartPoint_Base<T>(rt);
		return *this;
	}
	
	~SmartPoint(){
		base->distruction();
	}
};



#endif SMART_POINT