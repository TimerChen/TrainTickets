#ifndef SJTU_UTILITY_HPP
#define SJTU_UTILITY_HPP

#include <utility>
#include <QDataStream>

namespace ttd {

template<class T1, class T2>
class pair {
public:
	T1 first;
	T2 second;
	constexpr pair() : first(), second() {}
	pair(const pair &other) = default;
	pair(pair &&other) = default;
	pair &operator = (const pair &other) = default;
	//{ first=other.first;second=other.second; return *}
	pair(const T1 &x, const T2 &y) : first(x), second(y) {}
	template<class U1, class U2>
	pair(U1 &&x, U2 &&y) : first(x), second(y) {}
	template<class U1, class U2>
	pair(const pair<U1, U2> &other) : first(other.first), second(other.second) {}
	template<class U1, class U2>
	pair(pair<U1, U2> &&other) : first(other.first), second(other.second) {}
};

template<class T1,class T2>
QDataStream& operator << (QDataStream& out, const pair<T1,T2> &data)
{
	out << data.first << data.second;
	return out;
}
template<class T1,class T2>
QDataStream& operator >> (QDataStream& in, pair<T1,T2> &data)
{
	in >> data.first >> data.second;
	return in;
}

}

#endif
