#include <bits/stdc++.h>

using namespace std;

bool compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main() {
  int a[] = {1,2,5,8,3,5,7,1,7,8};
  sort(a+5,a+10,compare_int);
  sort(a,a+5,greater<int>());
  // qsort(a,)
  for(int i=0;i<10;i++)cout << a[i] << " ";
  cout << endl;
}