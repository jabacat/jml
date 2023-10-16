#ifndef JMLDEFS_H
#define JMLDEFS_H

// stolen from https://gcc.gnu.org/wiki/Visibility
// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define JML_HELPER_DLL_IMPORT __declspec(dllimport)
#define JML_HELPER_DLL_EXPORT __declspec(dllexport)
#define JML_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define JML_HELPER_DLL_IMPORT __attribute__((visibility("default")))
#define JML_HELPER_DLL_EXPORT __attribute__((visibility("default")))
#define JML_HELPER_DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define JML_HELPER_DLL_IMPORT
#define JML_HELPER_DLL_EXPORT
#define JML_HELPER_DLL_LOCAL
#endif
#endif

// Now we use the generic helper definitions above to define JML_API and
// JML_LOCAL. JML_API is used for the public API symbols. It either DLL imports
// or DLL exports (or does nothing for static build) JML_LOCAL is used for
// non-api symbols.

#ifdef JML_DLL         // defined if JML is compiled as a DLL
#ifdef JML_DLL_EXPORTS // defined if we are building the JML DLL (instead of
                       // using it)
#define JML_API JML_HELPER_DLL_EXPORT
#else
#define JML_API JML_HELPER_DLL_IMPORT
#endif // JML_DLL_EXPORTS
#define JML_LOCAL JML_HELPER_DLL_LOCAL
#else // JML_DLL is not defined: this means JML is a static lib.
#define JML_API
#define JML_LOCAL
#endif // JML_DLL

#endif
