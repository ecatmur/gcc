// { dg-do compile { target c++11 } }
// { dg-options "-Wfunctional-cast=3" }
// Warn on functional cast interpreted as downcast.

struct B {} b;
struct D : B { D(B&); };
using R = D&&;
R r = R(b); // { dg-warning "functional cast" }
