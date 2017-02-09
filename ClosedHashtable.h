/*
	@NAME:		
	@DATE:		
	@FILE:		
	@PURPOSE:	
*/

#ifndef CLOSED_HASHTABLE_H
#define CLOSED_HASHTABLE_H

#include <iostream>

class ClosedHashtable
{
	public:
	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	ClosedHashtable(int table_size, bool use_quadratic_probing);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	~ClosedHashtable();

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void insert(int value_to_insert);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void remove(int value_to_remove);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void print();

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	bool find(int value_to_find);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	int hash(int value_to_hash);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	int quadraticHash(int value_to_hash, int iteration_number);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	int doubleHash(int value_to_hash, int iteration_number);


	private:

	bool* m_bool_array;
	
	int* m_closed_hashtable;

	int m_size;

	//"true" means this will be a quadratic probing,
	//"false" means will use double hashing
	bool m_use_quadratic_probing;

};


#endif
