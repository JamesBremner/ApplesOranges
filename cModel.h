#pragma once
#include "cScore.h"
#include "cChoice.h"
#include "cCriterion.h"

namespace dcd {
	class cModel {
	public:
		

/**

  The availables choices that are being evaaluated

*/
cChoiceVector theChoice;

/**

  The tree of criteria on which the choices are evaluated

*/
cCriteriaTree		 critTree;

/**

  The scores assigned to choices on each criterion

*/

cScoreSet theScore;

void ReCalculate();
void Calculate( dcd::cCritTreeNode^ parent );
void NormalizeWeights(  dcd::cCritTreeNode^ root );

dcd::cCriterion & getRootCrterion()		{ return *critTree.getRoot()->getCrit(); }



	};

extern cModel theModel;

}


