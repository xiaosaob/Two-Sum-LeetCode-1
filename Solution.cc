
// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, vector<int> > numToIdxMap;
        int n = numbers.size();
        for(int i = 0; i < n; ++i) {
            if(!numToIdxMap.count(numbers[i])) {
                numToIdxMap[numbers[i]] = vector<int>(1,i+1);
            } else {
                numToIdxMap[numbers[i]].push_back(i+1);
            }
        }
        
        sort(numbers.begin(), numbers.end());
        vector<int> res;
        int i = 0, j = n-1;
        while(i < j) {
            if(numbers[i] + numbers[j] == target) {
                if(numbers[i] == numbers[j]) {
                    res.push_back(numToIdxMap[numbers[i]][0]);
                    res.push_back(numToIdxMap[numbers[i]][1]);
                } else {
                    int iIdx = numToIdxMap[numbers[i]][0];
                    int jIdx = numToIdxMap[numbers[j]][0];
                    res.push_back(iIdx < jIdx ? iIdx : jIdx);
                    res.push_back(iIdx < jIdx ? jIdx : iIdx);
                }
                return res;
            } else if(numbers[i] + numbers[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
    }
};
