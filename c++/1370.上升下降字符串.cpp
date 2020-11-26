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




//桶排序
//参考：https://blog.csdn.net/zxzxzx0119/article/details/82889998
//设置n+1个桶是为了保证间距最大的两个数被分到不同的桶中
//因为最大间距 x >= (max_val - min_val) / (n-1)
//而使用n+1个桶每个桶中数的差值最大为 (max_val - min_val) / n 因此一个桶不可能同时存放间距最大的两个数
class Solution {
public:
	// 寻找当前值映射到第几个桶  
	int mapToBucket(long num,long len,long min,long max){
		return (int)((num-min)*len/(max-min));
	}
	// 代码里面占用了 max 和 min 所以重新定义一个 
	int mymin(int i,int j){
		return i<j?i:j;
	}
	int mymax(int i,int j){
		return i>j?i:j;
	}
	
	int maximumGap(vector<int>& nums) {
		// 不足两个 ，就返回0 
		if(nums.size()<2){
			return 0;
		} 
		// 声明一些变量 
		int len=nums.size();
		int min = INT_MAX,max=INT_MIN;
		bool hasNum[len+1];
		int mins[len+1];
		int maxs[len+1];
		// 进行初始化，寻找最大值，和最小值，用来作为桶的开头和结尾，以及初始化桶里面是否有值的标记 
		for(int i=0;i<nums.size();i++){
			min=nums[i]<min?nums[i]:min;
			max=nums[i]>max?nums[i]:max;
			hasNum[i]=false;
		}
		hasNum[len]=false;
		if(max==min){
			return 0;
		}
		//进行桶排序 
		for(int i=0;i<nums.size();i++){
			//寻找当前值映射的桶的位置 
			int bid=mapToBucket(nums[i],len,min,max);
			//更新这个桶的最大值和最小值，以及更新有值的标记 
			mins[bid]=hasNum[bid]?mymin(mins[bid],nums[i]):nums[i];
			maxs[bid]=hasNum[bid]?mymax(maxs[bid],nums[i]):nums[i];
			hasNum[bid]=true;
		}
		//对桶进行遍历，取出第一个桶的最大值，后面肯定会有桶的最小值，大于这个桶的最大值 
		int res=0,preMax=maxs[0];
		for(int i=1;i<=len;i++){
			//如果，后面的桶有值，就计算这个桶的最小值和当前记录的最大值的差，并和目前的结果对比更新
			//同时，更新当前记录的最大值为新的 
			if(hasNum[i]){
				res=mymax(res,mins[i]-preMax);
				preMax=maxs[i];
			}
		}
		return res;
    } 

};


int main(){
	vector<int> nums={1,10000000};
	Solution s = Solution();
	int  res = s.maximumGap(nums);
	cout<<res;
	
	return 0;
}  
