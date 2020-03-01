/* Self-referntial structure -Binary Tree
The nodes on a binary tree are maintained so that at any node the left subtree contains only word
that are lexicographically less than the word at the node, and the right subtree contains only
words that are greater */

/* now is the time for all good men to come to the aid of their party
   
the root is now, and words greater than now are on the right of the word

               now                         
            /     \
           is     the
          /  \    /  \
         for men  of  time
        /  \      \   /   \
    all good   party their to
    / \
 aid  good

*/

#include <stdio.h>
#include <ctype.h>    // isalpha()
#include <string.h>   // NULL macro, strcpy(), strdup()
#include <stdlib.h>   // malloc

/* It is illegal for a structure to contain an instance of itself but
struct tnode *left declares left to be a pointer to a tnode, not a tnode itself.
*/  
  
struct tnode {                  /* the tree node: */
  char *word;                   /* points to the text */
  int count;                    /* number of occurrences */
  struct tnode *left;           /* left child */
  struct tnode *right;          /* right child */
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);

void free_tree(struct tnode *);

void treeprint(struct tnode *);
int getword(char *, int);
char buf[10];
int bufp = 0;


/* word frequency count */
int main(void) {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word,MAXWORD) != 'X')
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  free_tree(root);
  return 0;
}

/* The function addtree is recursive. A word is presented by main to the top
level(the root) of the tree. At each stage, the word is compared to the word
already stored at the node, and is percolated down to either the left or right subtree
by a recursive call to addtree. Eventually the word either matches something 
already in the tree (in which case the count is incremented), or a null
pointer in encountered, indicating that a node must be created and added to the tree.
If a new node is created, addtree return a pointer to it, which is
installed in the parent. */

struct tnode *talloc(void);

/* talloc: make a node */
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}
				


//char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;

  if (p == NULL) {                       /* a new word has arrived */
    p = talloc();                        /* make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;                         /* repeat word */
  else if (cond < 0)                    /* less than into left subtree */
    p->left = addtree(p->left, w);
  else                                  /* greater than into right subtree */
    p->right = addtree(p->right,w);

  return p;
}

/* treeprint prints the tree in sorted order; at each node, it prints the left
subtree (all words less than this word), then the word itself, then the right
subtree (all words greater). */

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* strdup merely copies the string given by its argument into a safe place,
obtained by a call on malloc. malloc returns NULL if no space is available;
strdup passes that value on, leaving error handling to its caller */

/*
char *strdup(char *s) {        /*  make a duplication of s 
  char *p;
  p = (char *) malloc(strlen(s) + 1);    /*  +1 for '\0'  
  if (p!=NULL)
    strcpy(p,s);
  return p;
}
*/


int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w  = word;

    while(isspace(c = getch()))
      ;
    if (c != EOF)
      *w++ = c;
    if(!isalpha(c)) {
      *w = '\0';
      return c;
    }
    for(; --lim > 0; w++)
      if(!isalnum(*w = getch())) {
	ungetch(*w);
	break;
      }
    *w = '\0';
    return word[0];
  }

int getch(void){
    if (bufp > 0){
       return buf[--bufp];
    }else{
       return getchar();      
       }
   }
    
void ungetch(int c){ 
  if (bufp >= 50){
    printf("ungetch: too many characters\n");
  }  else{
    buf[bufp++] = c;
    }
}


/* free_tree() recursive function:
free_tree is called and in this function the 
free_tree(node->right) is called and so this is the
recursive call to the function. When the recursive call is
completed the program goes back to the original call to 
the free_tree function from where it left off therefore
will call the recursive call to free_tree(node->left)
Again when this recursive call to function is completed
the program goes to the original call of the function and
starts where is left off. */

/* free up the malloc used for the binary tree */

void free_tree(struct tnode * node){       
       if (node != NULL) {
	 printf("%s\n", node->word);
	 free_tree(node->right);
	 free_tree(node->left);
         free(node);
  	 node = NULL;
     }}
