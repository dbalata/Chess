#ifndef PAIR_H
#define PAIR_H

template<typename T>
class Pair
{
public:
	T fst;
	T snd;

	Pair(T fst, T snd)
	{
		this->fst = fst;
		this->snd = snd;
	}
};

#endif