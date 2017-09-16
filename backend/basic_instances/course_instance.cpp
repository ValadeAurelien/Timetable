#include "course_instance.hpp"

const Teacher* CourseInstance::getTeacher() const { return teacher; }
const EquivPupilsNb& CourseInstance::getPupils() const { return pupils; }
const CourseTemplate& CourseInstance::getTempl() const { return templ; }

void CourseInstance::setTeacher(const Teacher* _teacher) { teacher = _teacher; }
void CourseInstance::setPupils(const equiv_pupils_nb_t& _pupils) { pupils = _pupils; }
void CourseInstance::setTempl(const CourseTemplate* _templ) { templ = _templ };
