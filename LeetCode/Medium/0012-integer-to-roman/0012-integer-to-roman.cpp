class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> given;
        given.push_back({1000, "M"});
        given.push_back({900, "CM"});
        given.push_back({500, "D"});
        given.push_back({400, "CD"});
        given.push_back({100, "C"});
        given.push_back({90, "XC"});
        given.push_back({50, "L"});
        given.push_back({40, "XL"});
        given.push_back({10, "X"});
        given.push_back({9, "IX"});
        given.push_back({5, "V"});
        given.push_back({4, "IV"});
        given.push_back({1, "I"});

        // loop on given
        int i = 0;
        // ans str
        string ans = "";
        while (i < given.size()) {
            // get times of curr roman char 
            int times = num / given[i].first;
            // add to ans
            for (int j = 0; j < times; j++) {
                ans += given[i].second;
            }
            // get rem num
            num = num % given[i].first;
            // next index
            i++;
        }
        // return ans
        return ans;
    }
};