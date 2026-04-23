#pragma once
#include <stdio.h>
#include <string>

namespace std {

class XboxStreamBuf {
public:
  XboxStreamBuf *pubsetbuf(char *, size_t) { return this; }
};

class XboxOStream {
  XboxStreamBuf _buf;

public:
  bool capturing = false;
  string captured;

  XboxStreamBuf *rdbuf() { return &_buf; }

  XboxOStream &operator<<(const char *val) {
    if (capturing) captured += val; else printf("%s", val);
    return *this;
  }
  XboxOStream &operator<<(char val) {
    if (capturing) captured += val; else printf("%c", val);
    return *this;
  }
  XboxOStream &operator<<(bool val) {
    if (capturing) captured += (val ? "1" : "0"); else printf("%d", val);
    return *this;
  }
  XboxOStream &operator<<(int val) {
    if (capturing) captured += to_string(val); else printf("%d", val);
    return *this;
  }
  XboxOStream &operator<<(unsigned int val) {
    if (capturing) captured += to_string(val); else printf("%u", val);
    return *this;
  }
  XboxOStream &operator<<(long val) {
    if (capturing) captured += to_string(val); else printf("%ld", val);
    return *this;
  }
  XboxOStream &operator<<(long long val) {
    if (capturing) captured += to_string(val); else printf("%lld", val);
    return *this;
  }
  XboxOStream &operator<<(unsigned long val) {
    if (capturing) captured += to_string(val); else printf("%lu", val);
    return *this;
  }
  XboxOStream &operator<<(unsigned long long val) {
    if (capturing) captured += to_string(val); else printf("%llu", val);
    return *this;
  }
  XboxOStream &operator<<(float val) {
    if (capturing) captured += to_string(val); else printf("%f", val);
    return *this;
  }
  XboxOStream &operator<<(double val) {
    if (capturing) captured += to_string(val); else printf("%f", val);
    return *this;
  }
  XboxOStream &operator<<(const string &val) {
    if (capturing) captured += val; else printf("%s", val.c_str());
    return *this;
  }
  XboxOStream &operator<<(ostream &(*)(ostream &)) {
    if (capturing) captured += "\n"; else printf("\n");
    return *this;
  }
};

class XboxIStream {
  XboxStreamBuf _buf;
public:
  XboxStreamBuf *rdbuf() { return &_buf; }
};

inline XboxOStream cout;
inline XboxIStream cin;

inline bool getline(XboxIStream &, string &str) {
  str = "";
  return false;
}

}