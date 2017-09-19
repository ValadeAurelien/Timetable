#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER

#include <vector>

#include "shared_data/shared_instances.hpp"

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

    const TeachersType& getSharedTeachers() const;
    const RoomsType& getSharedRooms() const;
    const PupilssType& getSharedPupilss() const;
    const SharedPItemsType& getSharedPItems() const;
    const SharedCoursesType& getSharedCourses() const;

  private:
    TeachersType Teachers;
    RoomsType Rooms;
    PupilssType Pupilss;
    SharedPItemsType SharedPItems;
    SharedCoursesType SharedCourses;
};


#endif
