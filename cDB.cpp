#include "StdAfx.h"
#include "cModel.h"
#include "cDB.h"

cAODB::cAODB(void)
{
}

cAODB::~cAODB(void)
{
}
void cAODB::OpenProjectFile( 
			std::wstring path,
			System::Windows::Forms::TreeView^  CritTreeView ) 
{
	Open( path.c_str() );

	Query(L"SELECT * FROM choice;");
	dcd::theModel.theChoice.setTable( myResult );

	Query(L"SELECT * FROM score;");
	dcd::theModel.theScore.setTable( myResult );

	// read criteria from database
	std::vector< dcd::cCriterion* > vcrit;
	Query(L"SELECT * FROM criterium;");
	for( int krit = 0; krit < (int)myResult.size()/4; krit++ ) {
		vcrit.push_back( new dcd::cCriterion( myResult, krit ) );
	}

	CritTreeView->Nodes->Clear();
	System::Windows::Forms::TreeNode^ root = gcnew System::Windows::Forms::TreeNode("criteria");
	CritTreeView->Nodes->Add( root );
	LoadTree( 0, root, vcrit );

	dcd::theModel.ReCalculate( CritTreeView );

}

void cAODB::LoadTree( 
		int parent_id,
		System::Windows::Forms::TreeNode^ node,
		std::vector< dcd::cCriterion* > vcrit )
{
		// Load children from database
	Query(L"SELECT child FROM tree WHERE parent = %d;",
		parent_id);
	std::vector<std::wstring > vdbchild( myResult );

	// loop over children
	for( int kchild = 0; kchild < (int)vdbchild.size(); kchild++ ) {

		//database index of child
		int childid = _wtoi(vdbchild[kchild].c_str());

		// child criterium
		foreach( dcd::cCriterion * pcrit, vcrit ) {
			if( pcrit->getID() == childid ) {

				// store child in tree
 				dcd::cCritTreeNode^ newItem = gcnew dcd::cCritTreeNode( pcrit );
				node->Nodes->Add( newItem );

				// load grandchildren
				LoadTree( childid, newItem, vcrit );

				break;
			}
		}

	}

}
