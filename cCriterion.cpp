#include "stdafx.h"
#include "cModel.h"

namespace dcd {

	int cCriterion::myLastID = 0;


void cCriterion::ZeroScore()
{
	foreach( cChoice& choice, theModel.theChoice ) {
		theModel.theScore.Set( cScore( choice, *this, 0 ) );
	}
}
/**

  Calculate normalized scores

  @param[out] parent the parent criterion

*/
void cCriterion::EvaluateScores( cCriterion * parent )
{
	System::Diagnostics::Debug::WriteLine( "cCriterion::EvaluateScores" );
	theModel.theScore.DumpOutput();

	// find range of scores
	std::vector< float > value;
	std::vector<float> crit_score;
	theModel.theScore.getScore( crit_score, *this );
	float max_score = crit_score[0];
	float min_score = crit_score[0];
	foreach( float score, crit_score ) {
		if( score > max_score ) 
			max_score = score;
		if( score < min_score )
			min_score = score;
	}
	float range = max_score-min_score;
	if( range < 0.00001 )
		range = 1;

	// position of each score on range
	// so highest score gets a value of 1
	// lowest a value of 0
	value.clear();
	foreach( float score, crit_score ) {
		value.push_back( (score - min_score) / range );
	}

	// the weight assigned to this criterion
	float weight = (float)_wtof(myWeight.c_str());

	// a negative weight means that a high score on this criterion is a bad thing
	// We allow for this by adding an offset of +1 to the weight * score
	int negative_offset = 0;
	if( weight < 0 )
		negative_offset = 1;

	// loop over choices, assigning weighted score
	cChoiceVector::iterator choice = theModel.theChoice.begin();
	foreach( float v, value )
	{
		theModel.theScore.AddScore( *choice++, *parent, 
			myNormalizedWeight * v + negative_offset );
	}

	theModel.theScore.DumpOutput();

}




/**

  Delete the tree.

  Start of a new tree with a root item.
  The root item always has a criterium index 1

*/
void cCriteriaTree::Clear()
{
	myView->Nodes->Clear();
	dcd::cCritTreeNode^ root = gcnew dcd::cCritTreeNode( new dcd::cCriterion(1,L"criteria",L"1",
		dcd::cCriterion::numerical) );
	myView->Nodes->Add( root );
	mySelectedCriterion = root->getCrit();
}

void cCriteriaTree::AddAChild()
{
	dcd::cCritTreeNode^ newItem = gcnew dcd::cCritTreeNode( new dcd::cCriterion(L"child") );
	myView->SelectedNode->Nodes->Add(newItem);
}
void cCriteriaTree::AddASibling()
{
	dcd::cCritTreeNode^ newItem = gcnew dcd::cCritTreeNode( new dcd::cCriterion(L"sib") );
	myView->SelectedNode->Parent->Nodes->Add(newItem);
}
void cCriteriaTree::DeleteSelected()
{
	//wxTreeItemId deleted = mySelectedCriterium;
	//mySelectedCriterium = GetItemParent( deleted );
	//Delete( deleted );
}
/**

  Add choice scores for this criteria to parents, up to root

  @param[in] current  The criterion in the tree whose scores must be propogated
*/
void cCriteriaTree::PropogateScoreUpwards( dcd::cCritTreeNode^ node_current )
{
	System::Diagnostics::Debug::WriteLine( "PropogateScoreUpwards" );
	dcd::cCriterion * crit_cur = node_current->getCrit();
	while( node_current != myView->Nodes[0] ) {
		dcd::cCriterion * crit_parent = ((dcd::cCritTreeNode^)node_current->Parent)->getCrit();
		int sibling_count = node_current->Parent->GetNodeCount( false );
		//float weight = (float)_wtof( crit_cur->getWeight().c_str());
		float weight = crit_cur->getNormalizedWeight();

		// loop over choices
		foreach( dcd::cChoice& choice, theModel.theChoice ) {
			float score = theModel.theScore.getScore( choice, *crit_cur );
#ifdef _DEBUG
			theModel.theScore.DumpOutput();
			wchar_t msg[1000];
			swprintf(msg,999,L"choice=%s,score=%f, weight=%f, current=%s, parent=%s ( %f )",
				choice.myName.c_str(),
				score, weight, crit_cur->getName().c_str(), crit_parent->getName().c_str(),
				theModel.theScore.getScore( choice, *crit_parent ));
			System::Diagnostics::Debug::WriteLine( gcnew System::String(msg) );
#endif
			theModel.theScore.AddScore( choice, *crit_parent,
				weight * score / sibling_count );

			theModel.theScore.DumpOutput();
		}
		node_current = (dcd::cCritTreeNode^)node_current->Parent;
		crit_cur = crit_parent;
	}

}


}
