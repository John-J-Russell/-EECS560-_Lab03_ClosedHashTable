/*
	@NAME:		
	@DATE:		
	@FILE:		
	@PURPOSE:	
*/

#include "ClosedHashtable.h"


ClosedHashtable::ClosedHashtable(int table_size, bool use_quadratic_probing)
{
	m_bool_array = new bool[table_size];

	m_closed_hashtable = new int[table_size];

	//"True" means we'll use quad. probing,
	//"False" means using double hashing.
	m_use_quadratic_probing = use_quadratic_probing;

	for(int x=0; x < table_size; x++)
	{
		m_bool_array[x] = false;
		m_closed_hashtable[x] = -1;
	}

	m_size = table_size;
}

//////////////////////////////////////////////////////////////////////////////////////////////

ClosedHashtable::~ClosedHashtable()
{
	delete(m_bool_array);
	delete(m_closed_hashtable);
}

//////////////////////////////////////////////////////////////////////////////////////////////

void ClosedHashtable::insert(int value_to_insert)
{
	if( find(value_to_insert) )
	{
		std::cout<<"Value already in table.\n";
		return;
	}

	//insert
	if(m_use_quadratic_probing) //insert w/ quad. probing
	{
		int table_key;
		for(int x=0; x<=m_size; x++)
		{
			table_key = quadraticHash(value_to_insert, x);
			if(m_closed_hashtable[table_key] == -1)
			{ //insert
				m_closed_hashtable[table_key] = value_to_insert;
				return;
			}

		}

		std::cout<<"Insertion failed after "<<m_size + 1 <<" probes.\n\n";

	}
	else //insert w/ double hashing
	{
		int table_key;
		for(int x=0; x<=m_size; x++)
		{
			table_key = doubleHash(value_to_insert, x);
			if(m_closed_hashtable[table_key] == -1)
			{ //insert
				m_closed_hashtable[table_key] = value_to_insert;
				return;
			}

		}

		std::cout<<"Insertion failed after "<< m_size + 1 <<" probes.\n\n";
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////

void ClosedHashtable::remove(int value_to_remove)
{
	if( !find(value_to_remove) )
	{
		std::cout<<"Value not in table.\n";
		return;
	}

	//find and remove
	if(m_use_quadratic_probing) //remove w/ quad. probing
	{
		int table_key;
		
		for(int x=0; x <= m_size; x++)
		{
			table_key = quadraticHash(value_to_remove, x);
			
			if(m_closed_hashtable[table_key] == value_to_remove)
			{
				m_closed_hashtable[table_key] = -1;
				m_bool_array[table_key] = true; //a value has been removed
				std::cout<<"Value removed. \n\n";
				return;
			}
			else if(m_closed_hashtable[table_key] == -1 && m_bool_array[x] == false)
			{ //value not in table, though I don't think this should ever prompt?
				std::cout<<"Value not in table [in removal function] \n\n";
				return;
			}

		}
		std::cout<<"Removal failed due to unforseen circumstances.\n\n";
		return;

	}
	else //remove w/ double hashing
	{
		int table_key;
		
		for(int x=0; x <= m_size; x++)
		{
			table_key = doubleHash(value_to_remove, x);
			
			if(m_closed_hashtable[table_key] == value_to_remove)
			{
				m_closed_hashtable[table_key] = -1;
				m_bool_array[table_key] = true; //a value has been removed
				std::cout<<"Value removed. \n\n";
				return;
			}
			else if(m_closed_hashtable[table_key] == -1 && m_bool_array[x] == false)
			{ //value not in table, though I don't think this should ever prompt?
				std::cout<<"Value not in table [in removal function] \n\n";
				return;
			}

		}
		std::cout<<"Removal failed due to unforseen circumstances.\n\n";
		return;

	}

}

//////////////////////////////////////////////////////////////////////////////////////////////

void ClosedHashtable::print()
{
	std::cout<<"Table contents are: \n\n";

	for(int x=0; x<m_size; x++)
	{
		std::cout<< m_closed_hashtable[x] << " : " << m_bool_array[x]
				<< "\n";
	}
	std::cout<<"\n\n";
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////

bool ClosedHashtable::find(int value_to_find)
{
	if(m_use_quadratic_probing) //search w/ quad. probing
	{
		int table_key;

		for(int x=0; x <= m_size; x++)
		{
			table_key = quadraticHash(value_to_find, x);

			if(value_to_find == m_closed_hashtable[x])
			{
				return(true);
			}
			//else if entry is empty, and has never been emptied
			else if(m_closed_hashtable[x] == -1 && m_bool_array[x] == false)
			{
				return(false);
			}
			//implicit else: keep going.
		}


	}
	else //search w/ double hashing
	{
		int table_key;

		for(int x=0; x <= m_size; x++)
		{
			table_key = doubleHash(value_to_find, x);

			if(value_to_find == m_closed_hashtable[x])
			{
				return(true);
			}
			//else if entry is empty, and has never been emptied
			else if(m_closed_hashtable[x] == -1 && m_bool_array[x] == false)
			{
				return(false);
			}
			//implicit else: keep going.
		}
	
	}
	return(false);
}
//////////////////////////////////////////////////////////////////////////////////////////////
int ClosedHashtable::hash(int value_to_hash)
{
	return(value_to_hash % m_size);
}
//////////////////////////////////////////////////////////////////////////////////////////////
int ClosedHashtable::quadraticHash(int value_to_hash, int iteration_number)
{
	int hash_key = (hash(value_to_hash) + (iteration_number * iteration_number)) % m_size;
	return(hash_key);
}
//////////////////////////////////////////////////////////////////////////////////////////////
int ClosedHashtable::doubleHash(int value_to_hash, int iteration_number)
{
	//hi(x) = [h(x) + i(p-(x%p))] % m
	int basic_hash = hash(value_to_hash);
	
	int second_hash = iteration_number * (5 - (value_to_hash % 5));
	int hash_key = (basic_hash + second_hash) % m_size;
	return(hash_key);

}

