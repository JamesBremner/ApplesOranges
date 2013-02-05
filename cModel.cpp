#include "StdAfx.h"
#include "cModel.h"

namespace dcd {

	/** Recalculate total score
	*/
	void cModel::ReCalculate( System::Windows::Forms::TreeView^  CritTreeView )
	{
		myCritTreeView = CritTreeView;

		//dcd::cCritTreeNode^ root = (dcd::cCritTreeNode^)CritTreeView->Nodes[0];

		//// zero the total score
		//root->getCrit()->ZeroScore();

		//dcd::cCritTreeNode^ child = (dcd::cCritTreeNode^)root->FirstNode;

		//while( child != nullptr ) {

		//	Calculate( child );

		//	child = (dcd::cCritTreeNode^)root->NextNode;

		//}


	}
	/**

	Calculate total score of criterion, including all children

	*/
	void cModel::Calculate( dcd::cCritTreeNode^ parent )
	{
		if( ! parent->Nodes->Count ) {

			// this is a leaf

			parent->getCrit()->EvaluateScores( parent->getCrit() );

			critTree.PropogateScoreUpwards( 1 );

		}
	}
}