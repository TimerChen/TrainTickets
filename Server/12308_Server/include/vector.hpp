#ifndef TTD_VECTOR_HPP
#define TTD_VECTOR_HPP

#include "include/exceptions.hpp"
#include "include/utility.hpp"
#include "include/smartpoint.hpp"


#include <climits>
#include <cstddef>

#include <new>

namespace ttd {

/**
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */
template <typename T> class vector {
    // typedef unsigned int size_t;
    shared_ptr<T, true, true> container;
    size_t sz;
    size_t upbound;
    void doublespace() {
        if (sz == upbound) {
            size_t up = upbound;
            if (upbound == 0)
                up = 1;
            else
                up = 2 * upbound;
            shared_ptr<T, true, true> tmp =
                reinterpret_cast<T *>(operator new(sizeof(T) * up));

            for (size_t i = 0; i != sz; ++i) {
                new (static_cast<void *>(&tmp[i])) T(container[i]);
                container[i].~T();
            }
            container = tmp;
            upbound = up;
        }
    }

  public:
    /**
     * TODO
     * a type for actions of the elements of a vector, and you should write
     *   a class named const_iterator with same interfaces.
     */
    /**
     * you can see RandomAccessIterator at CppReference for help.
     */
    friend class iterator;
    class const_iterator;
    class iterator {
      private:
        /**
         * TODO add data members
         *   just add whatever you want.
         */

        friend iterator vector::begin();
        friend iterator vector::end();
        friend iterator vector::insert(iterator pos, const T &value);
        friend iterator vector::insert(const size_t &ind, const T &value);
        friend iterator vector::erase(iterator pos);
        friend iterator vector::erase(const size_t &ind);
        friend class const_iterator;

        // T *it;
        normal_ptr<const shared_ptr<T, true, true>> oriplace;
        size_t pos;
        iterator(size_t _pos, const shared_ptr<T, true, true> *_c)
            : oriplace(_c), pos(_pos) {}

      public:
        /**
         * return a new iterator which pointer n-next elements
         *   even if there are not enough elements, just return the answer.
         * as well as operator-
         */
        iterator(const iterator &it) {
            pos = it.pos;
            oriplace = it.oriplace;
        }
        iterator operator+(const int &n) const {
            // TODO
            return iterator(pos + n, &(*oriplace));
        }
        iterator operator-(const int &n) const {
            // TODO
            return iterator(pos - n, &(*oriplace));
        }
        // return th distance between two iterator,
        // if these two iterators points to different vectors, throw
        // invaild_iterator.
        int operator-(const iterator &rhs) const {
            // TODO
            if (*oriplace != *rhs.oriplace) throw invalid_iterator();
            return pos - rhs.pos;
        }
        int operator-(const const_iterator &rhs) const {
            // TODO
            if (*oriplace != *rhs.oriplace) throw invalid_iterator();
            return int(pos) - rhs.pos;
        }
        iterator operator+=(const int &n) {
            // TODO
            pos += n;
            return *this;
        }
        iterator operator-=(const int &n) {
            // TODO
            pos -= n;
            return *this;
        }
        /**
         * TODO iter++
         */
        iterator operator++(int) {
            iterator tmp(pos, &(*oriplace));
            ++pos;
            return tmp;
        }
        /**
         * TODO ++iter
         */
        iterator &operator++() {
            ++pos;
            return *this;
        }
        /**
         * TODO iter--
         */
        iterator operator--(int) {
            iterator tmp(pos, &(*oriplace));
            --pos;
            return tmp;
        }
        /**
         * TODO --iter
         */
        iterator &operator--() {
            --pos;
            return *this;
        }
        /**
         * TODO *it
         */
        T &operator*() const { return (*oriplace)[pos]; }
        /**
         * a operator to check whether two iterators are same (pointing to the
         * same memory).
         */
        bool operator==(const iterator &rhs) const {
            return (*oriplace == *(rhs.oriplace) && pos == rhs.pos);
        }
        bool operator==(const const_iterator &rhs) const {
            return (*oriplace == *(rhs.oriplace) && pos == rhs.pos);
        }
        /**
         * some other operator for iterator.
         */
        bool operator!=(const iterator &rhs) const {
            return *oriplace != *(rhs.oriplace) || pos != rhs.pos;
        }
        bool operator!=(const const_iterator &rhs) const {
            return *oriplace != *(rhs.oriplace) || pos != rhs.pos;
        }
    };
    /**
     * TODO
     * has same function as iterator, just for a const object.
     */
    class const_iterator {
      private:
        /**
        * TODO add data members
        *   just add whatever you want.
        */
        friend const_iterator vector::cbegin() const;
        friend const_iterator vector::cend() const;
        friend class iterator;
        normal_ptr<const shared_ptr<T, true, true>> oriplace;
        size_t pos;
        const_iterator(size_t _pos, const shared_ptr<T, true, true> *_c)
            : oriplace(_c), pos(_pos) {}

      public:
        /**
        * return a new iterator which pointer n-next elements
        *   even if there are not enough elements, just return the answer.
        * as well as operator-
        */
        const_iterator(const const_iterator &it) {
            pos = it.pos;
            oriplace = it.oriplace;
        }
        const_iterator operator+(const int &n) const {
            // TODO
            return const_iterator(pos + n, &(*oriplace));
        }
        const_iterator operator-(const int &n) const {
            // TODO
            return const_iterator(pos - n, &(*oriplace));
        }
        // return th distance between two iterator,
        // if these two iterators points to different vectors, throw
        // invaild_iterator.
        int operator-(const iterator &rhs) const {
            // TODO
            if (*oriplace != *rhs.oriplace) throw invalid_iterator();
            return int(pos) - rhs.pos;
        }
        int operator-(const const_iterator &rhs) const {
            // TODO
            if (*oriplace != *rhs.oriplace) throw invalid_iterator();
            return int(pos) - rhs.pos;
        }
        const_iterator operator+=(const int &n) {
            // TODO
            pos += n;
            return *this;
        }
        const_iterator operator-=(const int &n) {
            // TODO
            pos -= n;
            return *this;
        }
        /**
        * TODO iter++
        */
        const_iterator operator++(int) {
            const_iterator tmp(pos, &(*oriplace));
            ++pos;
            return tmp;
        }
        /**
        * TODO ++iter
        */
        const_iterator &operator++() {
            ++pos;
            return *this;
        }
        /**
        * TODO iter--
        */
        const_iterator operator--(int) {
            const_iterator tmp(pos, &(*oriplace));
            --pos;
            return tmp;
        }
        /**
        * TODO --iter
        */
        const_iterator &operator--() {
            --pos;
            return *this;
        }
        /**
        * TODO *it
        */
        const T &operator*() const { return (*oriplace)[pos]; }
        /**
        * a operator to check whether two iterators are same (pointing to the
        * same memory).
        */
        bool operator==(const iterator &rhs) const {
            return (*oriplace == *rhs.oriplace && pos == rhs.pos);
        }
        bool operator==(const const_iterator &rhs) const {
            return (*oriplace == *rhs.oriplace && pos == rhs.pos);
        }
        /**
        * some other operator for iterator.
        */
        bool operator!=(const iterator &rhs) const {
            return (*oriplace != *rhs.oriplace || pos != rhs.pos);
        }
        bool operator!=(const const_iterator &rhs) const {
            return (*oriplace != *rhs.oriplace || pos != rhs.pos);
        }
    };
    /**
     * TODO Constructs
     * Atleast three: default constructor, copy constructor and a constructor
     * for std::vector
     */
    vector() : container(nullptr), sz(0), upbound(0) {}
    vector(const vector &other) {
        upbound = other.capacity();
        sz = other.size();
        container = reinterpret_cast<T *>(operator new(sizeof(T) * upbound));
        for (size_t i = 0; i != sz; ++i) {
            new (static_cast<void *>(&container[i])) T(other[i]);
        }
    }
    /* template <typename A> vector(const A &other) {
         upbound = other.capacity();
         sz = other.size();
         container = reinterpret_cast<T *>(operator new(sizeof(T) * upbound));
         for (int i = 0; i != sz; ++i) {
             new (static_cast<void *>(&container[i])) T(other[i]);
         }
     }*/
    vector(size_t n)
        : container(reinterpret_cast<T *>(operator new(sizeof(T) * n))), sz(n), upbound(n){
        for (size_t i = 0; i < n; ++i) {
            new (static_cast<void *>(&container[i])) T();
        }
    }
    /**
     * TODO Destructor
     */
    ~vector() {
        // size_t osz = sz;
        for (size_t i = 0; i != sz; ++i) {
            container[i].~T();
        }
    }
    /**
     * TODO Assignment operator
     */
    vector &operator=(const vector &other) {
        for (size_t i = 0; i != sz; ++i) {
            container[i].~T();
        }
        upbound = other.capacity();
        sz = other.size();
        container = reinterpret_cast<T *>(operator new(sizeof(T) * upbound));
        for (size_t i = 0; i != sz; ++i) {
            new (static_cast<void *>(&container[i])) T(other[i]);
        }
        return *this;
    }
    /**
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     */
    T &at(const size_t &pos) {
        if (pos < 0 || pos >= sz) throw index_out_of_bound();
        return container[pos];
    }
    const T &at(const size_t &pos) const {
        if (pos < 0 || pos >= sz) throw index_out_of_bound();
        return container[pos];
    }
    /**
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     * !!! Pay attentions
     *   In STL this operator does not check the boundary but I want you to do.
     */
    T &operator[](const size_t &pos) {
        if (pos < 0 || pos > sz) throw index_out_of_bound();
        return container[pos];
    }
    const T &operator[](const size_t &pos) const {
        if (pos < 0 || pos >= sz) throw index_out_of_bound();
        return container[pos];
    }
    /**
     * access the first element.
     * throw container_is_empty if size == 0
     */
    const T &front() const {
        if (sz == 0) throw container_is_empty();
        return container[0];
    }
    /**
     * access the last element.
     * throw container_is_empty if size == 0
     */
    const T &back() const {
        if (sz == 0) throw container_is_empty();
        return container[sz - 1];
    }
    /**
     * returns an iterator to the beginning.
     */
    iterator begin() { return iterator(0, &container); }
    const_iterator cbegin() const { return const_iterator(0, &container); }
    /**
     * returns an iterator to the end.
     */
    iterator end() { return iterator(sz, &container); }
    const_iterator cend() const { return const_iterator(sz, &container); }
    /**
     * checks whether the container is empty
     */
    bool empty() const { return sz == 0; }
    /**
     * returns the number of elements
     */
    size_t size() const { return sz; }
    /**
     * returns the number of elements that can be held in currently allocated
     * storage.
     */
    size_t capacity() const { return upbound; }
    /**
     * clears the contents
     */
    void clear() {
        for (size_t i = 0; i != sz; ++i) {
            container[i].~T();
        }
        container = nullptr;
        upbound = 0;
        sz = 0;
    }
    /**
     * inserts value before pos
     * returns an iterator pointing to the inserted value.
     */
    iterator insert(iterator pos, const T &value) {
        doublespace();
        new (static_cast<void *>(&container[sz])) T(container[sz - 1]);
        for (size_t i = sz - 1; i != pos.pos; --i) {
            container[i].~T();
            new (static_cast<void *>(&container[i])) T(container[i - 1]);
        }
        container[pos.pos].~T();
        new (static_cast<void *>(&container[pos.pos])) T(value);
        ++sz;
        return iterator(pos.pos, &container);
    }
    /**
     * inserts value at index ind.
     * after inserting, this->at(ind) == value is true
     * returns an iterator pointing to the inserted value.
     * throw index_out_of_bound if ind > size (in this situation ind can be size
     * because after inserting the size will increase 1.)
     */
    iterator insert(const size_t &ind, const T &value) {
        if (ind < 0 || ind > sz) throw index_out_of_bound();
        return insert(iterator(ind, container), value);
    }
    /**
     * removes the element at pos.
     * return an iterator pointing to the following element.
     * If the iterator pos refers the last element, the end() iterator is
     * returned.
     */
    iterator erase(iterator pos) {
        for (size_t i = pos.pos; i != sz - 1; ++i) {
            container[i].~T();
            new (static_cast<void *>(&container[i])) T(container[i + 1]);
        }
        container[sz - 1].~T();
        --sz;
        return pos;
    }
    /**
     * removes the element with index ind.
     * return an iterator pointing to the following element.
     * throw index_out_of_bound if ind >= size
     */
    iterator erase(const size_t &ind) {
        if (ind < 0 || ind >= size) throw index_out_of_bound();
        return erase(iterator(ind, container));
    }
    /**
     * adds an element to the end.
     */
    void push_back(const T &value) {
        doublespace();
        new (static_cast<void *>(&container[sz])) T(value);
        ++sz;
    }
    /**
     * remove the last element from the end.
     * throw container_is_empty if size() == 0
     */
    void pop_back() {
        if (sz == 0) throw container_is_empty();
        container[sz - 1].~T();
        --sz;
    }
};
}

/*
 *
 * Writed by Jingxiao Chen.
 *
 *  [Passed test]
 *
 */
template<class T>
QDataStream& operator << (QDataStream& out, const ttd::vector<T>&v)
{
	out << (quint32)(v.size());
	for (size_t i = 0; i < v.size(); ++i)
		out << v[i] ;
	return out;
}

template<class T>
QDataStream& operator >> (QDataStream& in, ttd::vector<T>&v)
{
	v.clear();
	quint32 tmp_n;
	in >> tmp_n;
	v = ttd::vector<T>( tmp_n );
	for( size_t i = 0; i < tmp_n; ++i )
		in >> v[i];
	return in;
}

#endif
