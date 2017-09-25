#ifndef SHARED_INSTANCES_HEADER
#define SHARED_INSTANCES_HEADER

#include <string>
#include <map>
#include <unordered_set>
#include "common/common_types.hpp"

enum room_type_t {
    LAB_INGE=1, LAB_BIO, LAB_PHY, LAB_CHEMI, C_INGE, C_BIO, C_PHY, C_CHEMI, LAB
};

enum board_type_t {
    W_BOARD, B_BOARD
};

class Room {
public: 
    const TimeTableWishesType& getTimeTableWishes() const;
    ushort compare(const Room& room) const;

private:
    std::string name;
    room_id id;
    uchar number;
    bool projector;
    room_type_t room_type1,
                room_type2;
    board_type_t board_type;
    TimeTableWishesType ttwishes;
};

class SharedPItem {
public:
    const TimeTableWishesType& getTimeTableWishes() const;
private:
    unsigned int duration;
    TimeTableWishesType ttwishes;
};

class Teacher {

public:
    teacher_id getId() const;

    const TimeTableWishesType& getTimeTableWishes() const;
    bool wantsCourse(sharedcourse_id course) const;

private:
    teacher_id id;
    TimeTableWishesType ttwishes;
    std::unordered_set<sharedcourse_id> courseswishes;
};

class EqPupils {
public:


};

class SharedCourse {

private:
    std::string level;
    ushort number;
    teacher_id teacher;
    room_id room;
};

#endif
