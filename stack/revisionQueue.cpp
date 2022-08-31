#include<iostream>
using namespace std;
template <typename T>
class queue
{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    queue(T totalSize)
    {
        data=new int[totalSize]
        capacity=totalSize;
        firstIindex=-1;
        nextIndex=0;
        size=0;
    }
    void enqueue(int val)
    {
        if(size==capacity)
        {
            T *newData = new T[2 * capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++)
            {
                newdata[j]=data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++)
            {
                newdata[j]=data[i];
            }

            delete [] data;
            data=newdata;
            firstIndex=0;
            nextIndex=capacity;
            capacity=capacity*2;
        }
        if(firstIndex == -1) {
			firstIndex = 0;
		}
        data[nextIndex]=val;
        nextIndex=(nextIndex+1)%capacity;
        size++;
    }
    T dequeue()
    {
        T ans=data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
    }
};
