#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string compressWord(string &s, int &k) {
    stack<pair<char,int>> st;
    
    for(int i=0;i<s.size();i++) {
        if(st.empty() || st.top().first!=s[i])
            st.push(make_pair(s[i],1));
        else {
            int count = st.top().second;
            count++;
            st.pop();
            if(count<k) {
                st.push(make_pair(s[i],count));
            }
        }
    }
    
    string ans = "";
    while(!st.empty()) {
        int count = st.top().second;
        char ch = st.top().first;
        for(int i=0;i<count;i++)
            ans+=ch;
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main()
{
    string word = "adbbcccbbg";
    int k = 3;
    
    cout<<compressWord(word, k);
    
    return 0;
}
