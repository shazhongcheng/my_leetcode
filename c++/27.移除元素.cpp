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
		// ����nums��ͬʱ����һ��now����±꣬��������ֵ����ֵ��now�±��λ�ã����������ֵ����Ҫɾ���Ĳ�һ����now�±�����ӣ�������������� 
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
