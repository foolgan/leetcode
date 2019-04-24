class Solution {
    struct Num {
        int val;
        int index;
        bool operator<(const Num& other) const{
            return val < other.val;
        }
    };
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<Num> vec;
        for(int index = 0; index < nums.size(); ++index){
            Num num;
            num.val = nums[index];
            num.index = index;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        int begin = 0;
        int end = vec.size() - 1;
        while(begin < end){
            int sum = vec[begin].val + vec[end].val;
            if (sum == target) {
                break;
            }
            if (sum < target){
                begin++;
            } else{
                end--;
            }
        }
        if (begin >= end) {
            return ret;
        }
        ret.push_back(vec[begin].index < vec[end].index ? vec[begin].index : vec[end].index);
        ret.push_back(vec[begin].index > vec[end].index ? vec[begin].index : vec[end].index);
        return ret;
    }
};