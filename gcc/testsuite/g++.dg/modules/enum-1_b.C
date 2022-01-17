// { dg-additional-options "-fmodules-ts" }
import enUm;

Bill x = Three;
Ben y = Ben::Three;

int main ()
{
  if (x != 3)
    return 1;

  if (static_cast<int> (y) != 3)
    return 2;

  if (static_cast<int> (func1 ()) != 3)
    return 3;

  if (static_cast<int> (func2 ()) != 4)
    return 4;

  return 0;
}
