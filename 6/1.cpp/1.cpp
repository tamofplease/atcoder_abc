#include <iostream>

using namespace std;

int main(){
    int count =0 ;
    for(int i=1;i<1000;i++){
        if(i%3==0){
            count+=i;
            continue;
        }else if(i%5==0){
            count += i;
            continue;
        }
    }
    cout << count << endl;
    return 0;
}