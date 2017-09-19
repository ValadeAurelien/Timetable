#include "specimen_alpha.hpp"
#include <cmath>

SpecimenAlpha::SpecimenAlpha(const SharedData& _SD) : AbstractSpecimen(_SD)
{

}

void SpecimenAlpha::evaluate()
{
    
}

uchar SpecimenAlpha::mutate(AbstractSpecimen *_child, uchar min, uchar max)
{
    uchar nbmut_todo = (uchar) uniformDistrib(min, max) ;
    calcProbaLaw();
    for (uchar nbmut=0; nbmut<nbmut_todo; nbmut++)
        chooseAndDoOperation();
    return nbmut_todo;
}

void SpecimenAlpha::calcProbaLaw()
{

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
        changePupils();
        return CHPUPILS;
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

void SpecimenAlpha::changePupils()
{

}

