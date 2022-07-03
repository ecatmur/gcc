// { dg-options "-Wfunctional-cast=4" }
// Warn on functional cast interpreted as static_cast.

enum E {};
E e = E(10); // { dg-warning "functional cast" }
