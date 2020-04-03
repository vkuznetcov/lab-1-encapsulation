#include "cpp-resistance.h"

namespace cpp
{
	Resistance::Resistance() :resist(1) { }

	Resistance::Resistance(double r) : resist(r) { }

	Resistance Resistance::Serial(const Resistance &res)const
	{
		return Resistance(resist + res.resist);
	}

	Resistance Resistance::Parallel(const Resistance &res)const
	{
	
		return Resistance((resist * res.resist) / (resist + res.resist));
	}

	double Resistance::Amperage(const double u)const
	{
		return Resistance::Amperage_static(this, u);
		//return (u / resist);
	}

	double Resistance::Voltage(const double i)const
	{
		return (i * resist);
	}

	double Resistance::Amperage_static(const Resistance *res, const double u)
	{
		//return res->Amperage(u);
		return (u / res->resist);
	}

	void Resistance::SetRes(const double r)
	{
		resist = r;
	}

	double Resistance::GetRes() const
	{
		return resist;
	}
}