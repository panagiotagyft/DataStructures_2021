typedef char Letter;
typedef char Char[2];
typedef int Item;


struct listnode{
	Char str;
	struct listnode *next;
};

typedef struct listnode NodeType;

struct letters{
	Letter letter;
	Item item;
	int reserved_num;
}*array;

typedef struct letters Letters;
