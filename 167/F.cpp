#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)

int N;
const int MaxN=1000001;
typedef pair<int,string> pa;
pa Right[MaxN];
stack<string> sta;

string pop_brack(string s) {
    
    string S;
    int len = s.length();
    for(int j=0;j<len;j++) {
        if(s[j]=='('){
            sta.push("(");
        }else if(s[j]==')') {
            if(!sta.empty() && sta.top()=="(")sta.pop();
            else sta.push(")");
        }
    }
    int length = sta.size();
    for(int j=0;j<length;j++) {
        S += sta.top();sta.pop();
    }
    // S.reserve();

    for (int i = 0; i < length / 2; i++) swap(S[i], S[length - i - 1]); 

    return S;
}


int compare_int(const int a , const int b) {
    if (a < b) {
        return 1;
    } else if (a > b) {
        return -1;
    }
    return 0;
}

int comp_pair(const void *a,const void *b) 
{ 
    const pa* num1 = (const pa *)a;
    const pa* num2 = (const pa *)b;

    return (num1->first == num2->first) ? false : (num2->first - num1->first) ;
}
    

int main(){
    string max="";
    cin >> N;

    rep(i,N) {
        cin >> Right[i].second;
        Right[i].first = 0;
    }
    rep(i,N) {
        Right[i].second = pop_brack(Right[i].second);
        int len = Right[i].second.length();
        rep(j,len) {
            if(Right[i].second[j] == '(')Right[i].first++;
            else Right[i].first--;
        }
    }
    
    qsort(Right,N,sizeof(pa),comp);
    
    for(int i=0;i<N;i++) {
        max += Right[i].second;
    }

    string ans = pop_brack(max);
    if(ans=="")puts("Yes");
    else puts("No");
    return 0;
}