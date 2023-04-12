//树的度是6
struct TreeNode
{
	int data;
	struct TreeNode* child1;
	struct TreeNode* child2;
	struct TreeNode* child3;
	struct TreeNode* child4;
	struct TreeNode* child5;
	struct TreeNode* child6;
};

//不确定树的度
typedef struct TreeNode* SLDataType;
struct TreeNode
{
	int data;

	//顺序表存孩子的指针
	SeqList _childs;
	//...
	//vector<struct TreeNode*> vchild
};

//左孩子右兄弟
typedef int DataType;
struct TreeNode
{
	struct TreeNode* firstChild1;
	struct TreeNode* pNextBrother;
	DataType data;
};
