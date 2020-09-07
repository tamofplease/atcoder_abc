#include <iostream>
#include <vector>
#define MAX 200
using namespace std;



int main(){
    int N = 100;
    //cin >> N;
    pair<int,int> red[101];
    pair<int,int> blue[101];
    for(int i=0;i<N;i++){
        red[i].first = i;
        red[i].second = i;
        //cin >> red[i].first >> red[i].second;
    }
    sort(red,red+N);
    for(int i=0;i<N;i++){
        blue[i].first = i;
        blue[i].second = i;
    }
    sort(blue,blue+N);
    vector<bool> V(N,false);
    int count = 0;
    for(int i=0;i<N;i++){
        int max = 0;
        int tmp = -1;
        for(int j=0;j<N;j++){
            if(V[j])continue;
            if(blue[i].first>red[j].first&&blue[i].second>red[j].second&&max<=red[j].second){
                max=red[j].second;
                tmp = j;
            }
        }
        if(tmp!=-1){
            count++;
            V[tmp] = true;
        }
    }
    cout <<count << endl;
    return 0;
}