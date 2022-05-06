#include <iostream>
#include <time.h>

using namespace std;

int a[100000001]; // 100 million
int b[100000001]; 

void merge( int , int , int );

void merge_sort( int low , int high ){
	int mid;
	if( low < high ) {
		mid = (low + high)/2;
		merge_sort( low , mid );
		merge_sort( mid+1 , high );
		merge( low, mid, high );
	}
}

void merge( int low , int mid , int high ){
	int h = low, i = low, j = mid+1 , k;
	
	while( h <= mid  &&  j<=high ){
		if( a[h] <= a[j] ){
			b[i] = a[h];
			++h;
		}
		else{
			b[i] = a[j];
			++j;
		}
		++i;
	}
	
	if( h > mid ){
		for( k=j ; k <= high ; k++ ){
			b[i] = a[k];
			++i;
		}
	}
	else{
		for( k=h ; k <= mid ; k++ ){
			b[i] = a[k];
			++i;
		}
	}

	for( k=low ; k <= high ; k++ ){
		a[k] = b[k];
	}
}

void main(){
	int lenght;
	cout<<"enter size : ";
	cin>>lenght;

	int y = 100000;
	cout<<"filling array randomly...\n";
	for( int i=1 ; i<=lenght ; i++ )
	{
		a[i] = y;
		--y;
		//a[i] = i;
		//a[i] = (rand() % 100000); // 0 - 99,999
	}
	
	int x = 0;
	cout<<"print array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		for( int i=1 ; i<=lenght ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;

	// SORT ARRAY
	cout<<"sorting..."<<endl;

	clock_t begin = clock();
	merge_sort( 1, lenght );
	clock_t end = clock();

	cout<<"sorted.\nTime Elapsed : "<<end-begin<<" millis.\n"<<endl;
	// END SORT
	
	cout<<"print sorted array ? (1 to confirm) : ";
	cin>>x;
	if( x==1 )
	{
		for( int i=1 ; i<=lenght ; i++ )
		{
			cout<<a[i]<<endl;
		}cout<<endl;
	}
	else
		cout<<"cancelled."<<endl;

	cout<<"memory released."<<endl;

	system("pause");
}