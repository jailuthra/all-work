#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{

  int i;
  const int n = 100;
  char str[n] = {};

  cout<<"\nEnter the string : ";
  cin.getline (str, n);

  for ( i=0; i<n; i++) {
    
    if (str[i]<123 and str[i]>96) {
      str[i] -= 96;
      str[i] = 27-str[i];
      str[i] += 96;
    }
    else if (str[i]<91 and str[i]>64) {
      str[i] -= 64;
      str[i] = 27-str[i];
      str[i] += 64;
    }
    
  }
  
  cout <<"\nThe coded string is :" << str << endl;

  return 0;

}
