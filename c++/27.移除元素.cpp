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
	// 4ms
	int removeElement(vector<int>& nums, int val) {
		int now=0;
		// 遍历nums，同时定义一个now标记下标，将遍历的值，赋值给now下标的位置，如果遍历的值，和要删除的不一样，now下标就增加，表明结果被接受 
		for(int i=0;i<nums.size();i++){
			nums[now]=nums[i];
			if(nums[i]!=val){				
				now++;				
			}
		} 
		return now;
    }
};


int main(){
	vector<int> arr1={3,2,2,3};
	vector<int> arr2={0,1,2,2,3,0,4,2};
	
	 
		
	Solution s = Solution();
	int res = s.removeElement(arr2,2);
	for(int i=0;i<res;i++){
		cout<<arr2[i]<<endl;
	}
	
	return 0;
} 
