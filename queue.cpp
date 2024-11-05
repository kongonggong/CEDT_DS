#include<bits/stdc++.h>
using namespace std;

namespace CEDT
{
    template<typename T>
    class queue
    {
        protected:

        T *mData;
        size_t mCap;
        size_t mSize;
        int mfront;

        typedef T* iterator;
        
        void expand(size_t s)
        {
            T *cmData = new T[s]();
            for(size_t i=0;i<mSize;i++)
            {
                cmData[i] = mData[(mfront+i)%mCap];
            }
            delete [] mData;
            mfront = 0;
            mCap = s;
            mData = cmData;
        }

        void ensure_cap(size_t  cap)
        {
             if(cap > mCap)
             {
                    size_t s= (cap > mCap*2) ? cap: mCap *2;
                     expand(s);
             }
            
        }


        public:

        queue() { 
                mCap = 1;
                mSize = 0;
                mfront = 0;
                mData = new T[mCap]();
        }
        queue(queue<T> &other) : mCap(other.mCap), mSize(other.mSize), mfront(other.mfront) { 
            mData = new T[mCap]();
            for (size_t i = 0; i < mSize; i++) {
                mData[i] = other.mData[(mfront + i) % mCap];
            }
            mfront =0;
        }
        ~queue(){
            delete [] mData;
         }

        
        queue<T> & operator=(queue<T> other) {
            using std::swap;
            swap(mData,other.mData);
            swap(mSize,other.mSize);
            swap(mCap,other.mCap);
            swap(mfront,other.mfront);

            return *this;
        }

        ////---- function ----////
        T & push(const T &data)
        {
            mSize++;
            ensure_cap(mSize);
            size_t mat = ( mSize-1 +mfront) % mCap ;
            mData[mat] = data;
            cout << mfront<< " "  << mSize-1 << " " << mCap << " " <<  mat << " " <<"\n";
            return mData[mat] ;
        }

        // void push(const T &data)
        // {
        //     ensure_cap(mSize);
        //     size_t mat = ( mSize +mfront) % mCap ; // if not -1 will be the next space 
        //     mData[mat] = data;
        //     cout << mfront<< " "  << mSize-1 << " " << mCap << " " <<  mat << " " <<"\n";
        //     mSize++;
        // }

        void pop()
        {
            if(!empty()) 
            {
                mSize--;
                mfront = (mfront+1) % mCap;
            }
        }

        T &front()
        {
            return (mData[mfront % mCap]);
        }

         T &back()
        {
            return mData[ ( mSize-1 +mfront) % mCap ];// if msize -1 will be the cureent point
        }


        bool empty()
        {
            return (mSize==0);
        }
         size_t size()
        {
            return (mSize);
        }
    };
}

int main()
{
    CEDT::queue<int> q,r;
    // cout << q.front();
    q.push(86);
    q.push(56);
    q.push(23);
    q.push(89);
   
    q.push(88);
    r=q;
    while (!r.empty())//86 56 23 89
    {
        cout <<r.front() << " " <<r.back() << "\n";
        r.pop();
    }
    
}