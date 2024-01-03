#include "item.h"

void STACKinit(int);   // Initialize the first stack
int STACKempty();      // I check if the stack is empty
void STACKpush(Item);  // I insert elements in the stack
Item STACKpop();       // I export elements from the stack

void secSTACKinit(int);  // Initialize the second stack
int secSTACKempty(void); // I check if the stack is empty
void secSTACKpush(int);  // I insert elements in the stack
int secSTACKpop(void);   // I export elements from the stack
