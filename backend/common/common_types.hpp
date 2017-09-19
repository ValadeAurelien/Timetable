#ifndef COMMON_TYPES_HEADER
#define COMMON_TYPES_HEADER
#include <vector>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned char hour_t;

typedef std::vector<uchar> TimeTableWishes;

// 0 if not set

#define NO_TEACHER 0
#define NO_ROOM 0

typedef unsigned char teacher_id;
typedef unsigned char pupils_id;
typedef unsigned char room_id;

// can not be unset

typedef unsigned short sharedpitem_id;
typedef unsigned short sharedcourse_id;
typedef unsigned short piteminstance_id;
typedef unsigned short courseinstance_id;


#endif
