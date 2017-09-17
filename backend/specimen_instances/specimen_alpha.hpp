#ifndef SPECIMEN_ALPHA_HEADER
#define SPECIMEN_ALPHA_HEADER

#include "abstract_classes/abstract_spacimen.hpp"
#include "shared_data/shared_data.hpp"
#include "shared_data/shared_intances.hpp"
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "common/common_types.hpp"
#include <vector>

class SpecimenAlpha : public AbstractSpecimen
{
public:
    SpecimenAlpha(const SharedData& _SD);
    ~SpecimenAlpha() = default;
    void evaluate() = 0;
    uchar mutate(AbstractSpecimen *specimen, uchar min, uchar max) = 0; 
private:
    
};
#endif
