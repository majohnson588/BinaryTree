Top-K排序，一般情况下数据量比较大
时间复杂度O(K+(N-K)*logK)

void PrintTopK(int* a, int n, int k)
{
	//1、建堆-用a中前k个元素建小堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	for (int i = 0; i < k; ++i)
	{
		KMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(KMinHeap, k, i);
	}

	//2、将剩余n-k个元素依次与堆顶元素交换
	for (int j = k; j < n; ++j)
	{
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j];
			AdjustDown(KMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", KMinHeap[i]);
	}
	printf("\n");
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}

	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[120] = 1000000 + 5;
	a[99] = 1000000 + 6;
	a[0] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

//判断是否为单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树
#include "Heap.h"
#include "test.c"

bool flag = true;
void PreOrderCompare(struct TreeNode* root, int val)
{
	if (root == NULL || flag == false)
		return;

	if (root->val != val)
	{
		flag = false;
		return;
	}

	PreOrderCompare(root->left, val);
	PreOrderCompare(root->right, val);
}

bool inUnivalTree1(struct TreeNode* root) {
	if (root == NULL)
		return true;

	flag = true;
	PreOrderCompare(root, root->val);
	return flag;
}

bool inUnivalTree2(struct TreeNode* root) {
	if (root == NULL)
		return true;

	if (root->left && root->left->val != root->val)
		return false;

	if (root->right && root->right->val != root->val)
		return false;

	return isUnivalTree(root->left)
		&& isUnivalTree(root->right);
}

//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;

	if (p == NULL || q == NULL)
		return false;

	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left)
	&& isSameTree(p->right, q->right);
}

bool isSymmetricSubTree(struct TreeNode* root1, struct TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	
	if (root1 == NULL || root2 == NULL)
		return false;

	if (root1->val != root2->val)
		return false;

	return isSymmetricSubTree(root1->left, root2->right)
		&& isSymmetricSubTree(root1->right, root2->left);
}

//对称的树
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return isSymmetricSubTree(root->left, root->right);
}

//判断是否为子树
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL)
		return false;

	//遍历、跟root中所有子树都比较一遍
	if (isSameTree(root, subRoot))
		return true;

	return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);
}

int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//前序遍历

void preorder(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;

	a[(*pi)++] = root->val;
	preorder(root->left, a, pi);
	preorder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int* a = (int*)malloc(*returnSize * sizeof(int));
	int i = 0;
	preorder(root, a, &i);

	return a;
}

//根据字符串建立二叉树并遍历
BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = BuyNode(str[(*pi)++]);
	root->left = CreateTree(str, pi);
	root->right = CreateTree(str, pi);
	return root;
}

void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

int main()
{
	char str[100];
	scanf("%s ", str);
	int i = 0;
	BTNode* root = CreateTree(str, &i);
	InOrder(root);

	return 0;
}
