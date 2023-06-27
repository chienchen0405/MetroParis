#include <iostream>
#include <string>

using namespace std;

struct TSTNode {
	char data;
	bool isEndOfWord;
	TSTNode* left;
	TSTNode* right;
	TSTNode* middle;
};

TSTNode* createNode(char data) {
	TSTNode* node = new TSTNode;
	node->data = data;
	node->isEndOfWord = false;
	node->left = NULL;
	node->right = NULL;
	node->middle = NULL;
	return node;
}

void insert(TSTNode*& root, const string& word, int pos) {
	if (root == NULL) {
		root = createNode(word[pos]);
	}

	if (word[pos] < root->data) {
		insert(root->left, word, pos);
	} else if (word[pos] > root->data) {
		insert(root->right, word, pos);
	} else {
		if(root->isEndOfWord) {
			insert(root->middle, word, pos + 1);
		} else {
			if (pos + 1 < word.length()) {
				insert(root->middle, word, pos + 1);
			} else {
				root->isEndOfWord = true;
			}
		}
	}
}

bool search(TSTNode* root, const string& word, int pos) {
	if (root == NULL) {
		return false;
	}
	if (word[pos] < root->data) {
		return search(root->left, word, pos);
	} else if (word[pos] > root->data) {
		return search(root->right, word, pos);
	} else {
		if (pos + 1 < word.length()) {
			return search(root->middle, word, pos + 1);
		} else {
			return root->isEndOfWord;
		}
	}
}

int main() {
	
	TSTNode* root = NULL;
// 添加站点名称到词表树
	insert(root, "London", 0);
	insert(root, "Paris", 0);
	insert(root, "Tokyo", 0);
	insert(root, "New York", 0);
	insert(root, "Beijing", 0);
	insert(root, "Sydney", 0);
// 接受用户输入的站点名称
	string userInput;
	cout << "Enter a station name: ";
	cin >> userInput;
// 在词表树中搜索用户输入的站点名称
	if (search(root, userInput, 0)) {
		cout << "Found!" << endl;
	} else {
		cout << "Not found!" << endl;
	}

	return 0;
}
