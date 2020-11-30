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
		//��¼��ĸ������������
		//��¼26����ĸ�ļ�ֵ�� 
		vector<pair<char,int> > h(26,make_pair('a',0));
		//��ʼ���� 
		for(int i=0;i<26;i++){
			h[i].first+=i;
		}
		//���ַ������ַ����м�¼ 
		for(auto p:S)
			h[p-'a'].second++;
		//�������� 
		sort(h.begin(),h.end(),[](pair<char,int> a,pair<char,int> b){
			return a.second>b.second;
		});
		 
		//�ж��Ƿ��ܹ��ع� �����ַ����ܳ���һ�� 
		if(h[0].second>(S.size()+1)/2)
			return "";
		
		//����size���ַ���ƴ�Ӷ��ɣ���ת���롣
		//���ճ��ִ��������ַ��������������Ŀ���ַ���
		//֮�������ַ�ȫ��������ת������� 
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
