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
	// 12ms
	// 遍历数组，主要看两个数据，当前的油能不能开到下一个站，以及总油是不是大于需要的油 
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// rest 是看总油是不是大于需要的油  run是看当前的油能不能开到下一个站 start是更新出发点 
		int rest=0,run=0,start=0;
		// 循环遍历 
		for(int i=0;i<gas.size();i++){
			// 统计当前的油能不能开到下一个站 
			run+=(gas[i]-cost[i]);
			// 统计总油 
			rest+=(gas[i]-cost[i]);
			// 如果当前的油，开不到 i站，说明，i站的油加上i站的油耗，都不够前往下一个站了，就将起点更新为下一个站，
			// 从下一个站开始出发 
			if(run<0){
				start=i+1;
				run=0;
			}
		} 
		return rest<0?-1:start;
    }
};


int main(){
	vector<int> gas={1,2,3,4,5};
	vector<int> cost={3,4,5,1,2};
	Solution s = Solution();
	int res = s.canCompleteCircuit(gas,cost);
	cout<<res;
	
	return 0;
} 
