typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//分治算法

//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int count = 0;
void TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	++count;
	TreeSize(root->left);
	TreeSize(root->right);
}

int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	//左子树的叶子加上右子树的叶子
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeKLevel(BTNode* root, int k)
{
	//转化成求子问题
	//求左子树的k-1层+求右子树的k-1层
	assert(k >= 1);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKLevel(root->left, k - 1)
		+ TreeKLevel(root->right, k - 1);
}

int main()
{
	BTNode* root = CreateBinaryTree();
	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	//count = 0;
	TreeSize(root);
	TreeSize2(root);
	printf("TreeSize:%d\n", count);

	count = 0;
	TreeSize(root);
	printf("TreeSize:%d\n", count);

	printf("TreeSize:%d\n", TreeSize2(root));

	printf("TreeSize:%d\n", TreeLeafSize(root));

	printf("TreeKLevel:%d\n", TreeKLevel(root,3));

	return 0;
}

int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1: rightDepth + 1;
}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1 != NULL)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2 != NULL)
		return ret2;

	return NULL;
}

//二叉树的销毁
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
    }

	TestDestroy(root->left);
	TestDestroy(root->right);
	//printf("%p:%d\n", root, root->data);
	free(root);
}
