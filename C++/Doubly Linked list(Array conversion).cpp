#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *back;

	// Constructor
	Node(int data1, Node *next1, Node *back1)
	{
		data = data1;
		next = next1;
		back = back1;
	}

public:
	Node(int data1)
	{
		data = data1;
		next = nullptr;
		back = nullptr;
	}
};

Node *convertArray2DLL(vector<int> &arr)
{
	Node *head = new Node(arr[0]);
	Node *prev = head;

	for (int i = 1; i < arr.size(); i++)
	{
		Node *temp = new Node(arr[i], nullptr, prev);
		prev->next = temp;
		prev = temp;
	}
	return head;
}

void print(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node *beforeHead(Node *head, int val)
{
	Node *temp = new Node(val, head, nullptr);
	// temp->back = nullptr;
	// temp->next = head->next;
	head->back = temp;
	return temp;
}

Node *beforeTail(Node *head, int val)
{
	if (head->next == nullptr)
	{
		return beforeHead(head, val);
	}

	Node *tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}

	Node *prev = tail->back;
	Node *temp = new Node(val, tail, prev);
	prev->next = temp;
	tail->back = temp;
	return head;
}

Node *beforeKth(Node *head, int k, int val)
{
	if (k == 1)
	{
		return beforeHead(head, val);
	}
	Node *temp = head;
	int cnt = 0;
	while (temp != nullptr)
	{
		cnt++;
		if (cnt == k)
		{
			break;
		}
		temp = temp->next;
	}
	Node *prev = temp->back;
	Node *newNode = new Node(val, temp, prev);
	prev->next = newNode;
	temp->back = newNode;
	return head;
}

void beforeNode(Node *node, int val)
{
	Node *prev = node->back;
	Node *newNode = new Node(val, node, prev);
	prev->next = newNode;
	node->back = newNode;
}

int main()
{
	vector<int> arr = {1, 3, 2, 4};
	Node *head = convertArray2DLL(arr);
	// head = beforeKth(head, 3, 10);
	beforeNode(head->next, 100);
	print(head);
	return 0;
} 