typedef struct Nodo {
    struct Nodo* next;
    int dato;
} Nodo;

void freeList(Nodo** PrimerNodo);
void delLast(Nodo** PrimerNodo);
void insFirst(Nodo** PrimerNodo, int nuevoDato);
void printLista(Nodo* PrimerNodo);
Nodo* createNodo(int nuevoDato);