#ifndef PRINT_TREE_H_
# define PRINT_TREE_H_

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// Fichier include avec la structure de l'arbre
# include "../rbtree/rbtree.h"

// Nom du type de l'arbre
#define my_tree		t_rbnode

// Nom de la variable a afficher
#define VALUE_TO_PRINT	value

/*
Exemple:

typedef struct		s_rbnode {
  int			value;
  struct s_rbtree	*left, right;
}			t_rbnode;
*/

// Le code provient integralement de:
// http://web.archive.org/web/20071224095835/http://www.openasthra.com/wp-content/uploads/2007/12/binary_trees1.c

void print_ascii_tree(my_tree * t);

typedef struct asciinode_s
{
  struct asciinode_s * left, * right;

  //length of the edge from this node to its children
  int edge_length;
  int height;
  int lablen;
  //-1=I am left, 0=I am root, 1=right
  int parent_dir;
  //max supported unit32 in dec, 10 digits max
  char label[11];
}       asciinode;


void print_level(asciinode *node, int x, int level);
void compute_edge_lengths(asciinode *node);
asciinode * build_ascii_tree_recursive(my_tree * t);
void compute_lprofile(asciinode *node, int x, int y);
void compute_rprofile(asciinode *node, int x, int y);
asciinode * build_ascii_tree(my_tree * t);
void free_ascii_tree(asciinode *node);

#endif /* !PRINT_TREE_H_ */
