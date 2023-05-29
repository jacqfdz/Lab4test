#include "BST.h"
#include "Krone.h"

void BST::insertNode(Currency* insertee) {
	BSTNode* newNode = new BSTNode();
	newNode->data = new Krone(*insertee);

	if (count == 0) {
		root = newNode;
	}
	else {
		BSTNode* curr = root;

		while (curr) {
			if (curr->data->isGreater(insertee)) {
				if (curr->left) {
					curr = curr->left;
				}
				else {
					curr->left = newNode;
					curr = nullptr;
				}
			}
			else {
				if (curr->right) {
					curr = curr->right;
				}
				else {
					curr->right = newNode;
					curr = nullptr;
				}
			}
		}
	}

	count++;
}

bool BST::deleteNode(Currency* removee) {

}

void BSTNode* BST::search(Currency* searchee) const {
	BSTNode* curr = root;

	while (curr) {
		if (*(curr->data) == *searchee) {
			return curr;
		}
		else if (curr->data->isGreater(searchee)) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return nullptr;
}