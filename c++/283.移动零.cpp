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
	// 8ms ����ȡ��0ֵ��Ȼ����䵽ԭ���飬�ٲ���0 
//	void moveZeroes(vector<int>& nums) {
//		vector<int> temp;
//        for(int i=0;i<nums.size();i++){
//        	if(nums[i]!=0){
//        		temp.push_back(nums[i]);
//			}
//		}
//		for(int i=0;i<temp.size();i++){
//			nums[i]=temp[i];
//		}
//		for(int i=temp.size();i<nums.size();i++){
//			nums[i]=0;
//		}
//    }

	// 4ms
	//ͬ����˼·������һ��λ�ü�¼��j������������Ĳ��� 
	void moveZeroes(vector<int>& nums) {
		int i=0,j=0;
		for(i=0;i<nums.size();i++){
			if(nums[i]!=0){
				nums[j++]=nums[i];
			}
		} 
		while(j<nums.size()){
			nums[j++]=0;
		}
    }
};


int main(){
	vector<int> nums={0,1,0,3,12};
	Solution s = Solution();
	s.moveZeroes(nums);
	for(auto& n:nums){
		cout<<n<<endl;
	}
	
	return 0;
}  
