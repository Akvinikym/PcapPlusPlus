#ifndef PCAPPLUSPLUS_TIMESPECWIN_H
#define PCAPPLUSPLUS_TIMESPECWIN_H

#include <time.h>

/// this file defines structure timespec for storing nsec precision and conversion macroses,
/// as Windows does not define either of them

#if defined(WIN32) || defined(WINx64)

struct timespec {
	time_t tv_sec;
	long tv_nsec;
};

#define TIMEVAL_TO_TIMESPEC(tv, ts) {                               \
	(ts)->tv_sec = (tv)->tv_sec;                                    \
	(ts)->tv_nsec = (tv)->tv_usec * 1000;                           \
}
#define TIMESPEC_TO_TIMEVAL(tv, ts) {                               \
	(tv)->tv_sec = (ts)->tv_sec;                                    \
	(tv)->tv_usec = (ts)->tv_nsec / 1000;                           \
}

#endif

#endif //PCAPPLUSPLUS_TIMESPECWIN_H
