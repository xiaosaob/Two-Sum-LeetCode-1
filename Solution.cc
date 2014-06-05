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
