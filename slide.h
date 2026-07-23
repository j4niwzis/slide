#pragma once

#define EVAL2(...) __VA_ARGS__

#define OUT

#define VOID(...)

#define DELAY_OUT_0() OUT
#define DELAY_OUT_1() DELAY_OUT_0 OUT()
#define DELAY_OUT_2() DELAY_OUT_1 OUT()
#define DELAY_OUT_3() DELAY_OUT_2 OUT()
#define DELAY_OUT_4() DELAY_OUT_3 OUT()
#define DELAY_OUT_5() DELAY_OUT_4 OUT()

#define DELAY_COMMA_0() ,
#define DELAY_COMMA_1() DELAY_COMMA_0 OUT()
#define DELAY_COMMA_2() DELAY_COMMA_1 OUT()
#define DELAY_COMMA_3() DELAY_COMMA_2 OUT()

#define DELAY_OPEN_BRACE_0() (
#define DELAY_OPEN_BRACE_1() DELAY_OPEN_BRACE_0 OUT()
#define DELAY_OPEN_BRACE_2() DELAY_OPEN_BRACE_1 OUT()
#define DELAY_OPEN_BRACE_3() DELAY_OPEN_BRACE_2 OUT()

#define DELAY_CLOSE_BRACE_0() )
#define DELAY_CLOSE_BRACE_1() DELAY_CLOSE_BRACE_0 OUT()
#define DELAY_CLOSE_BRACE_2() DELAY_CLOSE_BRACE_1 OUT()
#define DELAY_CLOSE_BRACE_3() DELAY_CLOSE_BRACE_2 OUT()

#define CAT(a, b) CAT_(a, b)
#define CAT_(a, b) a##b

#define TEST_NULL_NULL 0,

#define IF_ELSE_1(test, next, ...) next OUT
#define IF_ELSE_0(test, next, ...) IF_ELSE_1(test, next, __VA_ARGS__, 0)

#define IF_ELSE(condition, t, f) IF_ELSE_0(condition OUT t, f, 0)

#define IF_ELSE_NO_OUT_1(test, next, ...) next
#define IF_ELSE_NO_OUT_0(test, next, ...) IF_ELSE_NO_OUT_1(test, next, __VA_ARGS__, 0)

#define IF_ELSE_NO_OUT(condition, t, f) IF_ELSE_NO_OUT_0(condition OUT t, f, 0)

#define SLIDE_2_A(x) \
  IF_ELSE_NO_OUT(    \
      CAT(TEST_NULL_, x), RIGHT_EDGE DELAY_CLOSE_BRACE_2(), x DELAY_CLOSE_BRACE_2() DELAY_OPEN_BRACE_2() x DELAY_COMMA_2() SLIDE_2_B)
#define SLIDE_2_B(x) \
  IF_ELSE_NO_OUT(    \
      CAT(TEST_NULL_, x), RIGHT_EDGE DELAY_CLOSE_BRACE_2(), x DELAY_CLOSE_BRACE_2() DELAY_OPEN_BRACE_2() x DELAY_COMMA_2() SLIDE_2_A)

#define SLIDE_2(seq) ( LEFT_EDGE, SLIDE_2_A seq(NULL)

#define WRAP_SEQ_A(...) (VALUE(__VA_ARGS__)) WRAP_SEQ_B
#define WRAP_SEQ_B(...) (VALUE(__VA_ARGS__)) WRAP_SEQ_A
#define WRAP_SEQ_A_END
#define WRAP_SEQ_B_END
#define WRAP_SEQ(seq) CAT(WRAP_SEQ_A seq, _END)

#define TEST_RIGHT_EDGE_RIGHT_EDGE 0,

#define REMOVE_EDGES_A(a, b) IF_ELSE(CAT(TEST_RIGHT_EDGE_, b), , (a, b)) REMOVE_EDGES_B
#define REMOVE_EDGES_B(a, b) IF_ELSE(CAT(TEST_RIGHT_EDGE_, b), , (a, b)) REMOVE_EDGES_A
#define REMOVE_EDGES_A_END
#define REMOVE_EDGES_B_END
#define REMOVE_EDGES(seq) EVAL2(VOID CAT(REMOVE_EDGES_A seq, _END))

#define FIRST_VALUE(a, b) a
#define SECOND_VALUE(a, b) b

#define SLIDE_3_A(a, b) (FIRST_##a, SECOND_##a, SECOND_##b) SLIDE_3_B
#define SLIDE_3_B(a, b) (FIRST_##a, SECOND_##a, SECOND_##b) SLIDE_3_A
#define SLIDE_3_A_END
#define SLIDE_3_B_END

#define SLIDE_3_HELPER(seq) CAT(SLIDE_3_A seq, _END)
#define SLIDE_3(seq) SLIDE_3_HELPER(REMOVE_EDGES(SLIDE_2(WRAP_SEQ(REMOVE_EDGES(SLIDE_2(seq))))))

// SLIDE_3((a)(b)(c)(d)(e)(f)(g))
