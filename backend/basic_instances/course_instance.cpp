#include "course_instance.hpp"

teacher_id CourseInstance::getTeacher() const { 
    return teacher; 
}

const EqPupilsNbType& CourseInstance::getEqPupilsNb() const { 
    return eqpupilsnb; 
}

ushort CourseInstance::getNumber() const { 
    return number; 
}

sharedcourse_id CourseInstance::getSharedId() const { 
    return shared_id; 
}

void CourseInstance::setTeacher(teacher_id _teacher) { 
    teacher = _teacher; 
}

void CourseInstance::setEqPupilsNb(const EqPupilsNbType& _eqpupilsnb) { 
    eqpupilsnb = _eqpupilsnb;
    number = 0;
    for (auto const& eqp : eqpupilsnb) number += eqp.second;
}

void CourseInstance::setShared(sharedcourse_id _shared_id) { 
    shared_id = _shared_id;
}

void CourseInstance::addEqPupils(eqpupils_id pid, ushort _number) { 
    eqpupilsnb[pid] += _number;
    number += _number;
}

void CourseInstance::remEqPupils(eqpupils_id pid, ushort _number) { 
    eqpupilsnb[pid] -= _number;
    number -= _number;
}
