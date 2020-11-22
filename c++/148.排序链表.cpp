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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 大神的题解…… 
//链表里操作最难掌握的应该就是各种断链啊，然后再挂接啊。在这里，我们主要用到链表操作的两个技术：
//
//merge(l1, l2)，双路归并，我相信这个操作大家已经非常熟练的，就不做介绍了。
//cut(l, n)，可能有些同学没有听说过，它其实就是一种 split 操作，即断链操作。不过我感觉使用 cut 更准确一些，它表示，将链表 l 切掉前 n 个节点，并返回后半部分的链表头。
//额外再补充一个 dummyHead 大法，已经讲过无数次了，仔细体会吧。
//---
//
//希望同学们能把双路归并和 cut 断链的代码烂记于心，以后看到类似的题目能够刷到手软。
//
//掌握了这三大神器后，我们的 bottom-to-up 算法伪代码就十分清晰了：
//
//current = dummy.next;
//tail = dummy;
//for (step = 1; step < length; step *= 2) {
//	while (current) {
//		// left->@->@->@->@->@->@->null
//		left = current;
//
//		// left->@->@->null   right->@->@->@->@->null
//		right = cut(current, step); // 将 current 切掉前 step 个头切下来。
//
//		// left->@->@->null   right->@->@->null   current->@->@->null
//		current = cut(right, step); // 将 right 切掉前 step 个头切下来。
//		
//		// dummy.next -> @->@->@->@->null，最后一个节点是 tail，始终记录
//		//                        ^
//		//                        tail
//		tail.next = merge(left, right);
//		while (tail->next) tail = tail->next; // 保持 tail 为尾部
//	}
//}

class Solution {
public:
	// 代码 的思路非常清晰，主要是链表的断链 链接的操作，比较难处理 
	ListNode* sortList(ListNode* head) {
		ListNode dummyHead(0);
		dummyHead.next=head;
		auto p = head;
		int length=0;
		// 先统计长度，以供后续自下而上的归并排序 
		while(p){
			++length;
			p=p->next;
		} 
		// 从1-2-4-8----进行指数增长，归并排序 
		for(int size=1;size<length;size<<=1){
			//当前轮数的开头 
			auto cur=dummyHead.next;
			//用来链接当前每一个小轮返回的归并好的子集 
			auto tail=&dummyHead;
			//如果没有到结尾，就继续 
			while(cur){
				//左边开头的子集 
				auto left=cur;
				//按照size，从left开始跳过指定size长度，并返回，形成右边子集 
				auto right=cut(left,size);
				// 右边子集还有后面的很多元素，所以再跳过指定size长度，并切断，然后返回，作为下一轮开始的迭代 
				cur=cut(right,size);
				//结尾续借当前归并的结果 ，并更新到结尾 
				tail->next=merge(left,right);
				while(tail->next){
					tail=tail->next;
				}
			}
		}
		//返回 结果 
		return dummyHead.next;
    }
    // 功能就是，跳过指定n长度的元素，并切断这个元素和下一个元素的链接，同时返回下一个元素地址 
    ListNode* cut(ListNode* head,int n){
    	auto p=head;
    	while(--n&&p){
    		p=p->next;
		}
		if(!p) return nullptr;
		
		auto next=p->next;
		p->next=nullptr;
		return next;
	}
    // 功能就是对l1和l2进行归并 
    ListNode* merge(ListNode* l1,ListNode* l2){
    	ListNode dummyHead(0);
    	auto p=&dummyHead;
    	//只要l1或者l2不为空，就循环比大小，续借到哨兵节点后面 
    	while(l1 && l2){
    		if(l1->val < l2->val){
    			p->next=l1;
    			p=l1;
    			l1=l1->next;
			}else{
				p->next=l2;
				p=l2;
				l2=l2->next;
			}
		}
		//不为空的全部续借到哨兵节点的最后面 
		p->next=l1?l1:l2;
		return dummyHead.next;
	}
};


int main(){
	ListNode *head = new ListNode(4);
	ListNode *tail=head;
	tail->next=new ListNode(2);
	tail=tail->next;
	tail->next=new ListNode(1);
	tail=tail->next;
	tail->next=new ListNode(3);
	tail=tail->next;
	
	Solution s = Solution();
	ListNode* res = s.sortList(head);
	while(res){
		cout<<res->val<<" ";
		res=res->next;
	}
	
	return 0;
} 
