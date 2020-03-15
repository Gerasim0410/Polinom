#include "gtest.h"
#include "../List/TList.h"

TEST(THeadList, can_create_a_head_list) {
	ASSERT_NO_THROW(THeadList<int> l);
}

TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(THeadList<int> l);
}

TEST(THeadList, can_insfirst)
{
	THeadList<int> l;
	ASSERT_NO_THROW(l.insFirst(1));
	ASSERT_NO_THROW(l.Reset());
	//EXPECT_EQ(l.GetCurr(), 1);
}


TEST(THeadList, stop)
{
	system("pause");
}