#pragma once
#include "cModel.h"

class cAODB : public raven::sqlite::cDB
{
public:
	cAODB(void);
	~cAODB(void);
	void OpenProjectFile( std::wstring path );
	void SaveProjectFile( std::wstring path );
private:
	void LoadTree( 
		int parent_id,
		System::Windows::Forms::TreeNode^ node,
		std::vector< dcd::cCriterion* > vcrit );
	void Clear();
	void SaveChoices();
	void SaveCriteria( 
		dcd::cCritTreeNode^ parent,
		int parent_rowid );
	void SaveScore(
		const dcd::cCriterion& crit );
};
