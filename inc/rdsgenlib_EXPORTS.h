
#ifndef shared_EXP_H
#define shared_EXP_H

#ifdef rdsgenlib_EXPORTS_BUILT_AS_STATIC
#  define shared_EXP
#  define RDSGENLIB_NO_EXPORT
#else
#  ifndef shared_EXP
#    ifdef rdsgenlib_EXPORTS
        /* We are building this library */
#      define shared_EXP __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define shared_EXP __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef RDSGENLIB_NO_EXPORT
#    define RDSGENLIB_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef RDSGENLIB_DEPRECATED
#  define RDSGENLIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef RDSGENLIB_DEPRECATED_EXPORT
#  define RDSGENLIB_DEPRECATED_EXPORT shared_EXP RDSGENLIB_DEPRECATED
#endif

#ifndef RDSGENLIB_DEPRECATED_NO_EXPORT
#  define RDSGENLIB_DEPRECATED_NO_EXPORT RDSGENLIB_NO_EXPORT RDSGENLIB_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define RDSGENLIB_NO_DEPRECATED
#endif

#endif
