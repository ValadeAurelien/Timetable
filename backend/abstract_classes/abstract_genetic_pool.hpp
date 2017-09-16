#ifndef ABSTRACT_GENETIC_POOL_HEADER
#define ABSTRACT_GENETIC_POOL_HEADER

#include <queue>

#include "abstract_specimen.hpp"


class AbstractGeneticPool
{

public:
  virtual void evolve(unsigned int generations_number) = 0;


protected:
  virtual void popAllocation() = 0;


private:
  std::vector<AbstractSpecimen> specimenPool;
  std::priority_queue<AbstractSpecimen> savedSpecimen;


};


#endif
