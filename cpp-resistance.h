#pragma once

namespace cpp
{
	class Resistance
	{
	private:
		double resist;

	public:
		Resistance();

		Resistance(double r);

		Resistance Serial(const Resistance &res)const;

		Resistance Parallel(const Resistance &res)const;

		double Amperage(const double u)const;

		double Voltage(const double i)const;

		static double Amperage_static(const Resistance *res, const double u);

		void SetRes(const double r);

		double GetRes()const;
	};
}