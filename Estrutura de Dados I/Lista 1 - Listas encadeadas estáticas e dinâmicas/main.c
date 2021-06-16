#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prox;
};

void push(struct Node **headref, int novo) {
    struct Node *novoNo = malloc(sizeof(struct Node));
    novoNo->data = novo;
    novoNo->prox = *headref;
    *headref = novoNo;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prox;
    }
}

// Exercício 1
int tamanho(struct Node *head) {
    int i;
    struct Node *current = head;
    for (i = 0; current != NULL; i++) {
        current = current->prox;
    }
    return i;
}

// Exercício 2
int tamanhoRecursivo(struct Node *head) {
    if (head == NULL) {
        return 0;
    } else {
        return tamanhoRecursivo(head->prox) + 1;
    }
}


// Exercício 3
int countKey(struct Node **headref, int key) {
    struct Node *temp = *headref;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->prox;
    }
    return count;
}

// Exercício 4
int countKeyGreater(struct Node **headref, int key) {
    struct Node *temp = *headref;
    int count = 0;
    while (temp != NULL) {
        if (temp->data > key) {
            count++;
        }
        temp = temp->prox;
    }
    return count;
}

// Exercício 5
int countKeyLess(struct Node **headref, int key) {
    struct Node *temp = *headref;
    int count = 0;
    while (temp != NULL) {
        if (temp->data < key) {
            count++;
        }
        temp = temp->prox;
    }
    return count;
}
// Exercício 6
void segregarParImpar(struct Node **headref, struct Node **pares, struct Node **impares) {
    struct Node *parInicio = NULL, *parFim = NULL;
    struct Node *imparInicio = NULL, *imparFim = NULL;
    struct Node *atual = *headref;

    while (atual != NULL) {
        int val = atual->data;
        if (val % 2 == 0) {
            if (parInicio == NULL) {
                parInicio = atual;
                parFim = parInicio;
            } else {
                parFim->prox = atual;
                parFim = parFim->prox;
            }
        } else {
            if (imparInicio == NULL) {
                imparInicio = atual;
                imparFim = imparInicio;
            } else {
                imparFim->prox = atual;
                imparFim = imparFim->prox;
            }
        }
        atual = atual->prox;
    }

    if (parInicio != NULL) {
        parFim->prox = NULL;
    }

    if (imparInicio != NULL) {
        imparFim->prox = NULL;
    }

    *pares = parInicio;
    *impares = imparInicio;
    return;
}

// Exercício 7
void segregarMaiorMenor(struct Node **headref, struct Node **maiores, struct Node **menores, int X) {
    struct Node *maiorInicio = NULL, *maiorFim = NULL;
    struct Node *menorInicio = NULL, *menorFim = NULL;
    struct Node *atual = *headref;

    while (atual != NULL) {
        int val = atual->data;
        if (val > X) {
            if (maiorInicio == NULL) {
                maiorInicio = atual;
                maiorFim = maiorInicio;
            } else {
                maiorFim->prox = atual;
                maiorFim = maiorFim->prox;
            }
        } else if (val < X) {
            if (menorInicio == NULL) {
                menorInicio = atual;
                menorFim = menorInicio;
            } else {
                menorFim->prox = atual;
                menorFim = menorFim->prox;
            }
        }
        atual = atual->prox;
    }

    if (maiorInicio != NULL) {
        maiorFim->prox = NULL;
    }

    if (menorInicio != NULL) {
        menorFim->prox = NULL;
    }

    *maiores = maiorInicio;
    *menores = menorInicio;
    return;
}

// Exercício 8
int replace(struct Node **headref, int X, int Y) {
    struct Node *temp = *headref;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == X) {
            temp->data = Y;
            count++;
        }
        temp = temp->prox;
    }
    *headref = temp;
    return count;
}

// Exercício 9
void deleteNode(struct Node **headref, int key) {
    struct Node *temp = *headref, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *headref = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL) {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->prox;
        }

        if (temp == NULL)
            return;
        
        prev->prox = temp->prox;
        
        free(temp); // Free memory
        temp = temp->prox;
    }
}

// Exercício 10
// ?????

// Exercício 11
// Admite-se que a lista nunca está vazia
int primeiroNo(struct Node *headref) {
   return headref->data;
}

// Exercício 12
// Admite-se que a lista nunca está vazia
int ultimoNo(struct Node *headref) {
    struct Node *temp = headref;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
    return temp->data;
}

// Exercício 13
// Admite-se que a lista nunca está vazia
struct Node *ponteiroUltimoNo (struct Node *headref) {
    struct Node *temp = headref;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    return temp;
}

int main(void) {
}
