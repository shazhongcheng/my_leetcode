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
	// 16ms
	// ˼·��̫����⣬��һ������num.size()-k�εĴ��ڣ�ÿ�ֱ���Ѱ�ҵ�ǰ���ڵ���Сֵ 
	/* 
	 string removeKdigits(string num, int k) {
		const int N = num.size();
		string result;
		// ÿһ�������Ĵ���ͷ 
		int from=0;
		//ÿһ�������Ĵ���β 
		int to=k;
		// ���������ָ��� 
		int last=N-k;
		bool start=false;
		//����������Ϊ��Ҫ���������ָ��� 
		while(last--){
			//������Χ���ҵ���С������ 
			int min=from;
			for(int current=from;current<=to;current++){
				if(num[current]<num[min]){
					min=current;
				}
			}
			// ÿһ�������Ĵ���ͷ���Ƶ���ǰ����С�ĺ���һ�� 
			from=min+1;
			// �ж��ǲ��ǵ�һ������0���� 
			if(!start){
				if(num[min]!='0'){
					start=true;
					result+=num[min];
				}
			}else{
				result+=num[min];
			}
			// ÿһ�������Ĵ���β�ͺ���һλ 
			to++;
		}
		// ��Ϊ����ȡ��0��û�н��жϵ���ӣ�resultΪ�� 
		if(!result.size()){
			return "0";
		}
		return result;
    }
    */
    // 0ms
    // ˼·�����������ַ����������ǰҪ��ӵģ����Ѿ��е�С�����滻������ͼӽ�ȥ 
    string removeKdigits(string num, int k) {
        vector<int> S;
        string result="";
        // ���� 
        for(int i=0;i<num.length();i++){
            //��ȡ���� 
			int number=num[i]-'0';
			//�ݴ�ļ��ϲ�Ϊ0���ҵ�ǰ�����ֱȼ�����������һ������ҪС����������ɾ���� 
            while(S.size()!=0 &&number<S[S.size()-1]&&k>0){
            	//ĩβ�Ľϴ�����ֵ���
                S.pop_back();
                //������һ������ 
                k--;
            }
            //���ֲ�Ϊ0�Ϳ������ ��������Ϊ0��ʱ�򳤶Ȳ�Ϊ0Ҳ������� 
			if(number!=0 || S.size()!=0){
                //������� 
				S.push_back(number);
            }
        }
        //ĩβ���ǵ��������� 
        while(S.size()!=0 && k>0){
            S.pop_back();
            k--;
        }
        //�������ϣ�Ȼ����ӵ��ַ����� 
        for(int i=0;i<S.size();i++){
            result.append(1,'0'+S[i]);
        }
        //����ַ���Ϊ�գ��ͷ��� "0" 
        if(result==""){
            result="0";
        }
        return result;
    }
};


int main(){
	Solution s = Solution();
	string res = s.removeKdigits("1432219",3);
	cout<<res<<endl;
	
	return 0;
} 
