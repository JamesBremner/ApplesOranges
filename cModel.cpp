#include "StdAfx.h"
#include "cModel.h"

namespace dcd {

	/** Recalculate total score
	*/
	void cModel::ReCalculate()
	{
		System::Diagnostics::Debug::WriteLine("->cModel::ReCalculate");
		theChoice.DumpOutput();
		theScore.DumpOutput();

		dcd::cCritTreeNode^ root = critTree.getRoot();

		// zero the total score
		root->getCrit()->ZeroScore();

		//check that we have some scores to calculate
		if( ! theScore.size() )
			return;
		if( ! theChoice.size() )
			return;

		//loop over children of root node
		for( 
			dcd::cCritTreeNode^ child = root->getFirstChild();
			child != nullptr;
			child = child->getNextSibling() )
		{

			Calculate( child );

		}

		theScore.DumpOutput();
		System::Diagnostics::Debug::WriteLine("<-cModel::ReCalculate");

		// sort the choices by their new total scores
		theChoice.SortByTotalScore();


	}
	/**

	Calculate total score of criterion, including all children

	*/
	void cModel::Calculate( dcd::cCritTreeNode^ current )
	{
		if( ! current->Nodes->Count ) {

			// this is a leaf

			current->getCrit()->EvaluateScores(  ((dcd::cCritTreeNode^)current->Parent)->getCrit() );

			critTree.PropogateScoreUpwards( (dcd::cCritTreeNode^)current->Parent );

			return;

		}

		// we have cildren, so zero any score we muight have
		current->getCrit()->ZeroScore();

		// loop over all children
		for(
			dcd::cCritTreeNode^ child = current->getFirstChild();
			child != nullptr;
			child = child->getNextSibling() )
			{
				Calculate( child );
			}

	}
}