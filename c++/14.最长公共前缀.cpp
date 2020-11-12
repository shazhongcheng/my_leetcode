//  7. ������ת
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
	// ��ʱ�ˡ���
	/* 
	string longestCommonPrefix(vector<string>& strs) {
		string str="";
		bool isAdd=true;
		int j=0;
		char mark;
		while(true){
			for(int i=0;i<strs.size();i++){
				if(i==0){
					if(strs[i].length()>j){
						mark=strs[i][j];
						isAdd=true;
					}else{
						isAdd=false;
						break;
					}
				}else{
					if(strs[i].length()>j){
						if(strs[i][j]!=mark){
							isAdd=false;
							break;
						}
					}else{
						isAdd=false;
						break;
					}
				}
				
			}
			if(isAdd==false){
				break;
			}else{
				j++;
			}
		}
		
		return strs[0].substr(0,j); 
    }
    */
    // ����ʱ�� 0ms
	// ˼·��1�����ַ�������Ӷ̵�������
	//       2������̵ĵ�һ���ַ������ȣ�����Ϊ��� right��֮�����������飬�Ͳ���Ҫ����right��
	//       3����1��ʼ�����ַ������飬ֻҪ��ǰ���ַ������ڵ�һ���ַ����ĵ�ǰ�ַ����͸���right
	//       4�����شӱ�ǵ��ַ����зֵ��ַ� 
	 string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size()==0) return res;
        sort(strs.begin(),strs.end(),cmp);
        int right=strs[0].size()-1;
        for(int j=1;j<strs.size()&&right>=0;j++){
        	int i;
        	for(i=0;i<=right;i++)
				if(strs[j][i]!=strs[0][i]){
        		break;
			}
			right=i-1;
		}
		res=strs[0].substr(0,right+1);
		
		return res; 
    }
    static bool cmp(string &a,string &b){
    	return a.size()<b.size();
	}
};


int main(){
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("floght");
		
	Solution s = Solution();
	string res = s.longestCommonPrefix(strs);
	cout<<res<<" "<<endl;
	
	return 0;
} 
