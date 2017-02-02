
//
// Searching for movies in a binary search tree.
//
// << NAME >>
// U. of Illinois, Chicago
// CS251, Spring 2017
// Project #02
//

// ignore stdlib warnings if working in Visual Studio:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef int     BSTKey;
typedef char  *BSTValue;

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
// BSTCreate: dynamically creates and returns an empty
// binary search tree:
//
BST *BSTCreate()
{
  BST *tree;

  tree = (BST *)malloc(sizeof(BST));
  tree->Root  = NULL;
  tree->Count = 0;

  return tree;
}

//
// BSTCompareKeys: compares key1 and key2, returning
//   value < 0 if key1 <  key2
//   0         if key1 == key2
//   value > 0 if key1 >  key2
//
int BSTCompareKeys(BSTKey key1, BSTKey key2)
{
  if (key1 < key2)
    return -1;
  else if (key1 == key2)
    return 0;
  else
    return 1;
}


//
// BSTSearch: searches the binary search tree for a node containing the
// same key.  If a match is found, a pointer to the node is returned, 
// otherwise NULL is returned.
//
BSTNode *BSTSearch(BST *tree, BSTKey key)
{
  	BSTNode *cur = tree->Root;
	BSTNode *prev = NULL;
	//BSTKey nodeKey;
	//BSTValue val;
	
  
	while(cur != NULL)
	{
		//val = (BSTValue)malloc(1+strlen(cur->Value)*sizeof(BSTValue));
		//printf("%s\n",cur->Value);
		if (key == cur->Key)  
		{
			printf("Visiting %d: '%s'\n",  cur->Key, cur->Value);
         return cur;
		}
		else if(key < cur->Key)
		{
		 prev = cur;
		 //nodeKey= cur->Key;
		 //al = cur->Value;
		 printf("Visiting %d: '%s'\n",  cur->Key, cur->Value);
		  cur = cur->Left;
		}
		else
		{
		 prev = cur;	
		 //nodeKey= cur->Key;
		 //val = cur->Value;
		 printf("Visiting %d: '%s'\n",  cur->Key, cur->Value);
		 		 cur = cur->Right;
		}
		
		
	}
	tree->Root = NULL;
  return tree->Root;
}


//
// BSTSearchDepth: searches the binary search tree for a node containing the
// same key, returning the depth of that node if found.  The root node is 
// considered depth 0, the next level down is a depth of 1, and so forth.
// If a matching key is not found, the function returns a depth of -1.
//
int BSTSearchDepth(BST *tree, BSTKey key)
{
  int count = 0;
	BSTNode *cur = tree->Root;
	BSTNode *prev = NULL;
	
  
	while(cur != NULL)
	{
		if (key == cur->Key)  
         return count;
		else if(key < cur->Key)
		{	
		 prev = cur;
		 cur = cur->Left;
		 count++;
		}
		else
		{
		 prev = cur;	
		 cur = cur->Right;
		 count++;
		}
		
	}
 
  return -1;// if key is not found then return -1
}


//
// BSTInsert: inserts the given (key, value) pair into the binary search
// tree.  Returns true (non-zero) if the insert was successful, returns 
// false (0) if the given key is already in the tree -- in which case the
// given (key, value) pair is not inserted.
//
int BSTInsert(BST *tree, BSTKey key, BSTValue value)
{
	BSTNode *cur = tree->Root;
	BSTNode *prev = NULL;
	
  
	while(cur != NULL)
	{
		if (key == cur->Key)  // found!
         return 0;
		else if(key < cur->Key)
		{	
		 prev = cur;
		 cur = cur->Left;
		}
		else
		{
		 prev = cur;	
		 cur = cur->Right;
		}
		
	}
	BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
	root->Key = key;
	root->Value = value;
	root->Left = NULL;
	root->Right = NULL;  
	//printf("Visiting %d: %s\n", root->Key, root->Value);
	if(prev == NULL)
	{
		tree->Root = root;
		tree->Count++;	
		return 1;
	}
	else if (key < prev->Key)
	{	
		prev->Left = root;
		tree->Count++;	
		return 1;
	}
	else
	{	
		prev->Right = root;
		tree->Count++;	
		return 1;
	
	}
  return 0;
}



//
// getFileName: inputs a filename from the keyboard, make sure the file can be
// opened, and returns the filename if so.  If the file cannot be opened, an
// error message is output and the program is exited.
//
char *getFileName()
{
  char filename[512];
  int  fnsize = sizeof(filename) / sizeof(filename[0]);

  // input filename from the keyboard:
  fgets(filename, fnsize, stdin);
  filename[strcspn(filename, "\r\n")] = '\0';  // strip EOL char(s):

  // make sure filename exists and can be opened:
  FILE *infile = fopen(filename, "r");
  if (infile == NULL)
  {
    printf("**Error: unable to open '%s'\n\n", filename);
    exit(-1);
  }

  fclose(infile);

  // duplicate and return filename:
  char *s = (char *)malloc((strlen(filename) + 1) * sizeof(char));
  strcpy(s, filename);

  return s;
}

void ParseMovieData(char line[], int* num,  int **numMovies, BST *tree)
{
	char *token;
	char *token2;
	char *token3;
	int i = *num;

	token = strtok(line, ",");
	token2 = strtok(NULL, ",");
	token3 = strtok(NULL, ",");
	
	//char tokentemp[256];
	
	//strcpy(tokentemp, token2);
	char *value;
	value = (char *) malloc( (strlen(token2) + 1) * sizeof(char()));
	strcpy(value, token2);
	if (BSTInsert(tree, atoi(token), value))
  {
      	numMovies++;
  }

	return;
}

void InputMovies(char *filename, int *numMovies, BST *tree)
{
	int i = 0;
	FILE *infile = fopen(filename, "r");
//	Movies *movie;
	//given in Project guidline pdf
	char line[256];
	int linesize = sizeof(line) / sizeof(line[0]);
	fgets(line, linesize, infile); // input a line from the keyboard:
	line[strcspn(line, "\r\n")] = '\0'; // strip EOL(s) char at end:
	//*numMovies =  atoi(line);
	
	int *num;
	//Movies* movie = (Movies*)malloc(sizeof(Movies)*(*numMovies));

	fgets(line, linesize, infile); // input a line from the keyboard:
	line[strcspn(line, "\r\n")] = '\0'; // strip EOL(s) char at end:
	while (!feof(infile))
		{
			ParseMovieData(line, &i, &num, tree);
			fgets(line, linesize, infile); // input a line from the keyboard:
			line[strcspn(line, "\r\n")] = '\0'; // strip EOL(s) char at end:
			i++;
		}
		numMovies = num;
	fclose(infile);
	return;
}

void skipRestOfInput(FILE *stream)
{
  char restOfLine[256];
  int rolLength = sizeof(restOfLine) / sizeof(restOfLine[0]);

  fgets(restOfLine, rolLength, stream);
}


int main()
{
  int    key;
  char  value[256];
  // get movies filename from the user/stdin:
  char *MoviesFileName = getFileName();
	int movieSize = 0;


  BST *tree = BSTCreate();
  InputMovies(MoviesFileName, &movieSize, tree);
 // printf("%d", movieSize);
	//printf("%s\n",tree->Root->Value);
	fscanf(stdin, "%d", &key);
  skipRestOfInput(stdin);
  
  BSTNode *node = BSTSearch(tree, key);
  
   if (node == NULL)
  {
    printf(">>%d not found\n", key);
  }
  else
  {
    printf("Movie %d: '%s'\n", node->Key, node->Value);
  }
  return 0;
}


