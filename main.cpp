#include"bitvector.cpp"
#include<iostream>
using namespace std; 
int main(int argc , char * argv[])
{
	bitVector b1;
	b1.resize(32);
	b1.setOne(31);
	b1.printBits();

	return 0;
}