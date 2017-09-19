#include "shared_instances.hpp"

teacher_id Teacher::getId() const { 
    return id;
}

int Teacher::isHappyToWork(hour_t hour) const {
    return ttwishes.at(hour);
}

bool Teacher::wantsCourse(sharedcourse_id  course) const {
    return (courseswishes.count(course) > 0);
}
