#include "shared_data.hpp"

int Teacher::isHappyToWork(int hour) const {
    return this->wishes[hour];
}

bool Teacher::wantThisCourse(std::string course) const {
    return this->domain.find(course)
}
