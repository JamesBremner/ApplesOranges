#pragma once


namespace dcd {
	class cChoice;
	class cCriterion;

	/**  The user score assigned to a choice for a criterium
	*/
	class cScore {
	public:
		cScore( int choiceID, int criteriumID, const float score )
			: myChoiceID( choiceID )
			, myCriteriumID( criteriumID )
			, myScore( score )
		{}
		cScore( const cChoice& choice,
			const cCriterion& crit,
			const float score );
		float getScore()				{ return myScore; }
		void setScore( float score )	{ myScore = score; }

		/**

		True if this has the same location ( not value ) has another score 

		*/
		bool operator ==( const cScore& other ) const
		{ 
			return ( myChoiceID == other.myChoiceID &&
					myCriteriumID == other.myCriteriumID );
		}
		/**

		True if this is 'less than' the other by location ( not value )

		@param[in] other the other score to be compared with this

		The scores are identified by the choice and criterium.  Think of them as being
		stored in a single line, with the criterium increasing most rapidly, the choice more slowly.
		This returns true if this score is saved to the left of the other.

		This allows a sparse 2D array of scores to be stored and then found again using binary search
		in the std::set container

		*/
		bool operator <( const cScore& other ) const
		{ 
			if( myChoiceID < other.myChoiceID )
				return true;
			if( myChoiceID == other.myChoiceID )
				if( myCriteriumID < other.myCriteriumID )
					return true;
			return false;
		}

	private:
		float myScore;
		int myChoiceID;
		int myCriteriumID;
	};
	/**

	Store the scores in a spase 2D array that is binary searchable

	*/
	class cScoreSet  {
	public:
		typedef std::set<cScore>::iterator iter;
		void clear() { myScore.clear(); }
		void Add( const cScore& score ) { myScore.insert( score ); }
		void Set( const cScore& target ) {
			iter found = Find( target );
			if( found == myScore.end() ) {
				myScore.insert( target );
			} else {
				*found = target;
			}
		}
		float getScore(  const cChoice& choice,
			const cCriterion& crit )
		{
			cScore target( choice, crit, 0 );
			iter found = Find( target );
			if( found == myScore.end() ) {
				return 0;
			}
			return found->getScore();
		}
		void AddScore(
			const cChoice& choice,
			const cCriterion& crit,
			const float score )
		{
			cScore target( choice, crit, score );
			iter found = Find( target );
			if( found == myScore.end() ) {
				myScore.insert( target );
			} else {
				found->setScore( found->getScore() + score );
			}
		}

		iter Find(  const cScore& target )
		{ return std::find(
				myScore.begin(), myScore.end(), target );
		}
		void getScore( std::vector<float>& score, const cCriterion& crit );
		void setTable(const std::vector< std::wstring >& table );

	private:
		//std::vector< cScore > myScore;
		std::set< cScore > myScore;
	};
}