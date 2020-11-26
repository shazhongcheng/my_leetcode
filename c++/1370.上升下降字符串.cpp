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




//Ͱ����
//�ο���https://blog.csdn.net/zxzxzx0119/article/details/82889998
//����n+1��Ͱ��Ϊ�˱�֤����������������ֵ���ͬ��Ͱ��
//��Ϊ����� x >= (max_val - min_val) / (n-1)
//��ʹ��n+1��Ͱÿ��Ͱ�����Ĳ�ֵ���Ϊ (max_val - min_val) / n ���һ��Ͱ������ͬʱ��ż������������
class Solution {
public:
	// Ѱ�ҵ�ǰֵӳ�䵽�ڼ���Ͱ  
	int mapToBucket(long num,long len,long min,long max){
		return (int)((num-min)*len/(max-min));
	}
	// ��������ռ���� max �� min �������¶���һ�� 
	int mymin(int i,int j){
		return i<j?i:j;
	}
	int mymax(int i,int j){
		return i>j?i:j;
	}
	
	int maximumGap(vector<int>& nums) {
		// �������� ���ͷ���0 
		if(nums.size()<2){
			return 0;
		} 
		// ����һЩ���� 
		int len=nums.size();
		int min = INT_MAX,max=INT_MIN;
		bool hasNum[len+1];
		int mins[len+1];
		int maxs[len+1];
		// ���г�ʼ����Ѱ�����ֵ������Сֵ��������ΪͰ�Ŀ�ͷ�ͽ�β���Լ���ʼ��Ͱ�����Ƿ���ֵ�ı�� 
		for(int i=0;i<nums.size();i++){
			min=nums[i]<min?nums[i]:min;
			max=nums[i]>max?nums[i]:max;
			hasNum[i]=false;
		}
		hasNum[len]=false;
		if(max==min){
			return 0;
		}
		//����Ͱ���� 
		for(int i=0;i<nums.size();i++){
			//Ѱ�ҵ�ǰֵӳ���Ͱ��λ�� 
			int bid=mapToBucket(nums[i],len,min,max);
			//�������Ͱ�����ֵ����Сֵ���Լ�������ֵ�ı�� 
			mins[bid]=hasNum[bid]?mymin(mins[bid],nums[i]):nums[i];
			maxs[bid]=hasNum[bid]?mymax(maxs[bid],nums[i]):nums[i];
			hasNum[bid]=true;
		}
		//��Ͱ���б�����ȡ����һ��Ͱ�����ֵ������϶�����Ͱ����Сֵ���������Ͱ�����ֵ 
		int res=0,preMax=maxs[0];
		for(int i=1;i<=len;i++){
			//����������Ͱ��ֵ���ͼ������Ͱ����Сֵ�͵�ǰ��¼�����ֵ�Ĳ����Ŀǰ�Ľ���Աȸ���
			//ͬʱ�����µ�ǰ��¼�����ֵΪ�µ� 
			if(hasNum[i]){
				res=mymax(res,mins[i]-preMax);
				preMax=maxs[i];
			}
		}
		return res;
    } 

};


int main(){
	vector<int> nums={1,10000000};
	Solution s = Solution();
	int  res = s.maximumGap(nums);
	cout<<res;
	
	return 0;
}  
