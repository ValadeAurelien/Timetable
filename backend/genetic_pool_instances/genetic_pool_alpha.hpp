#ifndef GENETIC_POOL_ALPHA_HEADER
#define GENETIC_POOL_ALPHA_HEADER
#include "abstract_classes/abstract_genetic_pool.hpp"
#include "specimen_instances/specimen_alpha.hpp"
#include <vector>

struct MarkSpePt {
     mark_t mark;
     AbstractSpecimen* spe_pt;

     MarkSpePt() = default;
     MarkSpePt(mark_t _mark, AbstractSpecimen*  _spe_pt);
     bool operator<(const MarkSpePt& msp);
};

class GeneticPoolAlpha : public AbstractGeneticPool
{
public:
     GeneticPoolAlpha(unsigned nb_spe, marks_t _coefs, const SharedData& _SD);
     void evolve(unsigned int generations_number);
private:
     void popAllocation();
     void calcAndSortMarks();
     mark_t calcMark(AbstractSpecimen* spe_pt) const;
     void calcMinMaxMutations(unsigned gene, unsigned generations_number);
     
     marks_t coefs;
     unsigned min_mut, max_mut;
     static const unsigned nb_children_per_parent = 10;
     std::vector<MarkSpePt> sorted_by_mark; 
};

#endif
