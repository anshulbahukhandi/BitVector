#include"bitvector.h"
#include<iostream>
using namespace std;

	bitVector::bitVector()
	{
		cout<<"Bit Vector Created!!\n";
		mArray=nullptr;
		mSize=0;
	}

	bitVector::~bitVector()
	{
		cout<<"Bit Vector Destroyed!!\n";
		delete mArray;
	}

	int bitVector::getSize()
	{
		return mSize;
	}

	/*Used to access any particular flag*/
	int bitVector::access( const int& nIndex )
	{
		int temp = 8*sizeof(unsigned int); //number of bits in one unsigned int
		if(nIndex>mSize*temp-1 || nIndex<0)
		{
			cout<<"Out of bound!!\n";
			exit(0);
		}
		else
		{ /* If not out of bound*/
		int index=nIndex/temp; /*index in the array of unsigned int*/
		int cell =nIndex%temp; /*cell index within above index*/
			
		int number=mArray[index]; 
			return (((1<<(temp-cell-1))&number)>>(temp-cell-1));
		}
	}

	/*Used to set any particular flag 1*/
	void bitVector::setOne( const int & nIndex)
	{
		cout<<"Seting index "<<nIndex<<" equal to 1\n";
		int temp = 8*sizeof(unsigned int); //number of bits in one unsigned int
		if(nIndex>mSize*temp-1 || nIndex<0)
		{
			cout<<"Out of bound . Increase the size of array first!!\n";
			exit(0);
		}
		else 
		{/* If not out of bound*/
		int index=nIndex/temp; /*index in the array of unsigned int*/
		int cell =nIndex%temp; /*cell index within above index*/
		mArray[index]=1<<(temp-cell-1)|mArray[index];
		}
	}

	/*Used to set any particular flag 0*/
	void bitVector::setZero( const int & nIndex)
	{
		cout<<"Seting index "<<nIndex<<" equal to 0\n";
		int temp = 8*sizeof(unsigned int); //number of bits in one unsigned int
		if(nIndex>mSize*temp-1 || nIndex<0)
		{
			cout<<"Out of bound . Increase the size of array first!!\n";
			exit(0);
		}
		else 
		{/* If not out of bound*/
		int index=nIndex/temp; /*index in the array of unsigned int*/
		int cell =nIndex%temp; /*cell index within above index*/
		mArray[index]=~(1<<(temp-cell-1))& mArray[index];
		}
	}

	/*Used to set all flags to 1 or ON or TRUE*/
	void bitVector::setAll()
	{
		for( int i= 0; i<mSize ; i++)
			mArray[i]=0xFFFFFFFF; /* System dependent , Size of unsigned int in my system is 32 bits,Hence 8 Fs*/
	}
	
	/*Used to set all flags to 0 or OFF or FLASE*/
	void bitVector::clearAll()
	{
		for( int i=0 ; i<mSize;i++)
			mArray[i]=0;
	}
	
	/* Used to resize the array when needed to "size" number of bits*/
	void bitVector::resize(const int& size)
	{
		int temp = 8*sizeof(unsigned int); //number of bits in one unsigned int
		int min;
		int lsize;
		if(size%temp==0) /* No. of bits perfectly divisible by the size of unsigned int in bits*/
			 lsize=size/temp;
			
		else
			 lsize=size/temp +1;
			
		/*Array created on the heap so doesnt gets destroyed when function end*/
		unsigned int * array =new unsigned int[lsize];
				/*Initialize to zero*/	
				for ( int i=0 ; i<lsize ; i++)
					array[i]=0;
				/*deside whether shrinking or expanding*/
				lsize<mSize? min=lsize: min=mSize;
				/* copy the previous data*/
				for(int i=0 ; i<min;i++)
					array[i]=mArray[i];
				mArray=array;
				mSize=lsize;
	}

	/*Used to print the array bits*/
	void bitVector::printBits()
	{
		int temp = 8*sizeof(unsigned int); //number of bits in one unsigned int
		int number;
		for ( int i=0 ; i<mSize ; i++)
		{
			number=mArray[i];
			for(int j=temp-1 ; j>=0 ; j--)
			{
				cout<< ( ( (1<<j)&number )>>j);
			}
		}
		cout<<endl;
	}