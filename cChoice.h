#pragma once
namespace dcd {
class cChoice {
public:
	std::wstring myName;
	cChoice( const std::wstring& name );
	cChoice( int id, const std::wstring& name );
	int getID() const		{ return myID; }
	bool operator <( const cChoice& other ) const;
private:
	int myID;
	static int myLastID;
};
class cChoiceVector {
public:
	typedef std::vector< dcd::cChoice >::iterator iterator;
	typedef std::vector< dcd::cChoice >::const_iterator const_iterator;
	cChoiceVector()
		: mySelected(-1)
	{}
	iterator begin()					{ return myChoice.begin(); }
	iterator end()						{ return myChoice.end(); }
	int size()							{ return (int) myChoice.size(); }
	void erase( iterator i )			{ myChoice.erase( i ); }
	void clear()						{ myChoice.clear(); }
	void Add( const cChoice& choice )	{ myChoice.push_back( choice ); }
	cChoice& operator[]( int idx )		{ return *(myChoice.begin()+idx); }
	void setTable( const std::vector< std::wstring >& table );
	void setSelected( int i );			
	cChoice& getSelected();
	bool IsSelected()					{ return (  0 <= mySelected || mySelected < (int)myChoice.size() ); }
	void DumpOutput();
private:
	std::vector< cChoice > myChoice;
	int mySelected;
};
}
