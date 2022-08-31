#include<iostream>
using namespace std;
//singlet -> template <typename T>
//doubles -> template <typename T,typename V>
//tirplet
template <typename T,typename V>
class Pair
{
    T x;
    V y;
public:
    T setx(T val)
    {
        this->x=val;
    }
    V sety(V val)
    {
        this->y=val;
    }
    T getx()
    {
        return x;
    }
    V gety()
    {
        return y;
    }
};
int main()
{
    //singlet
    /*
    Pair<int,int> p1;
    p1.setx(2);
    p1.sety(3);

    cout<<p1.getx()<<" "<<p1.gety()<<endl;
    */

    /*
    Pair<double> p2;
    p2.setx(100.34);
    p2.sety(99.99);

    cout<<p2.getx()<<" "<<p2.gety()<<endl;
    */
    /*
    Pair<char> p3;
    p3.setx('A');
    p3.sety('B');

    cout<<p3.getx()<<" "<<p3.gety()<<endl;
    */
    /*
    Pair<int ,double> p4;
    p4.setx(100.2);
    p4.sety(1.99);

    cout<<p4.getx()<<" "<<p4.gety()<<endl;
    */
    /*
    Pair<double,char> p5;
    p5.setx(11.1999);
    p5.sety('A');

    cout<<p5.getx()<<" "<<p5.gety()<<endl;
    */
    /*
    Pair<Pair<char,double>,int> p6;
    Pair<char, double> p7;
	p7.setx('C');
	p7.sety(3.145691);
	p6.setx(p7);

	p6.sety(3.00);
	cout<<p6.getx().getx()<<" "<<p6.getx().gety()<<" "<<p6.gety()<<endl;

	Pair<Pair<int,int>,int> p8;
	Pair <int,int> p9;
	p9.setx(9);
	p9.sety(8);

	p8.setx(p9);
	p8.sety(7);

	cout<<p8.getx().getx()<<" "<<p8.getx().gety()<<" "<<p8.gety()<<endl;
	*/
}
