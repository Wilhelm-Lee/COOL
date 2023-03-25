/*
 *     This file is part of project <https://github.com/WilliamPascal/COOL>
 *     Copyright (C) 2023  William Pascal
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/* Macro __STUDY_COOL_MinGW__ is an identifier for further development
   which involves in when variance of other projects come together. */
#ifdef __STUDY_COOL_MinGW__
# error Macro "__STUDY_COOL_MinGW__" should only be defined in main.c
#endif /* __STUDY_COOL_MinGW__ */

#ifdef __STUDY_COOL_GNU__
# warning Macro __STUDY_COOL_GNU__ is defined. Consider to merge them into one.
#endif /* __STUDY_COOL_GNU__ */

#define __STUDY_COOL_MinGW__ 1

/*** Welcome to COOL MinGW, developers! ***/

//# include "_var.h"
// #include "_array.h"
#include "advanced/objects.h"

int
main(int argc, char *argv[]);  /* For ANSI C */

int
main(int argc, char *argv[])
{
//  var_t _v;
//  _var_new(&_v, sizeof(int));

//  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);

//  _var_ren(&_v, sizeof(double));

//  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);

//  _var_del(&_v); /* Malfunctioning :( */

//  /* Memory was not freed, no Segmentation Fault */
//  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);

//  var_t p;
//  _var_new(&p, sizeof(int));

//  array_t arr;
//  arr.len = 6;
//  __array_pgoto(&p, &arr, 9);

////  int i1 = 10;
////  long long i2 = 0xFFFF;

////  var_t *v1;
////  _var_new(v1, sizeof(i1), itos(1)); /* 4 */

//  v1 = i1;

////  fprintf(stdout, "%p\n", v1->_addr);

////  var_t *v2 = _var_new(sizeof(i2)); /* 8 */

//  v2 = 0xFFFF;

////  fprintf(stdout, "%p\n", v2->_addr);

////  _var_del(v1);
////  _var_del(v2);

//  fprintf(stdout, "%p\n", v1->_addr);
//  fprintf(stdout, "%p\n", v2->_addr);
/* 
  object_t *obj = nullobjptr;
  objects_t *objs = nullobjsptr;
  objects_t objs1 = (objects_t){ _OBJS_MOV_INDIC_DEF, objs, objs, objs, objs, obj };

  _objects_succeed(&objs1, objs, objs->_indic);

  fprintf(stdout, "obj: %p\n", obj);
  fprintf(stdout, "objs: %p\n", objs);

  fprintf(stdout, "objs1.successor: %p\n", objs1._successor);

  fprintf(stdout, "%d\n", _objects_relation(objs, &objs1)); */

/* Var type */
  fprintf(stdout, "Var Type\n");
  var_t a = nullvar;
  _var_new(&a, sizeof(int), "256");

  fprintf(stdout, "%p\n%llu\n%s\n", a._addr, a._sz, a._val);

/* Array type */
  fprintf(stdout, "Array Type\n");

  var_t a1 = nullvar;
  var_t a2 = nullvar;
  var_t a3 = nullvar;
  _var_new(&a1, sizeof(int), "64");
  _var_new(&a2, sizeof(int), "128");
  _var_new(&a3, sizeof(int), "256");

  var_t *_varr[3] = {&a1, &a2, &a3};

  array_t b = nullarr;
  _array_newarr(&b, 3, _varr);

  fprintf(stdout, "length == %llu\n", _array_calclen(&b));
  for (register length_t i = 0; i < (_array_calclen(&b)); i ++)
    fprintf(stdout, "[%llu] == %s\n", i, b[i]._val);

/* Off */
  _var_del(&a);
  _var_del(&a3);
  _var_del(&a2);
  _var_del(&a1);
  // fprintf(stdout, "\n\n===ALLOCATION===\n\n");
  // char *_buff = (char *)malloc(sizeof(char) * 26);
  // for (register int i = 97; i < (97 + 26); i ++)
  //   {
  //     fprintf(stdout, "BEFORE:\t%c\tfrom %p\n", _buff[i], &_buff[i]); /* [a, z] are missing (26 elements) -> [1, 26] */
  //     _buff[(i-97)] = (char)i;
  //     fprintf(stdout, "AFTER:\t%c\tfrom %p\n", _buff[i], &_buff[i]);
  //   }
  // fprintf(stdout, "%s\n", _buff);

  // /* TEST: test for freeing individual element from char array _buff */
  // fprintf(stdout, "\n\n===DEALLOCATION===\n\n");
  // for (register length_t i = 0; i < 26; i ++)
  //   {
  //     fprintf(stdout, "BEFORE:\t%c\tfrom %p\n", _buff[i], &_buff[i]); /* [b, q) are missing (16 elements) -> [i=2,i=17) */
  //     free(&_buff[i]);
  //     fprintf(stdout, "AFTER:\t%c\tfrom %p\n", _buff[i], &_buff[i]);
  //   }
  // /* TEST OVER */
  _array_delarr(&b); /* SEGMENTATION FAULT */

  // fprintf(stdout, "\n\n===ALLOCATION===\n\n");
  // char *_buff = (char *)malloc(sizeof(char) * 26);
  // for (register int i = 97; i < (97 + 26); i ++)
  //   {
  //     fprintf(stdout, "BEFORE:\t%c\tfrom %p\n", _buff[i], &_buff[i]); /* [a, z] are missing (26 elements) -> [1, 26] */
  //     _buff[(i-97)] = (char)i;
  //     fprintf(stdout, "AFTER:\t%c\tfrom %p\n", _buff[i], &_buff[i]);
  //   }
  // fprintf(stdout, "%s\n", _buff);

  // /* TEST: test for freeing individual element from char array _buff */
  // fprintf(stdout, "\n\n===DEALLOCATION===\n\n");
  // for (register length_t i = 0; i < 26; i ++)
  //   {
  //     fprintf(stdout, "BEFORE:\t%c\tfrom %p\n", _buff[i], &_buff[i]); /* [b, q) are missing (16 elements) -> [i=2,i=17) */
  //     free(&_buff[i]);
  //     fprintf(stdout, "AFTER:\t%c\tfrom %p\n", _buff[i], &_buff[i]);
  //   }
  // /* TEST OVER */

  // free(_buff);
  // _buff = NULL;

  // fprintf(stdout, "%s\n", _buff);

  return 0;
}
