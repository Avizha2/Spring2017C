/*main.cpp*/

//
// Working with Binary Search Tree ADT.
//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS251, Spring 2017
// Lab 03
//

// ignore stdlib warnings if working in Visual Studio:
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "bst.h"


//
// skipRestOfInput:
//
// Inputs and discards the remainder of the current line for the 
// given input stream, including the EOL character(s).
//
void skipRestOfInput(FILE *stream)
{
  char restOfLine[256];
  int rolLength = sizeof(restOfLine) / sizeof(restOfLine[0]);

  fgets(restOfLine, rolLength, stream);
}


//
// BuildTree:
//
// Inputs data from keyboard, stores in a BST, and returns tree.
//
BST *BuildTree()
{
  char  netid[64];
  int midterm, final;
  BSTValue  value;

  BST *tree = BSTCreate();

  //
  // input:
  //   Netid Midterm Final
  //   Netid Midterm Final
  //   ...
  //   -1
  //
  scanf("%s", netid);  // first input the netid:

  while (netid[0] != '#')
  {
    scanf("%d %d", &midterm, &final);  // now input midterm and final score:
    skipRestOfInput(stdin);

    //
    // store Netid, Midterm, and Final into a BST value struct so we can insert:
    //
    value.Netid = (char *)malloc((strlen(netid)+1) * sizeof(char));
    strcpy(value.Netid, netid);
    value.Midterm = midterm;
    value.Final = final;

    //
    // now that we have (key, value) pair, call BSTInsert to 
    // copy this (key, value) pair into a new node of the tree:
    //
    BSTInsert(tree, value.Netid, value);

    scanf("%s", netid);  // get next netid or -1:
  }

  //
  // done, return tree:
  //
  return tree;
}


//
// PrintOneNode:
//
// Prints the info in one node of the tree.  This function is passed
// to BST inorder/preorder functions to control printing when a node 
// is "visited".
//
void PrintOneNode(BSTNode *cur)
{
  printf("%s: %d %d\n", cur->Value.Netid, cur->Value.Midterm, cur->Value.Final);
}



int main()
{
  BST *tree;

  tree = BuildTree();

  PrintInorder(tree, PrintOneNode);

  return 0;
}
