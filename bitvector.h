/*
  Objects of this class can be used to store the ON/OFF flag. 
  Class is so designed that one flag just takes one bit rather 
  than one int storage and hence its highly memory efficient.
  Every memory allocation is done on the heap.
  Auto Resize is not implemented so as to avoid unnecessaary 
  increase in size by mistake. User has to first incerease the 
  size if he wants to set some out of bound bit.
 */
#ifndef BIT_VECTOR_H_
#define BIT_VECTOR_H_

class bitVector
{

public:
	bitVector();
	~bitVector();
	/*Used to access any particular flag*/
	int access( const int& );
	/*Used to set any particular flag 1*/
	void setOne( const int &);
	/*Used to set any particular flag 0*/
	void setZero( const int &);
	/*Used to set all flags to 1 or ON or TRUE*/
	void setAll();
	/*Used to set all flags to 0 or OFF or FLASE*/
	void clearAll();
	/* Used to resize the array to the given number of bits*/
	void resize(const int&);
	/* Used to return the no of ints in array*/
	int getSize();
	/*Used to print the array bits*/
	void printBits();

private:
/*Array of unsigned integers*/
unsigned int * mArray;
/*No. of unsigned integers*/
int mSize ;
};
#endif 