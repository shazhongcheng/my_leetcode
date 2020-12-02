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
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int m=nums1.size(),n=nums2.size();
		vector<int> maxSubsequence(k,0); 
		int start=max(0,k-n),end=min(k,m);
		for(int i=start;i<=end;i++){
			// 寻找序列1的前i个最大的子序列 
			vector<int> subsequence1(MaxSbusequence(nums1,i));
			// 寻找序列2的前k-i个最大子序列 
			vector<int> subsequence2(MaxSbusequence(nums2,k-i));
			// 将两个最大子序列合并 
			vector<int> curMaxSubsequence(merge(subsequence1,subsequence2));
			// 比较是否比现在暂存的大 
			if(compare(curMaxSubsequence,0,maxSubsequence,0)>0){
				maxSubsequence.swap(curMaxSubsequence);
			}
		}
		return maxSubsequence;
    }
    vector<int> MaxSbusequence(vector<int>& nums,int k){
    	int length = nums.size();
    	vector<int> stack(k,0);
    	int top=-1;
    	int remain=length-k;
    	for(int i=0;i<length;i++){
    		int num=nums[i];
    		while(top>=0&&stack[top]<num&&remain>0){
    			top--;
    			remain--;
			}
			if(top<k-1){
				stack[++top]=num;
			}else{
				remain--;
			}
		}
		return stack;
	}
	
	vector<int> merge(vector<int>& subsequence1,vector<int>& subsequence2){
		int x=subsequence1.size(),y=subsequence2.size();
		if(x==0){
			return subsequence2;
		}
		if(y==0){
			return subsequence1;
		}
		int mergeLength=x+y;
		vector<int> merged(mergeLength);
		int index1=0,index2=0;
		for(int i=0;i<mergeLength;i++){
			if(compare(subsequence1,index1,subsequence2,index2)>0){
				merged[i]=subsequence1[index1++];
			}else{
				merged[i]=subsequence2[index2++];
			}
		} 
		return merged;
	}
	
	int compare(vector<int>& subsequence1,int index1,vector<int>& subsequence2,int index2){
		int x=subsequence1.size(),y=subsequence2.size();
		while(index1<x && index2<y){
			int difference=subsequence1[index1]-subsequence2[index2];
			if(difference!=0){
				return difference;
			} 
			index1++;
			index2++;
		}
		return (x-index1)-(y-index2);
	}
	
};


int main(){
	vector<int> nums1={3,4,6,5};
	vector<int> nums2={9,1,2,5,8,3};
	
	Solution s=Solution(); 
	vector<int>  res = s.maxNumber(nums1,nums2,5);
	for(auto& r:res){
		cout<<r<<" ";
	}
	
	return 0;
}  
