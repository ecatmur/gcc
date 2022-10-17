// { dg-options "-Wfunctional-cast=2" }
// Warn on functional cast interpreted as const_cast.

typedef char* P;
P p = P("test"); // { dg-warning "casts away qualifiers" }
