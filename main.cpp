#include <libutils/io.h>
#include "c-resistance.h"
#include "cpp-resistance.h"
#include <climits>
#include <cstdio>
#include <Windows.h>

int main()
{
	//c
	if(true)
	{
		printf("\tC variation\n");
		using namespace c;

		double res = utils::read_double("Enter the first resistance: ", 1, 100);
		Resistance FirstRes;
		FirstRes.resist = res;
		printf("\nResistance: %g Ohm\n\n", FirstRes.resist);

		double i = utils::read_double("Enter amperage: ", 1, 100);
		double u_calc = Voltage(&FirstRes, i);

		double u = utils::read_double("Enter voltage: ", 1, 100);
		double i_calc = Amperage(&FirstRes, u);
		
		printf("\nIf amperage = %g A, voltage = %g V\nIf voltage = %g V, amperage = %g A\n\n", i, u_calc, u, i_calc);

		i = i_calc = u = u_calc = 0;

		res = utils::read_double("Enter the second resistance: ", 1, 100);
		Resistance SecondRes; 
		SecondRes.resist = res;
		printf("\nFirst resistance: %g Ohm\nSecond resistance: %g Ohm\n\n", FirstRes.resist, SecondRes.resist);

		Resistance serialRes = Serial(&FirstRes, &SecondRes);
		Resistance parallelRes = Parallel(&FirstRes, &SecondRes);

		printf("Serial resistance: %g Ohm\nParallel resistance: %g Ohm\n", serialRes.resist, parallelRes.resist);
	}

	//cpp

	if(true)
	{
		using namespace cpp;
		printf("\n\tC++ variation\n");
		double res = utils::read_double("Enter the first resistance: ", 1, 100);
		Resistance FirstRes;
		FirstRes.SetRes(res);
		//res = FirstRes.GetRes();
		printf("\nResistance: %g Ohm\n\n", res);

		double i = utils::read_double("Enter amperage: ", 1, 100);
		double u_calc = FirstRes.Voltage(i);

		double u = utils::read_double("Enter voltage: ", 1, 100);
		double i_calc = FirstRes.Amperage(u);

		double u2 = utils::read_double("\nEnter the second voltage: ", 1, 100);
		double i_calc_static = Resistance::Amperage_static(&FirstRes, u2);

		printf("\nIf amperage = %g A, voltage = %g V\nIf voltage = %g V, amperage = %g A\nIf voltage = %g V, amperage = %g A\n", i, u_calc, u, i_calc, u2, i_calc_static);

		i = i_calc = u = u_calc = i_calc_static = u2 = 0;

		res = utils::read_double("Enter second resistance: ", 1, 100);
		Resistance SecondRes(res);
		printf("First resistance: %g Ohm\nSecond resistance: %g Ohm\n", FirstRes.GetRes(), SecondRes.GetRes());

		Resistance serialRes = FirstRes.Serial(SecondRes);
		Resistance parallelRes = FirstRes.Parallel(SecondRes);
		printf("Serial resistance: %g Ohm\nParallel resistance: %g Ohm\n", serialRes.GetRes(), parallelRes.GetRes());
	}
	system("pause");
	return 0;
}