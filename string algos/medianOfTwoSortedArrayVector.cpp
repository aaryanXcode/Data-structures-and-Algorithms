/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;
void merge (vector < int >&a, vector < int >&b)
{

  int i = 0;
  int j = 0;
  while (i <a.size ())
    {
     if (a[i] > b[j])
	{
	  int temp = a[i];
	  a[i] = b[j];
	  b[j] = temp;
	  i++;
	}
    else
	{
	  i++;
	}
    }
  while (j <b.size ())
    {
      a.push_back (b[j]);
      j++;
    }

}

double median (vector < int >a, vector < int >b)
{
  // Write your code here.
  merge (a, b);
  for(int i=0;i<a.size();i++)
  {
      cout<<a[i]<<",";
  }

}


int main ()
{
  vector < int >a;
  a.push_back (1);
  a.push_back (4);
  a.push_back (7);
  a.push_back (8);
  a.push_back(10);

  vector < int >b;
  b.push_back (11);
  b.push_back (14);
  b.push_back (17);
  b.push_back (19);

 cout<<median(a,b);


  return 0;
}

