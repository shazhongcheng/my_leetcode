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
	// 0ms 
	int strStr(string haystack, string needle) {
		// ��� ��Ҫ���ҵ��ַ���Ϊ�գ��ͷ���0 
		if(needle==""){
			return 0;
		}	
		// ����Ŀ���ַ���	
		for(int i=0;i<haystack.length();i++){
			int j=0;
			//���ʣ�µ��ַ�����������ҵ��ַ����ĳ��ȣ������� 
			if(i+needle.length()>haystack.length()){
				break;
			}
			//��ʼ�������ַ���ƥ�� 
			for(;j<needle.length();j++){
				if(needle[j]!=haystack[i+j]){
					break;
				}
			}
			//ƥ��ɹ� 
			if(j==needle.length()){
				return i;
			}
		} 
		return -1;
    }
};


int main(){
	Solution s = Solution();
	int res = s.strStr("hello","ll");
	cout<<res<<endl;
	
	return 0;
} 
