//
//  WordTree.cpp
//  Assignment 6
//
//  Created by Axel Garcia on 12/7/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#include "WordTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
WordTree::WordTree(){
    
}
void WordTree::Insert(WordNode * &nodeptr, string item){
    //Makes everything lowercase
    for(int i = 0; i < item.length(); ++i) {
        item[i] = tolower(item[i]);
    }
    if (nodeptr == nullptr)
    {

        nodeptr = new WordNode(item);
        nodeptr -> count++;
        return;
    }
    
    if (item < nodeptr -> word){
        Insert(nodeptr -> left, item);

    }
    else if (item == nodeptr -> word){
        nodeptr -> count++;
    }
    else{
        Insert(nodeptr -> right, item);
    }
}
int WordTree::CountNodes(WordNode * nodeptr, int &p){
    
    if(nodeptr == nullptr){
        return p;
    }
    
    CountNodes(nodeptr->right, p);
    CountNodes(nodeptr->left, p);
    p++;
    return p;
}
void WordTree::Destroy(WordNode*&nodeptr){
    if(nodeptr == nullptr){
        return;
    }
    Destroy(nodeptr->right);
    Destroy(nodeptr->left);
    delete nodeptr;
    nodeptr = nullptr;
    
}

void WordTree::PrintTree(WordNode*nodeptr){
    if(nodeptr == nullptr){
        return;
    }
    PrintTree(nodeptr ->left);
    std::cout << nodeptr -> word << " ";
    PrintTree(nodeptr->right);
}
void WordTree::PrintTree(ostream &os, WordNode *nodeptr)const{
    if(nodeptr == nullptr){
        return;
    }
    PrintTree(os,nodeptr ->left);
    os << nodeptr -> word << " " << nodeptr->count << endl;
    PrintTree(os,nodeptr->right);
}
ostream& operator<< (ostream&os, const WordTree& obj){
    obj.PrintTree(os, obj.root);
    return os;
   }
