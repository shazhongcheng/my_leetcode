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
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int res=0;
		map<int,int> map;
		for(const auto &a:A) for(const auto &b:B) ++map[a+b];
		for(const auto &c:C) for(const auto &d:D) res+=map[-(c+d)];
		return res; 
    }

};


int main(){
	vector<int> A={1,2};
	vector<int> B={-2,-1};
	vector<int> C={-1,2};
	vector<int> D={0,2};
	Solution s = Solution();
	int  res = s.fourSumCount(A,B,C,D);
	cout<<res;
	
	return 0;
}  
