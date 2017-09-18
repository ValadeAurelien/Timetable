#ifndef SPECIMEN_ALPHA_HEADER
#define SPECIMEN_ALPHA_HEADER

#include "abstract_classes/abstract_specimen.hpp"
#include "shared_data/shared_data.hpp"
#include "shared_data/shared_intances.hpp"
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "common/common_types.hpp"
#include <vector>


struct marks_t{
    float teacher_overlap = 0                 ,
          room_overlap = 0                    ,
          simpupils_overlap = 0               ,
          course_wrong_number = 0             ,
          room_wrong_number = 0               ,
          simpupils_spread = 0                ,
          simpupils_size_spread = 0           ,
          simpupils_corecurriculum_corres = 0 ,
          simpupils_prox = 0                  ,
          teachers_hours_violations = 0       , 
          establishment_hours_violations = 0  ,
          pitem_hours_violations = 0          ,
          room_hours_violations = 0           ;
};

enum operation_t {
    CHROOM, CHHOUR, CHTEACHER, CHPUPILS
};

struct proba_law_t{
    float ch_room,
          ch_hour,
          ch_teacher,
          ch_pupils;
};

class SpecimenAlpha : public AbstractSpecimen {
public:
    SpecimenAlpha(const SharedData& _SD);
    ~SpecimenAlpha() = default;
    void evaluate() = 0;
    uchar mutate(AbstractSpecimen *specimen, uchar min, uchar max) = 0; 
private:
    void calcProbaLaw();
    operation_t chooseAndDoOperation();
    void changeRoom();
    void changeHour();
    void changeTeacher();
    void changePupils();
    marks_t marks;
    proba_law_t proba_law;
};

#endif
