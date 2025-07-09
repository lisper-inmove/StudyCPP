#ifndef __MY_SMART_PTR__
#define __MY_SMART_PTR__

template <typename T>
class ShareCount {
   private:
    T *ptr;
    int count;
    ShareCount(const ShareCount &)            = delete;
    ShareCount &operator=(const ShareCount &) = delete;

   public:
    ShareCount(T *p) : ptr(p), count(1) {}
    ~ShareCount() { delete ptr; }

    void increment() { count++; }
    void decrement() {
        if (--count == 0) {
            delete this;
        }
    }

    T *get() { return ptr; }
};

template <typename T>
class shared_ptr {
   private:
    T *ptr;
    ShareCount<T> *countPtr;

   public:
    shared_ptr(T *p = nullptr) : ptr(p) {
        if (p) {
            countPtr = new ShareCount<T>(p);
        } else {
            p = nullptr;
        }
    }
    shared_ptr(const shared_ptr &other) : ptr(other.ptr), countPtr(other.countPtr) {
        if (countPtr) {
            countPtr->increment();
        }
    }

    shared_ptr(shared_ptr &&other) : ptr(other.ptr), countPtr(other.countPtr) {
        other.ptr      = nullptr;
        other.countPtr = nullptr;
    }
    ~shared_ptr() {
        if (countPtr) {
            countPtr->decrement();
        }
    }

    T *operator->() const { return ptr; }

    T &operator*() const { return *ptr; }

    void reset(T *p = nullptr) {
        if (p != ptr) {
            if (countPtr) {
                countPtr->decrement();
            }
        }
        ptr = p;
        if (p) {
            countPtr = new ShareCount<T>(p);
        } else {
            countPtr = nullptr;
        }
    }

    T *get() const { return ptr; }
};

#endif
