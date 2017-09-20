#ifndef SPECIMEN_ALPHA_HEADER
#define SPECIMEN_ALPHA_HEADER

#include "abstract_classes/abstract_specimen.hpp"
#include "shared_data/shared_data.hpp"
#include "shared_data/shared_instances.hpp"
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "common/common_types.hpp"
#include <vector>


struct marks_t{
    float teacher_overlap = 0                ,
          room_overlap = 0                   ,
          eqpupils_overlap = 0               ,
          course_wrong_number = 0            ,
          room_wrong_number = 0              ,
          inappropriate_room = 0             ,
          eqpupils_spread = 0                ,
          eqpupils_size_spread = 0           ,
          eqpupils_wrong_corecurriculum = 0  ,
          eqpupils_diff = 0                  ,
          teachers_hours_violation = 0       , 
          establishment_hours_violation = 0  ,
          pitem_hours_violation = 0          ,
          room_hours_violation = 0           ;
};

enum operation_t {
    CHROOM, CHHOUR, CHTEACHER, CHEQPUPILS
};

struct proba_law_t{
    float ch_room=0,
          ch_hour=0,
          ch_teacher=0,
          ch_eqpupils=0;
};

class SpecimenAlpha : public AbstractSpecimen {
public:
    SpecimenAlpha(const SharedData& _SD);
    SpecimenAlpha(const SpecimenAlpha& SA) = default;
    ~SpecimenAlpha() = default;
    SpecimenAlpha& operator=(const SpecimenAlpha& SA);

    void evaluate();
    uchar mutateToChild(AbstractSpecimen *specimen, uchar min, uchar max); 
    uchar mutate(uchar min, uchar max); 

    const marks_t& getMarks() const;
    const proba_law_t& getProbaLaw() const;

private:

    void calcProbaLaw();
    operation_t chooseAndDoOperation();

    void changeRoom();
    void changeHour();
    void changeTeacher();
    void changeEqPupils();

    marks_t marks;
    static marks_t coefs;
    proba_law_t proba_law;
};

#endif
