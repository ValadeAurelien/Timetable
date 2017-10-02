#include "abstract_genetic_pool.hpp"

AbstractGeneticPool::AbstractGeneticPool(unsigned nb_spe, const SharedData& _SD) : SD(_SD), specimens_pool(nb_spe), saved_specimens()
{
     
}

