#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* prev;
}TreeNode;

//방문한 노드의 개수 
int visit_node(TreeNode* node, int key)
{
	int count = 0;

	if (key < node->key)
		visit_node(node -> left, key);
	else
		visit_node(node->right, key);

	count++;
	return count;
	
}

//반복적 탐색 
int search(TreeNode* node, int key)
{
	printf("삽입할 값 입력:\n");
	scanf_s("%d", &key);

	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
		printf("검색 성공 : %d", key);
		
	}
	printf("검색 실패\n");
	printf("방문한 노드의 수 :\n");
	visit_node(node, key);
	inorder_Tree(node); 
	return NULL;
}

//노드 생성 
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//재귀적 노드 추가 
TreeNode* insert_Node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_Node(node->left, key);
	else
		node->right = insert_Node(node->right, key);

	return node;
}

//최소값 노드 반환 
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

//재귀적 노드 삭제 
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		//키와 루트와 같으면 노드를 삭제 

		//단말 노드 이거나 자식 노드가 한개인 경우 
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		//자식 노드가 두 개인 경우
		TreeNode* temp = min_value_node(root->right);

		//중위 순회시 후계 노드를 복사 
		root->key = temp->key;
		//중위 순회시 후계 노드를 삭제 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//재귀적 전체 트리 중위 순회 
void inorder_Tree(TreeNode* root)
{
	inorder_Tree(root->left);
	printf("%d", root->key);
	inorder_Tree(root->right);
}

//노드 추가 메뉴  반복적 방법으로 구현 
int Insertmenu(TreeNode* node, int item)
{
	TreeNode* previousNode = NULL;
	printf("삽입할 값 입력 : \n");
	scanf_s("%d", &item);

	if (item == previousNode->key)
		return item;
	else (item < previousNode->key)
		
		


}

//노드 삭제 메뉴 반복적 방법으로 구현 
int Deletedmenu(TreeNode* node, int item)
{

}




int main(void)
{
	printf("---------------");

}