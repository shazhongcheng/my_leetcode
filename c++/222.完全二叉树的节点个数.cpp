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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 最直白的做法，遍历一遍，并挨个统计 
//	int countNodes(TreeNode* root) {
//		if(root==nullptr){
//			return 0;
//		}
//		stack<TreeNode*> s;
//		TreeNode* temp=root;
//		int count=0;
//		while(temp){
////			cout<<temp->val;
//			count++;
//			if(temp->right){
//				s.push(temp->right);
//			}
//			if(temp->left){
//				s.push(temp->left);
//			}
//			if(!s.empty()){
//				temp=s.top();
//				s.pop();
//			}else{
//				temp=nullptr;
//			}
//		}
//		return count;
//    }

//	简洁的递归做法 递归统计左右节点个数，并加上自身返回 
	int countNodes(TreeNode* root) {
		if(root == NULL) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


int main(){
	TreeNode* root = new TreeNode(1);
	TreeNode* lchind1 = new TreeNode(2);
	TreeNode* rchild1 = new TreeNode(3);
	TreeNode* lchind11 = new TreeNode(4);
	TreeNode* lchind12 = new TreeNode(5);
	TreeNode* rchind11 = new TreeNode(6);
	root->left=lchind1;
	root->right=rchild1;
	lchind1->left=lchind11;
	lchind1->right=lchind12;
	rchild1->left=rchind11;
	
	
	 
	Solution s = Solution();
	int  res = s.countNodes(root);
	cout<<res;
	
	return 0;
}  
