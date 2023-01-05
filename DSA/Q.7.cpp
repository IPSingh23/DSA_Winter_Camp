# include <bits/stdc++.h>
using namespace std;

int count(int arr[], int x, int n)
{   
  int *low = lower_bound(arr, arr+n, x);

  if (low == (arr + n) || *low != x)
     return 0;
 
  int *high = upper_bound(low, arr+n, x);    

  return high - low;
}

int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  3;  
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  cout<<x<<" occurs "<<c<<" times";
  return 0;
}