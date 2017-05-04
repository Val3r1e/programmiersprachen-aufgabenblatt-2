#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

Vec2 value_con {2.4f, 0.0f};

Vec2 default_con {};

Vec2 plus_1 {2.0f, 3.0f};

Vec2 plus_2 {3.0f, 4.0f};

Vec2 plus_3 {5.3f, 4.3f};

Vec2 plus_4 {5.3f, 4.3f};

Vec2 minus_1 {2.0f, 3.0f};

Vec2 minus_2 {3.0f, 4.0f};

Vec2 minus_3 {5.3f, 7.3f};

Vec2 minus_4 {5.3f, 4.3f};

Vec2 mult_1 {2.0f, 3.0f};

Vec2 mult_2 {3.0f, 4.0f};

Vec2 div_1 {6.0f, 3.0f};

Vec2 div_2 {3.0f, 9.0f};

Vec2 nplus_1 {3.4f,5.4f};

Vec2 nplus_2 {4.4f,6.4f};

Vec2 nplus_3 {3.2f,3.4f};

Vec2 nminus_1 {4.5f,5.4f};

Vec2 nminus_2 {3.7f,2.5f};

Vec2 nminus_3 {6.2f,4.3f};

Vec2 nmult_1 {3.4f,5.6f};

Vec2 ndiv_1 {4.6f,2.7f};

Vec2 omult_1 {3.5,6.7};

float s = 3;

float z = 4;


TEST_CASE (" describe_value_constructor ", "[value_constructor]")
{
  REQUIRE (value_con.x_ == 2.4f);
  REQUIRE (value_con.y_ == 0.0f);
  REQUIRE (value_con.y_ != value_con.x_);
}

TEST_CASE (" describe_default_constructor ", "[default_constructor]")
{
  REQUIRE (default_con.x_ == 0);
  REQUIRE (default_con.y_ == 0);
  REQUIRE (default_con.x_ == default_con.y_);
}

TEST_CASE (" describe_plus_equals ", "[default_plus_equals]")
{

  plus_1 += plus_2;
  plus_3 += plus_4;
  REQUIRE (plus_1.x_ == 5.0f);
  REQUIRE (plus_1.y_ == 7.0f);
  REQUIRE (plus_3.x_ == 10.6f);
  REQUIRE (plus_3.y_ == 8.6f);
}

TEST_CASE (" describe_minus_equals ", "[default_minus_equals]")
{
  minus_1 -= minus_2;
  minus_3 -= minus_4;
  REQUIRE (minus_1.x_ == -1.0f);
  REQUIRE (minus_1.y_ == -1.0f);
  REQUIRE (minus_3.x_ == 0.0f);
  REQUIRE (minus_3.y_ == 3.0f);
}

TEST_CASE (" describe_mult_equals ", "[default_mult_equals]")
{
  mult_1 *= s;
  mult_2 *= s;
  REQUIRE (mult_1.x_ == 6.0f);
  REQUIRE (mult_1.y_ == 9.0f);
  REQUIRE (mult_2.x_ == 9.0f);
  REQUIRE (mult_2.y_ == 12.0f);
}

TEST_CASE (" describe_div_equals ", "[default_div_equals]")
{
  div_1 /= s;
  div_2 /= s;
  REQUIRE (div_1.x_ == 2.0f);
  REQUIRE (div_1.y_ == 1.0f);
  REQUIRE (div_2.x_ == 1.0f);
  REQUIRE (div_2.y_ == 3.0f);
}

TEST_CASE (" describe_only_plus ", "[default_only_plus]")
{
  Vec2 g = nplus_1 + nplus_2;
  Vec2 h = nplus_1 + nplus_3;
  REQUIRE (g.x_ == 7.8f);
  REQUIRE (g.y_ == 11.8f);
  REQUIRE (h.x_ == Approx(6.6f));
  REQUIRE (h.y_ == 8.8f);
}

TEST_CASE (" describe_only_minus ", "[default_only_minus]")
{
  Vec2 k = nminus_1 - nminus_2;
  Vec2 l = nminus_1 - nminus_3;
  REQUIRE (k.x_ == Approx(0.8f));
  REQUIRE (k.y_ == 2.9f);
  REQUIRE (l.x_ == Approx(-1.7f));
  REQUIRE (l.y_ == Approx(1.1f));
}

TEST_CASE (" describe_only_mult ", "[default_only_mult]")
{
  Vec2 t = nmult_1 * z;
  REQUIRE (t.x_ == Approx(13.6f));
  REQUIRE (t.y_ == 22.4f);
}

TEST_CASE (" describe_only_div ", "[default_only_div]")
{
  Vec2 j = ndiv_1 / z;
  REQUIRE (j.x_ == 1.15f);
  REQUIRE (j.y_ == 0.675f);
}

TEST_CASE (" describe_other_mult ", "[default_other_mult]")
{
  Vec2 o = omult_1 * z;
  REQUIRE (o.x_ == 14.0f);
  REQUIRE (o.y_ == 26.8f);
}

int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
