#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER


#include <map>
#include <vector>

class PItemInstance {
    PItemInstance();

    ~PItemInstance();


public:
    Classroom *getClassroom() const;

    void setClassroom(Classroom *classroom);

    unsigned int getHour() const;

    void setHour(unsigned int hour);

    PItem *getTempl() const;

    void setTempl(PItem *templ);

    CourseInstance *getCourse() const;

    void setCourse(CourseInstance *course);

private:
    Classroom *classroom;
    unsigned int hour;
    PItem *templ;
    CourseInstance* course;

};

class CourseInstance {
public:
    Teacher *getTeacher() const;

    void setTeacher(Teacher *teacher);

    const std::map<unsigned int, unsigned int> &getPupils() const;

    void setPupils(const std::map<unsigned int, unsigned int> &pupils);

    CourseTemplate *getTempl() const;

    void setTempl(CourseTemplate *templ);

private:
    Teacher *teacher;
    std::map<unsigned int, unsigned int> pupils;
    CourseTemplate *templ;

};


class AbstractSpecimen {

public:
    AbstractSpecimen();

    ~AbstractSpecimen();

    virtual float rate() = 0;

    virtual float mutate(AbstractSpecimen *specimen, unsigned int min = 0, unsigned int max = 10) = 0;

    virtual bool isBetterThan(AbstractSpecimen const &specimen) const = 0;

    bool operator<=(AbstractSpecimen const &specimen1, AbstractSpecimen const &specimen2);

    float getMark();

protected:
    std::vector<PItemInstance> pitems;
    std::vector<CourseInstance> courses;
    float mark = 0;

private:

};


#endif
