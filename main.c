#include "lib/stkque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void test_stack(void) {
  printf("=== Test Stack (LIFO) ===\n");

  Stack s = NewStack();
  assert(isStackEmpty(s));
  assert(Peek(&s) == -1.0f);
  assert(!exists(s, 10.0f));

  // Pop en pila vacía no debe fallar
  Pop(&s);
  assert(isStackEmpty(s));

  // Insertar elementos
  Push(&s, 10.0f);
  Push(&s, 20.5f);
  Push(&s, 30.0f);

  assert(!isStackEmpty(s));
  assert(Peek(&s) == 30.0f);
  assert(exists(s, 10.0f));
  assert(exists(s, 20.5f));
  assert(exists(s, 30.0f));
  assert(!exists(s, 99.0f));
  printf("Tras Push (10, 20.5, 30) -> Peek: %.2f\n", Peek(&s));

  // Extraer uno (debe salir el 30)
  Pop(&s);
  assert(Peek(&s) == 20.5f);
  assert(!exists(s, 30.0f));
  printf("Tras primer Pop -> Peek: %.2f\n", Peek(&s));

  // Vaciar el resto
  Pop(&s);
  assert(Peek(&s) == 10.0f);
  Pop(&s);
  assert(isStackEmpty(s));
  assert(Peek(&s) == -1.0f);
  printf("Pila vaciada correctamente.\n\n");

  // Asegurar limpieza si quedara algún bloque reservado
  free(s.values);
}

static void test_queue(void) {
  printf("=== Test Queue (FIFO) ===\n");

  Queue q = NewQueue();
  assert(isQueueEmpty(q));
  assert(Front(&q) == -1.0f);

  // Dequeue en cola vacía no debe fallar
  dequeue(&q);
  assert(isQueueEmpty(q));

  // Encolar elementos
  enqueue(&q, 1.5f);
  enqueue(&q, 2.5f);
  enqueue(&q, 3.5f);

  assert(!isQueueEmpty(q));
  assert(Front(&q) == 1.5f);
  printf("Tras enqueue (1.5, 2.5, 3.5) -> Front: %.2f\n", Front(&q));

  // Sacar el primero (FIFO: debe salir 1.5 y quedar 2.5 al frente)
  dequeue(&q);
  assert(!isQueueEmpty(q));
  assert(Front(&q) == 2.5f);
  printf("Tras primer dequeue -> Front: %.2f\n", Front(&q));

  // Reutilizar tras vaciar
  dequeue(&q);
  assert(Front(&q) == 3.5f);
  dequeue(&q);
  assert(isQueueEmpty(q));
  assert(Front(&q) == -1.0f);

  enqueue(&q, 42.0f);
  assert(!isQueueEmpty(q));
  assert(Front(&q) == 42.0f);
  printf("Tras vaciar y re-encolar 42.0 -> Front: %.2f\n", Front(&q));

  dequeue(&q);
  assert(isQueueEmpty(q));
  printf("Cola vaciada correctamente.\n\n");

  // Asegurar limpieza si quedara algún bloque reservado
  free(q.values);
}

int main(void) {
  test_stack();
  test_queue();
  printf("Todos los tests pasaron correctamente.\n");
  return 0;
}