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

	//CritTreeView->Nodes->Clear();
	//dcd::cCritTreeNode^ root = gcnew dcd::cCritTreeNode( new dcd::cCriterion(1,L"criteria",L"1",
	//	dcd::cCriterion::numerical) );
	//CritTreeView->Nodes->Add( root );
	dcd::theModel.critTree.Clear();

	LoadTree( 0, dcd::theModel.critTree.getRoot(), vcrit );

	dcd::theModel.ReCalculate( CritTreeView );

}
void cAODB::SaveProjectFile( std::wstring path,
		System::Windows::Forms::TreeView^  CritTreeView )
{
	Open( path.c_str() );
	Clear();
	SaveChoices();
}
/**

  Initialize project database

*/
void cAODB::Clear()
{
	Query(L"DROP TABLE IF EXISTS choice;");
	Query(L"DROP TABLE IF EXISTS criterium;");
	Query(L"DROP TABLE IF EXISTS tree;");
	Query(L"DROP TABLE IF EXISTS score;");
	Query(L"CREATE TABLE choice ( id INTEGER PRIMARY KEY, name );");
	Query(L"CREATE TABLE criterium ( id INTEGER PRIMARY KEY, "
		L"name, weight, score_style );");
	Query(L"CREATE TABLE tree ( parent, child );");
	Query(L"CREATE TABLE score ( choice, criterium, score );");
}

void cAODB::SaveChoices()
{
	foreach( dcd::cChoice& choice, dcd::theModel.theChoice ) {
		Query(L"INSERT INTO choice VALUES ( %d, '%s' );",
			choice.getID(),
			(const wchar_t *)choice.myName.c_str() );
	}
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
