//
//  WordNode.hpp
//  Assignment 6
//
//  Created by Axel Garcia on 12/7/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#ifndef WordNode_hpp
#define WordNode_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct WordNode{
    string word = "";
    int count = 0;
    WordNode * left;
    WordNode * right;
    WordNode(string w){
        word = w;
        left = right = nullptr;
    }
};
#endif /* WordNode_hpp */
