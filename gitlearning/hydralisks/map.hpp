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

#include<iostream>

namespace sjtu {

//Treap

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map {
public:
	typedef pair<const Key, T> value_type;
	
	struct node {
		value_type* val;
		node* pre, * nxt;
		
		node () {
			val = NULL;
			pre = NULL;
			nxt = NULL;
		}
		node (const value_type &v, node* p = NULL, node* n = NULL) {
			val = new value_type (v);
			pre = p;
			nxt = n;
		}
		~node () {
			if (val != NULL) delete val;
		}
	};
	
		
	int ran_a = 19980217;
	int ran_b = 20170607;
	int ran_c = 20130901;
	int ran_ans = 0;
	
		
	int getRand () {
		ran_ans *= ran_a;
		ran_ans += ran_b;
		ran_ans %= ran_c;
		return ran_ans;
	}
		
	struct tree_node {
	
		
		int weight;
		node* tru;
		tree_node* ls, * rs;
		
		tree_node (int w) {
			weight = w;
			tru = new node;
			ls = NULL;
			rs = NULL;
		}
		tree_node (int w, const value_type &v) {
			weight = w;
			tru = new node (v);
			ls = NULL;
			rs = NULL;
		}
		~tree_node () {
			delete tru;
		}
	
	};
	
		
		tree_node* tree_node_copy (tree_node* otherTreeNode) {
			if (otherTreeNode == NULL) return NULL;
			tree_node* nww; 
			if (otherTreeNode -> tru -> val == NULL) nww = new tree_node (otherTreeNode -> weight);
			else nww = new tree_node (otherTreeNode -> weight, *(otherTreeNode -> tru -> val));
			nww -> ls = tree_node_copy (otherTreeNode -> ls);
			nww -> rs = tree_node_copy (otherTreeNode -> rs);
			return nww;
		}
		
		void tree_node_delete (tree_node* nww) {
			if (nww == NULL) return;
			if (nww -> ls != NULL) {
				tree_node_delete (nww -> ls);
			}
			if (nww -> rs != NULL) {
				tree_node_delete (nww -> rs);
			}
			delete nww;
			return;
		}
		
	class const_iterator;
	class iterator {
	private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		
		node* itt;
		
	public:
		friend class map;

		iterator() {
			itt = NULL;
			// TODO
		}
		iterator(const iterator &other) {
			itt = other.itt;
			// TODO
		}
		iterator operator=(const iterator &other) {
			itt = other.itt;
		}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp;
			tmp.itt = itt;
			if (itt -> nxt == NULL) throw invalid_iterator ();
			itt = itt -> nxt;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator & operator++() {
			if (itt -> nxt == NULL) throw invalid_iterator ();
			itt = itt -> nxt;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			iterator tmp;
			tmp.itt = itt;
			if (itt -> pre == NULL) throw invalid_iterator ();
			itt = itt -> pre;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator & operator--() {
			if (itt -> pre == NULL) throw invalid_iterator ();
			itt = itt -> pre;
			return *this;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		value_type & operator*() const {
			return *(itt -> val);
		}
		bool operator==(const iterator &rhs) const {
			return itt == rhs.itt;
		}
		bool operator==(const const_iterator &rhs) const {
			return itt == rhs.itt;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
			return itt != rhs.itt;
		}
		bool operator!=(const const_iterator &rhs) const {
			return itt != rhs.itt;
		}

		/**
		 * for the support of it->first. 
		 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
		 */
		value_type* operator->() const noexcept {
			return itt -> val;
		}
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		private:
			// data members.
			node* itt;
			
		public:
			friend class map;
			
			const_iterator() {
				// TODO
				itt = NULL;
			}
			const_iterator(const const_iterator &other) {
				// TODO
				itt = other.itt;
			}
			const_iterator(const iterator &other) {
				// TODO
				itt = other.itt;
			}
			
			const_iterator operator=(const const_iterator &other) {
				itt = other.itt;
			}
			const_iterator operator=(const iterator &other) {
				itt = other.itt;
			}
			const_iterator operator++(int) {
				const_iterator tmp;
				tmp.itt = itt;
				if (itt -> nxt == NULL) throw invalid_iterator ();
				itt = itt -> nxt;
				return tmp;
			}
			const_iterator & operator++() {
				if (itt -> nxt == NULL) throw invalid_iterator ();
				itt = itt -> nxt;
				return *this;
			}
			const_iterator operator--(int) {
				const_iterator tmp;
				tmp.itt = itt;
				if (itt -> pre == NULL) throw invalid_iterator ();
				itt = itt -> pre;
				return tmp;
			}
			const_iterator & operator--() {
				if (itt -> pre == NULL) throw invalid_iterator ();
				itt = itt -> pre;
				return *this;
			}
			const value_type & operator*() const {
				return *(itt -> val);
			}
			bool operator==(const iterator &rhs) const {
				return itt == rhs.itt;
			}
			bool operator==(const const_iterator &rhs) const {
				return itt == rhs.itt;
			}
			bool operator!=(const iterator &rhs) const {
				return itt != rhs.itt;
			}
			bool operator!=(const const_iterator &rhs) const {
				return itt != rhs.itt;
			}
			const value_type* operator->() const noexcept {
				return itt -> val;
			}
			// And other methods in iterator.
			// And other methods in iterator.
			// And other methods in iterator.
	};
	/**
	 * TODO two constructors
	 */
	 
	
private:
	
	
	size_t siz;
	tree_node* root;
	node* truend;
	iterator beginNode, endNode;
	const_iterator c_beginNode, c_endNode;
	

	Compare cmp;
	
	tree_node* merge (tree_node* a, tree_node* b) {
		if (a == NULL) return b;
		if (b == NULL) return a;
		if (a -> weight < b -> weight) {
			a -> rs = merge (a -> rs, b);
			return a;
		}
		else {
			b -> ls = merge (a, b -> ls);
			return b;
		}
	}
	
	struct tnpair {
		tree_node* fir, * sec;
		tnpair (tree_node* a, tree_node* b) {
			fir = a;
			sec = b;
		}
	};
	
	tnpair split (tree_node* a, const Key &k) {
		if (a == NULL) return tnpair (NULL, NULL);
		if (cmp (a -> tru -> val -> first, k)) {
			tnpair km = split (a -> rs, k);
			a -> rs = km.fir;
			tnpair tnp (a, km.sec);
			return tnp;
		}
		else {
			tnpair km = split (a -> ls, k);
			a -> ls = km.sec;
			tnpair tnp (km.fir, a);
			return tnp;
		}
	}
	
	tnpair splitt (tree_node* a, const Key &k) {
		if (a == NULL) return tnpair (NULL, NULL);
		if (!cmp (k, a -> tru -> val -> first)) {
			tnpair km = splitt (a -> rs, k);
			a -> rs = km.fir;
			tnpair tnp (a, km.sec);
			return tnp;
		}
		else {
			tnpair km = splitt (a -> ls, k);
			a -> ls = km.sec;
			tnpair tnp(km.fir, a);
			return tnp;
		}
	}
	
	node* serch (tree_node* a, const Key &k) {
		if (a == NULL) return NULL;
		if (!cmp (a -> tru -> val -> first, k) && !cmp (k, a -> tru -> val -> first)) {
			return a -> tru;
		}
		else {
			if (cmp (a -> tru -> val -> first, k)) {
				return serch (a -> rs, k);
			}
			else {
				return serch (a -> ls, k);
			}
		}
	}
	
	node* serchPre (tree_node* a, const Key &k) {
		if (a == NULL) return NULL;
		if (cmp (a -> tru -> val -> first, k)) {
			node* np = serchPre (a -> rs, k);
			if (np == NULL) return a -> tru;
			else return np;
		}
		else {
			return serchPre (a -> ls, k);
		}
	}
	
	node* serchNxt (tree_node* a, const Key &k) {
		if (a == NULL) return NULL;
		if (cmp (a -> tru -> val -> first, k)) {
			return serchPre (a -> rs, k);
		}
		else {
			node* ns = serchNxt (a -> ls, k);
			if (ns == NULL) return a -> tru;
			else return ns;
		}
	}
	
	tree_node* create (const Key &k) {
		tree_node* tn = new tree_node (getRand (), value_type (k, T()));
		tn -> tru -> pre = serchPre (root, k);
		tn -> tru -> nxt = serchNxt (root, k);
		return tn;
	}
	
	void ins (tree_node* nww) {
		
		if (root == NULL) {
			root = nww;
			nww -> tru -> pre = NULL;
			nww -> tru -> nxt = truend;
			truend -> pre = nww -> tru;
			c_beginNode.itt = beginNode.itt = nww -> tru;
			return;
		}
		
		tnpair km = split (root, nww -> tru -> val -> first);
		if (km.fir == NULL) {
			c_beginNode.itt = beginNode.itt = nww -> tru;
			nww -> tru -> pre = NULL;
		}
		else {
			tree_node* prr = km.fir;
			while (prr -> rs != NULL) prr = prr -> rs;
			nww -> tru -> pre = prr -> tru;
			prr -> tru -> nxt = nww -> tru;
		}
		if (km.sec == NULL) {
			truend -> pre = nww -> tru;
			nww -> tru -> nxt = truend;
		}
		else {
			tree_node* nxx = km.sec;
			while (nxx -> ls != NULL) nxx = nxx -> ls;
			nww -> tru -> nxt = nxx -> tru;
			nxx -> tru -> pre = nww -> tru;
		}
		root = merge (km.fir, merge (nww, km.sec));
	}
	
	void rem (const Key &k) {
		tnpair km = split (root, k);
		tnpair kmm = splitt (km.sec, k);
		if (kmm.fir == NULL) std::cout <<"hhhh"<<'\n';
		delete kmm.fir;
		root = merge (km.fir, kmm.sec);
	}
	
	
public:
	/**
	 * the internal type of data.
	 * it should have a default constructor, a copy constructor.
	 * You can use sjtu::map as value_type by typedef.
	 */
	/**
	 * see BidirectionalIterator at CppReference for help.
	 *
	 * if there is anything wrong throw invalid_iterator.
	 *     like it = map.begin(); --it;
	 *       or it = map.end(); ++end();
	 */
	void fixpn (tree_node* &nww, node* &prr) {
		if (nww -> ls != NULL) fixpn (nww -> ls, prr);
		nww -> tru -> pre = prr;
		if (prr != NULL) nww -> tru -> pre -> nxt = nww -> tru;
		prr = nww -> tru;
		if (nww -> rs != NULL) fixpn (nww -> rs, prr);
	}
	
	
	map() {
		truend = new node;
		siz = 0;
		root = NULL;
		beginNode.itt = endNode.itt = c_beginNode.itt = c_endNode.itt = truend;
	}
	map(const map &other) {
		truend = new node ();
		siz = other.siz;
		root = tree_node_copy (other.root);
		if (root == NULL) beginNode.itt = endNode.itt = c_beginNode.itt = c_endNode.itt = truend;
		else {
			tree_node* tn = root;
			while (tn -> ls != NULL) tn = tn -> ls;
			c_beginNode.itt = beginNode.itt = tn -> tru;
			node* endd = NULL;
			fixpn (root, endd);
			endd -> nxt = truend;
			truend -> pre = endd;
			c_endNode.itt = endNode.itt = truend;
		}
		return;
	}
	/**
	 * TODO assignment operator
	 */
	map & operator=(const map &other) {
		if (this == &other) return *this;
		siz = other.siz;
		root = tree_node_copy (other.root);
		if (root == NULL) beginNode.itt = endNode.itt = c_beginNode.itt = c_endNode.itt = truend;
		else {
			tree_node* tn = root;
			while (tn -> ls != NULL) tn = tn -> ls;
			c_beginNode.itt = beginNode.itt = tn -> tru;
			node* endd = NULL;
			fixpn (root, endd);
			endd -> nxt = truend;
			truend -> pre = endd;
			c_endNode.itt = endNode.itt = truend;
		}
		return *this;
	}
	/**
	 * TODO Destructors
	 */
	~map() {
		tree_node_delete (root);
		delete truend;
		return;
	}
	
	/**
	 * TODO
	 * access specified element with bounds checking
	 * Returns a reference to the mapped value of the element with key equivalent to key.
	 * If no such element exists, an exception of type `index_out_of_bound'
	 */
	T & at(const Key &key) {
		node* tmp = serch (root, key);
		if (tmp == NULL) throw index_out_of_bound ();
		else return tmp -> val -> second;
	}
	const T & at(const Key &key) const {
		const_iterator a = find (key);
		if (a.itt == c_endNode.itt) throw index_out_of_bound ();
		else return a -> second;
	}
	/**
	 * TODO
	 * access specified element 
	 * Returns a reference to the value that is mapped to a key equivalent to key,
	 *   performing an insertion if such key does not already exist.
	 */
	T & operator[](const Key &key) {
		node* tmp = serch (root, key);
		if (tmp == NULL) {
			tree_node* nww = create (key);
			ins (nww);
			siz++;
			return nww -> tru -> val -> second;
		}
		else {
			return tmp -> val -> second;
		}
	}
	/**
	 * behave like at() throw index_out_of_bound if such key does not exist.
	 */
	const T & operator[](const Key &key) const {
		const_iterator a = find (key);
		if (a.itt == c_endNode.itt) throw index_out_of_bound ();
		else return a -> second;
	}
	/**
	 * return a iterator to the beginning
	 */
	iterator begin() {
		return beginNode;
	}
	const_iterator cbegin() const {
		return c_beginNode;
	}
	/**
	 * return a iterator to the end
	 * in fact, it returns past-the-end.
	 */
	iterator end() {
		return endNode;
	}
	const_iterator cend() const {
		return c_endNode;
	}
	/**
	 * checks whether the container is empty
	 * return true if empty, otherwise false.
	 */
	bool empty() const {
		if (siz == 0) return true;
		else return false;
	}
	/**
	 * returns the number of elements.
	 */
	size_t size() const {
		return siz;
	}
	/**
	 * clears the contents
	 */
	void clear() {
		siz = 0;
		tree_node_delete (root);
		root = NULL;
		c_beginNode.itt = beginNode.itt = truend;
	}
	/**
	 * insert an element.
	 * return a pair, the first of the pair is
	 *   the iterator to the new element (or the element that prevented the insertion), 
	 *   the second one is true if insert successfully, or false.
	 */
	pair<iterator, bool> insert(const value_type &value) {
		iterator a;
		a.itt = serch (root, value.first);
		if (a.itt != NULL) {
			pair <iterator, bool> b;
			b.first = a;
			b.second = false;
			return b;
		}
		else {
			tree_node* nww = create (value.first);
			nww -> tru -> val -> second = value.second;
			ins (nww);
			siz++;
			a.itt = serch (root, value.first);
			pair <iterator, bool> b;
			b.first = a;
			b.second = true;
			return b;
		}
	}
	/**
	 * erase the element at pos.
	 *
	 * throw if pos pointed to a bad element (pos == this->end() || pos points an element out of this)
	 */
	void erase(iterator pos) {
		if (pos.itt -> val == NULL) throw invalid_iterator ();
		node* tmp = serch (root, pos -> first);
		if (tmp == NULL || pos.itt != tmp) throw invalid_iterator ();
		siz--;
		if (beginNode == pos) c_beginNode.itt = beginNode.itt = tmp -> nxt;
		if (tmp -> pre != NULL) tmp -> pre -> nxt = tmp -> nxt;
		tmp -> nxt -> pre = tmp -> pre;
		rem (pos -> first);
	}
	/**
	 * Returns the number of elements with key 
	 *   that compares equivalent to the specified argument,
	 *   which is either 1 or 0 
	 *     since this container does not allow duplicates.
	 * The default method of check the equivalence is !(a < b || b > a)
	 */
	size_t count(const Key &key) const {
		const_iterator tmp = find (key);
		if (tmp.itt == truend) return 0;
		else return 1;
	}
	/**
	 * Finds an element with key equivalent to key.
	 * key value of the element to search for.
	 * Iterator to an element with key equivalent to key.
	 *   If no such element is found, past-the-end (see end()) iterator is returned.
	 */
	iterator find(const Key &key) {
		node* tmp = serch (root, key);
		if (tmp == NULL) return endNode;
		else {
			iterator a;
			a.itt = tmp;
			return a;
		}
	}
	const_iterator find(const Key &key) const {
		tree_node* nww = root;
		while (nww != NULL) {
			if (cmp (nww -> tru -> val -> first, key)) nww = nww -> rs;
			else if (cmp (key, nww -> tru -> val -> first)) nww = nww -> ls;
				else {
					const_iterator a;
					a.itt = nww -> tru;
					return a;
				}
		}
		return c_endNode;
	}
	/*
	void sh (tree_node* nww) {
		if (nww == NULL) return;
		if (nww -> ls != NULL) sh (nww -> ls);
		std::cout << nww->tru->val->first<<' '<<nww->tru->val->second<<std::endl;
		if (nww -> rs != NULL) sh (nww -> rs);
	}
	
	void show () {
		sh (root);
	}
	*/
	
};

}

#endif
