#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestIsValidPostalCode_Valid1)
		{
			char arr[] = "URUHU";
			Assert::IsTrue(isValidPostalCode(arr));
		}

		TEST_METHOD(TestIsValidPostalCode_Valid2)
		{
			char arr[] = "WER 983";
			Assert::IsTrue(isValidPostalCode(arr));
		}
	};

	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestIsValidPostalCode_Invalid1)
		{
			char arr[] = "65H  243"; // Contains space
			Assert::IsFalse(isValidPostalCode(arr));
		}

		TEST_METHOD(TestIsValidPostalCode_Invalid2)
		{
			char arr[] = "RTB01B2"; // Contains a zero in the middle
			Assert::IsFalse(isValidPostalCode(arr));
		}
	};

	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestIsValidPostalCode_Invalid3)
		{
			char arr[] = "D1T    ("; // Contains invalid character ')'
			Assert::IsFalse(isValidPostalCode(arr));
		}

		TEST_METHOD(TestIsValidPostalCode_Invalid4)
		{
			char arr[] = " EDS 1B3 "; // Contains spaces
			Assert::IsFalse(isValidPostalCode(arr));
		}
	};

	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(TestIsValidPostalCode_Invalid5)
		{
			char arr[] = "345634"; // Too short
			Assert::IsFalse(isValidPostalCode(arr));
		}

		TEST_METHOD(TestIsValidPostalCode_Invalid6)
		{
			char arr[] = "bbb uuu"; // Contains lowercase characters
			Assert::IsFalse(isValidPostalCode(arr));
		}
	};

	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(TestIsValidPostalCode_Invalid7)
		{
			char arr[] = "!@# $%^"; // Contains special characters
			Assert::IsFalse(isValidPostalCode(arr));
		}

		TEST_METHOD(TestIsValidPostalCode_Invalid8)
		{
			char arr[] = "       "; // Contains only spaces
			Assert::IsFalse(isValidPostalCode(arr));
		}
	};
	

	TEST_CLASS(ProvinceTests)
	{
	public:

		TEST_METHOD(TestIsValidProvince_Valid)
		{
			char province[] = "ON";
			Assert::IsTrue(isValidProvince(province));
		}

		TEST_METHOD(TestIsValidProvince_InvalidTooShort)
		{
			char province[] = "O"; // Too short
			Assert::IsFalse(isValidProvince(province));
		}

		TEST_METHOD(TestIsValidProvince_InvalidNonAlpha)
		{
			char province[] = "12"; // Contains non-alphabetic characters
			Assert::IsFalse(isValidProvince(province));
		}

		TEST_METHOD(TestIsValidProvince_InvalidMixedCase)
		{
			char province[] = "On"; // Mixed case
			Assert::IsFalse(isValidProvince(province));
		}

		TEST_METHOD(TestIsValidProvince_InvalidSpecialCharacters)
		{
			char province[] = "@#"; // Contains special characters
			Assert::IsFalse(isValidProvince(province));
		}
	};
}

