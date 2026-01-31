class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Time: O(n)
        // char ans = letters[0];
        // for (auto i : letters) {
        //     if (i > target) {
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        // arr is sorted then binary search can be used
        // Time: O(log n)
        int l = 0, r = letters.size()-1;
        if(target >= letters[r]){
            return letters[0];
        }
        while(l<=r){
            int m = l + (r-l)/2;
            if(letters[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return letters[l];


    }
};