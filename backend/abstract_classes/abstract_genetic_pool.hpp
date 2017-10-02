#ifndef ABSTRACT_GENETIC_POOL_HEADER
#define ABSTRACT_GENETIC_POOL_HEADER

#include <queue>

#include "abstract_specimen.hpp"
#include "shared_data/shared_data.hpp"


class AbstractGeneticPool
{
public:
  AbstractGeneticPool(unsigned nb_spe, const SharedData& _SD);
  ~AbstractGeneticPool() = default;
  virtual void evolve(unsigned int generations_number) = 0;
protected:
  virtual void popAllocation() = 0;
  
  const SharedData& SD;
  std::vector<AbstractSpecimen*> specimens_pool; // Collection of specimen
  std::priority_queue<AbstractSpecimen*> saved_specimens; // Best specimen recorded
};


#endif
