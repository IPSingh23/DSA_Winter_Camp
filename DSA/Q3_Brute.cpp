#include <bits/stdc++.h>
using namespace std;

bool searchBrute(string str, string pat)
{
    int n=str.size();
    int m=pat.size();
    
    for(int i=0;i<=(n-m);i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(pat[j]==str[j+i]){
                cnt++;
            }
        }
        if(cnt==m) return true;
    }
    
    return false;
}

int main(){

    string str = {"This is a beautiful string!"};
    string pat = {"is"};

    bool result = searchBrute(str, pat);

    if(result) cout<<"Pattern found using Brute Search!"<<endl;
    else cout<<"Pattern not found in string!"<<endl;

    pat = {"as"};
    result = searchBrute(str, pat);

    if(result) cout<<"Pattern found using Brute Search!"<<endl;
    else cout<<"Pattern not found in string!"<<endl;
}