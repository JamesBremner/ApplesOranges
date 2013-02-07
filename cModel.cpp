#include "StdAfx.h"
#include "cModel.h"

namespace dcd {

	/** Recalculate total score
	*/
	void cModel::ReCalculate( System::Windows::Forms::TreeView^  CritTreeView )
	{
		critTree.myView = CritTreeView;

		dcd::cCritTreeNode^ root = (dcd::cCritTreeNode^)CritTreeView->Nodes[0];

		// zero the total score
		root->getCrit()->ZeroScore();

		//check that we have some scores to calculate
		if( ! theScore.size() )
			return;

		dcd::cCritTreeNode^ child = (dcd::cCritTreeNode^)root->FirstNode;

		while( child != nullptr ) {

			Calculate( child );

			child = (dcd::cCritTreeNode^)root->NextNode;

		}


	}
	/**

	Calculate total score of criterion, including all children

	*/
	void cModel::Calculate( dcd::cCritTreeNode^ current )
	{
		if( ! current->Nodes->Count ) {

			// this is a leaf

			current->getCrit()->EvaluateScores(  ((dcd::cCritTreeNode^)current->Parent)->getCrit() );

			critTree.PropogateScoreUpwards( current );

			return;

		}

		// we have cildren, so zero any score we muight have
		current->getCrit()->ZeroScore();

		// loop over all children
		dcd::cCritTreeNode^ child = (dcd::cCritTreeNode^)current->FirstNode;

		while( child != nullptr ) {

			Calculate( child );

			child = (dcd::cCritTreeNode^)current->NextNode;

		}



	}
}