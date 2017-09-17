#include "pitem_instance.hpp"
#include "course_instance.hpp"

PItemInstance::PItemInstance(){}
PItemInstance::~PItemInstance(){}

room_id PItemInstance::getClassroom() const { return classroom; }
hour_t PItemInstance::getHour() const { return hour; }
sharedpitem_id PItemInstance::getShared() const { return shared_pitem; }
courseinstance_id PItemInstance::getCourse() const { return course; }

void PItemInstance::setClassroom(room_id _classroom) { classroom = _classroom; }
void PItemInstance::setHour(hour_t _hour) { hour = _hour; }
void PItemInstance::setShared(sharedpitem_id _shared_pitem) { shared_pitem = _shared_pitem; }
void PItemInstance::setCourse(courseinstance_id _course) { course = _course; }
