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
	// �������飬��Ҫ���������ݣ���ǰ�����ܲ��ܿ�����һ��վ���Լ������ǲ��Ǵ�����Ҫ���� 
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// rest �ǿ������ǲ��Ǵ�����Ҫ����  run�ǿ���ǰ�����ܲ��ܿ�����һ��վ start�Ǹ��³����� 
		int rest=0,run=0,start=0;
		// ѭ������ 
		for(int i=0;i<gas.size();i++){
			// ͳ�Ƶ�ǰ�����ܲ��ܿ�����һ��վ 
			run+=(gas[i]-cost[i]);
			// ͳ������ 
			rest+=(gas[i]-cost[i]);
			// �����ǰ���ͣ������� iվ��˵����iվ���ͼ���iվ���ͺģ�������ǰ����һ��վ�ˣ��ͽ�������Ϊ��һ��վ��
			// ����һ��վ��ʼ���� 
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
