# TDD Driven StringCalculator

Build a StringCalculator functionality that can take up to two numbers, separated by commas, and will return their sum. 
for example “” or “1” or “1,2” as inputs.

> DO NOT jump into implementation! Read the example and the starting task below.

- For an empty string it will return 0
- Allow the Add method to handle an unknown amount of numbers
- Allow the Add method to handle new lines between numbers (instead of commas).
  - the following input is ok: “1\n2,3” (will equal 6)
  - the following input is NOT ok: “1,\n” (not need to prove it - just clarifying)
- Support different delimiters : to change a delimiter, the beginning of the string will contain a separate line that looks like this: “//[delimiter]\n[numbers…]” for example “//;\n1;2” should return three where the default delimiter is ‘;’ .
the first line is optional. all existing scenarios should still be supported
- Calling Method with a negative number will throw an exception “negatives not allowed” - and the negative that was passed. if there are multiple negatives, show all of them in the exception message.
- Numbers bigger than 1000 should be ignored, so adding 2 + 1001 = 2
- Delimiters can be of any length with the following format: “//[delimiter]\n” for example: “//[***]\n1***2***3” should return 6

## Tasks



Establish quality parameters:

- Ensure  maximum complexity (CCN) per function == 3

- Ensure 100% line and branch coverage at every step

  

Start Test-driven approach

1. Write the smallest possible failing test: give input `"" assert output to be 0 ` .
2. Write the minimum amount of code that'll make it pass.
3. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.


## Test Specifications based on requirements

TestCaseID 	Name 	Precondition 	Input 	Action 	Expected Output 	Comment
TC001 	Empty string returns 0 	Calculator instance exists 	"" 	Call Add method 	0 	Tests empty input handling
TC002 	Single number returns the value itself 	Calculator instance exists 	"1" 	Call Add method 	1 	Tests single number input
TC003 	Two numbers comma separated returns sum 	Calculator instance exists 	"1,2" 	Call Add method 	3 	Tests two numbers separated by comma
TC004 	Unknown amount of numbers returns their sum 	Calculator instance exists 	"1,2,3,4,5" 	Call Add method 	15 	Tests multiple numbers separated by comma
TC005 	New line between numbers is delimiter 	Calculator instance exists 	"1\n2,3" 	Call Add method 	6 	Tests newline delimiter alongside comma
TC006 	Custom single-character delimiter specified 	Calculator instance exists 	"//;\n1;2" 	Call Add method 	3 	Tests custom single-character delimiter
TC007 	Negative numbers throw exception 	Calculator instance exists 	"1,-2,-3" 	Call Add method 	Exception with message "negatives not allowed: -2, -3" 	Validates exception with all negative numbers
TC008 	Numbers larger than 1000 are ignored 	Calculator instance exists 	"2,1001" 	Call Add method 	2 	Tests ignoring numbers > 1000
TC009 	Delimiters of any length with square brackets 	Calculator instance exists 	"//[***]\n1***2***3" 	Call Add method 	6 	Tests multi-character custom delimiter
