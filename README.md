# d.h
minimal c++ and eventually c debugging header

# usage

```c++
#include <iostream>
// use this or pass the defintion through the compiler
// with the -D flag (e.g., g++ main.cpp -DDEBUG)
#define DEBUG

#include "d.h"

CREATE_D_LEVEL(std::cout, hello, "hello: ");

int main() {
  d::hello("i am a debugging header library");
}
```

# note
there are 3 included debugging levels in d.h that if not needed can be deleted from your copy of d.h
