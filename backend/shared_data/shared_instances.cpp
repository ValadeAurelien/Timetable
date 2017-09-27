#include "shared_instances.hpp"

uchar Room::getNumber() const { 
    return number; 
}

const TimeTableWishesType& Room::getTimeTableWishes() const{
    return ttwishes;
}

ushort Room::compare(const Room& room) const{
    return 0;
}

const TimeTableWishesType& SharedPItem::getTimeTableWishes() const{
    return ttwishes;
}

teacher_id Teacher::getId() const { 
    return id;
}

const TimeTableWishesType& Teacher::getTimeTableWishes() const {
    return ttwishes;
}

bool Teacher::wantsCourse(sharedcourse_id  course) const {
    return (courseswishes.count(course) > 0);
}

uchar EqPupils::compareEqPupils(const EqPupils& eqp) const {
    return 0;
}

uchar EqPupils::compareCoreCurriculum(const CoreCurriculum& eqp) const {
    return 0;
}

ushort SharedCourse::getNumber() const {
    return number;
}

room_id SharedCourse::getRoom() const {
    return room;
}

teacher_id SharedCourse::getTeacher() const {
    return teacher;
}

corecurriculum_id SharedCourse::getCoreCurriculum() const {
    return corecurriculum;
}
