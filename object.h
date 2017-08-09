/*
 * object.h
 *
 *  Created on: Aug 8, 2017
 *      Author: ln
 */

#include<stdio.h>
#include<stdlib.h>

// declarations - object

struct data;
struct object;
char *to_string(struct object *);
int get_hashcode(struct object *);
struct object* new();
int cnt;  // used for hashcode value

// definitions - object data

struct data {
	char *value;
};

struct object {
	struct data *data;
	struct object *parent;
	int hashcode;
	char *(*to_string)(struct object *);
	int (*get_hashcode)(struct object *);
};

// declarations - string

struct string_data;
struct string_object;
struct string_object* string_new();

// definitions - string data

struct string_data {
	char *value;
};

struct string_object {
	struct object *parent;
	struct string_data *data;
	void (*methods[4])(); // an array of 4 pointers to functions returning void
};


