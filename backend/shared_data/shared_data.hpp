#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER
#include "common/common_types.hpp"
#include "shared_data/shared_instances.hpp"
#include <vector>

typedef std::vector<Teacher> TeachersType;
typedef std::vector<Room> RoomsType;
typedef std::vector<Pupils> PupilssType;
typedef std::vector<SharedPItem> SharedPItemsType;
typedef std::vector<SharedCourse> SharedCoursesType;

class SharedData
{
  public:
    SharedData();
    ~SharedData();

    const TeachersType& getTeachers() const;
    const RoomsType& getRooms() const;
    const PupilssType& getPupilss() const;
    const SharedPItemsType& getSharedPItems() const;
    const SharedCoursesType& getSharedCourses() const;
    const hour_t getNbHoursPerWeek() const;
    const room_id getNbRooms() const;

  private:
    TeachersType Teachers;
    RoomsType Rooms;
    PupilssType Pupilss;
    SharedPItemsType SharedPItems;
    SharedCoursesType SharedCourses;
    hour_t nb_hours_per_week;
    room_id nb_rooms;
};


#endif
