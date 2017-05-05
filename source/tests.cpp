#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

//Tests für Vektoren

float s = 3;
float z = 4;

TEST_CASE (" describe_value_constructor ", "[value_constructor]")
{
  Vec2 value_con {2.4f, 0.0f};
  REQUIRE (value_con.x_ == 2.4f);
  REQUIRE (value_con.y_ == 0.0f);
  REQUIRE (value_con.y_ != value_con.x_);
}

TEST_CASE (" describe_default_constructor ", "[default_constructor]")
{
  Vec2 default_con {};
  REQUIRE (default_con.x_ == 0);
  REQUIRE (default_con.y_ == 0);
  REQUIRE (default_con.x_ == default_con.y_);
}

TEST_CASE (" describe_plus_equals ", "[default_plus_equals]")
{
  Vec2 plus_1 {2.0f, 3.0f};
  Vec2 plus_2 {3.0f, 4.0f};
  Vec2 plus_3 {5.3f, 4.3f};
  Vec2 plus_4 {5.3f, 4.3f};
  plus_1 += plus_2;
  plus_3 += plus_4;
  REQUIRE (plus_1.x_ == 5.0f);
  REQUIRE (plus_1.y_ == 7.0f);
  REQUIRE (plus_3.x_ == 10.6f);
  REQUIRE (plus_3.y_ == 8.6f);
}

TEST_CASE (" describe_minus_equals ", "[default_minus_equals]")
{
  Vec2 minus_1 {2.0f, 3.0f};
  Vec2 minus_2 {3.0f, 4.0f};
  Vec2 minus_3 {5.3f, 7.3f};
  Vec2 minus_4 {5.3f, 4.3f};
  minus_1 -= minus_2;
  minus_3 -= minus_4;
  REQUIRE (minus_1.x_ == -1.0f);
  REQUIRE (minus_1.y_ == -1.0f);
  REQUIRE (minus_3.x_ == 0.0f);
  REQUIRE (minus_3.y_ == 3.0f);
}

TEST_CASE (" describe_mult_equals ", "[default_mult_equals]")
{
  Vec2 mult_1 {2.0f, 3.0f};
  Vec2 mult_2 {3.0f, 4.0f};
  mult_1 *= s;
  mult_2 *= s;
  REQUIRE (mult_1.x_ == 6.0f);
  REQUIRE (mult_1.y_ == 9.0f);
  REQUIRE (mult_2.x_ == 9.0f);
  REQUIRE (mult_2.y_ == 12.0f);
}

TEST_CASE (" describe_div_equals ", "[default_div_equals]")
{
  Vec2 div_1 {6.0f, 3.0f};
  Vec2 div_2 {3.0f, 9.0f};
  div_1 /= s;
  div_2 /= s;
  REQUIRE (div_1.x_ == 2.0f);
  REQUIRE (div_1.y_ == 1.0f);
  REQUIRE (div_2.x_ == 1.0f);
  REQUIRE (div_2.y_ == 3.0f);
}

TEST_CASE (" describe_only_plus ", "[default_only_plus]")
{
  Vec2 nplus_1 {3.4f,5.4f};
  Vec2 nplus_2 {4.4f,6.4f};
  Vec2 nplus_3 {3.2f,3.4f};
  Vec2 g = nplus_1 + nplus_2;
  Vec2 h = nplus_1 + nplus_3;
  REQUIRE (g.x_ == 7.8f);
  REQUIRE (g.y_ == 11.8f);
  REQUIRE (h.x_ == Approx(6.6f));
  REQUIRE (h.y_ == 8.8f);
}

TEST_CASE (" describe_only_minus ", "[default_only_minus]")
{
  Vec2 nminus_1 {4.5f,5.4f};
  Vec2 nminus_2 {3.7f,2.5f};
  Vec2 nminus_3 {6.2f,4.3f};
  Vec2 k = nminus_1 - nminus_2;
  Vec2 l = nminus_1 - nminus_3;
  REQUIRE (k.x_ == Approx(0.8f));
  REQUIRE (k.y_ == 2.9f);
  REQUIRE (l.x_ == Approx(-1.7f));
  REQUIRE (l.y_ == Approx(1.1f));
}

TEST_CASE (" describe_only_mult ", "[default_only_mult]")
{
  Vec2 nmult_1 {3.4f,5.6f};
  Vec2 t = nmult_1 * z;
  REQUIRE (t.x_ == Approx(13.6f));
  REQUIRE (t.y_ == 22.4f);
}

TEST_CASE (" describe_only_div ", "[default_only_div]")
{
  Vec2 ndiv_1 {4.6f,2.7f};
  Vec2 j = ndiv_1 / z;
  REQUIRE (j.x_ == 1.15f);
  REQUIRE (j.y_ == 0.675f);
}

