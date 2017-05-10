#include <iostream>
#include <string> 
using namespace std;

template <class T>
class HashMap
{

private:
	
	struct Node {
		string origin;
		T territory;
		Node* next;
		Node () : origin (""), territory (), next (NULL) {
		}
	};
	
	int badLuckOmen;
	int luckyPrime;
	int maxSize;
	Node** bold;
	Node* cautious;
	int cautiousPoint;
	 
	int nextPrime (int n) {
		while (true) {
			bool bePrime = true;
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					bePrime = false;
					break;
				}
			}
			if (bePrime) break;
			n++;
		}
		return n;
	}
	
	void doubleSpace_cautious () {
		Node* tmp = cautious;
		cautious = new Node [maxSize * 2];
		for (int i = 0; i < maxSize; i++) {
			cautious[i] = tmp[i];
		}
		maxSize *= 2;
		delete [] tmp;
	}
	
	void fakeDoubleSpace_bold () {
		Node** tmp = bold;
		int oldLuckyPrime = luckyPrime;
		luckyPrime = nextPrime (luckyPrime * 2);
		bold = new Node* [luckyPrime];
		for (int i = 0 ; i <= luckyPrime; i++) bold[i] = NULL;
		for (int i = 0; i < oldLuckyPrime; i++) {
			for (Node* p = tmp[i]; p != NULL; p = p -> next) {
				(*this)[p -> origin] = p -> territory;
				p -> origin = "";
			}	
		}
		renovate ();
		delete [] tmp;
	}
	
	
public:
	
	HashMap (int sz = 29) {
		maxSize = sz;
		if (maxSize <= 29) luckyPrime = 29;
		else luckyPrime = nextPrime (maxSize);
		bold = new Node* [luckyPrime + 1];
		for (int i = 0 ; i <= luckyPrime; i++) bold[i] = NULL;
		cautious = new Node [maxSize + 1];
		cautiousPoint = 0;
		badLuckOmen = 3;
	}
	
	HashMap (const HashMap &ha1) {
		maxSize = ha1.maxSize;
		luckyPrime = ha1.luckyPrime;
		bold = new Node* [luckyPrime + 1];
		for (int i = 0 ; i <= luckyPrime; i++) bold[i] = NULL;
		cautious = new Node [maxSize + 1];
		cautiousPoint = ha1.cautiousPoint;
	}
	
	HashMap &operator = (const HashMap &ha1) {
		if (this == &ha1) return *this;
		
		if (bold) delete [] bold;
		if (cautious) delete [] cautious;
		
		maxSize = ha1.maxSize;
		luckyPrime = ha1.luckyPrime;
		bold = new Node* [luckyPrime + 1];
		for (int i = 0 ; i <= luckyPrime; i++) bold[i] = NULL;
		cautious = new Node [maxSize + 1];
		cautiousPoint = ha1.cautiousPoint;
		return *this;
	}
	
	void SeerDeclare (int newFortune) {
		badLuckOmen = newFortune;
	}
	
	int askHashPrime () {
		return luckyPrime;
	}
	
	int askQuantity () {
		return cautiousPoint;
	}
	
	T & operator[] (string name) {
		int l = name.length ();
		int nameNumber = 0;
		for (int i = 0; i < l; i++) {
			nameNumber *= 257;
			nameNumber += (int)name[i];
			nameNumber %= luckyPrime;
		}
		for (Node* p = bold[nameNumber]; p != NULL; p = p -> next) {
			if (p -> origin == name) {
				return p -> territory;
			}
		}
		cautious[cautiousPoint].origin = name;
		cautious[cautiousPoint].next = bold[nameNumber];
		bold[nameNumber] = &cautious[cautiousPoint];
		cautiousPoint++;
		if (cautiousPoint >= maxSize - 1) {
			doubleSpace_cautious ();
		}
		if (maxSize >= (long long)luckyPrime * badLuckOmen) {
			fakeDoubleSpace_bold ();
		}
		return cautious[cautiousPoint - 1].territory;
	}
	
	const T & operator[] (string name) const {
		int l = name.length ();
		int nameNumber = 0;
		for (int i = 0; i < l; i++) {
			nameNumber *= 257;
			nameNumber += (int)name[i];
			nameNumber %= luckyPrime;
		}
		for (Node* p = bold[nameNumber]; p != NULL; p = p -> next) {
			if (p -> origin == name) {
				return p -> territory;
			}
		}
		return NULL;
	}
	
	void renovate () {
		Node* tmp = cautious;
		cautious = new Node [maxSize];
		int newCautiousPoint = 0;
		for (int i = 0; i < cautiousPoint; i++) {
			if (tmp[i].origin != "") {
				cautious[newCautiousPoint] = tmp[i];
				newCautiousPoint++;
			}
		}
		cautiousPoint = newCautiousPoint;
		delete [] tmp;
	}
	
	~HashMap () {
		if (bold) delete [] bold;
		if (cautious) delete [] cautious;
	}
	
};
