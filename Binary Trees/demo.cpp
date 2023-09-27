#include <string>
#include <map>
#include <stack>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::map<char, int> m;
        std::map<char, int> vis;
        std::stack<char> st;
        
        for(auto i : s) {
            m[i]++;
        }
        
        for(auto i : s) {
            if(st.empty()) {
                if(vis[i] == 0 && m[i] != 0) {
                    st.push(i);
                    m[i]--;
                    vis[i] = 1;
                }
            }
            else if(i <= st.top() && m[st.top()] != 0 && vis[i] == 0) {
                while(!st.empty() && st.top() >= i && m[st.top()] != 0) {
                    vis[st.top()] = 0;
                    st.pop();
                }
                st.push(i);
                m[i]--;
                vis[i] = 1;
            }
            else {
                if(vis[i] == 0) {
                    st.push(i);
                    m[i]--;
                    vis[i] = 1;
                }
            }
        }
        
        std::string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
