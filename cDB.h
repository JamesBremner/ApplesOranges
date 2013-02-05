#pragma once
#include "cModel.h"

class cAODB : public raven::sqlite::cDB
{
public:
	cAODB(void);
	~cAODB(void);
	void OpenProjectFile( std::wstring path,
		System::Windows::Forms::TreeView^  CritTreeView );
	void LoadTree( 
		int parent_id,
		System::Windows::Forms::TreeNode^ node,
		std::vector< dcd::cCriterion* > vcrit );
};
