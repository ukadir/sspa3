#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    unordered_map<int,int>* bF;
    traverse(root, bF);   
    return *bF;
}

void BinaryTree::traverse(Node* curr, unordered_map<int,int>* bF) {
    int leftDepth = 0;
    int rightDepth = 0;

    if(curr == NULL)
        return;
    
    if(curr->leftChild) {
        traverse(curr->leftChild, bF);
        leftDepth++;
    }

    if(curr->rightChild) {
        traverse(curr->rightChild, bF);
        rightDepth++;
    }

    if(curr->leftChild == NULL && curr->rightChild == NULL) {
        (*bF)[curr->label] = 0;
        return;
    }

    (*bF)[curr->label] = rightDepth - leftDepth;

}
