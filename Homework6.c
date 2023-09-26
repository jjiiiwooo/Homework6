#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* prev;
}TreeNode;

//�湮�� ����� ���� 
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

//�ݺ��� Ž�� 
int search(TreeNode* node, int key)
{
	printf("������ �� �Է�:\n");
	scanf_s("%d", &key);

	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
		printf("�˻� ���� : %d", key);
		
	}
	printf("�˻� ����\n");
	printf("�湮�� ����� �� :\n");
	visit_node(node, key);
	inorder_Tree(node); 
	return NULL;
}

//��� ���� 
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//����� ��� �߰� 
TreeNode* insert_Node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_Node(node->left, key);
	else
		node->right = insert_Node(node->right, key);

	return node;
}

//�ּҰ� ��� ��ȯ 
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

//����� ��� ���� 
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		//Ű�� ��Ʈ�� ������ ��带 ���� 

		//�ܸ� ��� �̰ų� �ڽ� ��尡 �Ѱ��� ��� 
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

		//�ڽ� ��尡 �� ���� ���
		TreeNode* temp = min_value_node(root->right);

		//���� ��ȸ�� �İ� ��带 ���� 
		root->key = temp->key;
		//���� ��ȸ�� �İ� ��带 ���� 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//����� ��ü Ʈ�� ���� ��ȸ 
void inorder_Tree(TreeNode* root)
{
	inorder_Tree(root->left);
	printf("%d", root->key);
	inorder_Tree(root->right);
}

//��� �߰� �޴�  �ݺ��� ������� ���� 
int Insertmenu(TreeNode* node, int item)
{
	TreeNode* previousNode = NULL;
	printf("������ �� �Է� : \n");
	scanf_s("%d", &item);

	if (item == previousNode->key)
		return item;
	else (item < previousNode->key)
		
		


}

//��� ���� �޴� �ݺ��� ������� ���� 
int Deletedmenu(TreeNode* node, int item)
{

}




int main(void)
{
	printf("---------------");

}