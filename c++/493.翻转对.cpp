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
	vector<int> tmp;
	int reversePairs(vector<int>& nums) {
		int n=nums.size();
		tmp.reserve(n);
		//不包括右边界 
		return merge_sort(nums,0,n);
    }
    
    int merge_sort(vector<int>& nums,int l,int r){
    	// 只有一个，就返回0 
    	if(r-l<=1) return 0;
    	// 计算中间值 
    	int mid=l+(r-l)/2;
    	// 归并 返回的count 为左边的符合条件的值 和 右边符合条件的值的和 
    	int count=merge_sort(nums,l,mid)+merge_sort(nums,mid,r);
    	int j=mid;
    	//计算当前左边序列中，在右边序列中符合条件的值，要完成这一点，就需要顺便对nums的左边和右边排序
		// i < j 且 nums[i] > 2*nums[j] 的值 
    	// 双重 
    	for(int i=l;i<mid;++i){
    		while(j<r && nums[i]/2.0 > (double)nums[j]){
    			++j;
			}
			count=count+j-mid;
		}
		// 进行归并排序 
		int pos=l,l1=l,l2=mid;
		while(l1<mid && l2<r){
			if(nums[l1]<nums[l2]){
				tmp[pos++] = nums[l1++];
			}else{
				tmp[pos++]=nums[l2++];
			}
		}
		while(l1<mid)tmp[pos++]=nums[l1++];
		while(l2<r)tmp[pos++]=nums[l2++];
		for(int i=l;i<r;++i){
			nums[i]=tmp[i];
		}
		return count;
	}
};


int main(){
	vector<int> nums={1,3,2,3,1};
	Solution s=Solution(); 
	int  res = s.reversePairs(nums);
	cout<<res;
	
	return 0;
}  
