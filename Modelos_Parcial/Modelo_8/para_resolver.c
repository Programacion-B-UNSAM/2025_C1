/* Buenas, les dejo acá las funciones que me hice para resolver los ejercicios, les
 * recomiendo que intenten resolverlo por su cuenta primero, y usen esto si están
 * muy trabados, o para verificar sus resultados.
 * Algunas funciones con cosas más generales que vimos en clase no las voy a incluir,
 * por que considero que ya lo deberían tener hecho, o pueden sacarlo de los otros
 * códigos del GitHub y/o videos / cosas que vimos en la materia.
 */

#include <stdlib.h>
#include <stdio.h>
#include "definiciones.h"

/* ########################################################################
 * EJERCICIO 1:
 * 1) Ultimo numero: 18 --> suma = 1692
 * 2) Primer numero que cumple --> 19 = 0b 0001 0011
 *                                           5^ ^4 (les marco 4to y 5to bit)
 *   a/b) Impriman el numero en binario y verifiquen que funcione
 *   c) 10
 * ########################################################################
 */

/* @brief  Suma los multiplos de un numero dado en un array
 * @param[in]   list[], puntero a la primer posición del array que quiero analizar
 * @param[in]   list_size, tamaño de la lista
 * @param[in]   mult, numero que quiero usar como condicion
 * @return      devuelve la suma de los multiplos de mult
 */
long suma_multiplos(int list[], int list_size, int mult)
{
  double tot = 0;
  for (int i = 0; i < list_size; ++i)
  {
    if ((list[i] % mult) == 0)
      tot += list[i];
  }
  return tot;
}

/* @brief  Busca el primer numero que cumpla la condicion pedida
 * @param[in]   list[], puntero a la primer posición del array que quiero analizar
 * @param[in]   list_size, tamaño de la lista
 * @return      devuelve el primer numero que cumple la condicion
 */
int find_condition(int list[], int list_size)
{
  int sum = 0;
  float prom = 0;
  for (int i = 0; i < list_size; ++i)
  {
    /* El siguiente printf() me ayuda a verificar que este funcionando */
    // printf("%d - %d - prom = %f\n", i, list[i], prom);

    if ((prom == (int)prom) && i > 10)
    {
      printf("%d --> list[%d]\n", list[i], i);
      return list[i];
    }
    sum += list[i];

    /* Algunos estaban teniendo problemas, por que empezaban con i = 1, sum = list[0]
     * y despues dividian por i. Pero si hacen eso, la primer iteracion les queda:
     * sum = list[0]+list[1]
     * prom  = sum/1 <-- esto no es el promedio!
     */
    prom = (float)sum / (i + 1);
    printf("num = %d - prom = %6f\n", list[i], prom);
  }
  printf("No se encontro un numero que cumpla!\n");
  return 0;
}

/* @brief  Setea el bit_to_set para que sea igual al base_bit
 * @param[in]   num, numero sobre el que voy a operar
 * @param[in]   base_bit, bit en el que me voy a "basar" (en este caso el 5to)
 * @paran[in]   bit_to_set, numero de bit que tengo que modificar
 * @return      numero con los bits cambiados
 */
int swap_bits(int num, int base_bit, int bit_to_set)
{
  int base_bit = (num >> base_bit - 1) & 0b1; /* Agarro el base bit */

  /* Todos estos printf() y variables auxiliares son por si quieren verificar que las
   * mascaras y shifts esten funcionando como deberian

   */
  // for (int i = 8; i >= 0; --i)            /* uso 8 por que se que no hay numeros mas grandes que 100 */
  // printf("%d", (base_bit >> i) & 0b1);
  // printf("\n");

  // int aux = (base_bit << (set - 1));
  // for (int i = 8; i >= 0; --i) /* uso 8 por que se que no hay numeros mas grandes que 100 */
  // printf("%d", (aux >> i) & 0b1);
  // printf("\n");
  return (num | (base_bit << (bit_to_set - 1)));
}

/* @brief  Cuenta cuantas veces se repite un numero en un array
 * @param[in]   list[], puntero a la primer posición del array que quiero analizar
 * @param[in]   list_size, tamaño de la lista
 * @param[in]   num, numero que quiero contar cuantas veces se repite
 * @return      repetitions, cantidad de veces que aparece el numero en el array
 */
int count_repeated(int list[], int list_size, int num)
{
  int repetitions = 0;
  for (int i = 0; i < list_size; ++i)
    if (list[i] == num)
      repetitions++;
  return repetitions;
}

/* ########################################################################
 * EJERCICIO 2:
 * La lista es corta, por lo que se puede verificar rápidamente si los resultados
 * son correctos imprimiendo la lista!
 *
 * Para el ultimo punto, las funciones que están acá no les van a alcanzar, pero casi.
 * ########################################################################
 */

/* @brief  Imprime una lista doblemente enlazada en el sentido next
 * @param[in]   first, primer nodo de la lista doblemente enlazada
 */
