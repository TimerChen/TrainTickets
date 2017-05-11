/**
 * implement a container like std::map
 */
#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

// only for std::less<T>
#include <functional>
#include <cstddef>
#include "utility.hpp"
#include "exceptions.hpp"

#include <iostream>

namespace sjtu {
	/*
	template<class T>
	struct normal_ptr
	{
		T *ptr;
		normal_ptr(T *Ptr = nullptr):ptr(Ptr){}
		T& operator *()
		{	return *ptr;	}
		T* operator ->()
		{	return ptr;		}
		const T& operator *()const
		{	return *ptr;	}
		const T* operator ->()const
		{	return ptr;		}
		bool operator == (const normal_ptr &a){return ptr==a.ptr;}
		bool operator != (const normal_ptr &a){return ptr!=a.ptr;}
		int operator - (const normal_ptr &a){return ptr - a.ptr;}
		void del(){delete ptr;ptr = nullptr;}
	};
	*/
	template<class T>
	void swap( T &a, T &b )
	{ T c(a); a=b;b=c; }
	template<class T>
	T min(const T &a, const T &b){return a<b?a:b;}
	template<class T>
	T max(const T &a, const T &b){return a>b?a:b;}

/*
template<
	class Key,
	class T,
	class Compare
>
class Debuger_Map;*/

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map {
	//friend class Debuger_Map<Key,T,Compare>;
public:
	/**
	 * the internal type of data.
	 * it should have a default constructor, a copy constructor.
	 * You can use sjtu::map as value_type by typedef.
	 */
	typedef pair<const Key, T> value_type;
private:
	struct Node
	{
		Node(Node *Null);
		Node(const Node &a);
		~Node()
		{
			if(data)
				delete data;
		}
		value_type *data;
		int height;
		Node *ch[2],*fa,*nflag,*near[2];
		void update()
		{
			if(this == nflag)return;
			height = max(ch[0]->height,ch[1]->height)+1;
		}
		short pl()
		{ return this==fa->ch[1]; }
	}null[1],*ROOT,*BEGIN,*END;
public:
	/**
	 * see BidirectionalIterator at CppReference for help.
	 *
	 * if there is anything wrong throw invalid_iterator.
	 *     like it = map.begin(); --it;
	 *       or it = map.end(); ++end();
	 */
	class const_iterator;
	class iterator {
		friend class map;
		private:
			/**
			 * TODO add data members
			 *   just add whatever you want.
			 */
			map *ori;
			Node *add;
			iterator( map *Origin, Node *Address )
				 { ori = Origin; add = Address; }
		public:
			iterator() {
				// TODO
				add = NULL;
				ori = NULL;
			}
			iterator(const iterator &other) {
				// TODO
				ori = other.ori;
				add = other.add;
			}
			/**
			 * return a new iterator which pointer n-next elements
			 *   even if there are not enough elements, just return the answer.
			 * as well as operator-
			 */
			/**
			 * TODO iter++
			 */
			iterator operator++(int)
			{
				if(add == ori->null)throw(index_out_of_bound());
				iterator tmp(*this);
				add = add->near[1];
				return tmp;
			}
			/**
			 * TODO ++iter
			 */
			iterator & operator++()
			{
				if(add == ori->null)throw(index_out_of_bound());
				add = add->near[1];
				return *this;
			}
			/**
			 * TODO iter--
			 */
			iterator operator--(int)
			{
				if(add == ori->BEGIN)throw(index_out_of_bound());
				iterator tmp(*this);
				if(add == ori->null)add = ori->END;
				else add = add->near[0];
				return tmp;
			}
			/**
			 * TODO --iter
			 */
			iterator & operator--()
			{
				if(add == ori->BEGIN)throw(index_out_of_bound());
				if(add == ori->null)add = ori->END;
				else add = add->near[0];
				return *this;
			}
			/**
			 * a operator to check whether two iterators are same (pointing to the same memory).
			 */
			value_type & operator*() const
			{ return *(add->data); }
			bool operator==(const iterator &rhs) const
			{ return add == rhs.add; }
			bool operator==(const const_iterator &rhs) const
			{ return add == rhs.add; }
			/**
			 * some other operator for iterator.
			 */
			bool operator!=(const iterator &rhs) const
			{ return add != rhs.add; }
			bool operator!=(const const_iterator &rhs) const
			{ return add != rhs.add; }

			/**
			 * for the support of it->first.
			 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
			 */
			value_type* operator->() const noexcept
			{ return add->data; }
		};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		friend class map;
		private:
			// data members.
			const map *ori;
			const Node *add;
			const_iterator( const map *Origin, const Node *Address )
			:ori(Origin),add(Address){}
		public:
			const_iterator()
			:ori(NULL),add(NULL){}
			const_iterator(const const_iterator &other)
			:ori(other.ori),add(other.add){}
			const_iterator(const iterator &other)
			:ori(other.ori),add(other.add){}

			// And other methods in iterator.
			// And other methods in iterator.
			// And other methods in iterator.
			/**
			 * TODO iter++
			 */
			const_iterator operator++(int)
			{
				if(add == ori->null)throw(index_out_of_bound());
				const_iterator tmp(*this);
				add = add->near[1];
				return tmp;
			}
			/**
			 * TODO ++iter
			 */
			const_iterator & operator++()
			{
				if(add == ori->null)throw(index_out_of_bound());
				add = add->near[1];
				return *this;
			}
			/**
			 * TODO iter--
			 */
			const_iterator operator--(int)
			{
				if(add == ori->BEGIN)throw(index_out_of_bound());
				const_iterator tmp(*this);
				if(add == ori->null)add = ori->END;
				else add = add->near[0];
				return tmp;
			}
			/**
			 * TODO --iter
			 */
			const_iterator & operator--()
			{
				if(add == ori->BEGIN)throw(index_out_of_bound());
				if(add == ori->null)add = ori->END;
				else add = add->near[0];
				return *this;
			}
			/**
			 * a operator to check whether two iterators are same (pointing to the same memory).
			 */
			//const ???
			const value_type & operator*() const
			{ return *(add->data); }
			bool operator ==(const iterator &rhs) const
			{ return add == rhs.add; }
			bool operator ==(const const_iterator &rhs) const
			{ return add == rhs.add; }
			/**
			 * some other operator for iterator.
			 */
			bool operator!=(const iterator &rhs) const
			{ return add != rhs.add; }
			bool operator!=(const const_iterator &rhs) const
			{ return add != rhs.add; }

			/**
			 * for the support of it->first.
			 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
			 */
			//const ???
			const value_type* operator->() const noexcept
			{ return add->data; }
	};
private:
	int SIZE;
	//Node* copy(Node *&ro,Node *cr,Node *Fa=null, Node *pre=null)
	Node* copy(Node *&ro,Node *cr,Node *Fa, Node *pre)
	{
		if(cr == cr->nflag){ro=null;return pre;}
		ro = new Node(*cr);
		//printf("new%d\n",ro);
		ro->nflag = null;
		ro->fa = Fa;
		ro->near[0] = copy(ro->ch[0],cr->ch[0],ro,pre);
		if(ro->near[0]==null)BEGIN = ro;
		else ro->near[0]->near[1] = ro;
		return copy(ro->ch[1],cr->ch[1],ro,ro);
	}
	void clear(Node *&ro)
	{
		if(ro==null)return;
		clear(ro->ch[0]);
		clear(ro->ch[1]);
		//printf("delete ro:%d\n",ro);
		delete ro;ro=null;
	}
	/*
	void rotate(Node *k){
		Node *r = k->fa;if(k==null||r==null)return;
		r->push();k->push();
		int x = k->pl()^1;
		r->ch[x^1] = k->ch[x];
		r->ch[x^1]->fa = r;
		if(r->fa!=null)r->fa->ch[r->pl()] = k;
		else ROOT = k;
		k->fa = r->fa;r->fa = k;
		k->ch[x] = r;
		r->count();k->count();
	}
	*/
	Node *findit(const Key &val) const
	{
		Node *ro = ROOT;
		while(ro!=null)
		{
			if( !Compare()(val, ro->data->first) && !Compare()(ro->data->first, val) )
				return ro;
			else if( Compare()(val, ro->data->first) )
				ro = ro->ch[0];
			else
				ro = ro->ch[1];
		}
		return ro;
	}
	//void insert(const value_type &val, Node *&r = ROOT, Node *fa = null)
	Node *insert(const value_type &val, Node *&r, Node *fa)
	{
		if( r == null )
		{
			r = new Node(null);
			r->data = new value_type(val);
			//printf("new r%d\n",r);
			//printf("new r->data%d\n",r->data);
			r->fa = fa;
			if(fa == null)
			{
				BEGIN = END = r;
			}else{
				int x = r->pl();
				r->near[x^1] = r->fa;
				r->near[x] = r->fa->near[x];
				r->fa->near[x] = r;
				if(r->near[x]!=null)
					r->near[x]->near[x^1] = r;
				if(r->near[0] == null)BEGIN = r;
				if(r->near[1] == null)END = r;
			}
			return r;
		}else{
			int x = Compare()(r->data->first, val.first);
			Node *k = insert(val, r->ch[x], r);
			if( r->ch[x]->height - r->ch[x^1]->height == 2)
			{
				if(Compare()(r->ch[x]->data->first, val.first) == x) rotate(r->ch[x]);
				else krotate(r->ch[x]->ch[x^1]);
			}
			r->update();
			return k;
		}
	}
	short balanced(Node *r,short x)
	{
		int ob = r->ch[x]->height - r->ch[x^1]->height + 1,nb;
		if(ob == 0)return 1;
		if(ob == 1)return 0;
		if(ob == -1)
		{
			nb = r->ch[x^1]->ch[x]->height - r->ch[x^1]->ch[x^1]->height;
			if(nb == 0)
			{
				rotate(r->ch[x^1]);
				return 1;
			}else if(nb == -1){
				rotate(r->ch[x^1]);
				return 0;
			}else{
				krotate(r->ch[x^1]->ch[x],2);
				return 0;
			}
		}
		throw(0);
	}
	bool removeNode( Node *&k, Node *&r )
	{
		bool stop = 0;
		if(k->ch[0]!=null){
			stop = removeNode(k->ch[0],r);
		}else{
			//ro will never be BEGIN or END

			Node *ro=r,*ko=k;
			//k
			//k = null;
			k = k->ch[1];
			//ko = k->ch[1];
			if(k!=null)
			k->fa = ko->fa;
			//r

			r = ko;
			r->fa = ro->fa;
			r->ch[0] = ro->ch[0];
			r->ch[1] = ro->ch[1];
			if(r->ch[0]!=null)
			r->ch[0]->fa = r;
			if(r->ch[1]!=null)
			r->ch[1]->fa = r;
			//near
			//ro is not BEGIN
			r->near[0] = ro->near[0];
			r->near[0]->near[1] = r;
			//NEVER DELETE HERE!!!!!!!!!!!!!!!!!
			//delete ro;
			return false;
		}
		k->update();
		if(stop) return true;
		return balanced(k,0);
	}
	//bool remove( const iterator &i, Node *&r = ROOT )
	bool remove( const iterator &i, Node *&r)
	{
		short stop=0,x;
		if(i.add == null)throw(invalid_iterator());
		if(r == null) return 1;
		else if( Compare()(i->first, r->data->first)){
			stop = remove( i, r->ch[x=0] );
		}else if( Compare()(r->data->first, i->first)){
			stop = remove( i, r->ch[x=1]);
		}else{
			if(i!=iterator(this,r))throw(invalid_iterator());
			if( r->ch[0]!=null && r->ch[1]!=null ){
				Node *k = r;
				stop = removeNode(r->ch[x=1],r);
				//DELETE HERE!!!!!!
				delete k;
			}else{
				Node *k = r;
				x = (r->ch[0]==null);
				r = r->ch[x];
				if(r!=null)
					r->fa = k->fa;
				//k->fa->ch[k->pl()] = r;

				if(BEGIN == k)
					BEGIN = k->near[1];
				else
					k->near[0]->near[1] = k->near[1];
				if(END == k)
					END = k->near[0];
				else
					k->near[1]->near[0] = k->near[0];

				//printf("delete k:%d\n",k);
				delete k;
				r->update();
				return false;
			}
		}
		r->update();
		if(stop) return true;

		//maintain balance
		return balanced(r,x);
	}
	void rotate(Node *k)
	{
		Node *r = k->fa;
		if(k==null||r==null)return;
		//r->push();k->push();
		int x = (k->pl()^1);
		r->ch[x^1] = k->ch[x];
		r->ch[x^1]->fa = r;
		if(r->fa==null)ROOT = k;
		else r->fa->ch[r->pl()] = k;
		k->fa = r->fa;r->fa = k;
		k->ch[x] = r;
		r->update();k->update();
	}
	void krotate(Node *r,int k=2)
	{
		for(;k;--k)
			rotate(r);
	}
public:
	/**
	 * TODO two constructors
	 */
	map()
	:null({Node(null)})
	{
		//null[0] = Node(null);
		BEGIN = END = ROOT = null;
		SIZE=0;
	}
	map(const map &other)
	:null({Node(null)})
	{
		ROOT = BEGIN = null;
		END = copy(ROOT,other.ROOT,null,null);
		END->near[1] = null;
		SIZE=other.SIZE;
	}
	/**
	 * TODO assignment operator
	 */
	map & operator=(const map &other)
	{
		if(&other == this) return *this;
		clear(ROOT);
		BEGIN = null;
		END = copy(ROOT,other.ROOT,null,null);
		END->near[1] = null;
		SIZE=other.SIZE;
		return *this;
	}
	/**
	 * TODO Destructors
	 */
	~map() {clear(ROOT);}
	/**
	 * TODO
	 * access specified element with bounds checking
	 * Returns a reference to the mapped value of the element with key equivalent to key.
	 * If no such element exists, an exception of type `index_out_of_bound'
	 */
	T & at(const Key &key)
	{
		Node *r = findit( key );
		if(r == null)throw( index_out_of_bound() );
		return (r->data)->second;
	}
	const T & at(const Key &key) const
	{
		Node *r = findit( key );
		if(r == null)throw( index_out_of_bound() );
		return (r->data)->second;
	}
	/**
	 * TODO
	 * access specified element
	 * Returns a reference to the value that is mapped to a key equivalent to key,
	 *   performing an insertion if such key does not already exist.
	 */
	T & operator[](const Key &key)
	{
		Node *r = findit( key );
		if(r == null)
		{
			r = insert(value_type(key,T()), ROOT,null);
			SIZE++;
		}
		return (r->data)->second;
	}
	/**
	 * behave like at() throw index_out_of_bound if such key does not exist.
	 */
	const T & operator[](const Key &key) const
	{ return at(key); }
	/**
	 * return a iterator to the beginning
	 */
	iterator begin()
	{ return iterator(this,BEGIN); }
	const_iterator cbegin() const
	{ return const_iterator(this,BEGIN); }
	/**
	 * return a iterator to the end
	 * in fact, it returns past-the-end.
	 */
	iterator end()
	{ return iterator(this,null); }
	const_iterator cend() const
	{ return const_iterator(this,null); }
	/**
	 * checks whether the container is empty
	 * return true if empty, otherwise false.
	 */
	bool empty() const
	{ return SIZE==0; }
	/**
	 * returns the number of elements.
	 */
	size_t size() const
	{ return SIZE; }
	/**
	 * clears the contents
	 */
	void clear()
	{	clear(ROOT);SIZE = 0;BEGIN=END=null; }
	/**
	 * insert an element.
	 * return a pair, the first of the pair is
	 *   the iterator to the new element (or the element that prevented the insertion),
	 *   the second one is true if insert successfully, or false.
	 */
	pair<iterator, bool> insert(const value_type &value)
	{
		Node *r = findit( value.first );
		pair<iterator, bool> re;
		if(r!=null)
		{
			re.second = false;
		}else{
			r = insert(value, ROOT, null);
			re.second = true;
			SIZE++;
		}
		re.first = iterator(this,r);
		return re;
	}
	/**
	 * erase the element at pos.
	 *
	 * throw if pos pointed to a bad element (pos == this->end() || pos points an element out of this)
	 */
	void erase(iterator pos)
	{
		if(pos.ori!=this || pos.add==null)
		throw(invalid_iterator());
		remove(pos,ROOT);
		SIZE--;
		if(SIZE == 0)
		{
			ROOT = BEGIN = END = null;
		}
		//if not find KEY also throw;

	}
	/**
	 * Returns the number of elements with key
	 *   that compares equivalent to the specified argument,
	 *   which is either 1 or 0
	 *     since this container does not allow duplicates.
	 * The default method of check the equivalence is !(a < b || b > a)
	 */
	size_t count(const Key &key) const
	{ Node *r = findit(key); return size_t(r!=null); }
	/**
	 * Finds an element with key equivalent to key.
	 * key value of the element to search for.
	 * Iterator to an element with key equivalent to key.
	 *   If no such element is found, past-the-end (see end()) iterator is returned.
	 */
	iterator find(const Key &key)
	{
		Node *r = findit(key);
		return iterator(this,r);
	}
	const_iterator find(const Key &key) const
	{
		Node *r = findit(key);
		return const_iterator(this,r);
	}
	/*
	void debug_p(Node *r)
	{
		using namespace std;
		if(r==null)return;
		cout << "{" << endl;
		cout << "Address: " << r <<endl;
		cout << "DataAddress: " << r->data <<endl;
		cout << "ch[0]:\n";
		debug_p(r->ch[0]);
		cout << "ch[1]:\n";
		debug_p(r->ch[1]);

		cout << "}" << endl;
	}
	void debug_p()
	{

		std::cout << "this:" << this << std::endl;
		std::cout << "null:" << &null[0] << std::endl;
		debug_p(ROOT);
	}
	*/

};
template<
	class Key,
	class T,
	class Compare
>
map<Key,T,Compare>::Node::Node(Node *Null)
:nflag(Null)
{
	data = NULL;
	near[0]=near[1]=ch[0]=ch[1]=fa=Null;
	if(nflag!=this)height = 0;
	else height = -1;
}

template<
	class Key,
	class T,
	class Compare
>
map<Key,T,Compare>::Node::Node(const Node &a)
{
	data = new value_type(*a.data);
	ch[0]=ch[1]=near[0]=near[1]=fa=nflag=NULL;
	height = a.height;
}

}

#endif
