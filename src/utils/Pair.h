#ifndef PAIR_H
#define PAIR_H

template<class T1, class T2>
struct Pair {
	T1 el1;
	T2 el2;

	void SetPair( T1 a_el1, T2 a_el2 );
};

template<class T1, class T2>
void Pair<T1, T2>::SetPair( T1 a_el1, T2 a_el2 ) {
	el1 = a_el1;
	el2 = a_el2;
}

#endif
