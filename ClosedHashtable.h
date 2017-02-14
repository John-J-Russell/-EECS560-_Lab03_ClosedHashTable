/*
	@NAME:		John Russell, 2798357
	@DATE:		14 February 2017
	@FILE:		ClosedHashtable.h
	@PURPOSE:	header file for closed hashtable class
*/

#ifndef CLOSED_HASHTABLE_H
#define CLOSED_HASHTABLE_H

#include <iostream>

class ClosedHashtable
{
	public:
	/*
		@PRE:	is passed proper values
		@POST:	creates a closed hashtable of size table_size, and
			either uses quadradic probing or double hashing.
		@RETURN:none
	*/
	ClosedHashtable(int table_size, bool use_quadratic_probing);

	/*
		@PRE:	none
		@POST:	destroys the hashtable
		@RETURN:none
	*/
	~ClosedHashtable();

	/*
		@PRE:	is passed an integer, table was made properly
		@POST:	value put into array if possible. Note: if table is overfull,
			then there is a chance of failure.
		@RETURN:none
	*/
	void insert(int value_to_insert);

	/*
		@PRE:	is passed an integer, table made properly.
		@POST:	If value is present in table, then it is removed
		@RETURN:none
	*/
	void remove(int value_to_remove);

	/*
		@PRE:	none
		@POST:	contents of table printed to terminal
		@RETURN:none
	*/
	void print();

	/*
		@PRE:	is passed integer, table was made properly
		@POST:	none
		@RETURN:"true" if value in table, "false" otherwise.
	*/
	bool find(int value_to_find);

	/*
		@PRE:	passed int, table made.
		@POST:	none
		@RETURN:the basic hash (value % m_size)
	*/
	int hash(int value_to_hash);

	/*
		@PRE:	passed int, table made
		@POST:	none
		@RETURN:returned the quadratic hash for given inputs
	*/
	int quadraticHash(int value_to_hash, int iteration_number);

	/*
		@PRE:	passed it, table made
		@POST:	none
		@RETURN:returned the double hash for the given inputs
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
