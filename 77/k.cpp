#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> a  = {1,2,3,3,3,4,5,6,7,8};
    cout << upper_bound(a.begin(),a.end(),4) -a.begin()<<endl;;
    return 0;
}