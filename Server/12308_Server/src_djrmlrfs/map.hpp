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
namespace ttd {

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map {
public:
	typedef pair<const Key, T> value_type;
	class node{
		int height, stsize;//高度，子树size 
		value_type val;//值 
		node*pre, nxt;//前驱后继 
		node*fa, ls, rs;//父亲，左右儿子 
		node()
		{
			stsize = height = 1;
			pre = nxt = NULL;
			fa = ls = rs = NULL;
		}
		node(const value_type &vl)
		{
			val = vl;
			height = stsize = 1;
			
			pre = nxt = NULL;
			fa = ls = rs = NULL;
		}
		~node()
		{
			pre = nxt = NULL;
			fa = ls = rs = NULL;
		}
	};
	class const_iterator;
	class iterator {
	private:
		node*val, end;
	public:
		iterator() {
			val = end = NULL;
		}
		iterator(const iterator &other) {
			val = other.val, end = other.end;
		}
		~iterator()
		{
			val = end = NULL;
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
			iterator tmp;
			tmp.val = val;
			tmp.end = end;
			if (val->nxt == NULL)
			{
				throw "invalid_iterator";
				return tmp;
			}
			val = val->nxt;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator & operator++()
		{
			if (val->nxt == NULL)
			{
				throw "invalid_iterator";
				return this;
			}
			val = val->nxt;
			return this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int)
		{
			iterator tmp;
			tmp.val = val;
			tmp.end = end;
			if (val->pre == NULL)
			{
				throw "invalid_iterator";
				return tmp;
			}
			val = val->pre;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator & operator--()
		{
			if (val->pre == NULL)
			{
				throw "invalid_iterator";
				return this;
			}
			val = val->pre;
			return this;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		value_type & operator*() const
		{
			return val->val;
		}
		bool operator==(const iterator &rhs) const
		{
			return val==rhs->val;
		}
		bool operator==(const const_iterator &rhs) const
		{
			return val==rhs->val;			
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const
		{
			return val!=rhs->val;
		}
		bool operator!=(const const_iterator &rhs) const
		{
			return val!=rhs->val;
		}

		/**
		 * for the support of it->first. 
		 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
		 */
		value_type* operator->() const noexcept
		{
			return &(val->val);
		}
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		private:
			// data members.
		public:
			const_iterator() {
				// TODO
			}
			const_iterator(const const_iterator &other) {
				// TODO
			}
			const_iterator(const iterator &other) {
				// TODO
			}
			// And other methods in iterator.
			// And other methods in iterator.
			// And other methods in iterator.
	};
	
	/**
	 * TODO two constructors
	 */
	map()
	{
		root = NULL;
		endnode = new node;
		Begin->val = End->val = endnode;
	}
	void Cpy(node*&A, node*now)
	{
		A = new node(now.val);
		A.stsize = now.stsize, A.height = now.height;
		if (now->ls != NULL)	Cpy(A->ls,now->ls), A->ls->fa = A;
		if (now->rs != NULL)	Cpy(A->rs,now->rs), A->rs->fa = A;
	}
	map(const map &other)
	{
		endnode = new node;
		End->val = endnode;
		Cpy(root,other.root);
		Begin->val = root;
		while (Begin->val->ls != NULL)	Begin->val = Begin->val->ls;
	}
	/**
	 * TODO assignment operator
	 */
	map & operator=(const map &other)
	{
		map Tmp(other);	clear();

		End->val = Tmp.end->val, endnode = Tmp.endnode;
		root = Tmp.root, Begin->val = Tmp.Begin->val;
		
		Tmp.Begin = Tmp.End = Tmp.root = Tmp.endnode = NULL;
	}
	/**
	 * TODO Destructors
	 */
	~map()
	{
		clear();
		delete endnode;
		endnode = Begin = End = NULL;
	}
	/**
	 * TODO
	 * access specified element with bounds checking
	 * Returns a reference to the mapped value of the element with key equivalent to key.
	 * If no such element exists, an exception of type `index_out_of_bound'
	 */
	T & at(const Key &key)
	{
		iterator Now = find(key);
		if (Now == End)
		{
			throw "index_out_of_bound";
			return root->val.second;
		}
		return Now->second;
	}
	const T & at(const Key &key) const
	{
		const_iterator Now = find(key);
		if (Now == cEnd)
		{
			throw "index_out_of_bound";
			return root->val.second;
		}
		return Now->second;
	}
	/**
	 * TODO
	 * access specified element 
	 * Returns a reference to the value that is mapped to a key equivalent to key,
	 *   performing an insertion if such key does not already exist.
	 */
	T & operator[](const Key &key)
	{
		iterator Now = find(key);
		if (Now == End)
		{
			throw "index_out_of_bound";
			return root->val.second;
		}
		return Now->second;
	}
	const T & operator[](const Key &key) const
	{
		const_iterator Now = find(key);
		if (Now == cEnd)
		{
			throw "index_out_of_bound";
			return root->val.second;
		}
		return Now->second;
	}
	/**
	 * return a iterator to the beginning
	 */
	iterator begin()
	{
		return Begin;
	}
	const_iterator cbegin() const {}
	/**
	 * return a iterator to the end
	 * in fact, it returns past-the-end.
	 */
	iterator end()
	{
		return End;
	}
	const_iterator cend() const {}
	/**
	 * returns the number of elements.
	 */
	size_t size() const
	{
		if (root == NULL)	return 0;
		return root.stsize;
	}
	/**
	 * checks whether the container is empty
	 * return true if empty, otherwise false.
	 */
	bool empty() const
	{
		return (size()==0);
	}
	/**
	 * clears the contents
	 */
	void clear()
	{
		root->stsize = 0;
		for (iterator i = Begin; i != End; ++i)
		{
			delete i->val;
			i->val = NULL;
		}
		Begin = End, root = NULL;
		root->nxt = root->ls = root->rs = root->pre = NULL;
	}
	/**
	 * insert an element.
	 * return a pair, the first of the pair is
	 *   the iterator to the new element (or the element that prevented the insertion), 
	 *   the second one is true if insert successfully, or false.
	 */
	pair<iterator,bool> add(const value_type &value, node*&t, node*l, node*r)
	{
		
		pair<iterator,bool>	tmp;
		if (t == NULL)
		{
			t = new node(value);
			if (l == NULL)
			{
				t->nxt = r, t->pre = r->pre;
				t->nxt->pre = t->pre->nxt = t;
			}
			else
			{
				t->pre = l, t->nxt = t->pre->nxt;
				t->nxt->pre = t->pre->nxt = t;
			}
			
			tmp.seccond = 1, tmp.first.val = t, tmp.first.end = endnode;
		}
		else if (value.first < t->val.first)
		{
			tmp = add(value,t->ls,NULL,t);
			if (t->ls->height == t->rs->height+2)
				if (value.first < t->ls->val.first)	LL(t);	else	LR(t);
		}
		else if (value.first > t->val.first)
		{
			tmp = add(value,t->rs,t,NULL);
			if (t->rs->height == t->ls->height+2)
				if (value.first > t->rs->val.first)	RR(t);	else	RL(t);
		}
		else	tmp.seccond = 0, tmp.first.val = t, tmp.first.end = endnode;
		t->height = max(t->ls->height,t->rs->height)+1; 
		return tmp;
	}
	pair<iterator, bool> insert(const value_type &value)
	{
		return add(value,root,NULL,End);
	}
	bool del(Key now, node*&t)
	{
		int stop = 0, subtree;
		if (t == NULL)	return 1;
		if (now < t->val.first)	stop = del(now,t->ls), subtree = 1;
		else if (now > t->val.first)	stop = del(now,t->rs), subtree = 2;
		else if (t->ls!=NULL && t->rs!=NULL)
		{
			node*tmp = t->rs;
			while (tmp->ls != NULL)	tmp = tmp->ls;
			t->val = tmp->val;
			tmp->pre->nxt = tmp->nxt->pre = t;
			t->pre = tmp->pre, t->nxt = tmp->nxt;
			tmp->pre = tmp->nxt = tmp;
			stop = del(t->val->first,t->rs);
			subtree = 2;
		}
		else
		{
			node*tmp = t;
			t->nxt->pre = t->pre;
			t->pre->nxt = t->nxt;
			t = (t->ls==NULL)?t->rs:t->ls;
			delete tmp;
			return 0;
		}
		if (stop)	return 1;
		int bf;
		switch (subtree){
			case 1:
				bf = t->ls->height-t->rs->height+1;
				if (bf == 0)	return 1;
				if (bf == 1)	return 0;
				if (bf == -1)
				{
					 bf = t->rs->ls->height-t->rs->rs->height;
					 switch(bf){
					 	case 0:RR(t);return 1;
					 	case -1:RR(t);return 0;
					 	default:RL(t);return 0;
					 }
				}
				break;
			case 2:
				bf = t->ls->height-t->rs->height-1;
				if (bf == 0)	return 1;
				if (bf == -1)	return 0;
				if (bf == 1)
				{
					bf = t->ls->ls->height-t->ls->rs->height;
					switch(bf){
						case 0:LL(t);return 1;
						case 1:LL(t);return 0;
						default:LR(t);return 0;
					}
				}
		}
	}
	void erase(iterator pos)
	{
		if (pos->end!=endnode || pos==End || pos->val==NULL)
		{
			throw "invalid_iterator";
			return;
		}
		del(pos->val->val.first,root);
	}
	size_t count(const Key &key) const
	{
		iterator now = find(key);
		if (now == End)	return 0;
		return 1;
	}
	/**
	 * Finds an element with key equivalent to key.
	 * key value of the element to search for.
	 * Iterator to an element with key equivalent to key.
	 *   If no such element is found, past-the-end (see end()) iterator is returned.
	 */
	iterator find(const Key &key)
	{
		node*now = root;
		while (now != NULL)
		{
			if (key < now->val.first)	now = now->ls;
			else if (now->val.first < key)	now = now->rs;
			else
			{
				iterator tmp;
				tmp->val = now;
				tmp->end = End;
				return tmp;
			}
		}
		return End;
	}
	const_iterator find(const Key &key) const {}
private:
	int Size;
	iterator* Begin, End;
	const_iterator* cBegin, cEnd;
	node* root, endnode;
};

}

#endif
