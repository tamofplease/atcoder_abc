#include <iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    if(A==B)cout<<C<<endl;
    else if(A>B && C>(A-B))cout<<C-(A-B)<<endl;
    else if(A>B && C<=(A-B))cout <<0<<endl;
}

