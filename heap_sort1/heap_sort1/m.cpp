#include <iostream>
#include <time.h>
using namespace std;

int _size; // = heap_size

int parent( int i ){
	return (int)i/2;
}

int left( int i ){
	return 2*i;
}

int right( int i ){
	return 2*i + 1;
}

template<class T>
void max_heapify( T* arr , int i ){

	int largest = NULL;
	int l = left(i);
	int r = right(i);

	if( l <= _size  &&  arr[l] > arr[i] ){
		largest = l;
	}
	else{
		largest = i;
	}

	if( r <= _size  &&  arr[r] > arr[largest] ){
		largest = r;
	}

	if( largest != i ){

		T tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		max_heapify(arr , largest);
	}
}

template<class T>
void build_max_heap( T* arr ){

	for( int i=(int)_size/2 ; i>0 ; i-- ){

		max_heapify(arr , i);
	}
}

template<class T>
void heap_sort( T* arr ){

	build_max_heap( arr );

	for( int i=_size ; i>1 ; i-- ){
		T tmp = arr[1];
		arr[1] = arr[i];
		arr[i] = tmp;
		--_size;
		max_heapify( arr , 1 );
	}
}

/*
template<class T>
void heap_increase_key( T* arr , int i , int key ){
	if( key < arr[i] ){
		printf("new key is smaller than current key !\n");
		return;
	}
	arr[i] = key;
	
	while( i>1 && arr[parent(i)]<arr[i] ){

		T tmp = arr[i];
		arr[i] = arr[parent(i)];
		arr[parent(i)] = tmp;
	}
	i = parent(i);
}
*/


void main(){
	
	cout<<"enter size : ";
	cin>>_size;

	_size++;

	// algorithm starts from index "one" in array
	// value in array at index "zero" is redundant
	// thus it should print array from starting index "one"
	int print_size = _size; // use this variable for console output
	
	int *a = new int[_size];
	
	_size--;
	
	/*int y = 100000;*/
	cout<<"filling array randomly...\n";
	for( int i=1 ; i<print_size ; i++ )
	{
		/*a[i] = y;
		--y;*/
		//a[i] = i;
		a[i] = (rand() % 1000000) ; // 0 - 99,999
	}

	int x = 0;
	cout<<"print array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		// print a[]
		for( int i=1 ; i<print_size ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;

	// SORT ARRAY
	cout<<"sorting..."<<endl;
	
	clock_t begin = clock();
	heap_sort(a);
	clock_t end = clock();

	cout<<"sorted.\nTime Elapsed : "<<end-begin<<" millis.\n"<<endl;
	// END SORT
	
	cout<<"print sorted array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		// print a[]
		for( int i=1 ; i<print_size ; i++ )
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