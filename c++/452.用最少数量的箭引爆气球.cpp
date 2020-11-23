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
	// 按照每个气球的右边界进行从小到大的排序，最后按照新左边界是不是超过的旧气球的右边界，如果超过了，就要来新的一箭，同时更新记录的右边界 
	int findMinArrowShots(vector<vector<int>>& points) {
		if(points.size()<1) return 0;
		sort(points.begin(),points.end(),[](auto&& a,auto &&b){
			return a[1]<b[1];
		});
//		for(auto&& r:points){
//			cout<<r[0]<<" "<<r[1]<<endl;
//		}
		int count=1;
		int axis=points[0][1];
		
		for(int i=1;i<points.size();i++){
			if(axis<points[i][0]){
				count++;
				axis=points[i][1];
			}
		}
		return count;
    }
};


int main(){
	vector<vector<int> > points={{10,16},{2,8},{1,6},{7,12}}; 
	 
	Solution s = Solution();
	int  res = s.findMinArrowShots(points);
	cout<<res;
	
	return 0;
}  
