#ifndef SMART_POINT
#define SMART_POINT

template <typename T, bool array> class SmartPoint;
template <typename T, bool array> class SmartPoint_Base {
    friend class SmartPoint<T, array>;

  private:
    int cnt;
    T *baseptr;
    SmartPoint_Base(T *_ptr) : baseptr(_ptr), cnt(1) {}
    void AddNewPoint() { ++cnt; }
    void distruction() {
        --cnt;
        if (cnt <= 0) this->~SmartPoint_Base();
    }
    ~SmartPoint_Base() {
        if (array)
            delete[] baseptr;
        else
            delete baseptr;
    }
};

template <typename T, bool array = false> class SmartPoint {
    SmartPoint_Base<T, array> *base;

  public:
    SmartPoint() : base(nullptr) {}
    SmartPoint(T *ptr) : base(new SmartPoint_Base<T, array>(ptr)) {}
    SmartPoint(const SmartPoint &rs) {
        base = rs.base;
        base->AddNewPoint();
    }
    T &operator*() { return *(base->baseptr); }
    T &operator[](int i) { return (base->baseptr)[i]; }
    T *operator->() { return base->baseptr; }
    SmartPoint &operator=(const SmartPoint &rs) {
        if (!base) {
            base = rs.base;
            base->AddNewPoint();
        } else {
            base->distruction();
            base = rs.base;
            base->AddNewPoint();
        }
        return *this;
    }
    SmartPoint &operator=(const T *rt) {
        if (base) {
            base->distruction();
        }
        base = new SmartPoint_Base<T, array>(rt);
        return *this;
    }

    ~SmartPoint() { base->distruction(); }
};

#endif