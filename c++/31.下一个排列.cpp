//  973. 最接近原点的 K 个点
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
	// 8ms
	/* 
	void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int j = nums.size() - 1; 
        while(j-1>=0 && nums[j-1] >= nums[j]){ --j;}
        if(j == 0){
            for(int i = 0; i < nums.size()/2; ++i){
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return ;
        }
        int r = nums.size() - 1;
        while(r >= j){
            if(nums[r] > nums[j-1]) break;
            --r;
        }
        swap(nums[r], nums[j-1]);
        int cnt = (nums.size() - j)/2;
        int i = 0;
        while(cnt > 0){
            swap(nums[j+i], nums[nums.size() - 1 - i]);
            ++i; --cnt;
        }
        return;
    }
	*/
	
	// 修改自上面 
	// 12ms 
	/* 
	void nextPermutation(vector<int>& nums) {
		// 长度小于2 直接返回 
		if(nums.size()<=1) return;
		// 判断是否是降序 
		int j=nums.size()-1;
		while(j-1>=0 && nums[j-1]>=nums[j]){
			--j;
		}
		//是降序 
		if(j==0){
//			for(int i=0;i<nums.size()/2;++i){
//				swap(nums[i],nums[nums.size()-1-i]);
//			}
			reverse(nums.begin(),nums.end()); 
			return;
		}
		//从(j,nums.size())中找到第一个比j-1大的值，因为上面的判断原因，所以从后往前找到的第一个大于的，一定是最接近的 
		int r=nums.size()-1;
		while(r>=j){
			if(nums[r]>nums[j-1]) break;
			--r;
		}
		//交换 
		swap(nums[r],nums[j-1]);
		//对[j,nums,size()] 进行重排序 
//		int cnt=(nums.size()-j)/2;
//		int i=0;
//		while(cnt>0){
//			swap(nums[j+i],nums[nums.size()-1-i]);
//			++i;--cnt;
//		}
		//默认按照升序排列 
		sort(nums.begin()+j,nums.end()); 
		return;
    }
    */
    // 8ms
    // 将范围内的元素重新排列到下一个字典上的更大的排列 
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
    
	
};


int main(){
	vector<int> v;
	Solution s = Solution();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	 
	s.nextPermutation(v);
	for(int &n:v){
		cout<<n<<" ";
	}
	cout<<endl;
	
	v.clear();
	
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	 
	s.nextPermutation(v);
	for(int &n:v){
		cout<<n<<" ";
	}
	cout<<endl;
	
	return 0;
} 
