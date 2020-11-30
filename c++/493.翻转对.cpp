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

#define frop(i,s,n) for(int i=(s);i<(n);i++) 
class Solution {
public:
	string reorganizeString(string S) {
		//记录字母数并降序排列
		//记录26个字母的键值对 
		vector<pair<char,int> > h(26,make_pair('a',0));
		//初始化键 
		for(int i=0;i<26;i++){
			h[i].first+=i;
		}
		//对字符串的字符进行记录 
		for(auto p:S)
			h[p-'a'].second++;
		//降序排序 
		sort(h.begin(),h.end(),[](pair<char,int> a,pair<char,int> b){
			return a.second>b.second;
		});
		 
		//判断是否能够重构 最多的字符不能超过一半 
		if(h[0].second>(S.size()+1)/2)
			return "";
		
		//答案有size个字符串拼接而成，轮转排入。
		//按照出现次数最多的字符，来构建相等数目的字符串
		//之后其他字符全部按照轮转往后面放 
		int size=h[0].second;
		vector<string> ans(size);
		int l=0;
		frop(i,0,26){
			int n=h[i].second;
			frop(j,0,n){
				ans[l++%size].push_back(h[i].first);
//				for(auto p:ans){
//					cout<<p<<" ";
//				}
//				cout<<endl;
			}
		}
		string res;
		frop(i,0,size){
			res+=ans[i];
		}
		return res;
    }
};


int main(){
	Solution s=Solution(); 
	string  res = s.reorganizeString("aabccddee");
	cout<<res;
	
	return 0;
}  
