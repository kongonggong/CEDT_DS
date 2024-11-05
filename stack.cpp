#include<bits/stdc++.h>
using namespace std;

namespace CEDT{
    template<typename T>
    class stack{

        protected:

        T *mData;
        size_t mSize;
        size_t mCap;
        void ensure_cap(size_t sz)
        {
            if(sz > mCap)
            {
                size_t s = (sz > mCap*2) ? sz : mCap*2;
                expand(s);
            }
        }

        void expand(size_t cap)
        {
            T *cData = new T[cap]();
            for(int i=0;i<mSize;i++)
            {
                cData[i] = mData[i];
            }
            delete [] mData;
            mData = cData;
            mCap = cap;
        }

        public :
       
        stack()
        {
            mSize = 0;
            mCap= 1;
            mData = new T[mCap]();
        } 


        T& push (const T &data)//
         {
            ensure_cap(mSize+1);
            mData[mSize++] = data;
            return mData[mSize-1];
         }
        T& top()
         {
            return mData[mSize-1];
         }

        void pop()
         {
            mSize--;
         }
        size_t size()
        const{
            return mSize;
        }

        size_t capacity()
        const{
            return mCap;
        }
        void clear()
        {
            mData = new T[mCap]();
            mSize = 0;
            mCap= 1;
            delete [] mData;
        }
        // void swap(stack s1, stack s2)
        // {
        //     using std::swap;
        //     swap(s1.size(),s2.size());
        //     swap(s1.capacity(),s2.capacity());
        //     swap(s1.mData,s2.mData);
        // }
        bool empty()
        const{
            
            return (mSize == 0);
        }

        stack<T> &operator=(stack other)
        {
            using std::swap;
            swap(mSize,other.mSize);
            swap(mCap,other.mCap);
            swap(mData,other.mData);
            return *this;
        }
        
    };



}

int main()
{
    CEDT :: stack<int> d,s;
    s.push(99);
    s.push(56);
    d=s;
    cout << s.size() << "\n";
    s.clear();///
    // cout << s.empty();
    cout << s.size() << "\n";
    cout << d.size() << "\n";
}