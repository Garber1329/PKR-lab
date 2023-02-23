//6.9

#include <iostream>
#include <string>
#include <Windows.h> 

using namespace std;
typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
	char ch;
};

Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
Node* FindMax(Node*& root);
void RightRotation(Node*& root);
void LeftRotation(Node*& root);
int Height(Node* root);
int BFactor(Node* root);
void BalanceHeight(Node*& root);
Node* BinarySearchInsert(Node*& root, Info value, char ch, bool& found);
Node* BinarySearchDelete(Node* root, Info value);
Info PostfixOrder(Node* root, Info& max, char& ch);
int Count(Node* root);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch;
	int menuItem;
	int N;
	Info max;
	bool found = false;
	Node* root = NULL;
	Info value;

	do {
		cout << endl << endl << endl;
		cout << "Меню:" << endl << endl;
		cout << " [1] - Cтворення бінарного дерева із наперед вказаною кількістю елементів" << endl;
		cout << " [2] - Вивід бінарного дерева" << endl;
		cout << " [3] - Створення бінарного дерева пошуку із наперед вказаною кількістю елементів" << endl;
		cout << " [4] - Добавлення нового елемента із збереженням порядку" << endl;
		cout << " [5] - Збалансування бінарного дерева пошуку" << endl;
		cout << " [6] - Видалення елемента бінарного дерева, який не має дочірніх вузлів" << endl;
		cout << " [7] - Видалення елемента бінарного дерева, який має один дочірній вузол " << endl;
		cout << " [8] - Видалення елемента бінарного дерева, який має два дочірніх вузли " << endl;
		cout << " [9] - Видалення елемента бінарного дерева з усіма його дочірніми вузлами " << endl;
		cout << " [10] - Перший елемент із максимальним значенням " << endl << endl;
		cout << " [0] - Меню закінчує свою роботу" << endl << endl;

		cout << "Введіть пункт меню: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cout << "Enter nodes count: "; cin >> N;
			root = CreateTree(N);
			break;
		case 2:
			PrintTree(root, 0);
			break;
		case 3:
			cout << "Enter nodes count: "; cin >> N;
			for (int i = 0; i < N; i++)
			{
				cout << "value: "; cin >> value;
				cout << "symbol: "; cin >> ch;
				BinarySearchInsert(root, value, ch, found);
			}
			break;
		case 4:
			cout << "value: "; cin >> value;
			cout << "symbol: "; cin >> ch;
			BinarySearchInsert(root, value, ch, found);

			break;
		case 5:
			BalanceHeight(root);
			break;
		case 6:
			cout << "delete value: "; cin >> value;
			root = BinarySearchDelete(root, value);
			break;
		case 7:
			cout << "delete value: "; cin >> value;
			root = BinarySearchDelete(root, value);
		case 8:
			cout << "delete value: "; cin >> value;
			root = BinarySearchDelete(root, value);
			break;
		case 9:
			cout << "delete value: "; cin >> value;
			root = BinarySearchDelete(root, value);
			break;
		case 10:
			cout << "Postfix order: ";
			PostfixOrder(root, max, ch);
			cout << endl << "First max: " << max << ch << endl;
			cout << "Count - " << Count(root);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели неправильне число! "
				"Введіть число вибраного елемента в меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;

		cout << " Enter node symbol: ";
		cin >> newNode->ch;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << root->info;
		cout << root->ch << endl;
		PrintTree(root->left, level + 1);
	}
}

Node* FindMax(Node*& root)
{
	while (root->right != NULL)
		root = root->right;
	return root;
}

void RightRotation(Node*& root)
{
	Node* tmp1 = root->left;
	Node* tmp2 = tmp1->right;
	tmp1->right = root;
	root->left = tmp2;
	root = tmp1;
}
void LeftRotation(Node*& root)
{
	Node* tmp1 = root->right;
	Node* tmp2 = tmp1->left;
	tmp1->left = root;
	root->right = tmp2;
	root = tmp1;
}

int Height(Node* root)
{
	if (root == NULL)
		return 0;
	int hL = Height(root->left);
	int hR = Height(root->right);
	return (hL > hR ? hL : hR) + 1;
}

int BFactor(Node* root)
{
	return Height(root->right) - Height(root->left);
}

void BalanceHeight(Node*& root)
{
	if (root != NULL)
	{
		while (BFactor(root) >= 2)
		{
			if (BFactor(root->right) < 0)
				RightRotation(root->right);
			LeftRotation(root);
		}
		while (BFactor(root) <= -2)
		{
			if (BFactor(root->left) > 0)
				LeftRotation(root->left);
			RightRotation(root);
		}
		BalanceHeight(root->left);
		BalanceHeight(root->right);
	}
}

Node* BinarySearchInsert(Node*& root, Info value, char ch, bool& found)
{
	if (root == NULL)
	{
		root = new Node;
		root->info = value;
		root->ch = ch;
		root->left = NULL;
		root->right = NULL;
		found = false;
		return root;
	}
	else
		if (value == root->info)
		{
			found = true;
			return root;
		}
		else
			if (value < root->info)
				return BinarySearchInsert(root->left, value, ch, found);
			else
				return BinarySearchInsert(root->right, value, ch, found);
}

Info PostfixOrder(Node* root, Info& max, char& ch)
{
	if (root != NULL)
	{
		PostfixOrder(root->left, max, ch);
		PostfixOrder(root->right, max, ch);
		if (root->info > max)
		{
			max = root->info;
			ch = root->ch;
		}
		cout << root->info << "";
		cout << root->ch << "   ";
	}
	return ch;
}

Node* BinarySearchDelete(Node* root, Info value)
{
	if (NULL == root) return NULL;
	if (root->info == value)
	{
		if (NULL == root->left && NULL == root->right)
		{
			delete root;
			return NULL;
		}
		if (NULL == root->right && root->left != NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		if (NULL == root->left && root->right != NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}

		root->info = FindMax(root->left)->info;
		root->left = BinarySearchDelete(root->left, root->info);
		return root;
	}

	if (value < root->info)
	{
		root->left = BinarySearchDelete(root->left, value);
		return root;
	}
	if (value > root->info)
	{
		root->right = BinarySearchDelete(root->right, value);
		return root;
	}
	return root;
}
int Count(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}