//
// Created by mecha on 07.10.2022.
//

#include <io/Logger.h>

#ifdef DEBUG
#ifdef WIN32
#define DEBUGBREAK() __debugbreak()
#elif defined(__linux__)
#include <signal.h>
		#define DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
#endif
#else
#define DEBUGBREAK()
#endif

#ifdef DEBUG
#define ASSERT(x, msg) static_assert(x, msg);

#define RUNTIME_ASSERT(x, ...) if (!(x)) { \
    RUNTIME_ERR("Assertion failed : {0}", __VA_ARGS__); \
    DEBUGBREAK();                              \
    }

#define ENGINE_ASSERT(x, ...) if (!(x)) { \
    ENGINE_ERR("Assertion failed : {0}", __VA_ARGS__); \
    DEBUGBREAK();                             \
    }
#else
#define ASSERT(x, msg)
#define RUNTIME_ASSERT(x, ...)
#define ENGINE_ASSERT(x, ...)
#endif