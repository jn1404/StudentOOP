#include <iostream>
#include "llist.h"

using namespace std;

/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (!nd) os << "nullptr";
	else {
		os << "data: " << nd->data << " ";// << " next: " << nd->next;
	}
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d, nullptr);
	}
	else { 
		add_at_end(head->next, d);
	}
}

bool del_head(Node*& head){
	if (!head) return false;
	else { 
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
}

bool del_tail(Node*& curr) {
	if (!curr) return false;
	if (curr->next == nullptr) {
		delete curr; // frees memory
		curr = nullptr; // dangling pointer
		return true;
	}
	else {
		return del_tail(curr->next);
	}
}

Node* reverse(Node* curr, Node* new_next) {
	if (!curr) return new_next;
	else { 
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}

Node* duplicate(Node* head) {
	if (!head) return nullptr;
	else {
		return new Node(head->data, duplicate(head->next));
	}
}

Node* join(Node*& list1, Node* list2) {
	last(list1)->next = list2;
	return list1;
}

/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	if (head){
		os << head;
		print_list(os, head->next);
	}
	else os << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head); // new node pointing to current head 
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (!head) return nullptr; // head == nullptr
	else if (!head->next) return head; // head->next = nullptr
	else return last(head->next);
}