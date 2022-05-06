#include <iostream>
#include <time.h>

using namespace std;

template <class T>
void stooge_sort( T* arr , int i , int j ){
	if( arr[i] > arr[j] ) {
		T tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	if( i+1 >= j ) {
		return;
	}
	int k = (int)( ( j-i+1 )/3 );
	stooge_sort( arr , i , j-k );
	stooge_sort( arr , i+k , j );
	stooge_sort( arr , i , j-k );
}

void main(){

	int size = 0;
	cout<<"enter size : ";
	cin>>size;

	int *a = new int[size];
	
	// fill a[] with rand()
	for( int i=0 ; i<size ; i++ )
	{
		a[i] = rand() % 100000 ; // 0 - 99,999
	}

	int x = 0;
	cout<<"print array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		for( int i=0 ; i<size ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;

	// SORT ARRAY
	cout<<"sorting..."<<endl;
	clock_t begin = clock();

	// CALL SORT FUNC
	stooge_sort( a , 0 , size-1 );

	clock_t end = clock();

	cout<<"sorted.\nTime Elapsed : "<<end-begin<<" millis.\n"<<endl;
	// END SORT
	
	cout<<"print sorted array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		for( int i=0 ; i<size ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;
	
	delete a;

	cout<<"memory released."<<endl;

	system("pause");
}