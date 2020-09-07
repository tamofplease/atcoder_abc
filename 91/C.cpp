#include <iostream>
#include <vector>
#define MAX 200
using namespace std;


bool my_comp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    if(a.second!=b.second){
        return a.second>b.second;
    }else return true;
}

int main(){
    int N;
    cin >> N;
    pair<int,int> red[101];
    pair<int,int> blue[101];
    for(int i=0;i<N;i++){
        cin >> red[i].first >> red[i].second;
    }
    sort(red,red+N);
    for(int i=0;i<N;i++){
        cin >> blue[i].first >> blue[i].second;
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