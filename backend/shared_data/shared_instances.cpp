#include "shared_instances.hpp"

int Teacher::isHappyToWork(hour_t hour) const {
    return wishes.at(hour);
}

//bool Teacher::wantThisCourse(std::string course) const {
//    return this->domain.find(course)
//
