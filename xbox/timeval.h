#pragma once
#include <windows.h>

struct timeval {
  long tv_sec;
  long tv_usec;
};

inline int gettimeofday(struct timeval *tp, void *tzp) {
  ULONGLONG t;
  KeQuerySystemTime((LARGE_INTEGER *)&t);
  t /= 10000; // convert to milliseconds
  tp->tv_sec = t / 1000;
  tp->tv_usec = (t % 1000) * 1000;
  return 0;
}