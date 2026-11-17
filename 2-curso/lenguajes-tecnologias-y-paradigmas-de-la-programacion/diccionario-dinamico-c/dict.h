//
// Created by Andrés on 22/10/2024.
//

#ifndef DICT_H
#define DICT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 100

// type=0,1,2–int/float/string
typedef struct {int type; char data[MAX_DATA];} object;
typedef struct st_dict_node {
    object key;
    object value;
    struct st_dict_node *next;
} dict_node;
typedef struct {
    dict_node *first;
    int len;
} dict;

void int_to_obj(int src, object *dst);
void float_to_obj(float src, object *dst);
void str_to_obj(char *src, object *dst);

void obj_to_int(object src, int *dst);
void obj_to_float(object src, float *dst);
void obj_to_str(object src, char *dst);

// crear, eliminar
dict *dict_new(); // Retorna un puntero
void dict_destroy(dict *dic); // Libera la memoria, de forma correcta!!
// añadir, buscar, eliminar por clave
int dict_add(dict *dic, object key, object value); // 0 si éxito, -1 si fallo
int dict_search(dict *dic, object key, object *dst); // 0 si éxito, -1 si fallo
int dict_remove(dict *dic, object key); // 0 si éxito, -1 si fallo
// utilidades
int dict_len(dict *dic); // Retorna longitud del diccionario
int dict_equals(dict *dic1, dict *dic2); // 0 si iguales, -1 si no
// iterar
dict_node *dict_first(dict *dic); // primera entrada; NULL si no hay
dict_node *dict_next(dict *dic, dict_node *current); // sig ent; NULL si no hay
// obtener clave/valor desde una entrada del diccionario
void dict_key(dict_node *pair, object *dst);
void dict_value(dict_node *pair, object *dst);

#endif //DICT_H
