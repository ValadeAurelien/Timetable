#include "shared_instances.hpp"

const Room::TimeTableWishesType& getTimeTableWishes() const{
    return ttwishes;
}

ushort Room::compare(const Room& room) const{
    return 0;
}

const SharedPItem::TimeTableWishesType& getTimeTableWishes() const{
    return ttwishes;
}

teacher_id Teacher::getId() const { 
    return id;
}

int Teacher::isHappyToWork(hour_t hour) const {
    return ttwishes.at(hour);
}

bool Teacher::wantsCourse(sharedcourse_id  course) const {
    return (courseswishes.count(course) > 0);
}
