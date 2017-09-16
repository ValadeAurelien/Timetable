#include "abstract_specimen.hpp"


bool AbstractSpecimen::operator<=(AbstractSpecimen const &specimen1, AbstractSpecimen const &specimen2) {

    return specimen1.isBetterThan(specimen2);

}

float AbstractSpecimen::getMark() {
    return this->mark;
};

Classroom *PItemInstance::getClassroom() const {
    return classroom;
}

void PItemInstance::setClassroom(Classroom *classroom) {
    PItemInstance::classroom = classroom;
}

unsigned int PItemInstance::getHour() const {
    return hour;
}

void PItemInstance::setHour(unsigned int hour) {
    PItemInstance::hour = hour;
}

PItemTemplate *PItemInstance::getTempl() const {
    return templ;
}

void PItemInstance::setTempl(PItemTemplate *templ) {
    PItemInstance::templ = templ;
}

CourseInstance *PItemInstance::getCourse() const {
    return course;
}

void PItemInstance::setCourse(CourseInstance *course) {
    PItemInstance::course = course;
}

Teacher *CourseInstance::getTeacher() const {
    return teacher;
}

void CourseInstance::setTeacher(Teacher *teacher) {
    CourseInstance::teacher = teacher;
}

const std::map<unsigned int, unsigned int> &CourseInstance::getPupils() const {
    return pupils;
}

void CourseInstance::setPupils(const std::map<unsigned int, unsigned int> &pupils) {
    CourseInstance::pupils = pupils;
}

CourseTemplate *CourseInstance::getTempl() const {
    return templ;
}

void CourseInstance::setTempl(CourseTemplate *templ) {
    CourseInstance::templ = templ;
}
