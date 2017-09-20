#include "course_instance.hpp"

teacher_id CourseInstance::getTeacher() const { return teacher; }
const EqPupilsNbType& CourseInstance::getEqPupilsNb() const { return eqpupilsnb; }
sharedcourse_id CourseInstance::getSharedId() const { return shared_id; }

void CourseInstance::setTeacher(teacher_id _teacher) { teacher = _teacher; }
void CourseInstance::setPupils(const EqPupilsNbType& _eqpupilsnb) { eqpupilsnb = _eqpupilsnb; }
void CourseInstance::setShared(sharedcourse_id _shared_id) { shared_id = _shared_id; }

void CourseInstance::addEqPupils(pupils_id pid, ushort number) { eqpupilsnb[pid] += number; }

void CourseInstance::remEqPupils(pupils_id pid, ushort number) { eqpupilsnb[pid] -= number;}