TEST_CASE (" describe_other_mult ", "[default_other_mult]")
{
  Vec2 omult_1 {3.5,6.7};
  Vec2 o = omult_1 * z;
  REQUIRE (o.x_ == 14.0f);
  REQUIRE (o.y_ == 26.8f);
}

//Tests für Matrizen


TEST_CASE (" describe_default_matrix ", "[default_matrix]")
{
  Mat2 default_mat {};
  REQUIRE (default_mat.x_ == 1.0f);
  REQUIRE (default_mat.y_ == 0.0f);
  REQUIRE (default_mat.g_ == 0.0f);
  REQUIRE (default_mat.h_ == 1.0f);
}

TEST_CASE (" describe_value_matrix ", "[value_matrix]")
{
  Mat2 value_mat {3.0f, 2.0f, 5.0f, 3.0f};
  REQUIRE (value_mat.x_ == 3.0f);
  REQUIRE (value_mat.y_ == 2.0f);
  REQUIRE (value_mat.g_ == 5.0f);
  REQUIRE (value_mat.h_ == 3.0f);
}

TEST_CASE (" describe_determinante ", "[value_determinante]")
{
  Mat2 mat_det {4.0f,3.0f,5.0f,2.0f};
  Mat2 mat2_det {4.0f,-2.0f,8.0f,3.0f};
  REQUIRE (mat_det.det() == -7.0f);
  REQUIRE (mat2_det.det() == 28.0f);
}

TEST_CASE (" describe_mult_equals_mat ", "[value_mult_equals_mat]")
{
  Mat2 mat_one {6.0f, 5.0f, 6.0f, 7.0f};
  Mat2 mat_two {5.0f, 2.0f, 2.0f, 3.0f};
  mat_one *= mat_two;
  REQUIRE (mat_one.x_ == 40.0f);
  REQUIRE (mat_one.y_ == 27.0f);
  REQUIRE (mat_one.g_ == 44.0f);
  REQUIRE (mat_one.h_ == 33.0f);
}

TEST_CASE (" describe_nmult_mat ", "[value_nmult_mat]")
{
  Mat2 mat_three {3.0f, 4.5f, 7.6f, 3.6f};
  Mat2 mat_four {3.3f, 6.5f, 7.0f, 8.0f};
  Mat2 sum = mat_three * mat_four;
  REQUIRE (sum.x_ == 41.4f);
  REQUIRE (sum.y_ == 55.5f);
  REQUIRE (sum.g_ == 50.28f);
  REQUIRE (sum.h_ == 78.2f);
}

TEST_CASE (" describe_mult_mat_vec ", "[value_mult_mat_vec]")
{
  Mat2 mat_vec {3.0f,2.0f,6.0f,4.0f};
  Vec2 vec_mat {3.0f,2.0f};
  Vec2 sam = mat_vec * vec_mat;
  REQUIRE (sam.x_ == 13.0f);
  REQUIRE (sam.y_ == 26.0f);
}

TEST_CASE (" describe_mult_vec_mat ", "[value_mult_vec_mat]")
{
  Mat2 mat_vec2 {2.0f, 3.0f, 4.5f, 5.6f};
  Vec2 vec_mat2 {2.3f,4.0f};
  Vec2 sem = mat_vec2 * vec_mat2;
  REQUIRE (sem.x_ == 16.6f);
  REQUIRE (sem.y_ == 32.75f);
}

TEST_CASE (" describe_transpose ", "[value_transpose]")
{
  Mat2 mat_tran {2.3f,3.0f,4.0f,2.5f};
  Mat2 tran = transpose(mat_tran);
  REQUIRE (tran.x_ == 2.3f);
  REQUIRE (tran.y_ == 4.0f);
  REQUIRE (tran.g_ == 3.0f);
  REQUIRE (tran.h_ == 2.5f);
}

TEST_CASE (" describe_inverse ", "[value_inverse]")
{
  Mat2 mat_inv {2.0f,-3.0f,1.0f,5.0f};
  Mat2 inv = inverse(mat_inv);
  REQUIRE (inv.x_ == Approx(0.38462f));
  REQUIRE (inv.y_ == Approx(0.23077f));
  REQUIRE (inv.g_ == Approx(-0.07692f));
  REQUIRE (inv.h_ == Approx(0.15385f));
}

TEST_CASE (" describe_rotation ", "[value_rotation]")
{
  Mat2 rot = make_rotation_mat2(30);
  REQUIRE (rot.x_ == Approx(0.15425f));
  REQUIRE (rot.y_ == Approx(0.98803f));
  REQUIRE (rot.g_ == Approx(-0.98803f));
  REQUIRE (rot.h_ == Approx(0.15425f));
}

int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
