//
//  WordTree.hpp
//  Assignment 6
//
//  Created by Axel Garcia on 12/7/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#ifndef WordTree_hpp
#define WordTree_hpp

#include <stdio.h>
#include <string>
#include "WordNode.hpp"
class WordTree{
private:
    WordNode*root;
    void Insert(WordNode *&nodeptr, string item);
    void PrintTree(WordNode*nodeptr);
    void PrintTree(ostream&,WordNode*nodeptr) const;
    void Destroy(WordNode *&nodeptr);
    int CountNodes(WordNode * nodeptr, int &);
public:
    WordTree();
    void Add(string word){Insert(root,word);}
    void Print(){PrintTree(root);}
    ~WordTree(){Destroy(root);}                      //Destructor
    int CountNodes(){int n= 0;return CountNodes(root, n);}
    friend ostream& operator<< (ostream&, const WordTree&);
};

#endif /* WordTree_hpp */
