# ifndef UDLL_C
# define UDLL_C

union Data { //union to hold node data
   int i;
   int* iPtr;
   float f;
   float* fPtr;
   char c;
   char* cPtr;
};

struct Node {
   int length; //the length of the list
   union Data data; //data value
   struct Node *next; //pointer to the next node
   struct Node *prev; //pointer to the previous node
}; typedef struct Node Node;


void insert(int position, union Data data);
void removeNode(int index);
int length();
union Data get (int index);

#endif
