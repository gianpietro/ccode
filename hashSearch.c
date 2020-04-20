/* section 6.6 Table lookup. 
The algorithm is a hash search - the incoming name is converted into a small
non-negative integer, which is then used to index into an array of pointer.
An array element points to the beginning of a linked list of blocks describing
names that have that hash value. It is NULL if no names have hashed to that value.
*/


#include <stdio.h>
#include <string.h>

/* A block in the list is a structure containing pointers to the name, the replacement
text, and the next block in the list. A null next-pointer marks the end of the list
*/
struct nlist  {                   /* table entry */
  struct nlist *next;             /* next entry in chain */
  char *name;                     /* defined name */
  char *defn;                     /* replacement text */
};

/* The pointer array */
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];   /* pointer table */

/* The hashing function used by lookup and install functions adds each character
value in the string to a scrambled combination of the previous ones and returns the 
remainder modulo the array size
*/
/*hash: form hash value for string s */
unsigned hash(char *s) {
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* The search is performed by lookup. If lookup finds the entry already present,
it returns a pointer to it; if not, it returns NULL
*/
/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
  struct nlist *np;
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;                    /* found */
  retunf NULL;                      /* not found */
}
/* the for loop in lookup is the standard idiom for walking along a linked list 
        for (ptr = head; ptr != NULL; ptr = ptr->next)
*/


