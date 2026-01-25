class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int ans = INT_MIN;
        set<int> s;
        for(auto i: nums){
            s.insert(i);
            if(s.size()>3){
                s.erase(s.begin());
            }
            // cout<<i<<*s.begin()<<*s.rbegin()<<endl;
        }
        // cout<<*s.begin()<<*s.rbegin()<<s.size();
        return s.size() < 3 ? *s.rbegin() : *s.begin();
    }
};