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
	//��ʱ 96ms
	//ԭ��������һά���������ֵľ���Ȼ���յ� r0 c0 �ľ������� 
	vector<vector<int> > allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int> > v(R*C,vector<int>(2));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				v[i*C+j][0]=i;
				v[i*C+j][1]=j;				
			}
		}
		sort(v.begin(),v.end(),[r0,c0](auto&& a,auto&& b){
			int dis1=abs(a[0]-r0)+abs(a[1]-c0);
			int dis2=abs(b[0]-r0)+abs(b[1]-c0);
			return dis1<dis2;
		});
		return v; 
    }
};


int main(){
	Solution s = Solution();
	vector<vector<int> > res = s.allCellsDistOrder(2,3,1,2);
	for(auto&& n:res){
		for(int i=0;i<n.size();i++){
			cout<<n[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
