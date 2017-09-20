#include "specimen_alpha.hpp"
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "common/common_types.hpp"
#include <cmath>

SpecimenAlpha::SpecimenAlpha(const SharedData& _SD) : AbstractSpecimen(_SD)
{

}

void SpecimenAlpha::evaluate()
{
   marks_t m;

}

uchar SpecimenAlpha::mutateToChild(AbstractSpecimen *_child, uchar min, uchar max)
{
    child = _child;
    *child = *this;
    return child->mutate(min, max);
}

uchar SpecimenAlpha::mutateToChild(uchar min, uchar max)
{
    uchar nbmut_todo = (uchar) uniformDistrib(min, max) ;
    calcProbaLaw();
    for (uchar nbmut=0; nbmut<nbmut_todo; nbmut++)
        chooseAndDoOperation();
    return nbmut_todo;
}

void SpecimenAlpha::calcProbaLaw()
{
    proba_law_t p;
    p.ch_room = marks.room_overlap
              + marks.room_wrong_number
              + marks.inappropriate_room
              + marks.room_hours_violation;
    p.ch_hour = marks.teacher_overlap
              + marks.room_overlap
              + marks.eqpupils_overlap
              + marks.teachers_hours_violation
              + marks.establishment_hours_violation
              + marks.pitem_hours_violation
              + marks.room_hours_violation;
    p.ch_teacher = marks.teacher_overlap
                 + marks.teachers_hours_violation;
    p.ch_eqpupils = marks.eqpupils_overlap
                  + marks.course_wrong_number
                  + marks.eqpupils_spread
                  + marks.eqpupils_size_spread
                  + marks.eqpupils_wrong_corecurriculum
                  + marks.eqpupils_diff;
    float sum_p = p.ch_room + p.ch_hour + p.ch_teacher + p.ch_pupils;
    proba_law.ch_room = p.ch_room / ( sum_p );
    proba_law.ch_hour = p.ch_hour / ( sum_p );
    proba_law.ch_teacher = p.ch_teacher / ( sum_p );
    proba_law.ch_pupils = p.ch_pupils / ( sum_p );
}

operation_t SpecimenAlpha::chooseAndDoOperation()
{
    float val = (float) rand()/RAND_MAX; //on découpe un segment en 4 portions inégales de taille p_i tq \sum p_i = 1
    if (val<proba_law.ch_room){
        changeRoom();
        return CHROOM;
    }
    val -= proba_law.ch_room;
    if (val<proba_law.ch_hour){
        changeHour();
        return CHHOUR;
    }
    val -= proba_law.ch_hour;
    if (val<proba_law.ch_teacher){
        changeTeacher();
        return CHTEACHER;
    }
    else {
        changeEqPupils();
        return CHEQPUPILS;
    }
}


void SpecimenAlpha::changeRoom()
{
    ushort to_mod = (ushort) uniformDistrib(0, pitems.size()-1);
    pitems[to_mod].room = (uchar) uniformDistrib(0, shareddata.getNbRooms());
}

void SpecimenAlpha::changeHour()
{
    ushort to_mod = (ushort) uniformDistrib(0, pitems.size()-1);
    pitems[to_mod].hour = (uchar) uniformDistrib(0, shareddata.getNbHoursPerWeek());
}

void SpecimenAlpha::changeTeacher()
{
    ushort to_mod = (ushort) uniformDistrib(0, courses.size()-1);
    sharedcourse_id sharedcourse = courses[to_mod].getSharedId();
    std::vector<teacher_id> corres_teachers;
    for (auto const& T : shareddata.getTeachers())
        if (T.wantsCourse(sharedcourse)) corres_teachers.push_back(T.getId());
    courses[to_mod].setTeacher( corres_teachers[uniformDistrib(0, corres_teachers.size()-1)] );
}

void SpecimenAlpha::changeEqPupils()
{
    ushort c_prov = (ushort) uniformDistrib(0, courses.size()-1),
           c_dest = (ushort) uniformDistrib(0, courses.size()-1);
    CourseInstance& course_prov = courses[c_prov],
                  & course_dest = courses[c_dest];
    auto& eqpunb = courses_prov.pupils.at(uniformDistrib(0, course_prov.pupils.size()-1));
    bool full = uniformDistrib(0, 1);
    if (full){
        course_dest.add_eqpunb(eqpunb.first, eqpunb.second);
        course_prov.rem_eqpunb(eqpunb.first, eqpunb.second);
    }
    else {
        course_dest.add_eqpunb(eqpunb.first, floor(eqpunb.second/2));
        course_prov.rem_eqpunb(eqpunb.first, floor(eqpunb.second/2));
    }
}

