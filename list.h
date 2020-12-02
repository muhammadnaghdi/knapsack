typedef struct {
	int wight;
	int value;
} item;

struct Node {
	item *data;
	int value;
	struct Node *next;
};

typedef struct Node node;

typedef struct {
	node *first;
	node *last;
	int value;
} list;

struct SuperList {
	struct SuperList *first;
	struct SuperList *second;
	list *data;
	int value;
};

typedef struct SuperList super_list;

void list_node_init(node *n, item *i);

void list_list_init(list *l);
void list_list_add(list *l, node *n);
void list_list_print(list *l);

void list_super_list_init(super_list *sl);
void list_super_list_print(super_list *sl);
