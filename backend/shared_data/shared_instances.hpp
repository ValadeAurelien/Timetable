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
private:
    std::string name;
    room_id id;
    unsigned char capacity;
    bool projector;
    room_type_t room_type1,
                room_type2;
    board_type_t board_type;
};

class SharedPItem {
private:
    unsigned int duration;

};

class Teacher {

    int isHappyToWork(hour_t hour) const;
//    bool wantThisCourse(std::string course) const;

private:
    TimeTableWishes ttwishes;
    std::unordered_set<std::string> domain;
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