void print_next(dnode_t *first)
{
  dnode_t *current = first;
  while (current != NULL)
  {
    printf("(%d | %d C) -> ", current->data.humedad, current->data.temp);
    current = current->next;
  }
  printf(" NULL\n");
}

/* @brief   Imprime una lista doblemente enlazada en el sentido prev
 * @param[in]   last, ultimo nodo de la lista doblemente enlazada
 */
void print_prev(dnode_t *last)
{
  dnode_t *current = last;
  while (current != NULL)
  {
    printf("(%d|%d C) -> ", current->data.humedad, current->data.temp);
    current = current->prev;
  }
  printf(" NULL\n");
}

/* @brief  Funcion "wrapper" para imprimir listas dobles, me permite rapidamente
 *         imprimir la lista doble en sentido next, prev, o ambos
 * @param[in]   first, primer nodo de la lista doblemente enlazada
 * @param[in]   last, ultimo nodo de la lista doblemente enlazada
 * @param[in]   type, tipo de impresion: 0 = next, 1 = prev, 2 = ambos sentidos
 */
void show_dlist(dnode_t *first, dnode_t *last, int type)
{

  if (type == 0)
    print_next(first);
  if (type == 1)
    print_prev(last);
  if (type == 2)
  {
    print_next(first);
    print_prev(last);
  }
}

/* @brief  Elimina un nodo de una lista doble, sin hacer romper conexiones
 * @param[in]   first, direccion de memoria de la variable que guarda el primer nodo
                de la lista doblemente enlazada
 * @param[in]   last, direccion de memoria de la variable que guarda el ultimo nodo
                de la lista doblemente enlazada
 * @param[in]   erase, puntero al nodo que quiero eliminar
 */
void eliminar_lista_doble(dnode_t **first, dnode_t **last, dnode_t *erase)
{
  /* En este caso, necesito que first y last sean punteros dobles por si el nodo a
   * eliminar es el primero o ultimo nodo de la lista. Necesito poder modificar la
   * variable que guarda esta direccion, por lo que uso un puntero doble.
   */

  /* Separo de acuerdo a los tres casos que se presentan el la teorica. Esta
   * funcion asume que yo se la direccion de memoria del nodo a eliminar, por lo que
   * no necesito 'moverme' hasta este nodo dentro de ella!
   */

  /* Eliminar al principio */
  if (erase == *first)
  {
    *first = (*first)->next;
    (*first)->prev = NULL;
    free(erase);
    return;
  }

  /* Eliminar al final */
  if (erase == *last)
  {
    *last = (*last)->prev;
    (*last)->next = NULL;
    free(erase);
    return;
  }

  /* Eliminar en el medio */
  erase->next->prev = erase->prev;
  erase->prev->next = erase->next;
  free(erase);
  return;
}

/* @brief  Busca y elimina todos los nodos cuya humedad sea negativa
 * @param[in]   first, direccion de memoria de la variable que guarda el primer nodo
                de la lista doblemente enlazada
 * @param[in]   last, direccion de memoria de la variable que guarda el ultimo nodo
                de la lista doblemente enlazada
 */
void delete_neg_hum(dnode_t **first, dnode_t **last)
{
  dnode_t *current = *first, *temp = NULL;
  while (current != NULL)
  {
    if (current->data.humedad < 0)
    {
      temp = current;
      current = current->next;
      eliminar_lista_doble(first, last, temp); /* uso la funcion mas 'general' */
    }
    else
    {
      current = current->next;
    }
  }
}

/* @brief Intercambia la data contenida en dos nodos
 * @param[in]   nodoA, puntero a un nodo
 * @param[in]   nodoB, puntero a otro nodo
 */
void swap_data(dnode_t *nodoA, dnode_t *nodoB)
{
  data_t temp = nodoA->data;
  nodoA->data = nodoB->data;
  nodoB->data = temp;
}

/* @brief Algoritmo de ordenamiento Bubble Sort para listas doblemente enlazadas
 * @param[in]   primerDNode, primer nodo de la lista doblemenete enlzada
 */
void bubble_sort_llist(dnode_t *primerDNode)
{
  dnode_t *current = NULL;
  int orden_count = 1; /* 'flag' para saber cuando termine de ordenar la lista*/
  dnode_t *last = NULL;
  while (orden_count != 0)
  {
    orden_count = 0;
    current = primerDNode;
    while (current->next != last)
    { /* para optimizar numero de iteraciones */
      if (current->data.humedad > current->next->data.humedad)
      {
        /*quiero cambiar el orden de los nodos*/
        orden_count = 1;
        swap_data(current, current->next);
      }
    }
    current = current->next;
  }
  last = current;
}

/* @brief Imprime unicamente los nodos que cumplan alguna condicion
 * @param[in]   first, primer nodo de la lista doblemenete enlzada
 */
void print_some_nodes(dnode_t *first)
{
  dnode_t *current = first;
  while (current != NULL)
  {
    if (current->data.humedad > 80 && current->data.temp < 2)
      printf("(%d|%d C)\n", current->data.humedad, current->data.temp);
    current = current->next;
  }
}
