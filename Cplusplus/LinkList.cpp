#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList
{
public:
    ListNode* head;
    int size = 0;
public:
    MyLinkedList(): head(nullptr) {}
    MyLinkedList(ListNode *linkList){head = linkList;}

    int get(int index)
    {
        ListNode* trv = head;
        if(index < size)
            return 0;
        trv = getIndexListNode(index);
        return trv->val;
    }

    void addAtHead(int val)
    {
        size++;
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp; 
    }

    void addAtTail(int val)
    {
        size++;
        ListNode* new_temp = new ListNode(val);
        if(head == nullptr)
        {
            head = new_temp;
            return;
        }
        ListNode* trv = head;
        // 定位到尾巴
        while (trv->next != nullptr)
            trv = trv->next;
        trv->next = new_temp;

    }

    void addAtIndex(int index, int val)
    {
        size++;
        ListNode* insertNode = getIndexListNode(index);
        ListNode* newNode = new ListNode(val);
        ListNode* temp = insertNode->next;
        insertNode->next = newNode;
        newNode->next = temp;
    }

    void deleteAtIndex(int index)
    {
        if(index >= size)
            return;
        ListNode* insertNode = getIndexListNode(index);
        ListNode* temp = insertNode->next;
        insertNode->next = insertNode->next->next;
        delete temp; 
    }

    ListNode* getIndexListNode(int index)
    {
        ListNode* trv = head;
        for(int i=0; i < index; i++)
            trv = trv->next;
        return trv;
    }

};


class Solution
{
public:
    ListNode* removeElement(ListNode* head, int val)
    {
        if(head !=nullptr)
            return head;
        // 使用虚拟头节点
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;

        // 定义一个 遍历指针
        ListNode* trv = dummyHead;
        
        while(trv->next != nullptr)
        {
            if(trv->next->val == val)
            {
                ListNode* temp = trv->next;
                trv->next = trv->next->next;
                delete temp;
            }
            else
                trv = trv->next;
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    ListNode* removeElementV2(ListNode* head, int val)
    {
        if(head == nullptr)
            return head;

        while(head->next != nullptr && head->val == val)
        {
            ListNode* temp;
            temp = head;
            head = head->next;
            delete temp;
        }

        // 定义一个遍历节点
        ListNode* trv = head;
        
        while(trv->next != nullptr)
        {
            if(trv->next->val == val)
            {
                ListNode* temp = trv->next;
                trv->next = trv->next->next;
                delete temp;                
            }
            else
                trv = trv->next;
        }

        return head;
    }

    ListNode* reverseList(ListNode* head)
    {
        // 定义两个指针 一个插入节点 一个待插入位置 也可认为是双指针
        ListNode* prePoint = nullptr; 
        ListNode* backPoint = head; 
        
        while(backPoint != nullptr)
        {
            ListNode* temp = backPoint->next;
            backPoint->next = prePoint;
            prePoint = backPoint;
            backPoint = temp;
        }
        return backPoint;
    }

    ListNode* swapPairs(ListNode* head)
    {
        // 使用双指针 prePoint backPoint
        if(head == nullptr && head->next == nullptr)
            return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* prePoint = dummyHead;
        ListNode* backPoint = prePoint->next->next;

        while (backPoint != nullptr)
        {
            // 交互
            ListNode* firstP = prePoint->next;
            ListNode* secondP = backPoint->next;
            prePoint->next = backPoint;
            backPoint->next = firstP;
            firstP->next = secondP;
            // 

        }
        

    }
};


int main()
{
    Solution solution;
    ListNode *head = new ListNode(7);
    ListNode *test1 = new ListNode(7);
    head->next = test1;

    solution.removeElementV2(head, 7);
    delete head;
    return 0;
}
