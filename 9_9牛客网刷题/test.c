#define _CRT_SECURE_NO_WARNINGS 1


//链表中的节点每k个一组翻转
void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void reverse(int* a, int left, int right)
{
    while (left < right)
    {
        Swap(&a[left], &a[right]);
        left++;
        right--;
    }
}
struct ListNode* CreateNode(int x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int size = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        cur = cur->next;
        size++;
    }
    cur = head;
    int* tmp = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        tmp[i] = cur->val;
        cur = cur->next;

    }
    for (int i = 0; i < size; i += k)
    {
        if (i + k - 1 < size)
        {
            reverse(tmp, i, i + k - 1);
        }
    }
    struct ListNode* newhead = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < size; i++)
    {
        struct ListNode* newnode = CreateNode(tmp[i]);
        if (newhead == NULL)
        {
            newhead = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return newhead;
}





void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void reverse(int* a, int left, int right)
{
	while (left < right)
	{
		Swap(&a[left], &a[right]);
		left++;
		right--;
	}
}
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int k = 2;
	for (int i = 0; i < 5; i += k)
	{
		if (i + k - 1 < 5)
		{
			reverse(arr, i, i + k - 1);
		}
	}
	return 0;
}

////链表内指定区间反转
//void Swap(int* p1, int* p2)
//{
//    int tmp = *p1;
//    *p1 = *p2;
//    *p2 = tmp;
//}
//void reverse(int* a, int left, int right)
//{
//    while (left < right)
//    {
//        Swap(&a[left], &a[right]);
//        left++;
//        right--;
//    }
//
//}
//
//struct ListNode* CreateNode(int x)
//{
//    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newnode->val = x;
//    newnode->next = NULL;
//    return newnode;
//}
//struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
//    // write code here
//    struct ListNode* cur = head;
//    int size = 0;
//    while (cur)
//    {
//        cur = cur->next;
//        size++;
//    }
//    cur = head;
//    int* tmp = (int*)malloc(sizeof(int) * size);
//    for (int i = 0; i < size; i++)
//    {
//        tmp[i] = cur->val;
//        cur = cur->next;
//    }
//    reverse(tmp, m - 1, n - 1);
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", tmp[i]);
//    }
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    for (int i = 0; i < size; i++)
//    {
//        struct ListNode* newnode = CreateNode(tmp[i]);
//        if (newhead == NULL)
//        {
//            newhead = tail = newnode;
//        }
//        else
//        {
//            tail->next = newnode;
//            tail = tail->next;
//        }
//    }
//    return newhead;
//
//}