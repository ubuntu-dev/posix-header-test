#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#define NAME1(n) name_##n
#define NAME2(n) NAME1(n)
#define NAME NAME2(__COUNTER__)

#define IDENT(name, type) _Static_assert(_Generic(name, type : 1), "")
#define IDENT_INIT(name, type) static const type NAME = name
#define IDENT_INT(name) IDENT((int)((name)&0), int)
#define IDENT_PROC(name) static inline void NAME(void) { name; }
#define MEMBER(obj, field, type) IDENT(((obj *)0)->field, type)
#define TYPE(name) static const name NAME
#define TYPE_ARITH(name) static name NAME = (name)0 + 0
#define TYPE_EQ(a, b)                                                          \
  static const a inst_##a;                                                     \
  IDENT(inst_##a, b)
#define TYPE_FORWARD(name) static name *const NAME = 0
#define TYPE_INT(name) static const name NAME = 1
#define TYPE_SINT(name)                                                        \
  TYPE_INT(name);                                                              \
  _Static_assert((name)-1 < 0, "")
#define TYPE_UINT(name)                                                        \
  TYPE_INT(name);                                                              \
  _Static_assert((name)-1 > 0, "")

#endif
