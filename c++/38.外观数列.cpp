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
	//�ݹ�  8ms
	// ˼·������һ�ֵ����������� 
	string countAndSay(int n) {
		// ����ݹ鵽ͷ���ͷ��� "1" 
		if(n==1) return "1";
		// ��ȡ��һ�ֵĽ�� �������� 
		string num=countAndSay(n-1);
		string temp="";
		// ����һ�ֵĽ�������� 
		for(int i=0;i<num.size();i++){
			// ����һ�ֵĵ�ǰ������ͳ�� 
			int count=1;
			// ͳ����ͬ�����ֳ����˼��� 
			while(i<num.length()-1 && num[i]==num[i+1]){
				count++;
				i++;
			}
			// ƴ�ӵ���β 
			temp+=tostr(count);
			temp+=num[i];
		}
		//���� 
		return temp;
	}
	// ����ת�ַ��� 
	string tostr(int count){
		string res="";
		while(count){
			res=(char)(count%10+'0')+res;
			count/=10;
		}
		return res;
	}
};


int main(){
	Solution s = Solution();
	string res = s.countAndSay(4);
	cout<<res;
	
	return 0;
} 
