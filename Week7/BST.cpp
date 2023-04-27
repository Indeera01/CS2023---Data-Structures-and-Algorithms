#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != nullptr)
  {
    traverseInOrder(root->left); // to travel to the left most node
    cout<<root->key<<" ";
    traverseInOrder(root->right); // to travel to the right most node of the current node
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == nullptr)
  {
    struct node *newNode = new struct node;  // to create a new node
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }

  else if (key <= node->key)
  {
    node->left = insertNode(node->left, key); // to add to the left sub tree
  }

  else
  {
    node->right = insertNode(node->right, key); // to add to the right sub tree
  }

  return node;
}

// Find the minimum key
struct node *findMin(struct node *root)
{
  while (root->left != nullptr)  // to travel to the left most leaf
  {
    root = root->left;
  }

  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == nullptr) // when the tree is empty
  {
    return root;
  }

  if (root->key > key) // to travel to the left sub tree
  {
    root->left = deleteNode(root->left, key);
  }

  else if (root->key < key)  // to travel to the right sub tree
  {
    root->right = deleteNode(root->right, key);
  }

  else // when the required key is found
  {
    if (root->left == nullptr && root->right == nullptr) // when the key is a leaf 
    {
      delete root;
      root = nullptr;
      return root;
    }

    else if (root->right == nullptr) // only left child
    {
      struct node *temp = root;
      root = root->left;
      delete temp;
      return root;
    }

    else if (root->left == nullptr) // only right child
    {
      struct node *temp = root;
      root = root->right;
      delete temp;
      return root;
    }
    else  // when there are two children
    {
      struct node *minRight = findMin(root->right); 
      root->key = minRight->key;  // replacing the key with minimum key of the right sub tree
      root->right = deleteNode(root->right, minRight->key); // deleting the duplicate
    }
  }

  return root;
}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}