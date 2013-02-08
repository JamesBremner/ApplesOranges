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
	void cChoiceVector::setSelected( int i )
	{
		if( i >= (int)myChoice.size() )
			i = myChoice.size()-1;
		mySelected = i;
	}

	cChoice& cChoiceVector::getSelected()
	{
		if( 0 > mySelected || mySelected >= (int)myChoice.size() ) {
			static cChoice null(L"");
			return null;
		}
		return *(myChoice.begin()+mySelected);
	}
	namespace  ChoiceVector {
	static bool  FirstChoiceTotalScoreGreater(  const cChoice& first, const cChoice& second )
	{
		return dcd::theModel.theScore.getScore( first, dcd::theModel.getRootCrterion() ) >
			dcd::theModel.theScore.getScore( second, dcd::theModel.getRootCrterion() ); 
	}
	}
	void cChoiceVector::SortByTotalScore()
	{
		std::sort(myChoice.begin(),myChoice.end(),
			ChoiceVector::FirstChoiceTotalScoreGreater);
	}
	void cChoiceVector::DumpOutput()
	{
		foreach( cChoice& choice, myChoice ) {
			wchar_t buf[1000];
			swprintf_s(buf,999,L"%d %s, ",
				choice.getID(), choice.myName.c_str());
			System::Diagnostics::Debug::Write( gcnew System::String( buf ) );
		}
		System::Diagnostics::Debug::Write( gcnew System::String( "\n" ) );
	}


}