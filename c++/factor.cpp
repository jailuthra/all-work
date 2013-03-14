#include<iostream>
#include<cstdlib>

using namespace std;

int main (int argc, char* argv[])
{
	int i=1;
	int n = atoi(argv[1]);
	cout<<"\nThe Factors of the number are: "<<endl;
	while (i<=n)
	{
		if (n%i==0) 
		{
			cout<<i<<endl;
		}
			
		i+=1;
	}
}
