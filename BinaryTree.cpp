#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    //cout << "-----comes here";
    unordered_map<int,int> bF;
    int leftDepth = 0;
    int rightDepth = 0;
    root->traverse(&bF);   
    return bF;
}

int BinaryTree::Node::traverse(unordered_map<int,int>* bF) {
    int rightDepth = 0;
    int leftDepth = 0;


    if(this == NULL)
        return -1;

    if(this->leftChild == NULL && this->rightChild == NULL) {
        (*bF)[this->label] = 0;
        return 0;
    }

    if(this->rightChild) {
        rightDepth = this->rightChild->traverse(bF);
        rightDepth++;
    }

    if(this->leftChild) {
        leftDepth = this->leftChild->traverse(bF);
        leftDepth++;
    }

    
    //cout <<"lable="<< this->label<< "leftDepth=" << leftDepth << "rightDepth =" <<rightDepth<<endl;


    (*bF)[this->label] = rightDepth-leftDepth;
    if(leftDepth > rightDepth) {
        return leftDepth;
    }
    else {
        return rightDepth;
    }
}
