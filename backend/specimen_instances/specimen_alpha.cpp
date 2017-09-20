#include "specimen_alpha.hpp"
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "common/common_types.hpp"
#include <cmath>
#define MAX(a, b)=((a)>(b)?(a):(b))

SpecimenAlpha::SpecimenAlpha(const SharedData& _SD) : AbstractSpecimen(_SD)
{

}

SpecimenAlpha& SpecimenAlpha::operator=(const SpecimenAlpha& SA)
{
    pitems = SA.getPItems();
    courses = SA.getCourses();
    marks = SA.getMarks();
    proba_law = SA.getProbaLaw();
    mark = SA.getMark();
}

void SpecimenAlpha::evaluate()
{
    marks_t m;
    teacher_id tid;

    for (auto const& course : courses){
        ShareCourseType& sharedscourse = shareddata.getSharedCourses().at(course.getSharedId());
        m.course_wrong_number += MAX(course.number - sharedcourse.number, 0 ) / sharedcourse.number;
    }

    for (auto const& p1 : pitems){
        SharedPItemType& sharedpitem = shareddata.getSharedPItem().at(p1.shared_pitem);
        CourseInstancesType& course = courses.at(p1.course);
        ShareCourseType& sharedscourse = shareddata.getSharedCourses().at(course.getSharedId());
        tid = course.teacher_id;
        Teacher& teacher = shareddata.getTeachers().at(tid);
        Room& room = shareddata.getRooms().at(p1.room);

        m.room_wrong_number += MAX(course.number - room.number, 0 ) / room.number;

        m.teachers_hours_violation += teacher.getTimeTableWishes().at(p1.hour);
        m.establishment_hours_violation += shareddata.getEstabTimeTableWishes().at(p1.hour);
        m.room_hours_violation += room.getTimeTableWishes().at(p1.hour);


        for (auto const& p2 : pitems){
            
        }
    }
}

uchar SpecimenAlpha::mutateToChild(AbstractSpecimen *_child, uchar min, uchar max)
{
    child = _child;
    *child = *this;
    return child->mutate(min, max);
}

const marks_t& SpecimenAlpha::getMarks() const { return marks; }
const proba_law_t& SpecimenAlpha::getProbaLaw() const { return proba_law; }

uchar SpecimenAlpha::mutate(uchar min, uchar max)
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
    float sum_p = p.ch_room + p.ch_hour + p.ch_teacher + p.ch_eqpupils;
    proba_law.ch_room = p.ch_room / ( sum_p );
    proba_law.ch_hour = p.ch_hour / ( sum_p );
    proba_law.ch_teacher = p.ch_teacher / ( sum_p );
    proba_law.ch_eqpupils = p.ch_eqpupils / ( sum_p );
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
    
    auto it = course_prov.getEqPupilsNb().begin();
    uchar eqpu_id = uniformDistrib(0, course_prov.getEqPupilsNb().size()-1);
    for (int i=0; i<eqpu_id; i++) it++;

    auto& eqpunb = *it;
    bool full = uniformDistrib(0, 1);
    if (full){
        course_dest.addEqPupils(eqpunb.first, eqpunb.second);
        course_prov.remEqPupils(eqpunb.first, eqpunb.second);
    }
    else {
        course_dest.addEqPupils(eqpunb.first, floor(eqpunb.second/2));
        course_prov.remEqPupils(eqpunb.first, floor(eqpunb.second/2));
    }
}

