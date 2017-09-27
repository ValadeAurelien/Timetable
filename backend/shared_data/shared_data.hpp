#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER
#include "common/common_types.hpp"
#include "shared_data/shared_instances.hpp"

#include <vector>
#include "sqlite3.h"

typedef std::vector<Teacher> TeachersType;
typedef std::vector<Room> RoomsType;
typedef std::vector<EqPupils> EqPupilssType;
typedef std::vector<SharedPItem> SharedPItemsType;
typedef std::vector<SharedCourse> SharedCoursesType;
typedef std::vector<CoreCurriculum> CoreCurriculumsType;

class SharedData
{
  public:
    SharedData();
    ~SharedData();

    int establishConn(char *filepath);

    int loadTeachers();
    int loadRooms();
    int loadEqPupilss();
    int loadSharedPItems();
    int loadSharedCourses();

    int reIndexTeachers();
    int reIndexRooms();
    int reIndexEqPupilss();
    int reIndexSharedPItems();
    int reIndexSharedCourses();

    std::vector<int> buildReIndexVector(const char *sql_request);
    int execRequest(const char *sql_request); // Exec a request wich do not expect any return

    const TeachersType& getTeachers() const;
    const RoomsType& getRooms() const;
    const EqPupilssType& getEqPupilss() const;
    const SharedPItemsType& getSharedPItems() const;
    const SharedCoursesType& getSharedCourses() const;
    const CoreCurriculumsType& getCoreCurriculums() const;
    const hour_t getNbHoursPerWeek() const;
    const room_id getNbRooms() const;
    const TimeTableWishesType& getEstabTimeTableWishes() const;

  private:

    sqlite3 *db = 0;
    char *err = 0;

    TeachersType Teachers;
    RoomsType Rooms;
    EqPupilssType EqPupilss;
    SharedPItemsType SharedPItems;
    SharedCoursesType SharedCourses;
    CoreCurriculumsType CoreCurriculums;
    hour_t nb_hours_per_week;
    room_id nb_rooms;
    TimeTableWishesType EstabTimeTableWishes;
};


#endif
