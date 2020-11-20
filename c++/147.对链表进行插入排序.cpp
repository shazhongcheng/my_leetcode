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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	// 重新定义了一个新的链表dummy，然后往dummy中插入原来的head中的节点 
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy=new ListNode(-1);
		while(head){
			ListNode* p=dummy;
			// 在dummy中找到第一个比head当前节点值大的数 
			while(p->next && p->next->val<head->val) p=p->next;
			//找到了，就在dummy中间插入，没找到，就在最后插入 q用来暂存当前节点 
			ListNode* q=head;
			head=head->next;
			//先保存p的后继 
			q->next=p->next;
			//然后更新o的后继 
			p->next=q;
		}
		
		return dummy->next;
    }
};


int main(){
	ListNode* head = new ListNode(4);
	ListNode* tail=head;
	tail->next=new ListNode(2);
	tail=tail->next;
	tail->next=new ListNode(1);
	tail=tail->next;
	tail->next=new ListNode(3);
	tail=tail->next;
	 
	Solution s = Solution();
	ListNode *res = s.insertionSortList(head);
	while(res){
		cout<<res->val<<" ";
		res=res->next; 
	}
	
	return 0;
}  
