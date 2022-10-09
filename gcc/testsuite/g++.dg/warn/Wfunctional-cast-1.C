// { dg-options "-Wfunctional-cast=1" }
// Warn on functional cast interpreted as reinterpret_cast to indirect type.

using T = char*;
using U = char&;
T p = T(0x12345678); // { dg-warning "functional cast" }
U r = U(p); // { dg-warning "functional cast" }
