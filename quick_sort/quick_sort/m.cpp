#include <iostream>
#include <time.h>

using namespace std;

template <class T>
int partition( T* arr , int p , int r ) {
	T x = arr[r];
	int i = p-1;

	for( int j=p ; j<=r-1 ; j++ ){

		if( arr[j] <= x ){
			++i;

			T tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	T tmp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tmp;
	return i+1;
}
/*
template <class T>
int random_partition( T* arr , int p , int r ) {
	int i = rand() % r;

	T tmp = arr[r];
	arr[r] = arr[i];
	arr[i] = tmp;
	return partition( arr , p , r );
}

template <class T>
int hoare_partition( T* arr , int p , int r ){
	T x = arr[p];
	int i = p-1;
	int j = r+1;

	while(true){

		while( ! arr[j] <= x )
			--j;

		while( ! arr[i] >= x )
			++i;

		if( i < j ){
			T tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		else {
			return j;
		}
	}
}
*/
template <class T>
void quick_sort( T* arr , int p , int r ){
	if( p < r ) {
		int q = partition( arr , p , r ); // random_partition( arr , p , r );
		quick_sort( arr , p , q-1 );
		quick_sort( arr , q+1 , r );
	}
}

void main(){

	int size = 0;
	cout<<"enter size : ";
	cin>>size;

	int *a = new int[size];


	//int y = 100000;
	cout<<"filling array randomly...\n";
	for( int i=0 ; i<size ; i++ )
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

	// to sort entire array initial call is QUICK_SORT ( A , 0 , lenght[A]-1 )
	// quick_sort ( array , start_index , finish_index ) 
	quick_sort( a , 0 , size-1 );

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
	
	delete [] a;

	cout<<"memory released."<<endl;

	system("pause");
}