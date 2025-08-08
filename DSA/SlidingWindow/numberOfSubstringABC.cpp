#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int counta = 0;
    int countb = 0;
    int countc = 0;
    int count = 0;
    int start = 0;
    int n = s.size();
    for(int end = 0; end<n; end++){
        if(s[end] == 'a') counta++;
        if(s[end] == 'b') countb++;
        if(s[end] == 'c') countc++;

        while((counta>=1) && (countb>=1) && (countc>=1)){
            if(s[start] == 'a') counta--;
            if(s[start] == 'b') countb--;
            if(s[start] == 'c') countc--;
            start++;
            count += n-end;
        }
    }
    return count;

}
int main(){
    string s = "abcabc";
    cout<<numberOfSubstrings(s)<<endl;
}