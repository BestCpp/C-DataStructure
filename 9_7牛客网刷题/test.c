#define _CRT_SECURE_NO_WARNINGS 1

//��ת����
struct ListNode* ReverseList(struct ListNode* pHead)
{
    // write code here

    struct ListNode* cur = pHead;
    struct ListNode* newHead = NULL;
    //ʹ��ͷ�巨��ı�cur�����ӣ�����Ҫ�ȴ洢��һ���ڵ�ĵ�ַ
    struct LsitNode* next = NULL;
    while (cur)
    {
        next = cur->next;
        if (newHead == NULL)
        {
            newHead = cur;
            newHead->next = NULL;
        }
        else
        {
            cur->next = newHead;
            newHead = cur;
        }
        cur = next;
    }
    return newHead;
}

//struct ListNode* ReverseList(struct ListNode* pHead)
//{
//    // write code here
//
//    struct ListNode* cur = pHead;
//    struct ListNode* newHead = NULL;
//    //ʹ��ͷ�巨��ı�cur�����ӣ�����Ҫ�ȴ洢��һ���ڵ�ĵ�ַ
//    struct LsitNode* next = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        cur->next = newHead;
//        newHead = cur;
//        cur = next;
//    }
//    return newHead;
//}

//�ϲ�������������
struct ListNode* CreateNode(int val)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    struct ListNode* p1 = pHead1;
    struct ListNode* p2 = pHead2;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while (p1 && p2)
    {
        if (p1->val <= p2->val)
        {
            if (head == NULL && tail == NULL)
            {
                head = tail = CreateNode(p1->val);
            }
            else
            {
                tail->next = CreateNode(p1->val);
                tail = tail->next;
            }
            p1 = p1->next;
        }
        else
        {
            if (head == NULL && tail == NULL)
            {
                head = tail = CreateNode(p2->val);
            }
            else
            {
                tail->next = CreateNode(p2->val);
                tail = tail->next;
            }
            p2 = p2->next;
        }
    }
    if (p1 != NULL)
    {
        while (p1)
        {
            if (head == NULL && tail == NULL)
            {
                head = tail = CreateNode(p1->val);
            }
            else
            {
                tail->next = CreateNode(p1->val);
                tail = tail->next;
            }
            p1 = p1->next;
        }
    }
    else
    {
        while (p2)
        {
            if (head == NULL && tail == NULL)
            {
                head = tail = CreateNode(p2->val);
            }
            else
            {
                tail->next = CreateNode(p2->val);
                tail = tail->next;
            }
            p2 = p2->next;
        }
    }
    return head;
}


//�ж������Ƿ��л�
bool hasCycle(struct ListNode* head) {
    // write code here
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}


//��������k���ڵ�
struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    // write code here
    struct ListNode* slow = pHead;
    struct ListNode* fast = pHead;
    while (k--)
    {
        if (fast == NULL)
        {
            return fast;
        }
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}



//��������ĵ�һ�������ڵ�
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    int size1 = 0;
    int size2 = 0;
    struct ListNode* cur1 = pHead1;
    struct ListNode* cur2 = pHead2;
    while (cur1)
    {
        size1++;
        cur1 = cur1->next;
    }
    while (cur2)
    {
        size2++;
        cur2 = cur2->next;
    }
    //��λ
    cur1 = pHead1;
    cur2 = pHead2;
    //Ĭ��siez1�ǳ�����
    if (size1 < size2)
    {
        struct ListNode* tmp = cur1;
        cur1 = cur2;
        cur2 = tmp;
    }
    int gap = abs(size1 - size2);
    while (gap--)
    {
        cur1 = cur1->next;
    }
    while (cur1 && cur2)
    {
        if (cur1 == cur2)
        {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return NULL;
}



//�ж�һ�������Ƿ�Ϊ���Ľṹ
struct ListNode* CreateNode(int val)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}
bool isPail(struct ListNode* head) {
    // write code here

    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    //�����µķ�ת���������������ı�ԭ����Ľṹ
    while (cur)
    {
        struct ListNode* newnode = CreateNode(cur->val);
        if (newhead == NULL)
        {
            newhead = newnode;
        }
        else
        {
            newnode->next = newhead;
            newhead = newnode;
        }
        cur = cur->next;
    }

    while (head && newhead)
    {
        if (head->val != newhead->val)
        {
            return false;
        }
        head = head->next;
        newhead = newhead->next;
    }
    return true;
}


//ɾ���������ظ���Ԫ��
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // write code here
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* cur = head;
    while (cur->next)
    {
        if (cur->val == cur->next->val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}