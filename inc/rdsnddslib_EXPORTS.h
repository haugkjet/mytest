
#ifndef shared_EXP_H
#define shared_EXP_H

#ifdef rdsnddslib_EXPORTS_BUILT_AS_STATIC
#  define shared_EXP
#  define RDSNDDSLIB_NO_EXPORT
#else
#  ifndef shared_EXP
#    ifdef rdsnddslib_EXPORTS
        /* We are building this library */
#      define shared_EXP __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define shared_EXP __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef RDSNDDSLIB_NO_EXPORT
#    define RDSNDDSLIB_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef RDSNDDSLIB_DEPRECATED
#  define RDSNDDSLIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef RDSNDDSLIB_DEPRECATED_EXPORT
#  define RDSNDDSLIB_DEPRECATED_EXPORT shared_EXP RDSNDDSLIB_DEPRECATED
#endif

#ifndef RDSNDDSLIB_DEPRECATED_NO_EXPORT
#  define RDSNDDSLIB_DEPRECATED_NO_EXPORT RDSNDDSLIB_NO_EXPORT RDSNDDSLIB_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define RDSNDDSLIB_NO_DEPRECATED
#endif

#endif
