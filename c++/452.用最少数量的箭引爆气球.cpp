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
	// ����ÿ��������ұ߽���д�С������������������߽��ǲ��ǳ����ľ�������ұ߽磬��������ˣ���Ҫ���µ�һ����ͬʱ���¼�¼���ұ߽� 
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
