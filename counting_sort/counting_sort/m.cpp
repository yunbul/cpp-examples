#include <iostream>

using namespace std;

#include <time.h>

typedef int* int_ptr;

void c_sort( int_ptr &arr, int lenght )
{
	cout<<"c_sort in."<<endl;
	int *b = new int[lenght];

	int k = 0; //max number = lenght of c[]
	for( int i=0 ; i<lenght ; i++ )
	{
		// hold max number
		if( arr[i] > k ) 
		{
			k = arr[i];
		}
	}
	cout<<"found maximum number.\n";
	k++; // k was maximum index, now it's the lenght of c[]
	
	int *c = new int[k];

	clock_t begin = clock();

	// LINE 1 - 2
	for( int i=0 ; i<k ; i++ )
	{
		c[i] = 0;
	}
	
	// LINE 3 - 4
	for( int j=0 ; j<lenght ; j++ )
	{
		c[ arr[j] ]++;
	}
	// c[] now contains the number of elements in a[]

	// LINE 6 - 7
	for( int i=1 ; i<k ; i++ )
	{
		c[i] += c[i-1];
	}

	// LINE 9 - 10
	for( int j=lenght-1 ; j>-1 ; j--)
	{
		b[ c[ arr[j] ] - 1 ] = arr[j]; // change b[c[ a[j] ]] in algorithm
		c[ arr[j] ]--;
	}
	// print b[]
	for( int i=0 ; i<lenght ; i++ )
	{
		arr[i] = b[i];
	}
	
	clock_t end = clock();

	cout<<"sorted.\nTime Elapsed : "<<end-begin<<" millis.\n";

	delete [] b;
	delete [] c;
	cout<<"c_sort memory released."<<endl;
	cout<<"c_sort out."<<endl;
}


void main(){

	int lenght;
	cout<<"enter size : ";
	cin>>lenght;
	
	int *a = new int[lenght];

	
	/*int y = 100000;*/
	cout<<"filling array randomly...\n";
	for( int i=0 ; i<lenght ; i++ )
	{
		/*a[i] = y;
		--y;*/
		//a[i] = i + 1;
		a[i] = (rand() % 100000) ; // 0 - 99,999
	}
	
	int x = 0;
	cout<<"print array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		// print b[]
		for( int i=0 ; i<lenght ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;

	// SORT ARRAY
	cout<<"sorting..."<<endl;

	
	c_sort( a, lenght);


	// END SORT
	
	cout<<"print sorted array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		// print b[]
		for( int i=0 ; i<lenght ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;
	
	delete [] a;

	cout<<"memory released."<<endl;

	system("pause");
}