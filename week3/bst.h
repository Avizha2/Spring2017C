/*bst.h*/

//
// Binary Search Tree ADT header file.
//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS251, Spring 2017
//

// make sure this header file is #include exactly once:
#pragma once


//
// BST type declarations:
//
typedef char*    BSTKey;
typedef struct BSTValue
{
  char *Netid;
  int   Midterm;
  int   Final;
} BSTValue;

typedef struct BSTNode
{
  BSTKey    Key;
  BSTValue  Value;
  struct BSTNode  *Left;
  struct BSTNode  *Right;
} BSTNode;

typedef struct BST
{
  BSTNode *Root;
  int      Count;
} BST;


//
// BST API: function prototypes
//
BST *BSTCreate();
int  BSTCompareKeys(BSTKey key1, BSTKey key2);
BSTNode *BSTSearch(BST *tree, BSTKey key);
int  BSTSearchDepth(BST *tree, BSTKey key);
int  BSTInsert(BST *tree, BSTKey key, BSTValue value);

void PrintInorder(BST *tree, void(*pf)(BSTNode*));
void PrintPreorder(BST *tree, void(*pf)(BSTNode*));
