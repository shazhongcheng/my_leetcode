#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	/* 方法一： 暴力 
        vector<int>v;
		for(int i=0;i<nums.size();i++){
        	for(int j=i+1;j<nums.size();j++){
        		if(nums[i]+nums[j]==target){
        			v.push_back(i);
        			v.push_back(j);
        			break;
				}
			}
			if(v.size()>0){
				break;
			}
		}
		return v;
		*/
		/*方法二：字典*/
		vector<int>v;
		map<int,int> mymap;
		for(int i=0;i<nums.size();i++){
			if(mymap.find(target-nums[i])!=mymap.end()){
				v.push_back(mymap.find(target-nums[i])->second);
				v.push_back(i);
				break;
			}
			mymap[nums[i]]=i;
		} 
		return v;
    }
};

int main(){
	vector<int> v={2,7,11,15}; 
	int target=9;
	Solution s = Solution();
	vector<int> res = s.twoSum(v,target);
	for(auto i:res){
		cout<<i<<endl;
	}
}
