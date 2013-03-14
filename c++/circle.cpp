#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
float r;
float cir;
float area;
const float pi = (22/7);

        cout<<"Type Radius: ";
        cin>>r;
		area = (pi*r*r);
		cir = (2*pi*r);
	cout<<"\nThe Area Is "<<area;
	cout<<"\nThe Circumference Is "<<cir;
	
}



