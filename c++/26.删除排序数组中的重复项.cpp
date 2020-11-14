#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//长度不足2 就直接返回数组长度 
		if(nums.size()<=1){
			return nums.size();
		}
		int now=0;
		//循环数组。如果当前遍历的和标记的不一样，标记的就后移一位，并将标记替换为当前遍历 
		for(int i=1;i<nums.size();i++){
			if(nums[now]!=nums[i]){
				now++;
				nums[now]=nums[i];
			}
		}
		return now+1;
    }
};


int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	 
		
	Solution s = Solution();
	int length = s.removeDuplicates(nums);
	for(int i=0;i<length;i++){
		cout<<nums[i]<<endl;
	}
	
	return 0;
} 
