class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // int ans = INT_MIN;
        // set<int> s;
        // for(auto i: nums){
        //     s.insert(i);
        //     if(s.size()>3){
        //         s.erase(s.begin());
        //     }
        //     // cout<<i<<*s.begin()<<*s.rbegin()<<endl;
        // }
        // // cout<<*s.begin()<<*s.rbegin()<<s.size();
        // return s.size() < 3 ? *s.rbegin() : *s.begin();


        // use long as max and min can include INT_MAX or INT_MIN
        long long int first = LLONG_MIN;
        long long int second = first;
        long long int third = first;

        for(auto i:nums){
            if(i == first || i==second || i == third)
                continue;
            if(i>first){
                third = second;
                second = first;
                first = i;
            }
            else if(i > second){
                third = second;
                second = i;
            }
            else if(i> third){
                third = i;
            }
        }
        // cout<<first<<" "<<second<<" "<<third<<endl;
        return third != LLONG_MIN ? third : first;
    }
};