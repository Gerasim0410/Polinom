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
	m1.coeff = 2;
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
	TMonom m, n, c;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 7;
	n.px = 1;
	n.py = 2;
	n.pz = 3;
	c.coeff = 35;
	c.px = 2;
	c.py = 3;
	c.pz = 3;
	TPolinom p, res;
	p.insOrd(m);

	res.insOrd(c);
	EXPECT_TRUE(res == p*n);
}

TEST(TPolinom, can_add_pol_and_pol) {
	TMonom m, n, c;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 7;
	n.px = 1;
	n.py = 2;
	n.pz = 3;
	c.coeff = 35;
	c.px = 2;
	c.py = 3;
	c.pz = 3;
	TPolinom p, l, res;
	p.insOrd(m);
	l.insOrd(n);
	res.insOrd(c);
	EXPECT_TRUE(res == p*l);
}

TEST(TPolinom, can_multiplicate_pol_and_scal) {
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
	res.insOrd(m);
	EXPECT_TRUE(res == p);
}



TEST(TPolinom, stop)
{
	system("pause");
}