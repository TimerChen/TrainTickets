#ifndef SMART_POINT
#define SMART_POINT

template <typename T, bool array, bool opnew>
class shared_ptr;
template <typename T>
class normal_ptr;
template <typename T, bool array, bool opnew>
class shared_ptr_Base
{
    friend class shared_ptr<T, array, opnew>;

  private:
    int cnt;
    T* baseptr;
    shared_ptr_Base(T* _ptr)
      : baseptr(_ptr)
      , cnt(1)
    {
    }
    void AddNewPoint()
    {
        ++cnt;
    }
    void distruction()
    {
        --cnt;
    }
    T& operator[](int i)
    {
        return baseptr[i];
    }
    const T& operator[](int i) const
    {
        return *baseptr[i];
    }
    ~shared_ptr_Base()
    {
        if (!opnew) {
            if (array)
                delete[] baseptr;
            else
                delete baseptr;
        } else {
            operator delete(baseptr);
        }
    }
};

template <typename T, bool array = false, bool opnew = false>
class shared_ptr
{
    shared_ptr_Base<T, array, opnew>* base;

  public:
    shared_ptr()
      : base(nullptr)
    {
    }
    shared_ptr(T* ptr)
      : base(new shared_ptr_Base<T, array, opnew>(ptr))
    {
    }
    shared_ptr(const shared_ptr& rs)
    {
        base = rs.base;
        base->AddNewPoint();
    }
    T& operator*()
    {
        return *(base->baseptr);
    }
    T& operator[](int i)
    {
        return (*base)[i];
    }
    const T& operator[](int i) const
    {
        return (*base)[i];
    }
    T* operator->()
    {
        return base->baseptr;
    }
    shared_ptr& operator=(const shared_ptr& rs)
    {
        if (!base) {
            base = rs.base;
            base->AddNewPoint();
        } else {
            base->distruction();
            if (base->cnt <= 0)
                delete base;
            base = rs.base;
            base->AddNewPoint();
        }
        return *this;
    }
    shared_ptr& operator=(T* rt)
    {
        if (base) {
            base->distruction();
            if (base->cnt <= 0)
                delete base;
        }
        base = new shared_ptr_Base<T, array, opnew>(rt);
        return *this;
    }
    bool operator==(const shared_ptr& rt) const
    {
        return base == rt.base;
    }
    bool operator!=(const shared_ptr& rt) const
    {
        return base != rt.base;
    }
    normal_ptr<T> operator+(const int pos)
    {
        return normal_ptr<T>(base->baseptr + pos);
    }
    normal_ptr<T> operator-(const int pos)
    {
        return normal_ptr<T>(base->baseptr - pos);
    }
    normal_ptr<T> operator+=(const int pos)
    {
        normal_ptr<T> tmp(base->baseptr + pos);
        this->~shared_ptr();
        return tmp;
    }
    normal_ptr<T> operator-=(const int pos)
    {
        normal_ptr<T> tmp(base->baseptr - pos);
        this->~shared_ptr();
        return tmp;
    }
    normal_ptr<T> operator++()
    {
        normal_ptr<T> tmp(base->baseptr + 1);
        this->~shared_ptr();
        return tmp;
    }

    ~shared_ptr()
    {
        base->distruction();
        if (base->cnt <= 0)
            delete base;
    }
};

template <typename T>
class normal_ptr
{
    T* ptr;

  public:
    normal_ptr(T* rp = nullptr)
      : ptr(rp)
    {
    }
    normal_ptr& operator=(const normal_ptr& rp)
    {
        ptr = rp.ptr;
    }
    bool operator==(const normal_ptr& other)
    {
        return other.ptr == ptr;
    }
    bool operator!=(const normal_ptr& other)
    {
        return other.ptr != ptr;
    }
    normal_ptr<T> operator+(const int pos)
    {
        return normal_ptr<T>(ptr + pos);
    }
    normal_ptr<T> operator-(const int pos)
    {
        return normal_ptr<T>(ptr - pos);
    }
    normal_ptr<T>& operator+=(const int pos)
    {
        ptr += pos;
        return *this;
    }
    normal_ptr<T>& operator-=(const int pos)
    {
        ptr -= pos;
        return *this;
    }
    normal_ptr<T>& operator++()
    {
        ++ptr;
        return *this;
    }
    normal_ptr<T> operator++(int x)
    {
        normal_ptr<T> tmp(ptr);
        ++ptr;
        return tmp;
    }
    normal_ptr<T>& operator--()
    {
        --ptr;
        return *this;
    }
    normal_ptr<T> operator--(int x)
    {
        normal_ptr<T> tmp(ptr);
        --ptr;
        return tmp;
    }

    T& operator*() const
    {
        return *ptr;
    }
    T* operator->() const
    {
        return ptr;
    }
};

#endif