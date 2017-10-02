#include "genetic_pool_alpha.hpp"
#include "specimen_instances/specimen_alpha.hpp"
#include <algorithm>
#include <cmath>

MarkSpePt::MarkSpePt(mark_t _mark, AbstractSpecimen* _spe_pt) : mark(_mark), spe_pt(_spe_pt)
{
     
}

bool MarkSpePt::operator<(const MarkSpePt& msp)
{
     return (mark<msp.mark);
}

GeneticPoolAlpha::GeneticPoolAlpha(unsigned nb_spe, marks_t _coefs, const SharedData& _SD)
     : AbstractGeneticPool(nb_spe, _SD), sorted_by_mark(nb_spe), coefs(_coefs)
{
     
}

void GeneticPoolAlpha::evolve(unsigned int generations_number)
{
     for (int gene=0; gene<generations_number; gene++){
	  for (auto& spe_pt : specimens_pool) spe_pt->evaluate();
	  calcAndSortMarks();
	  calcMinMaxMutations(gene, generations_number); 
	  unsigned nb_parents = floor(specimens_pool.size()/nb_children_per_parent);
	  for (int parent=0; parent<nb_parents; parent++)
	       for (int child=0; child<nb_children_per_parent; child++)
		    sorted_by_mark.at(parent).spe_pt->mutateToChild(
			 sorted_by_mark.at(parent*nb_children_per_parent+child).spe_pt,
			 min_mut, max_mut);
     }
     
}

void GeneticPoolAlpha::popAllocation()
{

}

void GeneticPoolAlpha::calcAndSortMarks()
{
     for (int i=0; i<specimens_pool.size(); i++)
	  sorted_by_mark.at(i) = MarkSpePt(calcMark(specimens_pool.at(i)), specimens_pool.at(i));
     std::sort(sorted_by_mark.begin(), sorted_by_mark.end());
}

mark_t GeneticPoolAlpha::calcMark(AbstractSpecimen* spe_pt) const
{
     
}

void GeneticPoolAlpha::calcMinMaxMutations(unsigned gene, unsigned generations_number)
{
     max_mut = 1+generations_number-gene;
     min_mut = floor(max_mut/2);
}
