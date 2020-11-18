#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
	// 4ms 
	// 当前的数字=当前的数字+之前数字的和 
	vector<int> runningSum(vector<int>& nums) {
		for(int i=1;i<nums.size();i++){
			nums[i]=nums[i]+nums[i-1];
		} 
		return nums;
    }
};


int main(){
	vector<int> nums={1,2,3,4,5};
	Solution s = Solution();
	vector<int> res = s.runningSum(nums);
	for(auto& r:res){
		cout<<r<<endl;
	}
	
	return 0;
} 
