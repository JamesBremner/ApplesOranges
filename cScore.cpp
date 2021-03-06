#include "stdafx.h"
#include "cModel.h"

namespace dcd {
	cScore::cScore( const cChoice& choice,
		const cCriterion& crit,
		const float score )
		: myChoiceID( choice.getID() )
		, myCriteriumID( crit.getID() )
		, myScore( score )
	{}
	/**

	Get all choice scores for a criterium

	@param[out] score the scores
	@param[in] crit the criterium

	*/
	void cScoreSet::getScore( std::vector<float>& score, const cCriterion& crit )
	{
		score.clear();
		foreach( cChoice& choice, theModel.theChoice ) {
			score.push_back( getScore( choice, crit ) );
		}
	}
	/**

	Construct scores from database table

	*/
	void cScoreSet::setTable(const std::vector< std::wstring >& table )
	{
		myScore.clear();
		for( int k = 0; k < (int)table.size()/3; k++ ) {
			myScore.insert( dcd::cScore( 
				_wtoi(table[k*3].c_str()),
				_wtoi(table[k*3+1].c_str()),
				(float)_wtof(table[k*3+2].c_str())));
		}
	}
	/**

	Debug dump text

	*/
	std::wstring cScoreSet::DumpText()
	{
		std::wstring ret = L"(choice,crit,score): ";
		foreach( cScore& score, myScore ) {
			wchar_t buf[1000];
			swprintf_s(buf,999,L"%d %d %f, ",
				score.getChoice(),
				score.getCriterion(),
				score.getScore() );
			ret += buf;
		}
		return ret;
	}
	void cScoreSet::DumpOutput()
	{
		System::Diagnostics::Debug::WriteLine( gcnew System::String( DumpText().c_str() ) );
	}

}
