#include "StdAfx.h"
#include "cModel.h"

namespace dcd {

	/** Recalculate total score
	*/
	void cModel::ReCalculate( System::Windows::Forms::TreeView^  CritTreeView )
	{
		// zero the total score
		((dcd::cCritTreeNode^)CritTreeView->Nodes[0])->getCrit()->ZeroScore();
	}
}