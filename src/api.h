#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define Passthrough_DLLIMPORT __declspec(dllimport)
#  define Passthrough_DLLEXPORT __declspec(dllexport)
#  define Passthrough_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define Passthrough_DLLIMPORT __attribute__((visibility("default")))
#    define Passthrough_DLLEXPORT __attribute__((visibility("default")))
#    define Passthrough_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define Passthrough_DLLIMPORT
#    define Passthrough_DLLEXPORT
#    define Passthrough_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef Passthrough_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define Passthrough_DLLAPI
#  define Passthrough_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef Passthrough_EXPORTS
#    define Passthrough_DLLAPI Passthrough_DLLEXPORT
#  else
#    define Passthrough_DLLAPI Passthrough_DLLIMPORT
#  endif // Passthrough_EXPORTS
#  define Passthrough_LOCAL Passthrough_DLLLOCAL
#endif // Passthrough_STATIC