#ifndef ALGORITHM0_HPP
#define ALGORITHM0_HPP
#include <cstdio>
#include <iostream>

#include "include/smartpoint.hpp"
namespace ttd {

template<class T>
void swap( T &a, T &b )
{ T c(a),d(b); a=d;b=c; }
template<class T>
T min(const T &a, const T &b){return a<b?a:b;}
template<class T>
T max(const T &a, const T &b){return a<b?b:a;}




template<class TI, class T, class Compare>
TI lower_bound( TI data, TI end, const T &val, Compare cmp )
{
	int l,r;
	l = 0;r = end-data-1;
	while( l < r )
	{
		int mid = ( l+r )/2;
		if( cmp( *(data+mid), val ) )l = mid+1;
		else r = mid;
	}
	return data+l;
}

template<class TI, class T,class Compare>
TI upper_bound( TI data, TI end, const T &val, Compare cmp )
{
	int l,r;
	l = 0;r = end-data;
	while( l < r )
	{
		int mid = (l+r)/2;
		if( cmp( val, *(data+mid) ) )r = mid;
		else l = mid+1;
	}
	return data + l;
}

template<class TI, class T >
TI lower_bound( TI data, TI end, const T &val )
{ return lower_bound( data, end, val, std::less<T>() ); }

template<class TI, class T>
TI upper_bound( TI data, TI end, const T &val )
{ return upper_bound( data, end, val, std::less<T>() ); }

template<class TI, class BinaryPredicate>
TI unique( TI data, TI end, BinaryPredicate pred )
{
	int i,j=-1,n;
	n = end-data-1;
	for(i=0;i<n;i++)
	{
		if( j == -1 || !pred(*(data+j),*(data+i)) )
			*(data+(++j)) = *(data+i);
	}
	return data+j+1;
}
template<class TI>
TI unique( TI data, TI end )
{
	int i,j=-1,n;
	n = end-data-1;
	for(i=0;i<n;i++)
	{
		if( j == -1 || !(*(data+j) == *(data+i)) )
			*(data+(++j)) = *(data+i);
	}
	return data+j+1;
}
template<class TI, class Compare >
void sort( TI data, TI end, Compare cmp )
{
    if(end - data <= 1)return;
	int l,r;
	l = 0;r = end-data-1;
	swap( *(data+(l+r)/2), *(data+l) );
    TI x = data+l;
	while( l < r )
	{
		while( l < r && cmp( *x, *(data+r) ) )r--;
		if( l < r ){swap( *(data+(l++)), *(data+r) );x = data+r;}
		while( l < r && cmp( *(data+l), *x ) )l++;
		if( l < r ){swap( *(data+(r--)), *(data+l) );x = data+l;}
	}
	sort( data, x, cmp );
	sort( x+1, end, cmp );
}
template<class TI >
void sort( TI data, TI end )
{
    if(end - data <= 1)return;
	int l,r;
	l = 0;r = end-data-1;
	TI x;
	swap(*(data+((l+r)/2)), *(data+l));
	x = data+l;
	while( l < r )
	{
		while( l < r && ( *x < *(data+r) ) )r--;
		if( l < r ){swap( *(data+(l++)), *(data+r) );x = data+r;}
		while( l < r && ( *(data+l) < *x ) )l++;
		if( l < r ){swap( *(data+(r--)), *(data+l) );x = data+l;}
	}
	sort( data, x );
	sort( x+1, end );
}

}

#endif
