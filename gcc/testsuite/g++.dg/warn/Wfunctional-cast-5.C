// { dg-options "-Wfunctional-cast=5" }
// Warn on functional cast interpreted as other static_cast.

enum E {};
E e = E(10); // { dg-warning "functional cast" }
