#include<iostream>
#include<vector>
using namespace std;
class MaxHeap
{
    vector<int> pq;
public:
    MaxHeap()
    {

    }
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getMax()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex=pq.size()-1;

        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(pq[parentIndex]<pq[childIndex])
            {
                int temp=pq[parentIndex];
                pq[parentIndex]=pq[childIndex];
                pq[childIndex]=temp;
            }
            else
            {
                break;
            }
            childIndex=parentIndex;
        }

    }
    int removeMax()
    {
        if(isEmpty())
        {
            return 0;
        }
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq[pq.size()-1]=ans;
		pq.pop_back();    //here is removing part rest of the rearrangement part
		int parentIndex=0;
		int leftChildIndex=2*parentIndex+1;
		int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<pq.size())   //checking edge cases
		{
			int maxIndex=parentIndex;
			if(pq[maxIndex]<pq[leftChildIndex])
			{
				maxIndex=leftChildIndex;
			}
			if(rightChildIndex<pq.size() && pq[rightChildIndex]>pq[maxIndex])
			{
				maxIndex=rightChildIndex;
			}
			if(maxIndex==parentIndex)
			{
				break;
			}
			int temp=pq[maxIndex];
			pq[maxIndex]=pq[parentIndex];
			pq[parentIndex]=temp;

			parentIndex=maxIndex;   //new parent after swapping

			leftChildIndex=2*parentIndex+1;   //calculating new parents children
			rightChildIndex=2*parentIndex+2;
		}
		return ans;



    }
    void print()
    {
        for(int i=0;i<pq.size();i++)
        {
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};
//10 15 11 33 55 66 98 115 57 100
int main()
{
    MaxHeap p;
    p.insert(10);
    p.insert(15);
    p.insert(11);
    p.insert(33);
    p.insert(55);
    p.insert(66);
    p.insert(98);
    p.insert(115);
    p.insert(57);
    p.insert(100);
    p.print();

    p.getMax();
    p.getSize();
    p.removeMax();
    p.print();
    p.getMax();
    p.getSize();
}

