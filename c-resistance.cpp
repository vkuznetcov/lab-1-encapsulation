#include "c-resistance.h"

namespace c
{

	Resistance Serial(const Resistance *firstRes, const Resistance *secondRes)
	{
		Resistance res;
		res.resist = firstRes->resist + secondRes->resist;
		return res;
	}

	Resistance Parallel(const Resistance *firstRes, const Resistance *secondRes)
	{
		Resistance res;
		res.resist = ((firstRes->resist * secondRes->resist) / (firstRes->resist + secondRes->resist));
		return res;
	}

	double Amperage(const Resistance *res, const double u)
	{
		return (u/res->resist);
	}

	double Voltage(const Resistance *res, const double i)
	{
		return (i * res->resist);
	}
}