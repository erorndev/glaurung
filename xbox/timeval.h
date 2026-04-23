#pragma once
#include <windows.h>

struct timeval {
  long tv_sec;
  long tv_usec;
};

inline int gettimeofday(struct timeval *tp, void *) {
  ULONGLONG t;
  KeQuerySystemTime((LARGE_INTEGER *)&t);
  t -= 116444736000000000ULL;
  tp->tv_sec  = (long)(t / 10000000ULL);
  tp->tv_usec = (long)((t % 10000000ULL) / 10);
  return 0;
}