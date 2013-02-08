#include "StdAfx.h"
#include "cModel.h"

namespace dcd {

	/** Recalculate total score
	*/
	void cModel::ReCalculate( /*System::Windows::Forms::TreeView^  CritTreeView*/ )
	{
		System::Diagnostics::Debug::WriteLine("->cModel::ReCalculate");
		theChoice.DumpOutput();
		theScore.DumpOutput();

		//critTree.myView = CritTreeView;

		dcd::cCritTreeNode^ root = critTree.getRoot();

		// zero the total score
		root->getCrit()->ZeroScore();

		//check that we have some scores to calculate
		if( ! theScore.size() )
			return;
		if( ! theChoice.size() )
			return;

		dcd::cCritTreeNode^ child = (dcd::cCritTreeNode^)root->FirstNode;

		while( child != nullptr ) {

			Calculate( child );

			child = (dcd::cCritTreeNode^)root->NextNode;

		}

		System::Diagnostics::Debug::WriteLine( gcnew System::String( theModel.theScore.DumpText().c_str() ) );
		System::Diagnostics::Debug::WriteLine("<-cModel::ReCalculate");


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
		dcd::cCritTreeNode^ child = (dcd::cCritTreeNode^)current->FirstNode;

		while( child != nullptr ) {

			Calculate( child );

			child = (dcd::cCritTreeNode^)current->NextNode;

		}



	}
}