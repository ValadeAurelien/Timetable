#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER
#include "common/common_types.hpp"

typedef vector<Teacher> TeachersType;
typedef vector<Room> RoomsType;
typedef vector<Pupils> PupilssType;
typedef vector<SharedPitem> SharedPItemsType;
typedef vector<SharedCourse> SharedCoursesType;

class SharedData
{
  public:
    SharedData();
    ~SharedData();

    const TeachersType& getSharedTeachers() const;
    const RoomsType& getSharedRooms() const;
    const PupilssType& getSharedPupilss() const;
    const SharedPItemsType& getSharedPItems() const;
    const SharedCoursesType& getSharedCourses() const;
    const hour_t getNbHoursPerWeek() const;

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
