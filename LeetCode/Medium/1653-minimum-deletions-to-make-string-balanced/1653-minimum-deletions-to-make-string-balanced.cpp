class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count[2];
        count[0]=0;
        count[1]=0;
        int ans=0;
        for(int i =s.size()-1;i>=0;i--){
            if(!st.empty() && st.top() - 'a' < s[i]-'a'){
                if(count[st.top()-'a'] == 1){
                    st.pop();
                }else{
                    continue;
                }
            }
            st.push(s[i]);
            count[s[i]-'a']++;
        }
        return s.size()-st.size();
    }
};