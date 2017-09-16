#ifndef MARK_HEADER
#define MARK_HEADER

struct Mark
{
  float x;
  bool operator<(const Mark& m) const ;
};

#endif
