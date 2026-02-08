class Solution {
public:
    int greedy(string s) {
        /*
            Hint 1: Traverse the string from left to right.
            Hint 2: Keep a counter for the number of 'b' characters seen so far.
            Hint 3: An 'a' appearing after a 'b' makes the string unbalanced.
            Hint 4: Fix this greedily by deleting one earlier 'b'.
            Hint 5: Count each such fix as one deletion; the final count is the
           answer.
        */
        int countB = 0;
        int ans = 0;
        for (auto i : s) {
            if (i == 'b') {
                countB++;
            } else {
                if (countB > 0) {
                    countB--;
                    ans++;
                }
            }
        }
        return ans;
    }

    // for each index
    // precaculate no-A on right side and no-B on left side
    // update ans = min(ans, no-A[i] + no-B[i])
    // considering we are removing all left B and right A at each index
    // ans will min of all these ops
    int splitParts(string s) {
        int n = s.size();
        vector<int> noOfARight(n, 0);
        int totalA = 0;
        for (int i = n - 1; i >= 1; i--) {
            noOfARight[i] = totalA;
            if (s[i] == 'a') {
                totalA++;
            }
        }
        noOfARight[0] = totalA;

        int ans = totalA, leftB = 0;
        for (int i = 0; i < n; i++) {
            int rightA = noOfARight[i];
            ans = min(ans, rightA + leftB);
            if(s[i]=='b')
                leftB++;
            // cout<<i<<leftB<<rightA<<ans<<endl;
        }
        return ans;
    }
    int minimumDeletions(string s) {
        // return greedy(s);
        return splitParts(s);
    }
};