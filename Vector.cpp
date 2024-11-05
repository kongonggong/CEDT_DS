#include<bits/stdc++.h>
using namespace std;

namespace CEDT
{
    template<typename T>
    class vector
    {
        protected:
        T *mData;
        size_t mSize;
        size_t mCap;
        void range_check(int index) // check index
        {
            if(index < 0 || (size_t)index >= mSize)
            {
                throw std::out_of_range("Index Out of Range");
            }
        }

        void expand(size_t s)
        {   
            T *cmData = new T[s]();

            for(int i=0;i<mSize;i++) 
            {
                cmData[i] = mData[i];
            }
            delete [] mData; 
            mData = cmData;
            mCap = s;  
        }

        void ensureCapacity(size_t capacity)
        {
            if(capacity > mCap)
            {
                size_t s = ( capacity >= mCap*2 ) ? capacity : mCap*2; // ? yes : no
                expand(s);
            }
            
        }

        bool empty()
        const {
                return mSize == 0;
        }

        size_t size()
        const {
            return mSize;
        }

        size_t capacity()
        const {
                return mCap;
        } 

        public :

        typedef T* iterator; //define T* == iterator or pointer type

        //------constructure-----//
        vector()
        {
            size_t cap =1;
            mData =  new T[cap]();
            mCap = cap;
            mSize = 0; 
        }
        vector(size_t cap)
        {
            mData = new T[cap]();
            mSize = cap;
            mCap = cap;
        } 


        vector(vector<T> &oriData)
        {
            mData  = new T[oriData.mCap](); 
            mSize = oriData.mSize;
            mCap = oriData.mCap;
            for(int i=0;i<oriData.mSize;i++)
            {
                mData[i] = oriData[i];
            }
        }


         //------Destructure-----//

        ~vector() {
             delete [] mData;
        }
        // ~vector()

        //----------acess func-----//
        T &at(int index)
        {
            range_check(index);// check wheter if it's out of range 
            return mData[index];
        }
        
        void push_back(T &data)
        {
            ensureCapacity(mSize+1); // check if its already capacity
            mData[mSize++] = data; 
        }
        void pop_back()
        {
            mSize--;
        }

        iterator begin()
        {
            // return &mData[0];
            return mData;
        }
        iterator end()
        {
            return mData+mSize;
        }

        iterator insert(iterator it,const T &element)
        {
                size_t pos = it - begin(); // why we dont use *it straight out === because we use pause is easier and because it expand and vector deallocate adress
                // size_t pos = *it;
                // cout << pos << " ";
                ensureCapacity(mSize+1); //************ expand and vector deallocate adress
                for(size_t i= mSize; i > pos;i--)
                {
                        mData[i] = mData[i-1];
                } 
                mData[pos] = element;
                mSize++;
                return &mData[pos]; // why wont we return it;   === because it expand and vector deallocate adress
        }

        void erase(iterator it)
        {
             while (it != end())
             {
                *it = *(it+1);
                it ++;
             }
             mSize--;
        }


        //resize 



        //clear

        //----- operator overloading ---//


         vector<T> &operator=(vector<T> other)
         {
            using std::swap;
            swap(mData,other.mData);
            swap(mCap,other.mCap);
            swap(mSize,other.mSize);

            //cout << typeid(this).name() << "\n";

            return *this; // return a refference
         }

         // vector<T>& operator=(vector<T> &other)
        // {
        //     if(mData != other.mData)
        //     {
        //         delete [] mData;
        //         mData  = new T[other.mCap](); 
        //         mSize = other.mSize;
        //         mCap = other.mCap;
        //         for(size_t i=0;i<other.mSize;i++)
        //         {
        //             mData[i] = other.mData[i];
        //         }
        //     }
        //     return *this; // return a refference
        // }
    
        T &operator[] (int index) //return variable not value
        {
            //cout << typeid(mData[index]).name() << "\n";
            // cout << mData[index] << "\n";
            return mData[index];
        }
    };
    
}


int main()
{
    CEDT :: vector<int> n(5);
    CEDT :: vector<int> b;
    // n.at(99);
    // n[2]=3;
    b = n;
    *(n.end()-1) = 99;
    n.erase(n.begin()+1);
    for(auto x : n) cout << x << " ";
    cout << endl;
    n.insert(n.begin(),69);
    for(auto x : n) cout << x << " ";
}