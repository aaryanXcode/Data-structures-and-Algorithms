#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue<int> q;
    q.push(108);
    q.push(100);
    q.push(123);
    q.push(121);
    q.push(126);
    q.push(156);
    q.push(146);
    q.push(124);
    q.push(135);
    q.push(199);

    int len=q.size();
    int arr[len];
    int temp;
    for(int i=0;i<len;i++)
    {
        arr[i]=q.front();
        q.pop();
    }

    for (int i = 0; i < len/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
    for(int i=0;i<len;i++)
    {
        q.push(arr[i]);
    }

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }

}
//time and spqce complexity=O(n)
//or we can do same thing by taking stack;
//10 108 100 123 121 126 156 146 124 135 199

//199 135 124 146 156 126 121 123 100 108
