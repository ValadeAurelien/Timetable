#include "shared_instances.hpp"

int Teacher::isHappyToWork(hout_t hour) const {
    return wishes[hour];
}

//bool Teacher::wantThisCourse(std::string course) const {
//    return this->domain.find(course)
//
