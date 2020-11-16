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
	int searchInsert(vector<int>& nums, int target) {
		int i=0;
		for(;i<nums.size();i++){
			if(target<=nums[i]){
				break;
			}
		}
		return i;
    }
};


int main(){
	vector<int> nums={1,3,5,6};
	Solution s = Solution();
	int res = s.searchInsert(nums,2);
	cout<<res<<endl;
	
	return 0;
} 
