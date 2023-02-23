#include <iostream>

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
Info PostfixOrder(Node* root, Info& max, char& ch);
int Count(Node* root);

int main()
{
	char ch;
	int N, max = INT_MIN;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	cout << endl;
	PrintTree(root, 0);
	cout << "Postfix search: ";
	PostfixOrder(root, max, ch);
	cout << endl << "First max: " << max << ch << endl;
	cout << "Count - " << Count(root);
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

Info PostfixOrder(Node* root, Info& max, char& ch)
{
	if (root != NULL)
	{
		PostfixOrder(root->left, max, ch);
		PostfixOrder(root->right, max, ch);
		if (root->info > max) {
			max = root->info;
			ch = root->ch;
		}
		cout << root->info << "";
		cout << root->ch << "   ";
	}
	return ch;
}
int Count(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}