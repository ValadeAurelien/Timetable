#include "specimen_alpha.hpp"
#include <cmath>

SpecimenAlpha(const SharedData& _SD) : AbstractSpecimen(_SD)
{

}

void evaluate()
{
    
}

uchar mutate(AbstractSpecimen *_child, uchar min, uchar max)
{
    uchar nbmut_todo = (uchar) uniformDistrib(min, max) ;
    calcProbaLaw();
    for (uchar nbmut=0; nbmut<nbmu_todo; nbmut++)
        chooseAndDoOperation();
    return nbmut_todo;
}

void calcProbaLaw()
{

}

operation_t chooseAndDoOperation()
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
        changePupils();
        return CHPUPILS;
    }
}


void changeRoom()
{
    ushort to_mod = (ushort) uniformDistrib(0, pitems.size()-1);
    pitems[to_mod].room = (uchar) uniformDistrib(0, shareddata.getNbRooms());
}

void changeHour()
{
    ushort to_mod = (ushort) uniformDistrib(0, pitems.size()-1);
    pitems[to_mod].hour = (uchar) uniformDistrib(0, shareddata.getNbHoursPerWeek());
}

void changeTeacher()
{
    ushort to_mod = (ushort) uniformDistrib(0, pitems.size()-1);
    course_id course = courses[pitems[to_mod].course].id;
    std::vector<teacher_id> corres_teachers;
    for (auto const& T : shareddata.getTeachers())
        if (T.wantCourse(course)) corres_teachers.push_back(T.id);
    pitems[to_mod].teacher = corres_teachers[uniformDistrib(0, corres_teachers.size()-1)];
}

void changePupils()
{

}

