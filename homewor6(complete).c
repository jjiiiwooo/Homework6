#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
TreeNode* root = NULL;



//반복적 탐색 
TreeNode*  search(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;

		else 
			node = node->right;
	}

	return NULL; //탐색에 실패하였을 경우 NULL 반환 
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
	//트리가 공백이면 새로운 노드를 반환 
	if (node == NULL) return new_node(key);
	//그렇지 않으면 새로운 노드를 반환 
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
	if (root != NULL) {
		inorder_Tree(root->left);
		printf(" %d", root->key);
		inorder_Tree(root->right);
	}
}

//반복적 노드 추가 
int Insertmenu(TreeNode* root, int key)
{
	TreeNode* newNode = new_node(key);
	TreeNode* current = root;
	TreeNode* previous = NULL;

	while (current != NULL)
	{
		previous = current;
		if (key < current->key)
			current = current->left;
		else
			current = current->right;
	}

	if (previous == NULL)
	{
		previous = newNode;
		root = previous;
	}

	else if (key < previous->key)
		previous->left = newNode;
	else
		previous->right = newNode;
    
	return newNode;

}

//노드 삭제 메뉴 반복적 방법으로 구현 
int Deletedmenu(TreeNode* root, int key)
{
	TreeNode* delete = NULL; //삭제노드 
	TreeNode* parent = NULL; //삭제할 노드의 부모 노드 
	TreeNode* child = NULL; //삭제노드의 자식 노드 
	TreeNode* temp = min_value_node(root->right); //오른쪽 최솟값 노드 
	TreeNode* tempParent = NULL; //오른쪽 최솟값 노드의 부모 노드 

	delete = root;

	//탐색을 통한 삭제노드 찾기 
	while (delete != NULL) {
		if (key == delete->key) {
			//탐색 성공
			break;
		}
		parent = delete;
		if (key < delete->key) {
			delete = delete->left;
		}
		else {
			delete = delete->right;
		}
	}

	if (delete == NULL)
		return NULL;

	//삭제노드가 단말노드인 경우 
	if (delete->left == NULL && delete->right == NULL) {
		if (parent != NULL) {
			//부모 노드가 있는 경우 
			if (parent->left == delete) {
				//부모 노드의 왼쪽노드가 삭제 노드일 경우 
				parent->left = NULL;
			}
			else
			{
				//부모 노드의 오른쪽 노드가 삭제 노드일 경우 
				parent->right = NULL;
			}
		}
		else {
			//부모 노드가 없는 경우 (삭제노드 = root 노드)
			root = NULL;
		}
	}
	//자식이 있는 경우  
	else
	{
		//자식이 양쪽 다 있는 경우 
		if (delete->left != NULL && delete->right != NULL)
		{
			
			//최솟값 노드의 자식이 있는 경우 
			if (temp->right != NULL) {
				delete->key = temp->key;
				delete = temp;
				//최솟값 노드의 오른쪽 자식을 최솟값 노드의 원래부모에 연결
				tempParent->right = temp->right;
			}
			else //최솟값 노드의 자식이 없는 경우 
			{
				delete->key = temp->key;
				delete = temp;
			}
		}
		else
		{
			//삭제할 노드의 자식 노드가 1개인 경우 
			if (delete->left != NULL) {
				child = delete->left;
			}
			else {
				child = delete->right;
			}

			if (parent != NULL)
			{
				if (parent->left == delete) {
					parent->left = child;
				}
				else
				{
					parent->right = child;
				}
			}
			else
			{
				root = child;
			}
		}
	}
	
	free(delete); //메모리 해제
	return root;
}


int main(void)
{
	int menu;
	int key;
	TreeNode* root = NULL;

	root = insert_Node(root, 60);
	root = insert_Node(root, 41);
	root = insert_Node(root, 16);
	root = insert_Node(root, 25);
	root = insert_Node(root, 53);
	root = insert_Node(root, 46);
	root = insert_Node(root, 55);
	root = insert_Node(root, 42);
	root = insert_Node(root, 74);
	root = insert_Node(root, 65);
	root = insert_Node(root, 63);
	root = insert_Node(root, 70);
	root = insert_Node(root, 62);
	root = insert_Node(root, 64);

	printf("---------------------\n");
	printf("| 1. 검색           |\n");
	printf("| 2. 노드 추가      |\n");
	printf("| 3. 노드 삭제      |\n");
	printf("| 4. 중위 순회      |\n");
	printf("| 5.  노드 추가(반복) |\n");
	printf("| 6. 노드 추가(반복) |\n");
	printf("| 7. 종료           |\n");
	printf("---------------------\n");


	do {
		printf("메뉴 입력: ");
		scanf_s("%d", &menu);
		switch (menu) {

		case 1:
			printf("검색할 값 입력:");
			scanf_s("%d", &key);
			if (search(root, key) != NULL)
				printf("검색 성공 :%d\n", key);
			else
				printf("검색 실패 :%d\n", key);
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 2:
			printf("삽입할 값 입력:");
			scanf_s("%d", &key);
			insert_Node(root, key);
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 3:
			printf("삭제할 값 입력:");
			scanf_s("%d", &key);
			delete_node(root, key);
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 4:
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 5:
			printf("삽입할 값 입력:");
			scanf_s("%d", &key);
			Insertmenu(root, key);
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 6:
			printf("삭제할 값 입력:");
			scanf_s("%d", &key);
			Deletedmenu(root, key);
			inorder_Tree(root);
			printf("\n방문한 노드 개수: \n");
			printf("\n");
			break;

		case 7 :
			printf("종료합니다.");
			break;

		default:
			printf("메뉴를 다시 선택하세요.\n");
			return 0;
		}
		
	} while (menu != 7);
	return 0;
}
