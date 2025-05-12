typedef struct Node {
    int value;
    struct Node* parent;
    struct Node* child1;
    struct Node* child2;
} Node;

Node* createNode(int newValue);

void insChild(Node* parent, int newValue);
void recorrerHijos(Node* actual, int target, int newValue);

void insertChild(Node* root, int target, int newValue);
