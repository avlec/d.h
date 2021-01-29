#ifndef __D_HEADER
#define __D_HEADER

#ifdef __cplusplus

#ifdef DEBUG
#define CREATE_D_LEVEL(t,x,s)                   \
  namespace d {                                 \
    template <typename Arg>                     \
    void x(Arg __a) {                           \
      t << s << __a << std::endl << std::flush; \
    }                                           \
    template <typename Arg, typename... Args>   \
    void x(Arg __a, Args... __args) {           \
      t << s << __a << std::endl;               \
      x(__args...);                             \
    }                                           \
  }
#else // print debug
#define CREATE_D_LEVEL(t,x,s)                   \
  namespace d {                                 \
    template <typename Arg>                     \
    void x(Arg __a) {};                         \
    template <typename Arg, typename... Args>   \
    void x(Arg __a, Args... __args) {};         \
  }
#endif // noop debug

#else // __cplusplus

#error c not supported yet B)

#endif // c


/*
 * Example debugging levels. This is also where custom
 * debug levels are specified.
 */
#include <iostream>
CREATE_D_LEVEL(std::cout, l, "log: ");
CREATE_D_LEVEL(std::cout, w, "warn: ");
CREATE_D_LEVEL(std::cerr, f, "fatal: ");

#endif // __D_HEADER
