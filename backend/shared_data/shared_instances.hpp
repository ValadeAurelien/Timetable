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
private:
    unsigned int duration;

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

class Pupils {
    /* Faudra voir comment on definit les eleves....
    je propose éventuellement avec des string par type comme ça c'est dynamique avec la db plutôt qu'avec des defines
    qui emppècheraient la dynamicité des matières avec la db
     */

};

class SharedCourse {

private:
    std::string level;
    unsigned short number;
    teacher_id teacher;
    room_id room;
};

#endif
