#include<bits/stdc++.h>
using namespace std;

namespace CEDT
{
    template<typename T,typename Comp = std::less<T> >
    class priority_queue
    {
    protected:
        T *mData;
        size_t mSize;
        size_t mCap;
        Comp mless;

        void expand()
        {
            T *cData = new T[mCap*2]();
            for(size_t i=0;i<mSize;i++) cData[i] = mData[i];
            delete [] mData;
            mData = cData;
            mCap *= 2;
        }

        void fix_up(size_t idx) //
        {
            T tmpData = mData[idx];
            size_t tmpDown = idx;
            while (tmpDown != 0)
            {
                size_t tmpUp = (tmpDown-1)/2;
                if(mData[tmpUp] > tmpData) {mData[tmpDown] = tmpData; return; }
                else mData[tmpDown] = mData[tmpUp];
                tmpDown = tmpUp;
            }
            mData[0] = tmpData;
        }

        void fix_down(size_t idx) // root;
        {
            size_t tmp = idx;
            T tmpData = mData[idx];
            // cout << tmpData;
            while (tmp< mSize)
            {
                tmp = ((tmp*2)+1);//go to left;
                if(tmp + 1 < mSize && mData[tmp+1] > mData[tmp] ) tmp++ ;// if have right and right is greater;
                if(mData[tmp] < tmpData) break;
                else mData[(tmp-1)/2] = mData[tmp];
            }
            mData[tmp] = tmpData;
        }

    public:


        priority_queue(const Comp &c = Comp()) : mData(new T[1]() ),mSize(0),mCap(1) {} 
        priority_queue(const priority_queue<T, Comp>&pq,const Comp &c = Comp()) : mData(new T[pq.mCap]() ), mSize(pq.mSize),mCap(pq.mCap) 
        {
            for(size_t i=0;i<pq.mSize;i++) mData[i] = pq.mData[i];
        }
        ~priority_queue(){delete [] mData;};


         priority_queue<T, Comp>& operator=(priority_queue<T, Comp> other) {
            swap(mData, other.mData);
            swap(mSize, other.mSize);
            swap(mCap, other.mCap);
            return *this;
        }
        
        void push(T data)
        {
            if(mSize > mCap) expand();
            mData[mSize] = data;
            fix_up(mSize);
            mSize++;
        }

        void pop()
        {
            --mSize;
            mData[0] = mData[mSize-1];
            fix_down(0);
        }
        
        size_t top()
        {
            return mData[0];
        }

        size_t size()
        {
            return mSize;
        }

        bool empty()
        {
            if(mSize == 0) return 1;
            else {return 0;}
        }
    };
 
    
}

int main()
{
    CEDT:: priority_queue<int> pq,pq1;
    pq.push(99);
    pq.push(102);
    pq.push(43);
    pq.push(35);
    pq.push(42);
    cout << pq.top() << "\n";
    pq.pop();
    pq1 = pq;
    cout << "\n" << pq1.top();
}