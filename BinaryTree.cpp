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
    traverse(root, &bF, leftDepth, rightDepth);   
    return bF;
}

void BinaryTree::traverse(Node* curr, unordered_map<int,int>* bF, int leftDepth, int rightDepth) {
    //int leftDepth = 0;
    //int rightDepth = 0;

    /*cout << "-----NODE: " << curr->label << endl;
    for (std::pair<int, int> element : *bF)
    {
        std::cout << element.first << " :: " << element.second << std::endl;
    }*/

    if(curr == NULL)
        return;
    
    if(curr->leftChild) {
        traverse(curr->leftChild, bF, leftDepth, rightDepth);
        leftDepth++;
    }

    if(curr->rightChild) {
        traverse(curr->rightChild, bF, leftDepth, rightDepth);
        rightDepth++;
    }

    if(curr && curr->leftChild == NULL && curr->rightChild == NULL) {
        (*bF)[curr->label] = 0;
        return;
    }
    cout <<"lable="<< curr->label<< "leftDepth=" << leftDepth << "rightDepth =" <<rightDepth<<endl;

    (*bF)[curr->label] = rightDepth-leftDepth;

}
