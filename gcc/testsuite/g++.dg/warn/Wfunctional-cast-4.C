// { dg-options "-Wfunctional-cast=4" }
// Warn on functional cast interpreted as reinterpret_cast to non-indirect type.

long l = long("test"); // { dg-warning "functional cast" }
