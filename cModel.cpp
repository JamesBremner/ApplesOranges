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

		//Normalize the weights
		NormalizeWeights( root );

		// Calulate the score for the tree
		Calculate( root );

		theScore.DumpOutput();
		System::Diagnostics::Debug::WriteLine("<-cModel::ReCalculate");

		// sort the choices by their new total scores
		theChoice.SortByTotalScore();


	}
	/**

	Calculate normalized weights.

	The normalized absolute weights of all children of each criterion must 
	sum to 1.0

	*/
	void cModel::NormalizeWeights( dcd::cCritTreeNode^ root )
	{
		// Sum the weights
		float sumWeights = 0;
		// loop over all children
		for(
			dcd::cCritTreeNode^ child = root->getFirstChild();
			child != nullptr;
			child = child->getNextSibling() )
			{
				sumWeights += (float)fabs(_wtof(child->getCrit()->getWeight().c_str()));
			}
		
		// Normalize
		for(
			dcd::cCritTreeNode^ child = root->getFirstChild();
			child != nullptr;
			child = child->getNextSibling() )
			{
				child->getCrit()->CalcNormalizedWeight( sumWeights );

				NormalizeWeights( child );
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