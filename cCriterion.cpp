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
	value.clear();
	foreach( float score, crit_score ) {
		value.push_back( (score - min_score) / range );
	}

	float weight = (float)_wtof(myWeight.c_str());
	cChoiceVector::iterator choice = theModel.theChoice.begin();
	foreach( float v, value )
	{
		theModel.theScore.AddScore( *choice++, *parent, weight * v );
	}

}




/**

  Delete the tree.

  Start of a new tree with a root item.
  The root item always has a criterium index 1

*/
void cCriteriaTree::Clear()
{
	//DeleteAllItems();
	//wxTreeItemId root = AddRoot("criteria");
	//SetItemData( root, new dcd::cCriterion(1,"root","1",
	//	dcd::cCriterion::numerical ) );
	//mySelectedCriterium = root;
	static cCriterion null;
	mySelectedCriterion = &null;
}

void cCriteriaTree::AddAChild()
{
	dcd::cCritTreeNode^ newItem = gcnew dcd::cCritTreeNode( new dcd::cCriterion(L"child") );
	theModel.myCritTreeView->SelectedNode->Nodes->Add(newItem);
}
void cCriteriaTree::AddASibling()
{
	dcd::cCritTreeNode^ newItem = gcnew dcd::cCritTreeNode( new dcd::cCriterion(L"sib") );
	theModel.myCritTreeView->SelectedNode->Parent->Nodes->Add(newItem);
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
void cCriteriaTree::PropogateScoreUpwards( int current )
{
	//dcd::cCriterion * crit_cur = getCriterion( current );
	//while( current != GetRootItem() ) {
	//	wxTreeItemId parent = GetItemParent( current );
	//	dcd::cCriterion * crit_parent = getCriterion( parent );
	//	float weight = _wtof( crit_cur->getWeight().c_str());
	//	foreach( dcd::cChoice& choice, theModel.theChoice ) {
	//		theModel.theScore.AddScore( choice, *crit_parent,
	//			weight * theModel.theScore.getScore( choice, *crit_cur ) );
	//	}
	//	current = parent;
	//	crit_cur = crit_parent;
	//}

}


}
