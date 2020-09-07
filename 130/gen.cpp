#include <bits/stdc++.h>

using namespace std;

// std::vector<std::string> split(std::string str, char del) {
//     int first = 0;
//     int last = str.find_first_of(del);
 
//     std::vector<std::string> result;
 
//     while (first < str.size()) {
//         std::string subStr(str, first, last - first);
 
//         result.push_back(subStr);
 
//         first = last + 1;
//         last = str.find_first_of(del, first);
 
//         if (last == std::string::npos) {
//             last = str.size();
//         }
//     }
 
//     return result;
// }
 

// void set() {
//   string file;
//   // cin >> file;
//   ifstream ifs("testdata", ios::in);
//   string tmp,str;
//   int num,sum = 0;
//   while(getline(ifs, tmp)){
//         // ここでtmpを煮るなり焼くなりする
//         // cout << tmp << endl; // そのまま出力 
//         vector<string> s = split(tmp, ' ');
//         for(int i=0;i<s.size();i++) {
//           int x = atoi(s[i].c_str());
//           cout << x << endl;

//         }
//         // int x = atoi(tmp.c_str());
//         // cout << x << endl;
//         // stringstream ss;
//         // ss >> str >> num; // str == "name:"; num == number;
//         // sum += num; // 値をsumに加算
//   }

//   // cout << sum << endl;

//   ifs.close();
// }

int main(){
  string filename = "testdata";
  ofstream wf;
  wf.open(filename, std::ios::out);

  int N,K;
  cin >> N;
  cin>> K;
  wf << N << " " << K << endl;
  for(int i=0;i<N;i++){
    int x = rand() % 100000;
    wf << x << endl;
  }
}