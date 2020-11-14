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
		// 字典 
		unordered_map<int,int> mp;
		// 以arr2的值为键，以arr2值的下标作为值 
		for(int i=0;i<arr2.size();i++){
			mp[arr2[i]]=i;
		} 
		// 如果arr1的值不在字典键里面，就将其值赋值为arr2的长度 
		for(int i=0;i<arr1.size();i++){
			if(!mp.count(arr1[i])){
				mp[arr1[i]]=arr2.size();
			}
		}
		// 对arr1进行排序，按照字典来排序，如果两个值的下标相等(只有两种情况，一是a=b,二是arr1中不在arr2中的值)，就按照升序排，否则按照下标升序排序 
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
