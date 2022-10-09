// { dg-options "-Wfunctional-cast=1" }
// Warn on functional cast interpreted as reinterpret_cast to indirect type.

__UINTPTR_TYPE__ i = 0x12345678;
typedef char *T;
T p = T(i); // { dg-warning "functional cast" }
typedef char &U;
U r = U(i); // { dg-warning "functional cast" }
