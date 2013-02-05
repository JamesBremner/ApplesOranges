#include "stdafx.h"
#include "cModel.h"

namespace dcd {

	cModel theModel;

	int cChoice::myLastID = 0;

	cChoice::cChoice( const std::wstring& name )
		: myName( name )
	{
		myID = ++myLastID;
	}
	cChoice::cChoice( int id, const std::wstring& name )
		: myName( name )
		, myID( id )
	{
		if( myID > myLastID )
			myLastID = myID;
	}
	/**

	Compare choices by their total score

	*/
	bool cChoice::operator <( const cChoice& other ) const
	{

		// the total score of a choice is the score for the root criterion
		cCriterion * p_root_crit = theModel.critTree.getCriterion( /*theModel.critTree->GetRootItem()*/0 );

		// get the two scores
		float my_score = theModel.theScore.getScore( *this, *p_root_crit );
		float other_score = theModel.theScore.getScore( other, *p_root_crit );

		// and compare
		return my_score < other_score;
	}
	void cChoiceVector::setTable( const std::vector< std::wstring >& table )
	{
		myChoice.clear();
		for( int k = 0; k < (int)table.size()/2; k++ ) {
			myChoice.push_back( dcd::cChoice( 
				_wtoi(table[k*2].c_str()), table[k*2+1] ) );
		}

	}
	cChoice& cChoiceVector::getSelected()
	{
		if( 0 > mySelected || mySelected >= (int)myChoice.size() ) {
			static cChoice null(L"");
			return null;
		}
		return *(myChoice.begin()+mySelected);
	}

}