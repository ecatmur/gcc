// { dg-options "-Wfunctional-cast=1" }
// Warn on functional cast interpreted as reinterpret_cast.

long l = long("test"); // { dg-warning "functional cast" }
