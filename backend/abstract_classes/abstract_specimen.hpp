#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER

class AbstractSpecimen
{

public:
  virtual float rate() = 0;
  virtual float mutate(AbstractSpecimen *specimen) = 0;

  virtual bool isBetterThan(AbstractSpecimen const& specimen) = 0;

  bool operator<=(AbstractSpecimen const& specimen1, AbstractSpecimen const& specimen2);

protected:
  std::vector<PITemInstance> pitems;
  std::vector<CoursesInstance> courses;
  float mark = 0;

private:

};


#endif
