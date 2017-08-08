/*
 * limbo.c
 *
 *  Created on: Aug 8, 2017
 *      Author: lnarmour
 */

#include<stdio.h>
#include<stdlib.h>

// declarations

struct string_data;
struct string_object;
int string_size(struct string_object *);
struct string_object *new(char *);


// definitions - data

struct string_data {
      int size;
      char *value;
};

struct string_object {
      struct string_data data;
      int (*size)(struct string_object *);  // proof of concept - a pointer to a function that takes no arguments and returns an int.  Ultimately this will be an array of pointers to functions.
};


// definitions - methods

struct string_object *new(char *data)
{
      struct string_object *tmp_object;
      struct string_data *tmp_data;

      if((tmp_object = malloc(sizeof *tmp_object))==NULL || (tmp_data = malloc(sizeof *tmp_data))==NULL)
    	  return tmp_object;

      tmp_object->data = *tmp_data;
      tmp_object->data.value = data;
      tmp_object->data.size = string_size(tmp_object);
      tmp_object->size = &string_size;

      return tmp_object;
}

int string_size(struct string_object *obj)
{
	int done = 0;
	int i = 0;

	while (!done) {
		if (*(obj->data.value + i) == '\0') {
			done = 1;
		} else {
			i++;
		}
	}

	return i;
}


// testing entry point

int main() {

      struct string_object *str0 = new("Louis Narmour");
      struct string_object *str1 = new("AAABBBCCCDDD");

      printf("%s + size:%d\n", str0->data.value, str0->size(str0));
      printf("%s + size:%d\n", str1->data.value, str1->size(str1));

      return 0;
}






























