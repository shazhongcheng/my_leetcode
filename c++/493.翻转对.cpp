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
		//�������ұ߽� 
		return merge_sort(nums,0,n);
    }
    
    int merge_sort(vector<int>& nums,int l,int r){
    	// ֻ��һ�����ͷ���0 
    	if(r-l<=1) return 0;
    	// �����м�ֵ 
    	int mid=l+(r-l)/2;
    	// �鲢 ���ص�count Ϊ��ߵķ���������ֵ �� �ұ߷���������ֵ�ĺ� 
    	int count=merge_sort(nums,l,mid)+merge_sort(nums,mid,r);
    	int j=mid;
    	//���㵱ǰ��������У����ұ������з���������ֵ��Ҫ�����һ�㣬����Ҫ˳���nums����ߺ��ұ�����
		// i < j �� nums[i] > 2*nums[j] ��ֵ 
    	// ˫�� 
    	for(int i=l;i<mid;++i){
    		while(j<r && nums[i]/2.0 > (double)nums[j]){
    			++j;
			}
			count=count+j-mid;
		}
		// ���й鲢���� 
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
