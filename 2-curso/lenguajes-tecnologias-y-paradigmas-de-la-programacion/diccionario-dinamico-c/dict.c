#include "dict.h"
#include <stdio.h>
#include <string.h>

void int_to_obj(int src, object *dst) {
    dst->type = 0;
    sprintf(dst->data,"%d",src);
}
void float_to_obj(float src, object *dst) {
    dst->type = 1;
    sprintf(dst->data,"%f",src);
}
void str_to_obj(char *src, object *dst) {
    dst->type = 2;
    sprintf(dst->data,"%s",src);
}

void obj_to_int(object src, int *dst) {
    if(src.type == 0) {
        *dst = atoi(src.data);
    }else {
        printf("Error, tipo de dato incorrecto\n");
    }
}
void obj_to_float(object src, float *dst) {
    if(src.type == 1) {
        *dst = atof(src.data);
    }else {
        printf("Error, tipo de dato incorrecto\n");
    }
}
void obj_to_str(object src, char *dst) {
    if(src.type == 2) {
        strcpy(dst,src.data);
    }else {
        printf("Error, tipo de dato incorrecto\n");
    }
}

dict *dict_new() {
    dict *dic = (dict*)malloc(sizeof(dict));
    dic->len = 0;
    return dic;
}

void dict_destroy(dict *dic) {
    dict_node *current = dic->first;
    dict_node *next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(dic);
}

int dict_add(dict *dic, object key, object value) {
    object *past_value;
    if(dict_search(dic, key, past_value) == 0) {
        *past_value = value;
        return 0;
    }else if(dict_search(dic, key, past_value) == -1) {
        dict_node *aux = (dict_node*)malloc(sizeof(dict_node));
        aux->key = key;
        aux->value = value;
        aux->next = dic->first;
        dic->first = aux;
        dic->len++;
        return 0;
    }else {
        printf("No se ha podido crear la palabra");
        return -1;
    }
}

int dict_search(dict *dic, object key, object *dst) {
    dict_node *current = dic->first;
    while(current != NULL) {
        if(current->key.type == key.type && strcmp(current->key.data, key.data) == 0) {
            *dst = current->value;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

int main(void) {
    return 0;
}
