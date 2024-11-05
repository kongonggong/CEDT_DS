#include<bits/stdc++.h>
using namespace std;

namespace CEDT
{
    template<typename T>
    class deque
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

        deque() { 
                mCap = 1;
                mSize = 0;
                mfront = 0;
                mData = new T[mCap]();
        }
        
        deque(const deque<T>& other) : mCap(other.mCap), mSize(other.mSize), mfront(other.mfront) {
            mData = new T[mCap]();
            for (size_t i = 0; i < mSize; i++) {
                mData[i] = other.mData[(mfront + i) % mCap];
            }
            mfront = 0;
        }


        ~deque(){
            delete [] mData;
         }

        
        deque<T> & operator=(deque<T> other) {//need copy constructure****
            using std::swap;
            swap(mData,other.mData);
            swap(mSize,other.mSize);
            swap(mCap,other.mCap);
            swap(mfront,other.mfront);

            return *this;
        }

        ////---- function ----////

        // T & push_back(const T &data)
        // {
        //     mSize++;
        //     ensure_cap(mSize);
        //     size_t back = ( mSize-1 +mfront) % mCap ;
        //     mData[back] = data;
        //     // cout << mfront<< " "  << mSize-1 << " " << mCap << " " <<  back << " " <<"\n";
        //     return mData[back] ;
        // }

        void push_back(const T &data)
        {
            ensure_cap(mSize+1);
            size_t mat = ( mSize +mfront) % mCap ; // if not -1 will be the next space 
            mData[mat] = data;
            // cout << mfront<< " "  << mSize-1 << " " << mCap << " " <<  mat << " " <<"\n";
            mSize++;
        }

        void push_front(const T &data)
        {
            mSize++;
            ensure_cap(mSize);
            if(mfront-1 == -1) 
            {
                mData[mCap-1] = data;
                mfront = mCap-1;
            }
            else 
            {
                mData[--mfront] = data;
            }
        }


      

   

        void pop_back()
        {
            if(!empty()) 
            {
                mSize--;
            }
        }

         void pop_front()
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
    CEDT::deque<int> q,r;
    // cout << q.front();
    q.push_back(86);
    q.push_back(56);
    q.push_back(23);
    q.push_back(89);
    q.push_back(88);
    q.push_front(24);
    while (!q.empty())// 24 86 56 23 89 88
    {
        cout <<q.front() << " " <<q.back() << "\n";
        q.pop_front();
    }
}