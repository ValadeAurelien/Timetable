#include "course_instance.hpp"

teacher_id CourseInstance::getTeacher() const { return teacher; }
const EquivPupilsNb& CourseInstance::getPupils() const { return pupils; }
sharedcourse_id CourseInstance::getShared() const { return shared; }

void CourseInstance::setTeacher(teacher_id _teacher) { teacher = _teacher; }
void CourseInstance::setPupils(const EquivPupilsNb& _pupils) { pupils = _pupils; }
void CourseInstance::setShared(sharedcourse_id _shared) { shared = _shared; }

void CourseInstance::addPupils(const pupils_id _pupils, const unsigned short number) { pupils[_pupils] += number; }
