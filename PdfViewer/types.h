#ifndef TYPES_H
#define TYPES_H
#ifndef socktype

#ifdef _WIN32
#define socktype SOCKET
#else
#define socktype int
#endif

#endif

#ifndef sockaddrLen

#ifdef _WIN32
#define sockaddrLen int
#else
#define sockaddrLen socklen_t
#endif

#endif
#endif // TYPES_H
