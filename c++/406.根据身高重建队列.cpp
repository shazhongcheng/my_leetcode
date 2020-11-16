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
	// 原理 对以身高为主键降序排序  如果身高相同，就看位置升序排序
	//  {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}} ->  7 0|7 1|6 1|5 0|5 2|4 4|
	// 然后按照位置来进行插入 7-0->7-0,7-1->7-0,6-1,7-1->5-0,7-0,6-1,7-1-> 5-0,7-0,5-2,6-1,7-1-> 5-0,7-0,5-2,6-1,4-4,7-1-
	vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
		// 如果人数为空，或者开头第一个元素为空，就返回空 
		if(0==people.size() || 0==people[0].size()){
			return vector<vector<int> >();
		}	
		// 	对以身高为主键降序排序  如果身高相同，就看位置升序排序
		sort(people.begin(),people.end(),[](auto&& a,auto&& b){
			if (a[0] == b[0]) {
				return b[1]>a[1];
            }
			return b[0]<a[0];
		});
		// 照位置来进行插入 7-0->7-0,7-1->7-0,6-1,7-1->5-0,7-0,6-1,7-1-> 5-0,7-0,5-2,6-1,7-1-> 5-0,7-0,5-2,6-1,4-4,7-1-
		vector<vector<int> > result;
		for(int i=0;i<people.size();i++){
			result.insert(result.begin()+people[i][1],people[i]);
		}
		return people;
    }
};


int main(){
	vector<vector<int> > people={{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
	Solution s = Solution();
	vector<vector<int> > res = s.reconstructQueue(people);
	for(auto&& r:res){
		cout<<r[0]<<" "<<r[1]<<"|";
	}
	
	return 0;
} 
