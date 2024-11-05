#include<bits/stdc++.h>
using namespace std;

namespace CEDT
{

    template <typename T, typename Comp = std::less<T> >

    class priority_queue
    {
        protected:
            T *mData;
            size_t mSize;
            size_t mCap;
            Comp mComp; // less 

            void expand(size_t cap)
            {
                T *cData = new T[cap*2];
                for(size_t i=0;i<mSize;i++)
                {
                    cData[i] = mData[i];
                }
                delete [] mData;
                mData = cData;
                mCap = cap;
            }

            void fix_down(size_t i)
            {
                T tmp = mData[i];
                size_t c;
                while ( (c = (i*2) +1)  < mSize)// look for left first
                {
                    if(c+1 < mSize && mComp(mData[c],mData[c+1]) ) c++; // find max node
                    if(mComp(mData[c],tmp)) break; // if max node < tmp data == you fond the place where it should belongggg
                    mData[i] = mData[c]; // move on
                    i =  c; //move on
                }
                mData[i] = tmp; // place data here
            }

            void fix_up(size_t ind)
            {
                int tmp = mData[ind];
                size_t node = ind; 
                while (node  > 0)
                {
                   node = (node-1)/2;
                   if( mComp(mData[node], tmp) ) break;
                   mData[ind] = mData[node]; 
                   ind = node;// ind = lower //  node = upper;
                }
                mData[node]  = tmp; 
            }

        public:
            priority_queue(const Comp &c = Comp()) : mData(new T[1] () ) , mSize(0), mCap(1), mComp(c) {};// why do we ue &c = comp()

            
            priority_queue(priority_queue<T> &a) 
            {
                mData = new T[a.mSize]();
                mSize = a.mSize;
                mCap = a.mSize;
                mComp = a.mComp;
                for(int i=0;i<a.size();i++) mData[i] = a.mData[i];
                for(int i=(a.mSize/2)-1;i<0;i++) fix_down(i);
            }

            ~priority_queue( ) {delete [] mData;}
        

            void push(T inp)
            {
                mSize++;
                if(mSize > mCap)expand(mSize);
                mData[mSize-1] = inp;
                fix_up(mSize-1);
            }

             void pop()
            {
                mSize--;
                mData[0] = mData[mSize-1];
                fix_down(0);
            }


            size_t size()
            {
               return mSize;
            }

            bool empty()
            {
                if(mSize == 0) return 0;
                else return 1;
            }

            T top()
            {
                return mData[0];
            }


            priority_queue<T> &operator=(priority_queue<T> &a)
            {
                delete [] mData;
                mData = new T[a.mSize]();
                mSize = a.mSize;
                mCap = a.mSize;
                mComp = a.mComp;
                for(int i=0;i<a.size();i++) mData[i] = a.mData[i];
                for(int i=(a.mSize/2)-1;i<0;i++) fix_down(i);
                return *this;
            }
    };
    
   
    
}


int main()
{
    CEDT :: priority_queue<int> pq,pq1;
    pq.push(58);
    pq.push(69);
    pq.push(60);
    pq.push(29);
    pq.push(45);
    pq.push(30);
    pq.pop();
    pq1 = pq;
    cout << pq1.top();
    
}