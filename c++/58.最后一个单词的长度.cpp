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
	// �������ǰ��ʼͳ�ƣ������ֵ�һ���ǿ��ַ�ʱ����ʼͳ�ƣ������ֿ��ַ����ҳ��Ȳ�Ϊ0ʱ������ 
	int lengthOfLastWord(string s) {
		if(s.length()<=0){
			return 0;
		}
		int length=0;
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]!=' '){
				length++;
			}else if(length!=0){
				return length;
			}
		}
		return length;
    }
};


int main(){
	Solution s = Solution();
	int length = s.lengthOfLastWord("Hello World");
	cout<<length<<endl;
	
	return 0;
}  
