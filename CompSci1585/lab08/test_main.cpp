#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("List Elements", "[list]") {
	List<int> l;

	SECTION("copies identical") {
		for (int i = 0; i < 5; i++) {
			l.append(i);
		}

		List<int> copy(l);

		for (int i = 0; i < 5; i++) {
			CHECK(copy.head() == i);
			copy.pop();
		}
	}

	SECTION("Head works properly") {
		l.append(1);
		l.append(2);
		CHECK(l.head() == 1);
	}

	SECTION("Tail works properly") {
		l.append(1);
		l.append(2);
		l.append(3);
		List<int> test = l.tail();
		CHECK(test.head() == 2);
		test.pop();
		CHECK(test.head() == 3);
	}

	SECTION("Append works properly") {
		for (int i = 0; i < 10; i++) {
			l.append(i);
		}

		for (int i = 0; i < 10; i++) {
			CHECK(l.head() == i);
			l.pop();
		}
	}

	SECTION("Prepend works properly") {
		for (int i = 10; i > 0; i--) {
			l.prepend(i);
		}

		for (int i = 1; i < 10; i++) {
			CHECK(l.head() == i);
			l.pop();
		}
	}

	SECTION("Empty works properly") {
		CHECK(l.empty() == true);

		l.append(1);

		CHECK(l.empty() == false);
	}

	SECTION("length works properly") {
		CHECK(l.length() == 0);

		l.append(1);
		l.append(2);

		CHECK(l.length() == 2);
	}
}