#include "pitem_instance.hpp"
#include "course_instance.hpp"

PItemInstance(){}
~PItemInstance(){}

const Classroom& PItemInstance::getClassroom() const { return classroom; }
hour_t PItemInstance::getHour() const { return hour; }
const PItemTemplate* PItemInstance::getTempl() const { return templ; }
const CourseInstance* PItemInstance::getCourse() const { return course; }

void PItemInstance::setClassroom(const Classroom* _classroom) { classroom = _classroom; }
void PItemInstance::setHour(hour_t _hour) { hour = _hour; }
void PItemInstance::setTempl(const PItemTemplate* _templ) { templ = _templ; }
void PItemInstance::setCourse(const CourseInstance* _course) { course = _course; }
