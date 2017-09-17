#ifndef ABSTRACT_GENETIC_POOL_HEADER
#define ABSTRACT_GENETIC_POOL_HEADER

#include <queue>

#include "abstract_specimen.hpp"


class AbstractGeneticPool
{
public:
  AbstractGeneticPool(const SharedData& _SD);
  ~AbstractGeneticPool() = default;
  virtual void evolve(unsigned int generations_number) = 0;
protected:
  virtual void popAllocation() = 0;
  
  const SharedData& SD;
  std::vector<AbstractSpecimen*> specimenPool; // Collection of specimen
  std::priority_queue<AbstractSpecimen*> savedSpecimen; // Best specimen recorded
};


#endif
