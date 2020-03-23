#include "gtest.h"
#include "../List/TPolinom.h"

TEST(TMonom, can_create_monom) {
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_ins_monom_with_pos_coeff)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coeff = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coeff)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coeff = -1);
}

TEST(TMonom, can_ins_monom_with_neg_step)
{
	TMonom m;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	ASSERT_NO_THROW(m.coeff = 5);
}

TEST(TMonom, can_ins_monom_with_pos_step)
{
	TMonom m;
	m.px = -1;
	m.py = -1;
	m.pz = -1;
	ASSERT_NO_THROW(m.coeff = -5);
}

TEST(TMonom, can_compare_the_monom)
{
	TMonom m1, m2;
	m1.coeff = 10;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coeff = 10;
	m2.px = 1;
	m2.py = 1;
	m2.pz = 1;
	EXPECT_EQ(m1 == m2, 1);
}

TEST(TMonom, can_ne_monoms)
{
	TMonom m1, m2;
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coeff = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 != m2, 1);
}

TEST(TMonom, can_compare)
{
	TMonom m1, m2;
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 0;
	m2.coeff = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 < m2, 1);
	EXPECT_EQ(m1 > m2, 0);
}

TEST(TPolinom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom p);
}


TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	TMonom a;
	a.coeff = 1;
	a.px = 1;
	a.py = 1;
	a.pz = 1;
	p.insOrd(a);
	ASSERT_NO_THROW(p * 2);
	ASSERT_NO_THROW(p *= 2);
	ASSERT_NO_THROW(p * a);
	ASSERT_NO_THROW(p *= a);
}

TEST(TPolinom, can_multiplicate_pol_and_mon) {
	//(5xy+7xy^2z^3)*7xy^2z^3=49x^2y^4z^6+35x^2y^3z^3
	TMonom n;
	n.coeff = 7;
	n.px = 1;
	n.py = 2;
	n.pz = 3;
	TPolinom p, res;
	p.AddByPar(5, 1, 1, 0);
	p.AddByPar(7, 1, 2, 3);
	res.AddByPar(35, 2, 3, 3);
	res.AddByPar(49, 2, 4, 6);
	EXPECT_TRUE(res == p*n);
}

TEST(TPolinom, can_multiplicate_pol_and_pol) {
	//(5xy+7xy^2z^3)*(-10xy-7xy^2z^3+10x^2y^257xy^2z^3)=-50x^2y^2-70x^2y^3z^3+50x^6yz^2+70x^6y^2z^5
	TPolinom p, l, res,res1;
	p.AddByPar(5, 1, 1, 0);
	p.AddByPar(7, 1, 2, 3);
	l.AddByPar(-10,1,1,0);
	l.AddByPar(-7,1,2,3);
	l.AddByPar(10, 5, 0, 2);
	l.AddByPar(7, 1, 2, 3);
	res.AddByPar(-50,2,2,0);
	res.AddByPar(-70, 2, 3, 3);
	res.AddByPar(50, 6, 1, 2);
	res.AddByPar(70, 6, 2, 5);
	res1 = p * l;
	EXPECT_TRUE(res == p*l);
}

TEST(TPolinom, can_add_pol_and_pol) {
	//5xy+7xy^2z^3-5xy-7xy^2z^3=0
	TPolinom p, l, res;
	p.AddByPar(5, 1, 1, 0);
	p.AddByPar(7, 1, 2, 3);
	l.AddByPar(-5, 1, 1, 0);
	l.AddByPar(-7, 1, 2, 3);
	p += l;
	EXPECT_TRUE(res == p);
}

TEST(TPolinom, can_add_pol_and_pol1) {
	//5xy+7xy^2z^3+5xy-8xyz^4-7xy^2z^3=10xy-8xyz^4
	TPolinom p, l, res;
	p.AddByPar(5, 1, 1, 0);
	p.AddByPar(7, 1, 2, 3);
	l.AddByPar(5, 1, 1, 0);
	l.AddByPar(-8, 1, 1, 4);
	l.AddByPar(-7, 1, 2, 3);
	p += l;
	res.AddByPar(10, 1, 1, 0);
	res.AddByPar(-8, 1, 1, 4);
	EXPECT_TRUE(res == p);
}

TEST(TPolinom, can_multiplicate_pol_and_scal) {
	//(5xy+5xy)*3=30xy
	TMonom m, n;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 30;
	n.px = 1;
	n.py = 1;
	n.pz = 0;
	TPolinom p, res;
	p.insOrd(m);
	p.insOrd(m);
	p *= 3;
	res.insOrd(n);
	EXPECT_TRUE(res == p);
}



TEST(TPolinom, stop)
{
	system("pause");
}
