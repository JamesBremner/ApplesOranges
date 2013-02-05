#pragma once
namespace dcd {
	class cCriterion  {
	public:
		enum score_style {
			none,
			numerical,
			grade
		};
		cCriterion()
			: myScoreStyle( numerical )
			, myWeight( L"1" )
		{
			myID = ++myLastID;
		}
		cCriterion( const std::wstring& name )
			: myScoreStyle( numerical )
			, myWeight( L"1" )
			, myName( name )
		{
			myID = ++myLastID;
		}
		cCriterion( int id,
			const std::wstring& name,
			const std::wstring& weight,
			score_style style )
			: myID( id )
			, myName( name )
			, myWeight( weight )
			, myScoreStyle( style )
		{
			if( myID > myLastID )
				myLastID = myID;
		}
		/** Construct from database table row */
		cCriterion( std::vector<std::wstring>& table, int row )
		{
			myID = _wtoi( table[row*4].c_str() );
			myName = table[row*4+1];
			myWeight = table[row*4+2];
			myScoreStyle = (score_style)_wtoi(table[row*4+3].c_str());
		}
		int getID()	const						{ return myID; }
		void setWeight( const std::wstring& weight )	{ myWeight = weight; }
		const std::wstring& getWeight() const		{ return myWeight; }
		const std::wstring& getName() const			{ return myName; }
		void setName( const wchar_t * n )			{ myName = n; }
		void setScoreStyle( score_style style )	{ myScoreStyle = style; }
		score_style getScoreStyle() const		{ return myScoreStyle; }
		void ZeroScore();
		void EvaluateScores( cCriterion * parent );
	private:
		static int myLastID;
		int myID;
		score_style myScoreStyle;
		std::wstring myWeight;
		std::wstring myName;
	};



	ref class cCritTreeNode : public System::Windows::Forms::TreeNode
	{
		cCriterion * myCrit;
	public:
		cCritTreeNode( cCriterion* pcrit )
			: myCrit( pcrit )
			, System::Windows::Forms::TreeNode( 
			msclr::interop::marshal_as<System::String^>(pcrit->getName()) )
		{}
			cCriterion * getCrit()	{ return myCrit; }
	};


	/**

  The criteria used for assessing the choices, arranged as a tree.

*/
class cCriteriaTree
{
public:
	cCriteriaTree(  )
	{
		//Clear();
	}
	dcd::cCriterion * getCriterion( int item )	{ static int dum; return (dcd::cCriterion * ) &dum;/*GetItemData( item );*/ }
	dcd::cCriterion * getSelectedCriterion()			{ return mySelectedCriterion; }
	dcd::cCritTreeNode^ getRoot()				{ return (dcd::cCritTreeNode^) myView->Nodes[0]; }
	void			Clear();
	void			AddASibling();
	void			AddAChild();
	void			RenameSelected( const std::wstring& name){ 	/*SetItemText(mySelectedCriterium,name);*/ }
	std::wstring	getSelectedName()					{ return std::wstring(L"dummy");/*GetItemText( mySelectedCriterium );*/ }
	//bool			IsRootSelected()					{ return ( mySelectedCriterium == 0/*GetRootItem() */); }
	void			setSelected( cCriterion * p )		{ mySelectedCriterion = p; }
	void			DeleteSelected();
	void			PropogateScoreUpwards( dcd::cCritTreeNode^ current );

	gcroot<System::Windows::Forms::TreeView^>  myView; 

private:
	cCriterion		* mySelectedCriterion;

};
}