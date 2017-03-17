/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

#include "queue.h"


//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila

void queue_append(queue_t **queue, queue_t *elem) {

    *elem->next = **queue; //o elemento passa a apontar para o final da fila
    *queue->next = **elem; //o antigo final da fila passa a apontar para o elemento
    *elem->prev = **queue->prev; //o elemento passa a apontar para o antigo final da fila
    *queue->prev = **elem; //O inicio da fila aponta para o novo final da fila
};

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: apontador para o elemento removido, ou NULL se erro

queue_t *queue_remove(queue_t **queue, queue_t *elem) {
    *elem->prev->next = elem->next;
    *elem->next->prev = elem->prev;
    *elem->next = NULL;
    *elem->prev = NULL;
    return elem;
};

//------------------------------------------------------------------------------
// Conta o numero de elementos na fila
// Retorno: numero de elementos na fila

int queue_size(queue_t *queue) {
    int cont = 0;
    queue_t aux;
    aux = queue;
    while (queue->next != aux->prev) {
        cont++;
        queue->next = queue->next->next;
    }
};

//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca. Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir

void queue_print(char *name, queue_t *queue, void print_elem(void*));