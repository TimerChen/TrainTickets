#ifndef SMART_POINT
#define SMART_POINT

class not_an_array
{
};

template <typename T>
class const_normal_ptr;
template <typename T, bool array, bool opnew>
class shared_ptr;
template <typename T>
class normal_ptr;
template <typename T, bool array, bool opnew>
class const_shared_ptr;
template <typename T, bool array, bool opnew>
class const_shared_ptr_Base;

template <typename T, bool array, bool opnew>
class shared_ptr_Base
{
    friend class shared_ptr<T, array, opnew>;
    friend class const_shared_ptr_Base<T, array, opnew>;

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
    T& operator[](int i) const
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

template <typename T, bool array, bool opnew>
class const_shared_ptr_Base
{

  private:
    shared_ptr_Base<T, array, opnew>* sb;
    const T* baseptr;
    const_shared_ptr_Base(T* _ptr,
                          const shared_ptr_Base<T, array, opnew>* _sb = nullptr)
      : baseptr(_ptr)
    {
        if (!_sb) {
            sb = new shared_ptr_Base<T, array, opnew>(_ptr);
        } else
            sb = _sb;
    }
    void AddNewPoint()
    {
        sb->AddNewPoint();
    }
    void distruction()
    {
        sb->distruction();
        if (sb->cnt <= 0)
            delete sb;
    }
    const T& operator[](int i) const
    {
        return *baseptr[i];
    }
    ~const_shared_ptr_Base()
    {
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
    shared_ptr(T* const ptr)
      : base(new shared_ptr_Base<T, array, opnew>(ptr))
    {
    }
    shared_ptr(const shared_ptr<T, array, opnew>& rs)
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
    T& operator[](int i) const
    {
        return (*base)[i];
    }
    T* operator->()
    {
        return base->baseptr;
    }
    T* operator->() const
    {
        return base->baseptr;
    }
    shared_ptr& operator=(const shared_ptr<T, array, opnew>& rs)
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
        if (!array)
            throw not_an_array();
        return normal_ptr<T>(base->baseptr + pos);
    }
    const normal_ptr<T> operator+(const int pos) const
    {
        if (!array)
            throw not_an_array();
        return normal_ptr<T>(base->baseptr + pos);
    }
    ~shared_ptr()
    {
        base->distruction();
        if (base->cnt <= 0)
            delete base;
    }
};

template <typename T, bool array = false, bool opnew = false>
class const_shared_ptr
{
    const_shared_ptr_Base<T, array, opnew>* base;

  public:
    const_shared_ptr()
      : base(nullptr)
    {
    }
    const_shared_ptr(T* const ptr)
      : base(new const_shared_ptr_Base<T, array, opnew>(ptr))
    {
    }
    const_shared_ptr(const shared_ptr<T, array, opnew>& rs)
    {
        base =
          new const_shared_ptr_Base<T, array, opnew>(rs.base->baseptr, rs.base);
        base->AddNewPoint();
    }
    const_shared_ptr(const const_shared_ptr<T, array, opnew>& rs)
    {
        base =
          new const_shared_ptr_Base<T, array, opnew>(rs.base->baseptr, rs.base);
        base->AddNewPoint();
    }
    const T& operator*() const
    {
        return *(base->baseptr);
    }
    const T& operator[](int i) const
    {
        return (*base)[i];
    }
    const T* operator->() const
    {
        return base->baseptr;
    }

    const_shared_ptr& operator=(const const_shared_ptr<T, array, opnew>& rs)
    {
        if (base) {
            base->distruction();
            delete base;
        }
        base = rs.base;
        base->AddNewPoint();
        return *this;
    }
    const_shared_ptr& operator=(const shared_ptr<T, array, opnew>& rs)
    {
        base =
          new const_shared_ptr_Base<T, array, opnew>(rs.base->baseptr, rs.base);
        base->AddNewPoint();
    }
    const_shared_ptr& operator=(T* rt)
    {
        if (base) {
            base->distruction();
            delete base;
        }
        base = new const_shared_ptr_Base<T, array, opnew>(rt);
        return *this;
    }
    bool operator==(const const_shared_ptr& rt) const
    {
        return base == rt.base;
    }
    bool operator!=(const const_shared_ptr& rt) const
    {
        return base != rt.base;
    }
    const_normal_ptr<T> operator+(const int pos) const
    {
        if (!array)
            throw not_an_array();
        return const_normal_ptr<T>(base->baseptr + pos);
    }
    ~const_shared_ptr()
    {
        base->distruction();
        delete base;
    }
};

template <typename T>
class normal_ptr
{
    friend class const_normal_ptr<T>;
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
    bool operator==(const normal_ptr& other) const
    {
        return other.ptr == ptr;
    }
    bool operator!=(const normal_ptr& other) const
    {
        return other.ptr != ptr;
    }
    normal_ptr<T> operator+(const int pos) const
    {
        return normal_ptr<T>(ptr + pos);
    }
    normal_ptr<T> operator-(const int pos) const
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

template <typename T>
class const_normal_ptr
{
    const T* ptr;

  public:
    const_normal_ptr(const T* rp = nullptr)
      : ptr(rp)
    {
    }
    const_normal_ptr(const normal_ptr<T>& rp)
      : ptr(rp.ptr)
    {
    }
    const_normal_ptr& operator=(const const_normal_ptr& rp)
    {
        ptr = rp.ptr;
    }
    bool operator==(const const_normal_ptr& other) const
    {
        return other.ptr == ptr;
    }
    bool operator!=(const const_normal_ptr& other) const
    {
        return other.ptr != ptr;
    }
    const_normal_ptr<T> operator+(const int pos) const
    {
        return const_normal_ptr<T>(ptr + pos);
    }
    const_normal_ptr<T> operator-(const int pos) const
    {
        return const_normal_ptr<T>(ptr - pos);
    }
    const_normal_ptr<T>& operator+=(const int pos)
    {
        ptr += pos;
        return *this;
    }
    const_normal_ptr<T>& operator-=(const int pos)
    {
        ptr -= pos;
        return *this;
    }
    const_normal_ptr<T>& operator++()
    {
        ++ptr;
        return *this;
    }
    const_normal_ptr<T> operator++(int x)
    {
        const_normal_ptr<T> tmp(ptr);
        ++ptr;
        return tmp;
    }
    const_normal_ptr<T>& operator--()
    {
        --ptr;
        return *this;
    }
    const_normal_ptr<T> operator--(int x)
    {
        const_normal_ptr<T> tmp(ptr);
        --ptr;
        return tmp;
    }

    const T& operator*() const
    {
        return *ptr;
    }
    const T* operator->() const
    {
        return ptr;
    }
};
#endif