class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()%2 != 0){
            return 0;
        }  
        unordered_map<char, int> mp;
        int minCount = INT_MAX;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second == 1)
                return 0;
            minCount = min(minCount, i.second);
        }
        cout<<minCount<<endl;
        int req = 0;
        for(auto i: mp){
            if(i.second % minCount != 0){
                return 0;
            }else{
                req += i.second / minCount;
            }
        }

        int i =0, j = req;
        while(j<s.size()){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};