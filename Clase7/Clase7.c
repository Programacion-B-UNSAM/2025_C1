#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

#define GRUPO_A

int main() {
    Node* RootNode = createNode(0);

#ifdef GRUPO_A
    insertChild(RootNode, 0, 10);
    insertChild(RootNode, 0, 20);
    insertChild(RootNode, 20, 30);
    insertChild(RootNode, 10, 40);
    insertChild(RootNode, 10, 80);
#endif

#ifdef GRUPO_B
    recorrerHijos(RootNode, 0, 10);
    recorrerHijos(RootNode, 0, 20);
    recorrerHijos(RootNode, 20, 30);
    recorrerHijos(RootNode, 10, 40);
    recorrerHijos(RootNode, 10, 80);
#endif
    return 0;
}

Node* createNode(int newValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error en la creacion del nodo\n");
        exit(1);
    }
    newNode->value = newValue;
    newNode->child1 = NULL;
    newNode->child2 = NULL;
    return newNode;
}

void recorrerHijos(Node* actual, int target, int newValue) {
    if (actual->value == target) {
        insChild(actual, newValue);
        return;
    }
    if (actual->child1 != NULL) {
        recorrerHijos(actual->child1, target, newValue);
    }
    if (actual->child2 != NULL) {
        recorrerHijos(actual->child2, target, newValue);
    }
    return;
}

void insChild(Node* parent, int newValue) {
    Node* child = createNode(newValue);
    if (parent->child1 == NULL) {
        parent->child1 = child;
        child->parent = parent;
    } else if (parent->child2 == NULL) {
        parent->child2 = child;
        child->parent = parent;
    } else {
        perror("No se puede insertar");
        exit(1);
    }
    return;
}

void insertChild(Node* root, int target, int newValue) {
    if (root == NULL) {
        return;
    }

    Node* current = root;
    Node* lastParent = NULL;
    Node* nextToVisit = NULL;

    while (current != NULL) {
        if (current->value == target) {
            insChild(current, newValue);
            return;
        }
        if (current->child1 != NULL) {
            nextToVisit = current->child1;
            if (current->child2 != NULL) {
                lastParent = current;
            }
        } else if (current->child2 != NULL) {
            nextToVisit = current->child2;
        } else if (lastParent != NULL) {
            nextToVisit = lastParent->child2;
            lastParent = NULL;
        } else {
            nextToVisit = NULL;
        }
        current = nextToVisit;
    }
}