// { dg-options "-Wfunctional-cast=1" }
// Warn on functional cast interpreted as reinterpret_cast to indirect type.

typedef char *T;
__UINTPTR_TYPE__ i = 0x12345678;
T p = T(i); // { dg-warning "functional cast" }

typedef char &U;
struct S {} s;
U r = U(s); // { dg-warning "functional cast" }
