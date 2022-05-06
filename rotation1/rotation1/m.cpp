#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

template<class T>
void my_swap( T &left, T &right ){	
	T tmp = left;
	left = right;
	right = tmp;
}

template<class T>
void my_iter_swap( T left, T right ){	
	my_swap( *left , *right);
}

template <class T>
void my_reverse ( T first , T last ){
	while( (first != last) && (first != --last) ){
		my_iter_swap ( first , last );
		++first;
	}
}

template <class T>
void my_rotate1( T first , T middle , T last ){
	my_reverse( first , middle );
	my_reverse( middle , last );
	my_reverse( first , last );
}
/////////////////////////////////////////////
template <class T>
pair<T,T> my_reverse_until ( T first , T middle, T last ){
	while( (first != middle) && (middle != last) ){
		--last;
		my_iter_swap(first,last);
		++first;
	}
	return pair<T,T>(first,last);
}

template <class T>
pair<T,T> my_rotate2( T first , T middle , T last ){
	my_reverse( first , middle );
	my_reverse( middle , last );
	pair<T,T> p = my_reverse_until(first,middle,last);
	my_reverse( p.first , p.second );
	return p;
}
/////////////////////////////////////////////
void main(){
	vector<int> my_vector1;
	vector<int> my_vector2;

	for( int i=1 ; i<10 ; i++ ){
		my_vector1.push_back(i);
	}
	my_vector2 = my_vector1;
	cout<<"declared vector with sequence :\n";
	//before
	for( int i=0 ; i<9 ; i++ ){
		cout<<my_vector1.at(i)<<" ";
	}
	cout<<endl<<endl;
	cout<<"calling my_rotate1 on vector...\n";
	// starting index , finishing index , insertion point
	clock_t start1 = clock();
	for(int i=0 ; i<100001 ; ++i){
	my_rotate1( my_vector1.begin()+1 , my_vector1.begin()+4 , my_vector1.begin()+6 );
	}
	clock_t start2 = clock();
	//cout<<"done. time elapsed : "<<start2 - start1<<" millis.\nfinal vector is :"<<endl;
	//after
	for( int i=0 ; i<9 ; i++ ){
		cout<<my_vector1.at(i)<<" ";
	}
	cout<<endl<<endl;
	cout<<"calling my_rotate2 on vector...\n";
	// starting index , finishing index , insertion point
	clock_t start3 = clock();
	for(int i=0 ; i<100001 ; ++i){
	my_rotate2( my_vector2.begin()+1 , my_vector2.begin()+4 , my_vector2.begin()+6 );
	}
	clock_t start4 = clock();
	//cout<<"done. time elapsed : "<<start4 - start3<<" millis.\nfinal vector is :"<<endl;
	//after
	for( int i=0 ; i<9 ; i++ ){
		cout<<my_vector2.at(i)<<" ";
	}
	cout<<endl<<endl;
	system("pause");
}