#define _CRT_SECURE_NO_WARNINGS 1


//二叉树的中序遍历
void MidTraval(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    MidTraval(root->left, a, pi);
    a[*pi] = root->val;
    (*pi)++;
    MidTraval(root->right, a, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // write code here
    int* arr = (int*)malloc(sizeof(int) * 1000);
    int i = 0;
    MidTraval(root, arr, &i);
    *returnSize = i;
    return arr;

}


//二叉树的最大深度
int maxDepth(struct TreeNode* root) {
    // write code here
    if (root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;

}


//二叉树中和为某一值的路径
bool PreTraval(struct TreeNode* root, int sum, int num)
{
    if (root == NULL)
    {
        return false;
    }
    num += root->val;
    //根节点、和相等
    if (num == sum && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return PreTraval(root->left, sum, num) ||
        PreTraval(root->right, sum, num);
}
bool hasPathSum(struct TreeNode* root, int sum) {
    // write code here
    int num = 0;
    return PreTraval(root, sum, num);

}




//对称的二叉树
bool SameTree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->val != root2->val)
    {
        return false;
    }
    return SameTree(root1->left, root2->right) && SameTree(root1->right, root2->left);
}

bool isSymmetrical(struct TreeNode* pRoot) {
    // write code here
    if (pRoot == NULL)
    {
        return true;
    }
    return SameTree(pRoot->left, pRoot->right);
}




//合并二叉树
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    // write code here
    if (t1 == NULL && t2 == NULL)
    {
        return t1;
    }
    if (t1 == NULL && t2 != NULL)
    {
        return t2;
    }
    if (t1 != NULL && t2 == NULL)
    {
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}



//二叉树的镜像
void Swap(struct TreeNode** p1, struct TreeNode** p2)
{
    struct TreeNode* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
struct TreeNode* Mirror(struct TreeNode* pRoot) {
    // write code here
    if (pRoot == NULL)
    {
        return NULL;
    }
    Swap(&pRoot->left, &pRoot->right);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
}