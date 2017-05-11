#ifndef TTD_MAP_HPP
#define TTD_MAP_HPP

#include <functional>
#include <cstddef>
#include "exceptions.hpp"
#include "utility.hpp"
//using AVL
namespace ttd {
template<class Key,class T,class Compare = std::less<Key>
> class map {
public:
	typedef pair<const Key, T> value_type;
	
	class node{
	public:
		int height;
		value_type*val;
		node *pre, *nxt;
		node *ls, *rs;
		node():val(NULL)
		{
			height = 0;
			pre = nxt = ls = rs = NULL;
		}
		node(const value_type &vl, node*l, node*r, int h = 0):val(new value_type(vl))
		{
			height = h;
			ls = l, rs = r;
			pre = nxt = NULL;
		}
		~node()
		{
			delete val;
			val = NULL;
			pre = nxt = NULL;
			ls = rs = NULL;
		}
		void operator=(const node &a)
		{
			height = a.height;
			if (val == NULL)	val = new value_type(*a.val);
			else	*val = *a.val;
			pre = a.pre, nxt = a.nxt, ls = a.ls, rs = a.rs;
		}
	};
	
	class const_iterator;

	class iterator {
	public:
		node *val, *end;
		iterator():val(NULL),end(NULL){}
		iterator(const iterator &other):val(other.val),end(other.end){}
		iterator operator=(const iterator &other)
		{
			val = other.val , end = other.end;
		}
		~iterator(){val = end = NULL;}
		iterator operator++(int)
		{
			iterator tmp;
			tmp.val = val;
			tmp.end = end;
			if (val->nxt == NULL)
			{
				throw invalid_iterator();
				return tmp;
			}
			val = val->nxt;
			return tmp;
		}
		iterator & operator++()
		{
			if (val->nxt == NULL)
			{
				throw invalid_iterator();
				return *this;
			}
			val = val->nxt;
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp;
			tmp.val = val;
			tmp.end = end;
			if (val->pre == NULL)
			{
				throw invalid_iterator();
				return tmp;
			}
			val = val->pre;
			return tmp;
		}
		iterator & operator--()
		{
			if (val->pre == NULL)
			{
				throw invalid_iterator();
				return *this;
			}
			val = val->pre;
			return *this;
		}
		value_type & operator*() const
		{
			return *(val->val);
		}
		bool operator==(const iterator &rhs) const
		{
			return val==rhs.val;
		}
		bool operator==(const const_iterator &rhs) const
		{
			return val==rhs.val;			
		}
		bool operator!=(const iterator &rhs) const
		{
			return val!=rhs.val;
		}
		bool operator!=(const const_iterator &rhs) const
		{
			return val!=rhs.val;
		}
		value_type* operator->() const noexcept
		{
			return (val->val);
		}
	};
	class const_iterator {
		public:
			node*val,*end;
			const_iterator() {
				val = end = NULL;
			}
			const_iterator(const const_iterator &other) {
				val = other.val, end = other.end;
			}
			const_iterator(const iterator &other) {
				val = other.val, end = other.end;
			}
			const_iterator operator=(const iterator &other)
			{
				val = other.val , end = other.end;
			}
			const_iterator operator=(const const_iterator &other)
			{
				val = other.val , end = other.end;
			}
			~const_iterator()
			{
				val = end = NULL;
			}
			const_iterator operator++(int)
			{
				const_iterator tmp;
				tmp.val = val;
				tmp.end = end;
				if (val->nxt == NULL)
				{
					throw invalid_iterator();
					return tmp;
				}
				val = val->nxt;
				return tmp;
			}
			const_iterator & operator++()
			{
				if (val->nxt == NULL)
				{
					throw invalid_iterator();
					return *this;
				}
				val = val->nxt;
				return *this;
			}
			const_iterator operator--(int)
			{
				const_iterator tmp;
				tmp.val = val;
				tmp.end = end;
				if (val->pre == NULL)
				{
					throw invalid_iterator();
					return tmp;
				}
				val = val->pre;
				return tmp;
			}
			const_iterator & operator--()
			{
				if (val->pre == NULL)
				{
					throw invalid_iterator();
					return *this;
				}
				val = val->pre;
				return *this;
			}
			const value_type & operator*() const
			{
				return *(val->val);
			}
			bool operator==(const iterator &rhs) const
			{
				return val==rhs.val;
			}
			bool operator==(const const_iterator &rhs) const
			{
				return val==rhs.val;			
			}
			bool operator!=(const iterator &rhs) const
			{
				return val!=rhs.val;
			}
			bool operator!=(const const_iterator &rhs) const
			{
				return val!=rhs.val;
			}
			const value_type* operator->() const noexcept
			{
				return val->val;
			}
	};
	
	map()
	{
		Size = 0;
		root = NULL;
		endnode = new node;
		Begin.val = End.val = endnode;
		End.end = Begin.end = endnode;
		cBegin.val = cEnd.val = endnode;
		cBegin.end = cEnd.end = endnode;
	}
	
	void Cpy(node*&A, node*now)
	{
		if (now == NULL)
		{
			A = NULL;
			return;
		}
		A = new node(*(now->val),NULL,NULL);
		A->height = now->height;
		if (now->ls != NULL)	Cpy(A->ls,now->ls);
		if (now->rs != NULL)	Cpy(A->rs,now->rs);
	}
	void makepn(node*&now,node*&pre)
	{
		if (now->ls != NULL)	makepn(now->ls,pre);
		now->pre = pre;
		if (pre != NULL)	now->pre->nxt = now;
		pre = now;
		if (now->rs != NULL)	makepn(now->rs,pre);
	}
	map(const map &other)
	{
		Size = other.Size;
		root = NULL;
		endnode = new node;
		Begin.val = End.val = endnode;
		End.end = Begin.end = endnode;
		cBegin.val = cEnd.val = endnode;
		cBegin.end = cEnd.end = endnode;
		
		Cpy(root,other.root);
		if (root != NULL)	Begin.val = root;
		while (Begin.val->ls != NULL)	Begin.val = Begin.val->ls;
		
		node* tend = NULL;	cBegin.val = Begin.val;
		if (Size > 0)	{makepn(root,tend); tend->nxt = endnode;}
		endnode->pre = tend;
	}
	map & operator=(const map &other)
	{
		map Tmp(other);	clear();
		Size = Tmp.Size;
		root = Tmp.root, Tmp.root = NULL;
		cBegin = Tmp.cBegin, Begin = Tmp.Begin;
		delete endnode;
		endnode = Tmp.endnode;
		Tmp.endnode = NULL;
		cEnd = Tmp.cEnd, End = Tmp.End;
		Tmp.Begin = Tmp.End;
		return *this;
	}
	~map()
	{
		clear();
		if (endnode != NULL)	delete endnode;
		endnode = NULL;
	}
	T & at(const Key &key)
	{
		T aa;
		value_type a(key,aa);
		iterator Now = find(key);
		if (Now == cEnd)
		{
			throw invalid_iterator();
		}
		return Now->second;
	}
	const T & at(const Key &key) const
	{
		T aa;
		value_type a(key,aa);
		const_iterator Now = find(key);
		if (Now == cEnd)
		{
			throw invalid_iterator();
		}
		return Now->second;
	}
	T & operator[](const Key &key)
	{
		T aa;
		value_type a(key,aa);
		iterator Now = find(key);
		if (Now == End)	Now = insert(a).first;
		return Now->second;
	}
	const T & operator[](const Key &key) const
	{
		T aa;
		value_type a(key,aa);
		const_iterator Now = find(key);
		if (Now == cEnd)
		{
			throw invalid_iterator();
		}
		return Now->second;
	}
	iterator begin(){iterator tmp(Begin);return tmp;}
	const_iterator cbegin() const{return cBegin;}
	iterator end(){iterator tmp = End;return tmp;}
	const_iterator cend() const{return cEnd;}
	size_t size() const{return Size;}
	bool empty() const{return (size()==0);}
	void clear()
	{
		Size = 0;
		for (iterator i = Begin; i != End;)
		{
			node*now=(i++).val;
			delete (now->val);
			now->val = NULL;
			delete now;now = NULL;
		}
		Begin = End, cBegin = cEnd, root = NULL;
		if(endnode!=NULL)endnode->pre = NULL;
	}
	void TL(node*&t)
	{
		node*t1 = t->ls;
		t->ls = t1->rs;
		t1->rs = t;
		t = t1;
	}
	void TR(node*&t)
	{
		node*t1 = t->rs;
		t->rs = t1->ls;
		t1->ls = t;
		t = t1;
	}
	int max(int a, int b){return a>b?a:b;}
	inline int height(node *t) const{return (t==NULL?-1:t->height);}
	void uphei(node*&t)
	{
		if (t == NULL)	return;
		t->height = max(height(t->ls),height(t->rs))+1;
	}
	void LL(node*&t)
	{
		node*t1 = t->ls;
		t->ls = t1->rs;
		t1->rs = t;
		uphei(t), uphei(t1);
		t = t1;
	}
	void RR(node*&t)
	{
		node*t1 = t->rs;
		t->rs = t1->ls;
		t1->ls = t;
		uphei(t), uphei(t1);
		t = t1;
	}
	void RL(node*&t){RR(t->ls), LL(t);}
	void LR(node*&t){LL(t->rs), RR(t);}
	void balance(node*&t)
	{
		if (t == NULL)	return;
		if (height(t->ls)-height(t->rs) > 1)
			if (height(t->ls->ls) >= height(t->ls->rs))
				LL(t);	else	RL(t);
		else if (height(t->rs)-height(t->ls) > 1)
			if (height(t->rs->rs) >= height(t->rs->ls))
				RR(t);	else	LR(t);
		uphei(t);
	}
	pair<iterator,bool> add(const value_type &val, node*&t, node*l, node*r)
	{
		Compare cmp;
		Key key = val.first;
		T data = val.second;
		pair<iterator,bool>	tmp;
		if (t == NULL)
		{
			t = new node(val,NULL,NULL);
			if (l == NULL)
			{
				t->nxt = r, t->pre = r->pre;
				t->nxt->pre = t;
				if (t->pre != NULL)	t->pre->nxt = t;
			}
			else
			{
				t->pre = l, t->nxt = l->nxt;
				t->pre->nxt = t->nxt->pre = t;
			}
			tmp.second = true, tmp.first.val = t, tmp.first.end = endnode;
			balance(t);	return tmp;
		}
		else if (cmp(key,t->val->first))
		{
			pair<iterator,bool>	tt(add(val,t->ls,NULL,t));
			balance(t);	return tt;
		}
		else if (cmp(t->val->first,key))
		{
			pair<iterator,bool>	tt(add(val,t->rs,t,NULL));
			balance(t);	return tt;
		}
		else	{tmp.second = false, tmp.first.val = t, tmp.first.end = endnode;	return tmp;}
		return tmp;
	}
	pair<iterator, bool> insert(const value_type &value)
	{
		pair<iterator,bool> ans(add(value,root,NULL,endnode));
		if (Begin == End)	Begin.val = root;
		else	if (Begin.val->pre != NULL)		Begin.val = Begin.val->pre;
		cBegin.val = Begin.val;
		if (ans.second)	Size++;
		return ans;
	}
	node*findmin(node*t)
	{
		if (t == NULL)	return t;
		while (t->ls != NULL)	t = t->ls;
		return t;
	}
	void some(node*&p, node*q)
	{
		if (p == q)
		{
			p = p->rs;
			return;
		}
		some(p->ls,q);
		balance(p);
	}
	void remove(Key key, node*&t)
	{
		Compare cmp;
		if (cmp(key,t->val->first))	remove(key,t->ls);
		else if (cmp(t->val->first,key))	remove(key,t->rs);
		else if (t->ls!=NULL && t->rs!=NULL)
		{
			node*t1 = t->nxt;
			some(t->rs,t1);
			t1->ls = t->ls, t1->rs = t->rs;
			if (t->val != NULL)	delete t->val;
			t->val = NULL;	delete t;	t = t1;
		}
		else
		{
			node* tmp = t;
			if (tmp->val != NULL)	delete tmp->val;
			t = (t->ls==NULL)?t->rs:t->ls;	tmp->val = NULL; 
			delete tmp;
		}
		balance(t);
	}
	void erase(iterator pos)
	{
		if (pos.end!=endnode || pos==End || pos.val==NULL)
		{
			throw invalid_iterator();
			return;
		}
		--Size;	node*t = pos.val;
		t->nxt->pre = t->pre;
		if (pos == Begin)	++Begin, ++cBegin;
		else	t->pre->nxt = t->nxt;
		remove(pos->first,root);
	}
	size_t count(const Key &key) const
	{
		const_iterator zz = find(key);
		if (zz == End)	return 0;
		return 1;
	}
	iterator find(const Key &key)
	{
		node*now = root;
		while (now != NULL)
		{
			Compare cmp;
			if (cmp(key,now->val->first))	now = now->ls;
			else if (cmp(now->val->first,key))	now = now->rs;
			else
			{
				iterator tmp;
				tmp.val = now;
				tmp.end = endnode;
				return tmp;
			}
		}
		return End;
	}
	iterator findN(const Key &key)
	{
		node*now = root;	Compare cmp;
		iterator tmp;	tmp.val = tmp.end = endnode;
		while (now != NULL)
		{
			if (cmp(key,now->val->first))	tmp.val = now, now = now->ls;
			else if (cmp(now->val->first,key))	now = now->rs;
			else	{tmp.val = now;	break;}
		}
		return tmp;
	}
	const_iterator find(const Key &key) const
	{
		node*now = root;
		while (now != NULL)
		{
			Compare cmp;
			if (cmp(key,now->val->first))	now = now->ls;
			else if (cmp(now->val->first,key))	now = now->rs;
			else
			{
				const_iterator tmp;
				tmp.val = now;
				tmp.end = endnode;
				return tmp;
			}
		}
		return cEnd;
	}
		
	void IN(node*&A)
	{
	/*	if (now == NULL)
		{
			A = NULL;
			return;
		}
		T t;
		Key key(filein);
		filein t
		A = new node(pair(key,t),NULL,NULL);
		A->height = now->height;
		int havel(filein), haver(filein);
		if (havel)	Cpy(A->ls,now->ls);
		if (haver)	Cpy(A->rs,now->rs);*/
	}
	void input()
	{
		if (Size != 0)
		{
			/*int x;
			filein x
			while (x--)
			{
				T t;
				Key key(filein);
				filein t
				insert(pair(key,t))
			}
			return;*/
		}
		/*filein Size
		IN(root);
		if (root != NULL)	Begin.val = root;
		while (Begin.val->ls != NULL)	Begin.val = Begin.val->ls;
		node* tend = NULL;	cBegin.val = Begin.val;
		if (Size > 0)	{makepn(root,tend); tend->nxt = endnode;}
		endnode->pre = tend;*/
	}
	void Out(node *t)
	{
		/* fileout t->val->first
		fileout t->val->second
		fileout t->ls==NULL?0:1
		fileout t->rs==NULL?0:1
		if (t->ls != NULL)	Out(t->ls);
		if (t->rs != NULL)	Out(t->rs);
		*/
	}
	void output()
	{
		//fileout Size
		Out(root);
	}
private:
	int Size;
	iterator Begin, End;
	const_iterator cBegin, cEnd;
	node *root, *endnode;
};

}

#endif
