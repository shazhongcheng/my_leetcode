#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
	// 12ms
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		// �ֵ� 
		unordered_map<int,int> mp;
		// ��arr2��ֵΪ������arr2ֵ���±���Ϊֵ 
		for(int i=0;i<arr2.size();i++){
			mp[arr2[i]]=i;
		} 
		// ���arr1��ֵ�����ֵ�����棬�ͽ���ֵ��ֵΪarr2�ĳ��� 
		for(int i=0;i<arr1.size();i++){
			if(!mp.count(arr1[i])){
				mp[arr1[i]]=arr2.size();
			}
		}
		// ��arr1�������򣬰����ֵ��������������ֵ���±����(ֻ�����������һ��a=b,����arr1�в���arr2�е�ֵ)���Ͱ��������ţ��������±��������� 
		sort(arr1.begin(),arr1.end(),[&mp](int a,int b){
			if(mp[a]==mp[b]) return a<b;
			return mp[a]<mp[b];
		});
		return arr1;
    }
};


int main(){
	vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2={2,1,4,3,9,6};
	
	 
		
	Solution s = Solution();
	vector<int> res = s.relativeSortArray(arr1,arr2);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	
	return 0;
} 
