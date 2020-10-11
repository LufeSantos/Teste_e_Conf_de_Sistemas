#include "unity.h"
#include <string.h>

static char output[100];
static const char *expected;

void setUp(void)
{
  memset(output, 0xaa, sizeof output);
  expected = "";
}

void tearDown(void)
{
}

static void expect(const char * s)
{
  expected = s;
}

static void given(int charsWritten)
{
  TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
  TEST_ASSERT_EQUAL_STRING(expected, output);
  TEST_ASSERT_EQUAL_HEX8(0xaa, output[strlen(expected)+1]);
}

void test_sprintf1(void)
{

  expect("hey");
  given(sprintf(output,"hey"));
}

void test_sprintf2(void)
{
  expect("Hello World\n");
  given(sprintf(output, "Hello %s\n","World"));
}

void test_sprintf3(void)
{
  expect("");
  given(sprintf(output, ""));
}

void test_sprintf4(void)
{
  expect("1 a bc");
  given(sprintf(output, "%d %c %s", 1, 'a', "bc"));
}

void test_sprintf5(void)
{
  expect("0.333");
  given(sprintf(output, "%0.3f", 1/3.0));
}
