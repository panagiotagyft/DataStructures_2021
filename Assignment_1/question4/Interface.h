#include "Types.h"

int search(char *, NodeType *);    // if letter there is in list
int insert(char *, NodeType **, int);  //insert letters
void addarray(NodeType *, Letters *);  //i fill the array
int next_position(int);     //return dynamic 10
void Has_the_problem_been_solved(Letters *, int, char *, char *, char *);   //i check if the problem solved
void matching_numbers(int, Letters *, int, char *, char *, char *);         //i fill the array with numbers from 0 to 9 
int solve_the_problem(char *, char *, char *);                              //i create the array
int aritmetical_value(Letters *, int, char *);              //i return the aritmetical value of words
