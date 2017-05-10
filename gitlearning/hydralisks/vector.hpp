#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu
{
/**
 * a data container like std::vector
 * store data in a succ+
*/
template <class T>
class vector
{
	friend class iterator;
	friend class const_iterator;

  private:
	size_t finish;
	size_t end_of_storage;
	T *data;

	void resize()
	{
		T *tmp;

		size_t new_end_of_storage;
		new_end_of_storage = 2 * end_of_storage;

		tmp = reinterpret_cast<T *>(operator new(sizeof(T) * new_end_of_storage));

		for (size_t i = 0; i < finish; ++i)
		{
			new (&tmp[i]) T(data[i]);
		}

		T *temp = data;
		for (size_t i = 0; i < finish; ++i)
		{
			temp->~T();
			++temp;
		}
		::operator delete(data);

		end_of_storage = new_end_of_storage;
		data = tmp;
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
	class const_iterator;
	class iterator
	{
		friend class const_iterator;
		friend class vector;

	  private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		size_t ptr;
		T *vector_head;

	  public:
		iterator(const iterator &itr)
		{
			vector_head = itr.vector_head;
			ptr = itr.ptr;
		}
		iterator(T *_vector_head, const size_t &_ptr)
		{
			vector_head = _vector_head;
			ptr = _ptr;
		}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		iterator operator+(const int &n) const
		{
			//TODO
			return iterator(vector_head, ptr + n);
		}
		iterator operator-(const int &n) const
		{
			//TODO
			return iterator(vector_head, ptr - n);
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const
		{
			//TODO
			if (vector_head != rhs.vector_head)
				return invalid_iterator();
			return (ptr - rhs.ptr);
		}

		int operator-(const const_iterator &rhs) const
		{
			//TODO
			if (vector_head != rhs.vector_head)
				return invalid_iterator();
			return (ptr - rhs.ptr);
		}

		iterator operator+=(const int &n)
		{
			//TODO
			ptr += n;
			return *this;
		}
		iterator operator-=(const int &n)
		{
			//TODO
			ptr -= n;
			return *this;
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int)
		{
			iterator tmp(*this);
			++ptr;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator &operator++()
		{
			++ptr;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int)
		{
			iterator tmp(*this);
			--ptr;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator &operator--()
		{
			--ptr;
			return *this;
		}
		/**
		 * TODO *it
		 */
		T &operator*() const
		{
			return *(vector_head + ptr);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const
		{
			return (vector_head == rhs.vector_head && ptr == rhs.ptr);
		}
		bool operator==(const const_iterator &rhs) const
		{
			return (vector_head == rhs.vector_head && ptr == rhs.ptr);
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const
		{
			return (vector_head != rhs.vector_head || ptr != rhs.ptr);
		}
		bool operator!=(const const_iterator &rhs) const
		{
			return (vector_head != rhs.vector_head || ptr != rhs.ptr);
		}
	};
	/**
	 * TODO
	 * has same function as iterator, just for a const object.
	 */
	class const_iterator
	{
		friend class iterator;
		friend class vector;

	  private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		size_t ptr;
		const T *vector_head;

	  public:
		const_iterator(const iterator &itr) : vector_head(itr.vector_head), ptr(itr.ptr) {}
		const_iterator(T *_vector_head, const size_t &_ptr) : vector_head(_vector_head), ptr(_ptr) {}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		const_iterator operator+(const int &n) const
		{
			//TODO
			return const_iterator(vector_head, ptr + n);
		}
		const_iterator operator-(const int &n) const
		{
			//TODO
			return const_iterator(vector_head, ptr - n);
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const
		{
			//TODO
			if (vector_head != rhs.vector_head)
				return invalid_iterator();
			return (ptr - rhs.ptr);
		}

		int operator-(const const_iterator &rhs) const
		{
			//TODO
			if (vector_head != rhs.vector_head)
				return invalid_iterator();
			return (ptr - rhs.ptr);
		}
		const_iterator operator+=(const int &n)
		{
			//TODO
			ptr += n;
			return *this;
		}
		const_iterator operator-=(const int &n)
		{
			//TODO
			ptr -= n;
			return *this;
		}
		/**
		 * TODO iter++
		 */
		const_iterator operator++(int)
		{
			const_iterator tmp(*this);
			++ptr;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		const_iterator &operator++()
		{
			++ptr;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		const_iterator operator--(int)
		{
			iterator tmp(*this);
			--ptr;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		const_iterator &operator--()
		{
			--ptr;
			return *this;
		}
		/**
		 * TODO *it
		 */
		const T &operator*() const
		{
			return *(vector_head + ptr);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const
		{
			return (vector_head == rhs.vector_head && ptr == rhs.ptr);
		}
		bool operator==(const const_iterator &rhs) const
		{
			return (vector_head == rhs.vector_head && ptr == rhs.ptr);
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const
		{
			return (vector_head != rhs.vector_head || ptr != rhs.ptr);
		}
		bool operator!=(const const_iterator &rhs) const
		{
			return (vector_head != rhs.vector_head || ptr != rhs.ptr);
		}
	};
	/**
	 * TODO Constructs
	 * Atleast three: default constructor, copy constructor and a constructor for std::vector
	 */

  public:
	vector(size_t iniSize = 20) : finish(0), end_of_storage(iniSize)
	{
		data = reinterpret_cast<T *>(operator new(sizeof(T) * end_of_storage));
	}
	vector(const vector &other)
	{
		end_of_storage = other.end_of_storage;
		finish = other.finish;

		data = reinterpret_cast<T *>(operator new(sizeof(T) * end_of_storage));
		for (size_t i = 0; i < finish; ++i)
		{
			new (&data[i]) T(other.data[i]);
		}
	}
	/**
	 * TODO Destructor
	 */
	~vector()
	{
		for (size_t i = 0; i < finish; ++i)
		{
			data[i].~T();
		}

		::operator delete(data);
	}
	/**
	 * TODO Assignment operator
	 */
	vector &operator=(const vector &other)
	{
		for (size_t i = 0; i < finish; ++i)
		{
			data[i].~T();
		}

		::operator delete(data);

		finish = other.finish;
		end_of_storage = other.end_of_storage;

		data = reinterpret_cast<T *>(operator new(end_of_storage * sizeof(T)));
		for (size_t i = 0; i < finish; ++i)
		{
			new (&data[i]) T(other.data[i]);
		}

		return *this;
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 */
	T &at(const size_t &pos)
	{
		if (pos >= finish)
			throw index_out_of_bound();
		return data[pos];
	}
	const T &at(const size_t &pos) const
	{
		if (pos >= finish)
			throw index_out_of_bound();
		return data[pos];
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 * !!! Pay attentions
	 *   In STL this operator does not check the boundary but I want you to do.
	 */
	T &operator[](const size_t &pos)
	{
		if (pos >= finish)
			throw index_out_of_bound();
		return data[pos];
	}
	const T &operator[](const size_t &pos) const
	{
		if (pos >= finish)
			throw index_out_of_bound();
		return data[pos];
	}
	/**
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T &front() const
	{
		if (finish == 0)
			throw container_is_empty();
		else
			return data[0];
	}
	/**
	 * access the last element.
	 * throw container_is_empty if size == 0
	 */
	const T &back() const
	{
		if (finish == 0)
			throw container_is_empty();
		else
			return data[finish - 1];
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin()
	{
		return iterator(data, 0);
	}
	const_iterator cbegin() const
	{
		return const_iterator(data, 0);
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end()
	{
		return iterator(data, finish);
	}
	const_iterator cend() const
	{
		return const_iterator(data, finish);
	}
	/**
	 * checks whether the container is empty
	 */
	bool empty() const
	{
		return (finish == 0);
	}
	/**
	 * returns the number of elements
	 */
	size_t size() const
	{
		size_t tmp = finish;
		return tmp;
	}
	/**
	 * returns the number of elements that can be held in currently allocated storage.
	 */
	size_t capacity() const
	{
		size_t cap = end_of_storage;
		return cap;
	}
	/**
	 * clears the contents
	 */
	void clear()
	{
		finish = 0;
	}
	/**
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value.
	 */
	iterator insert(iterator pos, const T &value)
	{
		size_t tmpPtr = pos.ptr;
		if (finish == end_of_storage)
			resize();

		for (size_t i = finish; i > tmpPtr; --i)
			new (&data[i]) T(data[i - 1]);
		new (&data[tmpPtr]) T(value);
		++finish;
		return iterator(data, tmpPtr);
	}
	/**
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value is true
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value)
	{
		if (ind > finish)
			throw index_out_of_bound();
		if (finish == end_of_storage)
			resize();

		for (size_t i = finish; i > ind; --i)
			new (&data[i]) T(data[i - 1]);
		new (&data[ind]) T(value);
		++finish;
		return iterator(data, ind);
	}
	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos)
	{
		for (size_t i = pos.ptr + 1; i < finish; ++i)
		{
			new (&data[i - 1]) T(data[i]);
		}
		--finish;
		return iterator(data, pos.ptr);
	}
	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind)
	{
		if (ind >= finish)
			throw index_out_of_bound();
		for (size_t i = ind + 1; i < finish; ++i)
		{
			new (&data[i - 1]) T(data[i]);
		}
		--finish;
		return iterator(data, ind);
	}
	/**
	 * adds an element to the end.
	 */
	void push_back(const T &value)
	{
		if (finish == end_of_storage)
			resize();
		new (&data[finish]) T(value);
		++finish;

		//	data[finish] = value;
		//++finish;
	}
	/**
	 * remove the last element from the end.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back()
	{
		if (finish == 0)
			throw container_is_empty();
		--finish;
	}
};
}

#endif
