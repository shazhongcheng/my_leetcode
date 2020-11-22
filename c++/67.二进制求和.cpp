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
	// ���������ª�Ĵ��룬���ǴӺ���ǰ��Ӧ�ӣ��������1���ͽ�һλ��Ȼ��ӵ���һλ 
	//12ms
//	string addBinary(string a, string b) {
//		string res="";
//		int as=a.size()-1;
//		int bs=b.size()-1;
//		bool flag=false;
//		while(as>=0 && bs>=0){
//			int temp=(a[as]-'0')+(b[bs]-'0')+(flag?1:0);
//			if(temp>1){
//				flag=true;
//			}else{
//				flag=false;
//			}
//			res=char(temp%2+'0')+res;
//			as--;
//			bs--;
//		}
//		while(as>=0){
//			int temp=(a[as]-'0')+(flag?1:0);
//			if(temp>1){
//				flag=true;
//			}else{
//				flag=false;
//			}
//			res=char(temp%2+'0')+res;
//			as--;
//		}
//		while(bs>=0){
//			int temp=(b[bs]-'0')+(flag?1:0);
//			if(temp>1){
//				flag=true;
//			}else{
//				flag=false;
//			}
//			res=char(temp%2+'0')+res;
//			bs--;
//		}
//		if(flag){
//			res='1'+res;
//		} 
//		return res;
//    }

	// �����Ĵ���
	// 4ms 
	// ˼·������һ�£�������ͨ��c���ۼӣ�����1��ȡ������Ȼ���2����ʽΪ��λ���� 
	// ���������ӵ������Ǵ�ǰ����Ҫ��תһ�� 
	string addBinary(string a, string b) {
		if(a.size()==0) return b;
		if(b.size()==0) return a;
		int i=a.size()-1;
		int j=b.size()-1;
		int c=0;
		string res;
		while(i>=0 || j>=0){
			if(i>=0) c+=a[i--]-'0';
			if(j>=0) c+=b[j--]-'0';
			res.push_back(char(c%2+'0'));
			c>>=1;
		}
		reverse(res.begin(),res.end());
		return c>0?'1'+res:res;
	}
};


int main(){

	Solution s = Solution();
	string res = s.addBinary("1010","1011");
	cout<<res;
	
	return 0;
} 
