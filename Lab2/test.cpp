#include "pch.h"
#include "..\..\StaticMath\MathLibrary\Header1.h"
#include "iostream"

TEST(EvolvConstructor, DefaultConstructor)
{
	Prog2::Evolv a1;
	ASSERT_EQ(1, a1.GetRadius());

}
TEST(EvolvConstructor, InitConstructors)
{
	Prog2::Evolv a2(3);
	ASSERT_EQ(3, a2.GetRadius());

	Prog2::Evolv a3(8);
	ASSERT_EQ(8, a3.GetRadius());

	Prog2::Evolv a4(5);
	ASSERT_EQ(5, a4.GetRadius());
}
TEST(EvolvConstructor, TestException)
{

	ASSERT_ANY_THROW(Prog2::Evolv(-5));
	ASSERT_ANY_THROW(Prog2::Evolv(-1));
}

TEST(EvolvMethods, Setters){

	Prog2::Evolv a;
	a.SetRadius(2);
	ASSERT_EQ(2, a.GetRadius());
	ASSERT_ANY_THROW(a.SetRadius(-1));
	ASSERT_ANY_THROW(a.SetRadius(-2));
	ASSERT_ANY_THROW(a.SetRadius(-3));
	ASSERT_ANY_THROW(a.SetRadius(-4));

}
TEST(EvolvMethods, Parameters)
{
	Prog2::Evolv a1(1);
	const double PI = 3.14159265, err = 0.001;
	double f = 3.141;
	double f2 = 0;
	double f3 = 6.282;
	double f4 = -2;
	ASSERT_NEAR(3.29634, a1.distance(f), err);
	ASSERT_NEAR(0.398, a1.curvat(f), err);
	ASSERT_NEAR(4.932, a1.length(f), err);
	ASSERT_NEAR(1, a1.distance(f2), err);
	ASSERT_NEAR(0, a1.length(f2), err);
	ASSERT_NEAR(6.361, a1.distance(f3), err);
	ASSERT_NEAR(0.282, a1.curvat(f3), err);
	ASSERT_NEAR(19.731, a1.length(f3), err);

	
	ASSERT_EQ(1, a1.distance(f2));
	ASSERT_EQ(0, a1.length(f2));

	ASSERT_ANY_THROW(a1.curvat(f2));

	Prog2::Evolv a2(2);
	ASSERT_NEAR(6.592, a2.distance(f), err);
	ASSERT_NEAR(0.282, a2.curvat(f), err);
	ASSERT_NEAR(9.865, a2.length(f), err);
	ASSERT_NEAR(2, a2.distance(f2), err);
	ASSERT_NEAR(0, a2.length(f2), err);
	ASSERT_NEAR(12.722, a2.distance(f3), err);
	ASSERT_NEAR(0.199, a2.curvat(f3), err);
	ASSERT_NEAR(39.463, a2.length(f3), err);


	ASSERT_EQ(2, a2.distance(f2));
	ASSERT_EQ(0, a2.length(f2));

	ASSERT_ANY_THROW(a2.curvat(f2));
	ASSERT_ANY_THROW(a2.curvat(f4));

}
int _tmain(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}