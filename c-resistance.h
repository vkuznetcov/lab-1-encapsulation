#pragma once

namespace c
{
	struct Resistance
	{
		double resist;
	};

	Resistance Serial(const Resistance* firstRes, const Resistance* secondRes);

	Resistance Parallel(const Resistance* firstRes, const Resistance* secondRes);

	double Amperage(const Resistance* res, const double u);

	double Voltage(const Resistance* res, const double i);

}