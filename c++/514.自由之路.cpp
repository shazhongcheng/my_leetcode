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
	
	int findRotateSteps(string ring, string key) {
		// n���ַ������ȣ�m����Կ���� 
		int n =ring.size(),m=key.size();
		// idx �洢���ַ����У�ÿ���ַ���λ�ã�dp��״̬ת�ƾ���m��Ҫת�����Σ�n��ÿ�������ĳ���=�ַ������ȣ�INT_MAX������ʼ��ֵ��Ϊ��� 
		vector<vector<int> > idx(26),dp(m,vector<int>(n,INT_MAX));
		// idx λ���б��ʼ�� 
		for(int i=0;i<n;i++) idx[ring[i]-'a'].push_back(i);
		// ��̬�滮 m�� 
		for(int i=0;i<m;i++){
			//�Ե�ǰλ�������� 
			for(int &j:idx[key[i]-'a']){
				//����ǵ�һ�ֳ�ʼ������dp�У���һ��״̬�ĳ��ȣ�ȫ����ʼ��Ϊ(˳λ�����λ�ﵽ)����Сֵ 
				if(i==0) dp[0][j]=min(j,n-j);
				//���ǵ�һ���� 
				else{		
					//��λ�þ����У�ȡ����һ�ε��ַ�ֵ��λ�ã�Ȼ�󿴴ӵ�ǰλ�ã�����һ����һ��λ�ã�����			
					for(int &k:idx[key[i-1]-'a']){
						//�����֮ǰ������λ�ø������Ͳ��䣬�����(˳λ�����λ�ﵽ)�������͸��¾��� 
						dp[i][j]=min(dp[i][j],dp[i-1][k]+min(abs(j-k),n-abs(j-k)));
					}
				}
			}
		}
		//��ȡdp֮��һ���е���Сֵ + ����key���Ƚ���ƴд�ĵĲ��� 
		return *min_element(begin(dp.back()),end(dp.back()))+m;
    }
	
};


int main(){
	
	Solution s = Solution();
	
	cout<<s.findRotateSteps("godding","gd")<<endl;
	return 0;
} 
