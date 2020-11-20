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
	// ���¶�����һ���µ�����dummy��Ȼ����dummy�в���ԭ����head�еĽڵ� 
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy=new ListNode(-1);
		while(head){
			ListNode* p=dummy;
			// ��dummy���ҵ���һ����head��ǰ�ڵ�ֵ����� 
			while(p->next && p->next->val<head->val) p=p->next;
			//�ҵ��ˣ�����dummy�м���룬û�ҵ������������� q�����ݴ浱ǰ�ڵ� 
			ListNode* q=head;
			head=head->next;
			//�ȱ���p�ĺ�� 
			q->next=p->next;
			//Ȼ�����o�ĺ�� 
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
