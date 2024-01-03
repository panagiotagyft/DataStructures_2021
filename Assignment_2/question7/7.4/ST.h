typedef struct set *Tree;

void STinit(Tree*);
 int STcount(Tree);
Tree STinsert(Item, Tree);
Item STsearch(Key,Tree);
Tree STdeleteAll(Item, Tree);
Item STselect(int, Tree);
void STsort(void (*visit)(Item));
void STprint(Tree);
Tree STinsert1(Item, Tree);
