#include<iostream>
using namespace std;
class Pair
{
    int x;
    int y;
public:
    void setx(int val)
    {
        this->x=val;
    }
    int getx()
    {
        return x;
    }
    void sety(int val)
    {
        this->y=val;
    }
    int gety()
    {
        return y;
    }
};
int main()
{
    Pair p;
    p.setx(2);
    p.sety(4);

    cout<<p.getx()<<" "<<p.gety()<<endl;
}
